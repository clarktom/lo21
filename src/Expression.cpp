#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"

#include <QStringList>
#include <QStack>

Literal* Expression::operator+(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        return new Expression("(" + getExpression() + ")+(" + tmp.toString() + ")");
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        return new Expression("(" + getExpression() + ")+(" + tmp.toString() + ")");
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        return new Expression("(" + getExpression() + ")+(" + tmp.toString() + ")");
        break;
    }
    case complexe:
    {
        const Complexe& tmp = dynamic_cast<const Complexe&>(other);
        return new Expression("(" + getExpression() + ")+(" + tmp.toString() + ")");
        break;
    }
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + getExpression() + ")+(" + tmp.getExpression() + ")");
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}

Literal* Expression::operator-(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        return new Expression("(" + getExpression() + ")-(" + tmp.toString() + ")");
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        return new Expression("(" + getExpression() + ")-(" + tmp.toString() + ")");
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        return new Expression("(" + getExpression() + ")-(" + tmp.toString() + ")");
        break;
    }
    case complexe:
    {
        const Complexe& tmp = dynamic_cast<const Complexe&>(other);
        return new Expression("(" + getExpression() + ")-(" + tmp.toString() + ")");
        break;
    }
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + getExpression() + ")-(" + tmp.getExpression() + ")");
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}

Literal* Expression::operator*(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        return new Expression("(" + getExpression() + ")*(" + tmp.toString() + ")");
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        return new Expression("(" + getExpression() + ")*(" + tmp.toString() + ")");
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        return new Expression("(" + getExpression() + ")*(" + tmp.toString() + ")");
        break;
    }
    case complexe:
    {
        const Complexe& tmp = dynamic_cast<const Complexe&>(other);
        return new Expression("(" + getExpression() + ")*(" + tmp.toString() + ")");
        break;
    }
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + getExpression() + ")*(" + tmp.getExpression() + ")");
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}

Literal* Expression::operator/(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        return new Expression("(" + getExpression() + ")/(" + tmp.toString() + ")");
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        return new Expression("(" + getExpression() + ")/(" + tmp.toString() + ")");
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        return new Expression("(" + getExpression() + ")/(" + tmp.toString() + ")");
        break;
    }
    case complexe:
    {
        const Complexe& tmp = dynamic_cast<const Complexe&>(other);
        return new Expression("(" + getExpression() + ")/(" + tmp.toString() + ")");
        break;
    }
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + getExpression() + ")/(" + tmp.getExpression() + ")");
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}

Literal* Expression::$(const Literal& other) const {
    literal_type type = literalType(other);
    switch (type)
    {
    case entier:
    {
        const Entier& tmp = dynamic_cast<const Entier&>(other);
        return new Expression("(" + getExpression() + ")$(" + tmp.toString() + ")");
        break;
    }
    case reel:
    {
        const Reel& tmp = dynamic_cast<const Reel&>(other);
        return new Expression("(" + getExpression() + ")$(" + tmp.toString() + ")");
        break;
    }
    case rationnel:
    {
        const Rationnel& tmp = dynamic_cast<const Rationnel&>(other);
        return new Expression("(" + getExpression() + ")$(" + tmp.toString() + ")");
        break;
    }
    case complexe:
    {
        const Complexe& tmp = dynamic_cast<const Complexe&>(other);
        return new Expression("(" + getExpression() + ")$(" + tmp.toString() + ")");
        break;
    }
    case expression:
    {
        const Expression& tmp = dynamic_cast<const Expression&>(other);
        return new Expression("(" + getExpression() + ")$(" + tmp.getExpression() + ")");
        break;
    }
    default:
    {
        throw LiteralException("Erreur de type");
        break;
    }
    }
}



