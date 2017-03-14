#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "literal.h"

Literal* Rationnel::operator+(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
        Rationnel res(num + (tmp.getVal() * den), den);
		return res.reduce();
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
        Reel res(((float)num / den) + tmp.getVal());
		return res.round();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        Rationnel res(num*tmp.getDen() + den*tmp.getNum(), den*tmp.getDen());
		return res.reduce();
		break;
	}
	case complexe:
	{
		return other + *this;
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

Literal* Rationnel::operator*(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
        Rationnel res(num*tmp.getVal(), den);
		return res.reduce();
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
        Reel res(((float)num / den) * tmp.getVal());
		return res.round();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        Rationnel res(num*tmp.getNum(), den*tmp.getDen());
		return res.reduce();
		break;
	}
	case complexe:
	{
		return other * *this;
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

Literal* Rationnel::operator/(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
        Rationnel res(num, den*tmp.getVal());
		return res.reduce();
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
        Reel res(((float)num / den) / tmp.getVal());
		return res.round();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        Rationnel res(num*tmp.getDen(), den*tmp.getNum());
		return res.reduce();
		break;
	}
	case complexe:
	{
		const Complexe& tmp = dynamic_cast<const Complexe&>(other);
		Complexe res(*this / *(tmp.getRe()), (tmp.getIm()));
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

Literal* Rationnel::NEG() const { return new Rationnel(-num, den); }
Literal* Rationnel::NUM() const { return new Entier(num); }
Literal* Rationnel::DEN() const { return new Entier(den); }

Literal* Rationnel::reduce() {
    if (den < 0) {
        setDen(-den);
        setNum(-num);
	}
    if (num%den == 0) {
        return new Entier((int)(num / den));
	}
	else {
        int gcd = GCD(num, den);
        return new Rationnel((int)(num / gcd), (int)(den / gcd));
	}
}

unsigned GCD(unsigned u, unsigned v) {
	while (v != 0) {
		unsigned r = u % v;
		u = v;
		v = r;
	}
	return u;
}

Literal* Rationnel::$(const Literal& other) const {
    Rationnel* op1 = new Rationnel(num, den);
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		Entier* op2 = new Entier(tmp.getVal());
		return new Complexe(op1, op2);
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Reel* op2 = new Reel(tmp.getVal());
		return new Complexe(op1, op2);
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
		Rationnel* op2 = new Rationnel(tmp.getNum(), tmp.getDen());
		return new Complexe(op1, op2);
		break;
	}
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + toString() + ")$(" + tmp.getExpression() + ")");
        break;
    }
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
}

Literal* Rationnel::operator==(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        if (((float)num/den) == (float)tmp.getVal())
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        if (((float)num/den) == tmp.getVal()) 
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        if (((float)num/den) == ((float)tmp.getNum()/tmp.getDen()))
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}

Literal* Rationnel::operator>(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        if (((float)num/den) > (float)tmp.getVal())
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        if (((float)num/den) > tmp.getVal()) 
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        if (((float)num/den) > ((float)tmp.getNum()/tmp.getDen()))
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}
