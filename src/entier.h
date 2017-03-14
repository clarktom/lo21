#ifndef ENTIER_H
#define ENTIER_H

#include "literal.h"

/*! \class Entier
 * \brief Classe representant une littérale entier.
 *
 *  Hérite de LiteralNum.
 */
class Entier : public LiteralNum {
private:
    int val;
public:
    /*!
     * \brief Constructeur.
     *
     * \param n int, valeur de l'objet Entier.
     */
    Entier(int n = 0) : val(n) {}
    /*!
     *  \brief Accesseur de l'attribut val.
     *
     *  \return int correspondant à l'attribut val.
     */
    int getVal() const { return val; }
    /*!
     *  \brief Convertit la valeur de l'attribut val dans un QString.
     *
     *  \return QString correspondant à l'attribut val converti.
     */
    QString toString() const { QString stream = QString::number(val); return stream; }
    /*!
     *  \brief Surcharge de l'opérateur +.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator+(const Literal& other) const;
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
     *  \brief Opérateur DIV.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* DIV(const Literal& other) const;
    /*!
     *  \brief Opérateur MOD.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* MOD(const Literal& other) const;
    /*!
     *  \brief Opérateur NEG.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* NEG() const;
    /*!
     *  \brief Opérateur NUM.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* NUM() const;
    /*!
     *  \brief Opérateur DEN.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* DEN() const;
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
     *  \brief Clone l'objet Entier en un second objet.
     *
     *  \return Pointeur sur Literal pointant sur le nouvel Entier.
     */
    Literal* clone() const { return new Entier(val); }
    /*!
     *  \brief Surcharge de l'opérateur ==.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator==(const Literal& other) const;
    /*!
     *  \brief Surcharge de l'opérateur >.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator>(const Literal& other) const;
    /*!
     *  \brief Surcharge de l'opérateur !.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator!() const;
    /*!
     *  \brief Surcharge de l'opérateur &&.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator&&(const Literal& other) const;
    /*!
     *  \brief Surcharge de l'opérateur ||.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* operator||(const Literal& other) const;
};

/*! \class EntierFactory
 * \brief Classe permettant de générer un Entier via le design pattern Factory.
 *
 *  Hérite de LiteralFactory.
 */
class EntierFactory : public LiteralFactory {
public:
    /*!
     * \brief Constructeur.
     *
     * Appelle le constructeur de LiteralFactory
     */
    EntierFactory() : LiteralFactory() {}
    /*!
     * \brief Fournit un pointeur sur Literal en construisant le bon type d'objet grâce au polymorphisme. Ici, de type Entier.
     *
     *  \return Pointeur sur Literal pointant sur l'objet construit.
     */
    Literal* getLiteral(const QString& s) {
        string c = s.toLocal8Bit().constData();
        regex entier("([0-9]+)");
        match_results<std::string::const_iterator> res;
        regex_match(c, res, entier);
        return new Entier(atoi(((string)res[1]).c_str()));
    }
};

#endif
