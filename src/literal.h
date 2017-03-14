#ifndef LITTERAL_H
#define LITTERAL_H

#include <QString>
#include <QMap>
#include <regex>

using namespace std;

enum literal_type {
    entier,
    reel,
    rationnel,
    complexe,
    programme,
    expression,
    erreur
};

/*! \class LiteralException
 * \brief Classe exception concernant les littérales.
 */
class LiteralException {
    QString info;
public:
    /*!
     *  \brief Constructeur.
     *
     *  \param str Référence const sur QString pour initialiser l'attribut info.
     */
    LiteralException(const QString& str) : info(str) {}
    /*!
     *  \brief Accesseur de l'attribut info.
     *
     *  \return QString correspondant à l'attribut info.
     */
    QString getInfo() const { return info; }
};

/*! \class Literal
 * \brief Classe représentant une Literal.
 *
 *  La classe gère une Literal. C'est la classe mère des littérales.
 *  Literal est une classe abstraite car elle possède des méthodes virtuelles pures, cela oblige les classe fille à définir le comportement des méthodes concernées.
 *  Seules les méthodes indispensables à l'ensemble des classes filles sont déclarées en virtuelle pure.
 */
class Literal {
public:
    /*!
     *  \brief Convertit en QString l'attribut de l'objet.
     *
     * Virtuelle pure car l'attribut à retourner dépend de la classe.
     *  \return QString correspondant à l'attribut.
     */
    virtual QString toString() const = 0;
    /*!
     *  \brief Surcharge de l'opérateur +, virtuelle pure.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator+(const Literal& other) const = 0;
    /*!
     *  \brief Surcharge de l'opérateur -, virtuelle pure.
     *
     * Utilisation du NEG puis de operator+.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator-(const Literal& other) const;
    /*!
     *  \brief Surcharge de l'opérateur *, virtuelle pure.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator*(const Literal& other) const = 0;
    /*!
     *  \brief Surcharge de l'opérateur /, virtuelle pure.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator/(const Literal& other) const = 0;
    /*!
     *  \brief Opérateur DIV.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* DIV(const Literal& other) const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Opérateur MOD.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* MOD(const Literal& other) const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Opérateur NEG, virtuelle pure.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* NEG() const = 0;
    /*!
     *  \brief Opérateur NUM.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* NUM() const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Opérateur DEN.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* DEN() const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Surcharge de l'opérateur $.
     *
     * Sert à créer un complexe.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* $(const Literal& other) const{ throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Opérateur RE.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* RE() const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Opérateur IM.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* IM() const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Clone l'objet Literal en un second objet, virtuelle pure.
     *
     *  \return Pointeur sur Literal pointant sur la nouvelle Literal.
     */
    virtual Literal* clone() const = 0;
    /*!
     *  \brief Surcharge de l'opérateur ==.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator==(const Literal& other) const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Surcharge de l'opérateur !=.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator!=(const Literal& other) const;
    /*!
     *  \brief Surcharge de l'opérateur <=.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator<=(const Literal& other) const;
    /*!
     *  \brief Surcharge de l'opérateur >=.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator>=(const Literal& other) const;
    /*!
     *  \brief Surcharge de l'opérateur <.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator<(const Literal& other) const;
    /*!
     *  \brief Surcharge de l'opérateur >.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator>(const Literal& other) const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Surcharge de l'opérateur !.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator!() const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Surcharge de l'opérateur &&.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator&&(const Literal& other) const { throw LiteralException("Type non supporte"); }
    /*!
     *  \brief Surcharge de l'opérateur ||.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    virtual Literal* operator||(const Literal& other) const { throw LiteralException("Type non supporte"); }
};

/*! \class LiteralFactory
 * \brief Classe mère des classes littérales utilisées dans la Factory.
 *
 *  Classe principale du design pattern Factory.
 *  Elle possède un map static qui contiendra l'ensemble des factories.
 */
class LiteralFactory {
public:
    /*!
     * \brief Constructeur.
     */
    LiteralFactory() {}
    /*!
     * \brief Constructeur.
     */
    virtual ~LiteralFactory() {}
        /*!
     * \brief Fournit un pointeur sur Literal en construisant le bon type d'objet grâce au polymorphisme.
     *
     *  \return Pointeur sur Literal pointant sur l'objet construit.
     */
    virtual Literal* getLiteral(const QString&) = 0;
        /*!
     * \brief Permet de récupérer l'instance de la map Factories utilisée par la classe Controleur pour créer les différents objets.
     */
    static map<QString, LiteralFactory*> getFactoriesMap();
};

/*! \class LiteralNum
 * \brief Classe representant une litterale numérique.
 *
 *  Un partie des opérandes héritent de cette classe.
 */
class LiteralNum : public Literal {

};

/*!
 * \fn LiteralTypeString
 * \brief Renvoie un QString correspondant au type d'Literal passée en paramètre.
 *
 * \param v Référence const sur Literal.
 * \return QString correspondant au type.
 */
QString literalTypeString(const Literal& v);
/*!
 * \fn LiteralType
 * \brief Renvoie un Literal_type correspondant au type d'Literal passée en paramètre.
 *
 * \param other Référence const sur Literal.
 * \return Literal_type correspondant au type.
 */
literal_type literalType(const Literal& other);
/*!
 * \fn regexType
 * \brief Renvoie un QString correspondant au type du QString passé en paramètre.
 *
 * \param c Référence const sur QString.
 * \return QString correspondant au type.
 */
QString regexType(const QString& c);
/*!
 * \fn regexTypeSave
 * \brief Renvoie un pointeur sur Literal correspondant à une Literal du type du QString passé en paramètre.
 *
 * Méthode utilisée dans la méthode de lecture d'un fichier XML.
 * La méthode peut gérer les éventuels complexes enregistrés.
 *
 * \param c Référence const sur QString.
 * \return Literal* correspondant à une Literal du même type.
 */
Literal* regexTypeSave(const QString& s);

#endif



