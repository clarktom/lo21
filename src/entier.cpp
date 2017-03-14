#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"

Literal* Entier::operator+(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		return new Entier(val + tmp.val);
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Reel res(val + tmp.getVal());
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

Literal* Entier::operator*(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		return new Entier(val * tmp.val);
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Reel res(val * tmp.getVal());
		return res.round();
		break;
	}
	case rationnel:
	{
		return other * *this;
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

Literal* Entier::operator/(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		if (val%tmp.getVal()==0) {
			return new Entier(val / tmp.getVal());
		}
		else {
			Rationnel res(val, tmp.val);
			return res.reduce();
		}
		break;
	}
	case reel:
	{
		const Reel& tmp = dynamic_cast<const Reel&>(other);
		Reel res((float)val / tmp.getVal());
		return res.round();
		break;
	}
	case rationnel:
	{
		const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
		Rationnel res(tmp.getNum(), tmp.getDen()*val);
		return res.reduce();
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

Literal* Entier::DIV(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		return new Entier(val / tmp.val);
		break;
	}
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
}

Literal* Entier::MOD(const Literal& other) const {
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		return new Entier(val % tmp.val);
		break;
	}
	default:
	{
        throw LiteralException("Erreur de type");
		break;
	}
	}
}

Literal* Entier::NEG() const {
	return new Entier(-val);
}

Literal* Entier::NUM() const { return new Entier(*this); }
Literal* Entier::DEN() const { return new Entier(1); }

Literal* Entier::$(const Literal& other) const {
	Entier* op1 = new Entier(val);
    literal_type type = literalType(other);
	switch (type)
	{
	case entier:
	{
		const Entier& tmp = dynamic_cast<const Entier&>(other);
		Entier* op2 = new Entier(tmp.val);
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

Literal* Entier::operator==(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        if (val==tmp.getVal()) {
            return new Entier(1);
        }
        else {
            return new Entier(0);
        }
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        if (val==tmp.getVal()) {
            return new Entier(1);
        }
        else {
            return new Entier(0);
        }
        break;
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        Rationnel res(tmp.getNum(), tmp.getDen()*val);
        if (val==((float)tmp.getNum()/tmp.getDen())) {
            return new Entier(1);
        }
        else {
            return new Entier(0);
        }
        break;
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}

Literal* Entier::operator>(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        if (val>tmp.getVal()) {
            return new Entier(1);
        }
        else {
            return new Entier(0);
        }
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        if (val>tmp.getVal()) {
            return new Entier(1);
        }
        else {
            return new Entier(0);
        }
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        if (val>((float)tmp.getNum()/tmp.getDen())) {
            return new Entier(1);
        }
        else {
            return new Entier(0);
        }
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}

Literal* Entier::operator!() const {
    if(val==0) return new Entier(1);
    else return new Entier(0);
}

Literal* Entier::operator&&(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        if (val==1 && tmp.getVal()==1) {
            return new Entier(1);
        }
        else {
            return new Entier(0);
        }
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}
Literal* Entier::operator||(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        if (val==0 && tmp.getVal()==0) {
            return new Entier(0);
        }
        else {
            return new Entier(1);
        }
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}

