#ifndef QCOMPUTER_H
#define QCOMPUTER_H

#include <QVector>
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
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QtUiTools>
#include <QtGui>
#include <QMapIterator>
#include <QtXml>

#include "pile.h"
#include "ui_main.h"

/*! \class Memento
* \brief Permet le stockage de copies de la pile et de la QMap atome.
*
*  Possède deux attributs des mêmes types permettant cette sauvegarde.
*
*  Utilisé en particulier pour les opérateurs UNDO et REDO.
*/
class Memento{
private:
    Pile pileMem;
    QMap<QString,Literal*> atomeMem;
public:
    /*!
    *  \brief Constructeur.
    *
    *  \param pileToSave Référence sur Pile à copier dans pileMem, atomeToSave Référence sur QMap<QString,Literal*> à copier dans atomeMem.
    */
    Memento(Pile& pileToSave, QMap<QString,Literal*>& atomeToSave){ pileMem = pileToSave; atomeMem = atomeToSave;}
    /*!
    *  \brief Accesseur de l'attribut pileMem.
    *
    *  \return référence sur Pile pointant sur la pileMem.
    */
    Pile& getSavedPile(){ return pileMem; }
    /*!
    *  \brief Accesseur de l'attribut atomeMem.
    *
    *  \return référence sur QMap<QString,Literal*> pointant sur l'atomeMem.
    */
    QMap<QString,Literal*>& getSavedAtome(){ return atomeMem; }
};

/*! \class QComputer
* \brief Représente la calculatrice.
*
* Possède les différents éléments nécessaires à son fonctionnement :
* - la pile
* - le controleur
* - la QStringList cmd
* - la QMap atome
* - le QSignalMapper
* - l'UI
*
*   cmd représente l'ensemble des commandes à exécuter après parsage (vie cmdAnalyser) de la ligne de commande m_ui->commande.
*   atome permet de stocker l'ensemble des atomes dans la calculatrice.
*
* Elle possède donc les éléments de stockage mais aussi l'interface et réalise les connexions entre les signaux et les slots.
*
* Instance unique, singleton
* Hérite de QMainWindow
*/
class QComputer : public QMainWindow {
    Q_OBJECT
    Pile* pile;
    Controleur* controleur;
    QStringList* cmd;
    QMap<QString,Literal*>* atome;
    QSignalMapper* signalMapper;
    static QComputer* QCinstance;
    Ui::QComputer* m_ui;
    /*!
    * \brief Constructeur.
    *
    * \param parent Pointeur sur QWidget pour initialiser ou construire une QMainWindow.
    */
    explicit QComputer(QWidget *parent = 0);
    /*!
    * \brief Destructeur.
    */
    virtual ~QComputer();
public:
    /*!
    *  \brief Accesseur de l'instance.
    *
    *  \return référence sur QComputer pointant sur l'instance unique.
    */
    static QComputer& getInstance(){
        if (QCinstance==0)
            QCinstance = new QComputer();
        return *QCinstance;
    }
    /*!
    *  \brief Destructeur de l'instance.
    */
    static void freeInstance(){
        if (QCinstance !=0)
            delete QCinstance;
        QCinstance=0;
    }
    /*!
     *  \brief Crée un Memento contenant une copie de pile et d'atome.
     *
     *  \return Memento* correspondant au nouveau Memento créé.
     */
    Memento* saveToMemento()
    {
        return new Memento(*pile, *atome);
    }
    /*!
     *  \brief Recharge les contenus de pile et atome sauvegardés dans un Memento.
     *
     *  \param m Memento* correspondant au Memento contenant les pile et atome à charger.
     */
    void restoreFromMemento(Memento* m)
    {
        *pile = m->getSavedPile();
        *atome = m->getSavedAtome();
    }
    /*!
     *  \brief Accesseur de l'attribut pile.
     *
     *  \return Pile& correspondant à l'attribut pile.
     */
    Pile& getPile() const{ return *pile; }
    /*!
     *  \brief Accesseur de l'attribut cmd.
     *
     *  \return QStringList& correspondant à l'attribut cmd.
     */
    QStringList& getCmd() const{ return *cmd; }
    /*!
     *  \brief Accesseur de l'attribut atome.
     *
     *  \return QMap<QString,Literal*>& correspondant à l'attribut atome.
     */
    QMap<QString,Literal*>& getAtome() const{ return *atome; }
    /*!
     *  \brief Evenement de fermeture de la fenêtre.
     *
     *  \param event QCloseEvent *.
     */
    void closeEvent(QCloseEvent *event);
    /*!
     *  \brief Evenement d'ouverture de la fenêtre.
     *
     *  \param event QCloseEvent *.
     */
    void showEvent(QShowEvent *event);
public slots:
    /*!
     *  \brief Rafraichit l'intégralité de l'ui.
     */
    void refresh();
    /*!
     *  \brief Exécute l'ensemble des commandes présentes dans la QStringList cmd.
     */
    void getNextCommande();
    /*!
     *  \brief Charge la valeur d'un bouton sur la pile.
     *
     *  \param QString& correspond au QString associé au bouton.
     */
    void buttonToString(const QString&);
    /*!
     *  \brief Permet la suppression d'un caractère via la touche backspace sur la ligne de commande (m_ui->commande).
     */
    void suppr();
    /*!
     *  \brief Analyse la ligne de commande m_ui->commande.
     *
     * Parse grâce à des regex la ligne de commande m_ui->commande afin de stocker dans la QStringList cmd l'ensemble des opérandes à exécuter.
     */
    void cmdAnalyser();
    /*!
     *  \brief Permet de modifier le nombre de lignes à afficher dans le widget vuePile.
     */
    void modifierNbPile(int);
    /*!
     *  \brief Permet d'afficher ou de cacher le clavier étendu.
     */
    void afficherClavier();
    /*!
     *  \brief Permet d'enregistrer les modifications apportées dans la fenêtre de modification des atomes (vueVar, onglet variables).
     */
    void modifierAtome();
    /*!
     *  \brief Permet de charger un fichier de sauvegarde XML.
     */
    void loadSave();
    /*!
     *  \brief Permet de sauvegarder le contexte de la calculatrice dans un fichier XML.
     */
    void saveCalculator();
    /*!
     *  \brief Permet d'enregistrer les modifications apportées dans la fenêtre de modification des programmes (vueProg, onglet programme).
     */
    void modifierProg();
    /*!
     *  \brief Dans l'onglet programme, remplit la QComboBox uniquement avec les identifiants atome contenant des programmes. Une fois le programme sélectionné, place son contenu dans le QTextEdit.
     *
     *  \param QString.
     */
    void selectionProg(QString);
    /*!
     *  \brief Affiche ou cache les résultats du parseur cmdAnalyser dans un QTableWidget à gauche de la pile.
     *
     *  \param event bool.
     */
    void afficherCmd(bool);
    /*!
     *  \brief Permet de charger le fichier de test XML.
     */
    void loadSaveTest();
};

