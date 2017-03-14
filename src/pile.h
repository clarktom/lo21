#ifndef PILE_H
#define PILE_H

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <cmath>

#include <QVector>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include <QStringList>
#include <QApplication>
#include <QObject>

#include "literal.h"

#define nbPile 9

using namespace std;

/*! \class ComputerException
 * \brief Classe exception concernant QComputer.
 */
class ComputerException {
    QString info;
public:
    /*!
         *  \brief Constructeur.
         *
         *  \param str Référence const sur QString pour initialiser l'attribut info.
         */
    ComputerException(const QString& str) : info(str) {}
    /*!
         *  \brief Accesseur de l'attribut info.
         *
         *  \return QString correspondant à l'attribut info.
         */
    QString getInfo() const { return info; }
};

/*! \class Pile
 * \brief Classe permettant de stocker les littérales.
 *
 *  Elle hérite de la classe QT QVector et contient des pointeurs sur Literal.
 */
class Pile : public QVector<Literal*> {
    QString message;
    unsigned int nb;
public:
    /*!
     *  \brief Affecte l'attribut message. Accesseur en écriture.
     *
     *  \param msg Référence const sur QString permettant de passer la valeur.
     */
    void setMessage(const QString& msg) { message = msg; }
    /*!
     *  \brief Accesseur de l'attribut message.
     *
     *  \return QString correspondant à l'attribut message.
     */
    QString getMessage() const { return message; }
    /*!
     *  \brief Accesseur de l'attribut nb.
     *
     *  \return int correspondant à l'attribut nb.
     */
    unsigned int getNb() const { return nb; }
    /*!
    *  \brief Affecte l'attribut nb. Accesseur en écriture.
    *
    *  \param n int permettant de passer la valeur.
    */
    void setNb(int n) { nb=n; }
    /*!
     *  \brief Constructeur.
     *
     *  nbPile est un constante déclarée dans ce fichier correspondant au nombre d'item à afficher de base.
     */
    Pile() : message("Bienvenue"), nb(nbPile) {}
    /**
    * \brief Renvoie un entier correspondant au type de l'operateur.
    *
    * Renvoie une valeur qui correspond au nombre d'arg a dépiler, renvoi 0 si l'operateur n'est pas reconnu.
    *
    * \param s Référence const sur QString.
    * \return int correspondant au type. 1 pour les opérateurs unaires, 2 pour les opérateurs binaires, 3 pour les commandes console.
    */
    int estUnOperateur(const QString& s) const;
    /*!
    *  \brief Surcharge du =.
    *
    * Est utilisée dans la classe Memento, afin d'affecter à la pile de celui-ci celle du QComputer 
    *
    * \param p Référence const sur Pile.
    * \return Référence sur Pile correspondant à l'objet affecté.
    */
    Pile& operator=(const Pile& p){
        if (this!=&p){
            nb=p.nb;
            message=p.message;
            this->clear();
            for (unsigned int i=0; i<p.size(); i++){
                this->push_back(p.value(i)->clone());
            }
            return *this;
        }
    }
    /*!
    *  \brief Permet de comparer deux piles.
    *
    * Si les deux piles sont différentes, renvoie true.
    * Est appelée après l'exécution d'une commande, afin de savoir si la pile a été modifiée et si un Memento doit être créer. 
    *
    * \param p Référence const sur Pile pointant sur la pile à comparer.
    * \return bool.
    */
    bool isUpdated(const Pile& p)
    {
        if (this->size()!=p.size()){
            return true;
        }
        for (unsigned int i=0; i<p.size(); i++){
            Literal* e1, *e2;
            e1 = this->value(i);
            e2 = p.value(i);
            if (this->value(i)->toString()!=p.value(i)->toString())
                return true;
        } return false;
    }
    /*!
    *  \brief Constructeur par recopie.
    *
    * \param p Référence const sur Pile.
    */
    Pile(const Pile& p) : message(p.message), nb(p.nb){
        this->clear();
        for (unsigned int i=0; i<p.size(); i++){
            this->push_back(p.value(i)->clone());
        }
    }

    /*void afficher_pile(){
        for (unsigned int i=0; i<this->size(); i++){
            qDebug()<<this->value(i)->toString();
        }
    }*/
};

/*! \class Controleur
 * \brief Responsable du traitement des opérandes et fait office d'interface entre la calculatrice et la pile.
 *
 * Il est resposanles de la modification des attributs de QComputer, c'est à dire la pile, la QMap atome et la QStringList cmd, par le biais de références. 
 * Il gère également les éléments lastOp et lastArgs permettant le fonctionnement des opérateurs du même nom.
 * Enfin il possède la map factories et donc construit les différentes littérales.
 *
 *  Cette gestion se fait par le biais de la méthode commande.
 *  Elle hérite de la classe QT QObject afin de pouvoir émettre des signaux à QComputer.
 */
class Controleur : public QObject {
    Q_OBJECT
    Pile& pile;
    QStringList& cmd;
    QMap<QString,Literal*>& atome;
    QString lastOp;
    QVector<Literal*> lastArgs;
    map<QString,LiteralFactory*> factories;  
public:
    /*!
    *  \brief Utilisée par la méthode expPostFix pour respecter les ordres de priorité.
    *
    *  \param v Référence const sur QString pointant sur le QString à analyser.
    */
    int getPriorite(const QString&) const;
    /*!
    *  \brief Transforme une epxression infixe en expression postfixe
    *
    *  \param Référence const sur QStringList pointant sur l'expression à transformer.
    */
    QStringList expPostFix(const QStringList&);
    /*!
     *  \brief Constructeur.
     *
     * Fait appel à getFactoriesMap() pour instancier la map factories.
     *
     *  \param v Référence sur Pile pour initialiser l'attribut pile, c Référence sur QStringList pour initialiser l'attribut cmd, m Référence sur QMap<QString,Literal*> pour initialiser l'attribut atome.
     */
    Controleur(Pile& v, QStringList& c, QMap<QString,Literal*>& m) : pile(v), cmd(c), atome(m) {
        factories = LiteralFactory::getFactoriesMap();
    }
    /*!
     *  \brief Traite la commande à exécuter et effectue la bonne opération. Peut également construire des littérales.
     *
     *  Détermine l'opérateur et appelle les méthode appropriées, effectue les modifications nécessaires sur les attributs de QComputer et lastOp et lastArgs.
     *
     *  \param c Référence const sur QString pointant sur la commande passée.
     */
    void commande(const QString& c);
    /*!
     *  \brief Accesseur de l'attribut pile.
     *
     *  \return Pile correspondant à l'attribut pile.
     */
    Pile getPile() { return pile; }
signals:
    /*!
     *  \brief Envoie un sinal modificationEtat qui est utilisé dans QComputer afin d'être averti lorsque la pile est modifiée.
     */
    void modificationEtat();
};

#endif

