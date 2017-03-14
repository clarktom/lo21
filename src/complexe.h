#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "literal.h"

/*! \class Complexe
 * \brief Classe représentant une littérale complexe.
 *
 * Hérite de LiteralNum.
 * Composé de deux pointeur de litterale numerique.
 */
class Complexe : public LiteralNum {
    LiteralNum* re;
    LiteralNum* im;
public:
     /*!
     *  \brief Constructeur.
     *
     *  \param r Pointeur sur Literal pour la partie réelle et i Pointeur sur Literal pour la partie imaginaire.
     */
    Complexe(Literal* r, Literal* i) : re(dynamic_cast<LiteralNum*>(r)), im(dynamic_cast<LiteralNum*>(i)) {}
    /*!
     *  \brief Accesseur de l'attribut re.
     *
     *  \return Pointeur sur LiteralNum correspondant à l'attribut re.
     */
    LiteralNum* getRe() const { return re; }
    /*!
     *  \brief Accesseur de l'attribut im.
     *
     *  \return Pointeur sur LiteralNum correspondant à l'attribut im.
     */
    LiteralNum* getIm() const { return im; }
        /*!
     *  \brief Convertit les valeurs des deux attributs re et im en QString.
     *
     *  \return QString correspondant aux attributs convertis.
     */
    QString toString() const { QString stream = (*re).toString() + "$" + (*im).toString(); return stream; }
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
     *  \brief Opérateur RE.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* RE() const;
        /*!
     *  \brief Opérateur IM.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* IM() const;
        /*!
     *  \brief Opérateur NEG.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de l'opération.
     */
    Literal* NEG() const;
        /*!
     *  \brief Simplifie le Complexe si cela est possible.
     *
     *  Si la partie imaginaire est nulle, alors le complexe est transformé en un objet de même type que celui de la partie réelle.
     *
     *  \return Pointeur sur Literal pointant sur le résultat de la simplification.
     */
    Literal* simplify();
     /*!
     *  \brief Clone l'objet Complexe en un second objet.
     *
     *  \return Pointeur sur Literal pointant sur le nouvel objet.
     */
    Literal* clone() const { return new Complexe(re->clone(), im->clone()); }
};

#endif
