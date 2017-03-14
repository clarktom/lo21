#ifndef REEL_H
#define REEL_H

#include "literal.h"

/*! \class Reel
 * \brief Classe representant une littérale reel.
 *
 *  Hérite de LiteralNum.
 */
class Reel : public LiteralNum {
    float val;
public:
     /*!
     * \brief Constructeur.
     *
     * \param n float, valeur de l'attribut val.
     */
    Reel(float n = 0.0) : val(n) {}
        /*!
     *  \brief Accesseur de l'attribut val.
     *
     *  \return float correspondant à l'attribut val.
     */
    float getVal() const { return val; }
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
     *  \brief Opérateur NEG.
     *
     *  \param other Référence const sur Literal avec laquelle exécuter l'operator.
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* NEG() const;
        /*!
     *  \brief Arrondit le Reel si possible.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'arrondi.
     */
    Literal* round();
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
     *  \brief Clone l'objet Reel en un second objet.
     *
     *  \return Pointeur sur Literal pointant sur le nouveau Reel.
     */
    Literal* clone() const { return new Reel(val); }
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
};

/*! \class ReelFactory
 * \brief Classe permettant de générer un Reel via le design pattern Factory.
 *
 *  Hérite de LiteralFactory.
 */
class ReelFactory : public LiteralFactory {
public:
    /*!
    * \brief Constructeur.
    *
    * Appelle le constructeur de LiteralFactory
    */
    ReelFactory() : LiteralFactory() {}
    /*!
    * \brief Fournit un pointeur sur Literal en construisant le bon type d'objet grâce au polymorphisme. Ici, de type Reel.
    *
    *  \return Pointeur sur Literal pointant sur l'objet construit.
    */
    Literal* getLiteral(const QString& s) {
        string c = s.toLocal8Bit().constData();
        regex reel("([0-9]*)?\\.([0-9]*)?");
        match_results<std::string::const_iterator> res;
        regex_match(c, res, reel);
        Reel tmp(atof(((string)res[0]).c_str()));
        return tmp.round();
    }
};

#endif
