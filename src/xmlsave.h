#ifndef XMLSAVE_H
#define XMLSAVE_H

#include <QtGui>
#include <QtXml>
#include <QWidget>

/*! \class XmlSave
 * \brief Classe responsable de la sauvegarde et du chargement du contexte de l'application.
 *
 *  Crée et utilise un ou plusieurs fichiers XML.
 *  Elle hérite de la classe QT QWidget.
 *
 * Singleton
 */
class XmlSave : public QWidget
{
    private:
    QString filename;
    QXmlStreamReader Rxml;
    /*!
    * \brief Constructeur.
    */
    XmlSave();
    /*!
    * \brief Destructeur.
    */
    ~XmlSave();
    static XmlSave* Xinstance;
    public:
    /*!
    *  \brief Accesseur de l'instance.
    *
    *  \return référence sur XmlSave pointant sur l'instance unique.
    */
    static XmlSave& getInstance(){
        if (Xinstance==0)
            Xinstance = new XmlSave();
        return *Xinstance;
    }
    /*!
    *  \brief Destructeur de l'instance.
    */
    static void freeInstance(){
        if (Xinstance !=0)
            delete Xinstance;
        Xinstance=0;
    }
    /*!
    *  \brief Sauvegarde l'état de la calculatrice dans un ficher XML.
    */
    void SaveXMLFile();
    /*!
    *  \brief Charge l'état de la calculatrice à partir d'un fichier XML.
    */
    void ReadXMLFile(const QString&);
    /*!
    *  \brief Lit les balises Literal.
    */
    void ReadLiteralElement();
    /*!
    *  \brief Lit les balises Variable.
    */
    void ReadVariableElement();
};

#endif // XMLSAVE_H
