#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"

Literal* Complexe::operator+(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		Complexe res((*re) + tmp, im);
		return res.simplify();
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Complexe res((*re) + tmp, im);
		return res.simplify();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
		Complexe res((*re) + tmp, im);
		return res.simplify();
		break;
	}
	case complexe:
	{
		const Complexe& tmp = dynamic_cast<const Complexe&>(other);
		Complexe res((*re) + *(tmp.re), *im + *(tmp.im));
		return res.simplify();
        break;
	}
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + toString() + ")+(" + tmp.getExpression() + ")");
        break;
    }
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
}

Literal* Complexe::operator*(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		Complexe res((*re) * tmp, im);
		return res.simplify();
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Complexe res((*re) * tmp, im);
		return res.simplify();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
		Complexe res((*re) * tmp, im);
		return res.simplify();
		break;
	}
	case complexe:
	{
		const Complexe& tmp = dynamic_cast<const Complexe&>(other);
        /*Literal* x1x2 = (*re) * *(tmp.re);
        Literal* y1y2 = (*im) * *(tmp.im);
		Complexe res(*x1x2 - *y1y2, *im + *(tmp.im));*/
		Complexe res(*((*re) * *(tmp.re)) - *(*im * *(tmp.im)), *(*re * *(tmp.im)) + *(*im * *(tmp.re))); //z1 * z2 = (x1 * x2) - (y1 * y2) + i(x1 * y2 + y1 * x2)
		return res.simplify();
        break;
	}
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + toString() + ")*(" + tmp.getExpression() + ")");
        break;
    }
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
}

Literal* Complexe::operator/(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		Complexe res((*re) / tmp, im);
		return res.simplify();
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Complexe res((*re) / tmp, im);
		return res.simplify();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
		Complexe res((*re) / tmp, im);
		return res.simplify();
		break;
	}
	case complexe:
	{
		const Complexe& tmp = dynamic_cast<const Complexe&>(other);
		//Complexe conj = tmp.CONJ();
		Complexe res(*(*((*re) * *(tmp.re)) + *(*im * *(tmp.im))) / *(*(*(tmp.re) * *(tmp.re)) + *(*(tmp.im) * *(tmp.im))), *(*((*im) * *(tmp.re)) - *(*re * *(tmp.im))) / *(*(*(tmp.re) * *(tmp.re)) + *(*(tmp.im) * *(tmp.im))));
		return res.simplify();
        break;
	}
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + toString() + ")/(" + tmp.getExpression() + ")");
        break;
    }
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
}

Literal* Complexe::RE() const {
    literal_type type = literalType(*re);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(*re);
		return new Entier(tmp.getVal());
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(*re);
		Reel res(tmp.getVal());
		return res.round();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(*re);
		Rationnel res(tmp.getNum(), tmp.getDen());
		return res.reduce();
		break;
	}
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
}

Literal* Complexe::IM() const {
    literal_type type = literalType(*im);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(*im);
		return new Entier(tmp.getVal());
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(*im);
		Reel res(tmp.getVal());
		return res.round();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(*im);
		Rationnel res(tmp.getNum(), tmp.getDen());
		return res.reduce();
		break;
	}
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
}

Literal* Complexe::NEG() const {
	return new Complexe((*re).NEG(), (*im).NEG());
}

/*Complexe Complexe::CONJ() const {
	return Complexe(re, (*im).NEG());
}*/

Literal* Complexe::simplify() {
	float pIm = 0;
    literal_type type = literalType(*im);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(*im);
		pIm = tmp.getVal();
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(*im);
		pIm = tmp.getVal();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(*im);
		pIm = (float)tmp.getNum() / tmp.getDen();;
		break;
	}
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
	if (pIm == 0) {
		return RE();
	}
	return new Complexe(re, im);
}
