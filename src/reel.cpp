#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"

Literal* Reel::operator+(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		return other + *this;
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Reel res(val + tmp.val);
		return res.round();
		break;
	}
	case rationnel:
	{
		return other + *this;
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

Literal* Reel::operator*(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		return other * *this;
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Reel res(val * tmp.val);
		return res.round();
		break;
	}
	case rationnel:
	{
		return other * *this;
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

Literal* Reel::operator/(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		Reel res(val / tmp.getVal());
		return res.round();
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Reel res(val / tmp.val);
		return res.round();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
		Reel res(val / ((float)tmp.getNum() / tmp.getDen()));
		return res.round();
		break;
	}
	case complexe:
	{
		const Complexe& tmp = dynamic_cast<const Complexe&>(other);
		Complexe res(*this / *(tmp.getRe()), tmp.getIm());
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

Literal* Reel::NEG() const {
	return new Reel(-val);
}

Literal* Reel::round() {
	if (roundf(val) == val) {
		return new Entier(val);
	}
	return new Reel(val);
}

Literal* Reel::$(const Literal& other) const {
	Reel* op1 = new Reel(val);
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

Literal* Reel::operator==(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        return other == *this;
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        if (val == tmp.getVal()) 
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        if (val == ((float)tmp.getNum()/tmp.getDen()))
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

Literal* Reel::operator>(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        if (val > tmp.getVal())
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        if (val > tmp.getVal()) 
            return new Entier(1);
        else return new Entier(0);
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        if (val > ((float)tmp.getNum()/tmp.getDen()))
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