/*! \class Gardien
* \brief Permet la gestion d'un ensemble de Memento.
*
*  Possède un vector de Memento* permettant le stockage de plusieurs Memento.
*  Ajoute un Memento si des modification de la pile ou de la QMap ont été effectuées.
*  Renvoie un Memento selon les besoin de l'application.
*
* Possède également des indices permettant la navigation parmi les Mementos.
*
* Singleton
*/
class Gardien {
private:
    std::vector<Memento*> savedStates;
    int nbcommand;
    int nbundo;
    int nbredo;
    int indiceretour;
    static Gardien* Ginstance;
    /*!
    * \brief Constructeur.
    */
    Gardien() : nbcommand(0),nbundo(0),nbredo(0),indiceretour(0){}
public:
    /*!
    *  \brief Accesseur de l'instance.
    *
    *  \return référence sur Gardien pointant sur l'instance unique.
    */
    static Gardien& getInstance(){
        if (Ginstance==0)
            Ginstance = new Gardien();
        return *Ginstance;
    }
    /*!
    *  \brief Destructeur de l'instance.
    */
    static void freeInstance(){
        if (Ginstance !=0)
            delete Ginstance;
        Ginstance=0;
    }
    /*!
    *  \brief Remet à 0 le nombre d'undo.
    */
    void razNbUndo() {nbundo=0;}
    /*!
     *  \brief Accesseur de l'attribut nbundo.
     *
     *  \return int correspondant à l'attribut nbundo.
     */
    int getNbUndo() const{return nbundo;}
    /*!
    *  \brief incrémente le nombre d'undo.
    */
    void incNbUndo() {nbundo++;}
    /*!
    *  \brief décrémente le nombre d'undo.
    */
    void decNbUndo() {nbundo--;}
    /*!
     *  \brief Accesseur de l'attribut indret.
     *
     *  \return int correspondant à l'attribut indret.
     */
    int getIndRet() const{return indiceretour;}
    /*!
    *  \brief incrémente le nombre d'undo.
    */
    void incIndRet() {indiceretour++;}
    /*!
    *  \brief décrémente le nombre d'undo.
    */
    void decIndRet() {indiceretour--;}
    /*!
     *  \brief Accesseur en écriture de l'attribut indret.
     *
     *  \param indice int correspondant à la valeur à affecter.
     */
    void setIndRet(int indice) {indiceretour=indice;}
    /*!
     *  \brief Accesseur de l'attribut nbredo.
     *
     *  \return int correspondant à l'attribut nbredo.
     */
    int getNbRedo() const{return nbredo;}
    /*!
    *  \brief incrémente le nombre d'undo.
    */
    void incNbRedo() {nbredo++;}
    /*!
    *  \brief décrémente le nombre d'undo.
    */
    void decNbRedo() {nbredo--;}
    /*!
     *  \brief Accesseur en écriture de l'attribut nbredo.
     *
     *  \param indice int correspondant à la valeur à affecter.
     */
    void setNbRedo(int indice) {nbredo=indice;}
    /*!
     *  \brief Accesseur de l'attribut savedStates.
     *
     *  \return std::vector<Memento*> correspondant à l'attribut savedStates.
     */
    std::vector<Memento*> getSavedStates() const{return savedStates;}
    /*!
     *  \brief Ajoute un Memento* dans l'attribut savedStates.
     *
     *  \param m pointeur sur Memento pointant sur le Memento à ajouter.
     */
    void addMemento(Memento* m) { savedStates.push_back(m); nbcommand++;}
    /*!
     *  \brief Retourne un pointeur sur Memento.
     *
     *  \param indice int permettant le calcul de l'indice du Memento* dans le vecteur.
     *  \return Memento* correspondant au pointeur stocké dans savedStates renvoyé.
     */
    Memento* getMemento(int indice) const { return savedStates[nbcommand-2*indice];}
    /*!
     *  \brief Retourne le pointeur sur Memento correspond à l'état précédent.
     *
     *  \return Memento* correspondant au pointeur stocké dans savedStates renvoyé.
     */
    Memento* getMementoPrec() const{return savedStates[nbcommand-1];}
};


#endif // QCOMPUTER_H
