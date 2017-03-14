#ifndef PROGRAMME_H
#define PROGRAMME_H

#include <QRegExp>

#include "literal.h"

/*! \class Programme
 * \brief Classe representant une littérale programme.
 *
 *  Hérite de Literal.
 */
class Programme : public Literal {
    QString prog;
public:
        /*!
     * \brief Constructeur.
     *
     * \param p QString, valeur de l'attribut prog de l'objet Programme.
     */
    Programme(QString p="") : prog(p) {}
        /*!
     *  \brief Accesseur de l'attribut prog.
     *
     *  \return QString correspondant à l'attribut prog.
     */
    QString getProgramme() const { return prog; }
    /*!
     *  \brief Convertit la valeur de l'attribut prog dans un QString entouré de [].
     *
     *  \return QString correspondant à l'attribut prog converti.
     */
    QString toString() const { QString tmp = "[" + prog + "]"; return tmp; }
    /*!
     *  \brief Surcharge de l'opérateur +.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator+(const Literal& other) const { throw LiteralException("Erreur"); }
        /*!
     *  \brief Surcharge de l'opérateur -.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator-(const Literal& other) const { throw LiteralException("Erreur"); }
        /*!
     *  \brief Surcharge de l'opérateur *.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator*(const Literal& other) const { throw LiteralException("Erreur"); }
        /*!
     *  \brief Surcharge de l'opérateur /.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator/(const Literal& other) const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Opérateur $.
     *
     * Sert à créer un complexe.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* $(const Literal& other) const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Clone l'objet Programme en un second objet.
     *
     *  \return Pointeur sur Literal pointant sur le nouveau Programme.
     */
    Literal* clone() const { return new Programme(prog); }
    /*!
     *  \brief Opérateur DIV.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* DIV(const Literal& other) const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Opérateur MOD.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* MOD(const Literal& other) const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Opérateur NEG.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* NEG() const { throw LiteralException("Erreur"); }
        /*!
     *  \brief Opérateur NUM.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* NUM() const { throw LiteralException("Erreur"); }
        /*!
     *  \brief Opérateur DEN.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* DEN() const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Surcharge de l'opérateur ==.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator==(const Literal& other) const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Surcharge de l'opérateur >.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator>(const Literal& other) const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Surcharge de l'opérateur !.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator!() const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Surcharge de l'opérateur &&.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator&&(const Literal& other) const { throw LiteralException("Erreur"); }
    /*!
     *  \brief Surcharge de l'opérateur ||.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator||(const Literal& other) const { throw LiteralException("Erreur"); }
};

/*! \class ProgrammeFactory
 * \brief Classe permettant de générer un Programme via le design pattern Factory.
 *
 *  Hérite de LiteralFactory.
 */
class ProgrammeFactory : public LiteralFactory {
public:
        /*!
     * \brief Constructeur.
     *
     * Appelle le constructeur de LiteralFactory
     */
    ProgrammeFactory() : LiteralFactory() {}
        /*!
     * \brief Fournit un pointeur sur Literal en construisant le bon type d'objet grâce au polymorphisme. Ici, de type Programme.
     *
     *  \return Pointeur sur Literal pointant sur l'objet construit.
     */
    Literal* getLiteral(const QString& s) {
        string c = s.toLocal8Bit().constData();
        regex programme("^\\[(.*)\\]$");
        match_results<std::string::const_iterator> res;
        regex_match(c, res, programme);
        return new Programme(QString::fromStdString((string)res[1]));
    }
};

#endif // PROGRAMME_H
