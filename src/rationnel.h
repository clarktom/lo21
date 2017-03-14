#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "literal.h"

/*! \class Rationnel
 * \brief Classe representant une littérale rationnel.
 *
 *  Hérite de LiteralNum.
 */
class Rationnel : public LiteralNum {
    int num;
    int den;
public:
    /*!
    * \brief Constructeur.
    *
    *  \param n int pour initialiser le numérateur et d int pour initialiser le dénominateur.
    */
    Rationnel(int n = 0, int d = 0) : num(n), den(d) {}
    /*!
    *  \brief Accesseur de l'attribut num.
    *
    *  \return int correspondant à l'attribut num.
    */
    int getNum() const { return num; }
    /*!
    *  \brief Accesseur de l'attribut den.
    *
    *  \return int correspondant à l'attribut den.
    */
    int getDen() const { return den; }
    /*!
    *  \brief Accesseur en écriture de l'attribut num.
    *
    *  \param n int pour affecter l'attribut num.
    */
    void setNum(int n) { num = n; }
    /*!
    *  \brief Accesseur en écriture de l'attribut den.
    *
    *  \param d int pour affecter l'attribut den.
    */
    void setDen(int d) { den = d; }
    /*!
    *  \brief Convertit les valeurs des attributs num et den dans un QString.
    *
    *  \return QString correspondant aux attributs convertis.
    */
    QString toString() const { QString stream = QString::number(num) + "/" +  QString::number(den); return stream; }
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
    *  \brief Opérateur NEG.
    *
    *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
    *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
    */
    Literal* NEG() const;
    /*!
    *  \brief Opérateur NUM.
    *
    *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
    *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
    */
    Literal* NUM() const;
    /*!
    *  \brief Opérateur DEN.
    *
    *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
    *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
    */
    Literal* DEN() const;
    /*!
    *  \brief Réduit le Rationnel si cela est possible.
    *
    *  \return Pointeur sur Literal pointant sur le résultat de la réduction.
    */
    Literal* reduce();
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
    *  \brief Clone l'objet Rationnel en un second objet.
    *
    *  \return Pointeur sur Literal pointant sur le nouveau Rationnel.
    */
    Literal* clone() const { return new Rationnel(num, den); }
};

/*! \class RationnelFactory
 * \brief Classe permettant de générer un Rationnel via le design pattern Factory.
 *
 *  Hérite de LiteralFactory.
 */
class RationnelFactory : public LiteralFactory {
public:
        /*!
     * \brief Constructeur.
     *
     * Appelle le constructeur de LiteralFactory
     */
    RationnelFactory() : LiteralFactory() {}
        /*!
     * \brief Fournit un pointeur sur Literal en construisant le bon type d'objet grâce au polymorphisme. Ici, de type Rationnel.
     *
     *  \return Pointeur sur Literal pointant sur l'objet construit.
     */
    Literal* getLiteral(const QString& s) {
        string c = s.toLocal8Bit().constData();
        regex rationnel("([1-9][0-9]*)\\/([1-9][0-9]*)");
        match_results<std::string::const_iterator> res;
        regex_match(c, res, rationnel);
        int n(atoi(((string)res[1]).c_str()));
        int d(atoi(((string)res[2]).c_str()));
        Rationnel tmp(n, d);
        return tmp.reduce();;
    }
};

unsigned GCD(unsigned u, unsigned v);

#endif
