#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QRegExp>

#include "literal.h"

/*! \class Expression
 * \brief Classe representant une littérale expression.
 *
 *  Hérite de Literal.
 */
class Expression : public Literal {
    QString exp;
public:
    /*!
     * \brief Constructeur.
     *
     * \param e QString, valeur de l'attribut exp de l'objet Expression.
     */
    Expression(QString e="") : exp(e.replace(QRegExp("\\s+"),"")) {}
    /*!
     *  \brief Accesseur de l'attribut exp.
     *
     *  \return QString correspondant à l'attribut exp.
     */
    QString getExpression() const { return exp; }
        /*!
     *  \brief Convertit la valeur de l'attribut exp dans un QString entouré de " ' ".
     *
     *  \return QString correspondant à l'attribut exp converti.
     */
    QString toString() const { QString tmp = "'" + exp + "'"; return tmp; }
        /*!
     *  \brief Surcharge de l'opérateur +.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator+(const Literal& other) const;
        /*!
     *  \brief Surcharge de l'opérateur -.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator-(const Literal& other) const;
        /*!
     *  \brief Surcharge de l'opérateur *.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator*(const Literal& other) const;
        /*!
     *  \brief Surcharge de l'opérateur /.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator/(const Literal& other) const;
        /*!
     *  \brief Opérateur $.
     *
     * Sert à créer un complexe.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* $(const Literal& other) const;
        /*!
     *  \brief Clone l'objet Expression en un second objet.
     *
     *  \return Pointeur sur Literal pointant sur la nouvelle Expression.
     */
    Literal* clone() const { return new Expression(exp); }
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

/*! \class ExpressionFactory
 * \brief Classe permettant de générer une Expression via le design pattern Factory.
 *
 *  Hérite de LiteralFactory.
 */
class ExpressionFactory : public LiteralFactory {
public:
    /*!
     * \brief Constructeur.
     *
     * Appelle le constructeur de LiteralFactory
     */
    ExpressionFactory() : LiteralFactory() {}
    /*!
     * \brief Fournit un pointeur sur Literal en construisant le bon type d'objet grâce au polymorphisme. Ici, de type Expression.
     *
     *  \return Pointeur sur Literal pointant sur l'objet construit.
     */
    Literal* getLiteral(const QString& s) {
        string c = s.toLocal8Bit().constData();
        regex expression("^'(.*)'$");
        match_results<std::string::const_iterator> res;
        regex_match(c, res, expression);
        return new Expression(QString::fromStdString((string)res[1]));
    }
};


#endif // EXPRESSION_H
