#include "xmlsave.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QMap>
#include "pile.h"
#include "QComputer.h"

#include "Literal.h"
#include "rationnel.h"

using namespace std;

XmlSave* XmlSave::Xinstance=0;

XmlSave::XmlSave() : QWidget()
{

}

XmlSave::~XmlSave()
{

}

void XmlSave::SaveXMLFile()
{
    filename = "save.xml";
    /*filename = QFileDialog::getSaveFileName(this,
                                            tr("Save Xml"), ".",
                                            tr("Xml files (*.xml)"));*/
    //qDebug()<<filename;

    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("ROOT");

    xmlWriter.writeStartElement("ATOME");
    QMap<QString,Literal*> atometosave = QComputer::getInstance().getAtome();
    for (QMap<QString,Literal*>::const_iterator it = atometosave.constBegin(); it != atometosave.constEnd(); ++it){
        qDebug()<<it.key();
        qDebug()<<it.value()->toString();
        Literal* exp = it.value();
        literal_type typeexp = literalType(*exp);
        switch (typeexp)
        {
        case entier:
        {
            xmlWriter.writeStartElement("VARIABLE");
            xmlWriter.writeTextElement("Type", "Entier");
            xmlWriter.writeTextElement("Nom", it.key());
            xmlWriter.writeTextElement("Valeur",it.value()->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Expression";
            break;
            qDebug()<<"Entier";
            break;
        }
        case reel:
        {
            xmlWriter.writeStartElement("VARIABLE");
            xmlWriter.writeTextElement("Type", "Reel");
            xmlWriter.writeTextElement("Nom", it.key());
            xmlWriter.writeTextElement("Valeur",it.value()->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Expression";
            break;
            qDebug()<<"Reel";
            break;
        }
        case rationnel:
        {
            xmlWriter.writeStartElement("VARIABLE");
            xmlWriter.writeTextElement("Type", "Rationnel");
            xmlWriter.writeTextElement("Nom", it.key());
            xmlWriter.writeTextElement("Valeur",it.value()->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Expression";
            break;
            qDebug()<<"Rationnel";
            break;
        }
        case complexe:
        {
            xmlWriter.writeStartElement("VARIABLE");
            xmlWriter.writeTextElement("Type", "Complexe");
            xmlWriter.writeTextElement("Nom", it.key());
            xmlWriter.writeTextElement("Valeur",it.value()->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Expression";
            break;
            qDebug()<<"Complexe";
            break;
        }
        case expression:
        {
            xmlWriter.writeStartElement("VARIABLE");
            xmlWriter.writeTextElement("Type", "Expression");
            xmlWriter.writeTextElement("Nom", it.key());
            xmlWriter.writeTextElement("Valeur",it.value()->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Expression";
            break;
            qDebug()<<"Expression";
            break;
        }
        case programme:
        {
            xmlWriter.writeStartElement("VARIABLE");
            xmlWriter.writeTextElement("Type", "Programme");
            xmlWriter.writeTextElement("Nom", it.key());
            xmlWriter.writeTextElement("Valeur",it.value()->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Programme";
            break;
        }
        default:
        {
            qDebug()<<"Inconnu";
            //throw LitteralException("Erreur de type");
            break;
        }
        }
    }

    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("PILE");
    Pile piletosave = QComputer::getInstance().getPile();
    for (unsigned int i=0; i<piletosave.size(); i++){
        qDebug()<<piletosave.value(i)->toString();
        Literal* exp = piletosave.value(i);
        literal_type typeexp = literalType(*exp);
        switch (typeexp)
        {
        case entier:
        {
            xmlWriter.writeStartElement("LITERALE");
            xmlWriter.writeTextElement("Type", "Entier");
            xmlWriter.writeTextElement("Valeur",piletosave.value(i)->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Entier";
            break;
        }
        case reel:
        {
            xmlWriter.writeStartElement("LITERALE");
            xmlWriter.writeTextElement("Type", "Reel");
            xmlWriter.writeTextElement("Valeur",piletosave.value(i)->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Reel";
            break;
        }
        case rationnel:
        {
            xmlWriter.writeStartElement("LITERALE");
            xmlWriter.writeTextElement("Type", "Rationnel");
            //xmlWriter.writeTextElement("ValeurNum",dynamic_cast<const Rationnel*>(piletosave.value(i))->toStringnum());
            //xmlWriter.writeTextElement("ValeurDen",dynamic_cast<const Rationnel*>(piletosave.value(i))->toStringden());
            xmlWriter.writeTextElement("Valeur",piletosave.value(i)->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Rationnel";
            break;
        }
        case complexe:
        {
            xmlWriter.writeStartElement("LITERALE");
            xmlWriter.writeTextElement("Type", "Complexe");
            xmlWriter.writeTextElement("Valeur",piletosave.value(i)->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Complexe";
            break;
        }
        case programme:
        {
            xmlWriter.writeStartElement("LITERALE");
            xmlWriter.writeTextElement("Type", "Programme");
            xmlWriter.writeTextElement("Valeur",piletosave.value(i)->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Programme";
            break;
        }
        case expression:
        {
            xmlWriter.writeStartElement("LITERALE");
            xmlWriter.writeTextElement("Type", "Expression");
            xmlWriter.writeTextElement("Valeur",piletosave.value(i)->toString());
            xmlWriter.writeEndElement();
            qDebug()<<"Expression";
            break;
        }
        default:
        {
            qDebug()<<"Inconnu";
            //throw LitteralException("Erreur de type");
            break;
        }
        }
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();

    file.close();
}

void XmlSave::ReadXMLFile(const QString& s)
{
    filename = s;
    /*filename = QFileDialog::getOpenFileName(this,
                                            tr("Open Xml"), ".",
                                            tr("Xml files (*.xml)"));*/

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        std::cerr << "Error: Cannot read file " << qPrintable(filename)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;

    }

    Rxml.setDevice(&file);
    Rxml.readNext();

    while(!Rxml.atEnd())
            {
                if(Rxml.isStartElement())
                {
                        if(Rxml.name() == "ROOT")
                        {
                            Rxml.readNext();
                        }
                        else if(Rxml.name() == "ATOME")
                        {
                            QComputer::getInstance().getAtome().clear();
                            Rxml.readNext();
                        }

                        else if(Rxml.name() == "VARIABLE")
                        {
                            ReadVariableElement();//entra
                            Rxml.readNext();
                        }
                        else if(Rxml.name() == "PILE")
                        {
                            QComputer::getInstance().getPile().clear();
                            Rxml.readNext();
                        }
                        else if(Rxml.name() == "LITERALE")
                        {
                            ReadLiteralElement();//entra
                            Rxml.readNext();
                        }
                        else
                        {
                            Rxml.raiseError(QObject::tr("Not a bookindex file"));
                        }
                }
                else
                {
                    Rxml.readNext();
                }
            }
    file.close();
    if (Rxml.hasError())
    {
        std::cerr << "Error: Failed to parse file "
                  << qPrintable(filename) << ": "
                  << qPrintable(Rxml.errorString()) << std::endl;

    }
    else if (file.error() != QFile::NoError)
    {
        std::cerr << "Error: Cannot read file " << qPrintable(filename)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
    }
}

void XmlSave::ReadLiteralElement()
{
    QString type_exp_lue;
    while(!Rxml.atEnd())
    {
        if(Rxml.isEndElement())
        {
            Rxml.readNext();
            break;
        }
        else if(Rxml.isCharacters())
        {
            Rxml.readNext();
        }
        else if(Rxml.isStartElement())
        {
            if(Rxml.name() == "Type")
            {
                while(!Rxml.atEnd())
                {
                    if(Rxml.isEndElement())
                    {
                        Rxml.readNext();
                        break;
                    }
                    else if(Rxml.isStartElement())
                    {
                        type_exp_lue = Rxml.readElementText();
                        Rxml.readNext();
                        break;
                    }
                    else if(Rxml.isCharacters())
                    {
                        Rxml.readNext();
                    }
                    else
                    {
                        Rxml.readNext();
                    }
                }
            }
            else if(Rxml.name() == "Valeur")
            {
                while(!Rxml.atEnd())
                {
                    if(Rxml.isEndElement())
                    {
                        Rxml.readNext();
                        break;
                    }
                    else if(Rxml.isStartElement())
                    {
                        QString valeur = Rxml.readElementText();
                        Literal* newexp = regexTypeSave(valeur);
                        QString type = literalTypeString(*newexp);
                        QComputer::getInstance().getPile().push_back(newexp);

                        Rxml.readNext();
                        break;

                    }
                    else if(Rxml.isCharacters())
                    {
                        Rxml.readNext();
                    }
                    else
                    {
                        Rxml.readNext();
                    }
                }
            }
            Rxml.readNext();
        }
        else
        {
            Rxml.readNext();
        }
    }
}

void XmlSave::ReadVariableElement()
{
    QString nom;
    Literal* lit;
    while(!Rxml.atEnd())
    {
        if(Rxml.isEndElement())
        {
            Rxml.readNext();
            break;
        }
        else if(Rxml.isCharacters())
        {
            Rxml.readNext();
        }
        else if(Rxml.isStartElement())
        {
            if(Rxml.name() == "Type")
            {
                while(!Rxml.atEnd())
                {
                    if(Rxml.isEndElement())
                    {
                        Rxml.readNext();
                        break;
                    }
                    else if(Rxml.isStartElement())
                    {
                        QString type_exp_lue = Rxml.readElementText();
                        Rxml.readNext();
                        break;
                    }
                    else if(Rxml.isCharacters())
                    {
                        Rxml.readNext();
                    }
                    else
                    {
                        Rxml.readNext();
                    }
                }
            }
            else if(Rxml.name() == "Nom")
            {
                while(!Rxml.atEnd())
                {
                    if(Rxml.isEndElement())
                    {
                        Rxml.readNext();
                        break;
                    }
                    else if(Rxml.isStartElement())
                    {
                        nom = Rxml.readElementText();
                        Rxml.readNext();
                        break;

                    }
                    else if(Rxml.isCharacters())
                    {
                        Rxml.readNext();
                    }
                    else
                    {
                        Rxml.readNext();
                    }
                }
            }
            else if(Rxml.name() == "Valeur")
            {
                while(!Rxml.atEnd())
                {
                    if(Rxml.isEndElement())
                    {
                        Rxml.readNext();
                        break;
                    }
                    else if(Rxml.isStartElement())
                    {
                        QString valeur = Rxml.readElementText();
                        lit = regexTypeSave(valeur);
                        QString type = literalTypeString(*lit);
                        Rxml.readNext();
                        break;

                    }
                    else if(Rxml.isCharacters())
                    {
                        Rxml.readNext();
                    }
                    else
                    {
                        Rxml.readNext();
                    }
                }
            }
            Rxml.readNext();
        }
        else
        {
            Rxml.readNext();
        }
    }
    QComputer::getInstance().getAtome().insert(nom,lit);
}
