#include <regex>

#include "literal.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "programme.h"

literal_type literalType(const Literal& other) {
    if (typeid(other) == typeid(Entier)) return entier;
    if (typeid(other) == typeid(Reel)) return reel;
    if (typeid(other) == typeid(Rationnel)) return rationnel;
    if (typeid(other) == typeid(Complexe)) return complexe;
    if (typeid(other) == typeid(Expression)) return expression;
    if (typeid(other) == typeid(Programme)) return programme;
    return erreur;
}

map<QString, LiteralFactory*> LiteralFactory::getFactoriesMap() {
    map<QString, LiteralFactory*> factories;
    pair<QString, LiteralFactory*> modele;
    modele.first = "Entier";
    modele.second = new EntierFactory();
    factories.insert(modele);
    modele.first = "Reel";
    modele.second = new ReelFactory();
    factories.insert(modele);
    modele.first = "Rationnel";
    modele.second = new RationnelFactory();
    factories.insert(modele);
    /*modele.first = "Complexe";
    modele.second = new Entier();
    factories.insert(modele);*/
    modele.first = "Programme";
    modele.second = new ProgrammeFactory();
    factories.insert(modele);
    modele.first = "Expression";
    modele.second = new ExpressionFactory();
    factories.insert(modele);
    return factories;
}

QString regexType(const QString& s) {
    string c = s.toLocal8Bit().constData();
    regex entier("([0-9]+)");
    regex reel("([0-9]*)?\\.([0-9]*)?");
    regex rationnel("([1-9][0-9]*)\\/([1-9][0-9]*)");
    regex expression("^'(.*)'$");
    regex programme("^\\[(.*)\\]$");
    match_results<std::string::const_iterator> res;
    if (regex_match(c, res, entier)) {
        return "Entier";
    }
    else if (regex_match(c, res, reel)) {
        return "Reel";
    }
    else if (regex_match(c, res, rationnel)) {
        return "Rationnel";
    }
    else if (regex_match(c, res, expression)) {
        return "Expression";
    }
    else if (regex_match(c, res, programme)) {
        return "Programme";
    }
    else {
        return "Inconnu";
    }
}

Literal* regexTypeSave(const QString& s) {
    string c = s.toLocal8Bit().constData();
    smatch match;
    regex entier("([0-9]+)");
    regex reel("([0-9]*)?\\.([0-9]*)?");
    regex rationnel("([1-9][0-9]*)\/([1-9][0-9]*)");
    regex complexe("(.*)\\$(.*)");
    regex expression("^'(.*)'$");
    regex programme("^\\[(.*)\\]$");
    match_results<std::string::const_iterator> res;
    if (regex_match(c, res, entier)) {
        return new Entier(atoi(((string)res[1]).c_str()));
    }
    else if (regex_match(c, res, reel)) {
        Reel res(atof(((string)res[0]).c_str()));
        return res.round();
    }
    else if (regex_match(c, res, rationnel)) {
        int n(atoi(((string)res[1]).c_str()));
        int d(atoi(((string)res[2]).c_str()));
        Rationnel res(n, d);
        return res.reduce();
    }
    else if (regex_match(c, res, expression)) {
        return new Expression(QString::fromStdString((string)res[1]));
    }
    else if (regex_match(c, res, programme)) {
        return new Programme(QString::fromStdString((string)res[1]));
    }
    else if (regex_match(c, res, complexe)) {
        string sr = (string)res[1];
        string si = (string)res[2];
        Literal* r;
        Literal* i;
        if (regex_match(sr, res, entier)) {
            r = new Entier(atoi(((string)res[1]).c_str()));
        }
        else if (regex_match(sr, res, reel)) {
            Reel res(atof(((string)res[0]).c_str()));
            r = res.round();
        }
        else if (regex_match(sr, res, rationnel)) {
            int n(atoi(((string)res[1]).c_str()));
            int d(atoi(((string)res[2]).c_str()));
            Rationnel res(n, d);
            r = res.reduce();
        }
        else {
            r = nullptr;
        }
        if (regex_match(si, res, entier)) {
            i =  new Entier(atoi(((string)res[1]).c_str()));
        }
        else if (regex_match(si, res, reel)) {
            Reel res(atof(((string)res[0]).c_str()));
            i = res.round();
        }
        else if (regex_match(si, res, rationnel)) {
            int n(atoi(((string)res[1]).c_str()));
            int d(atoi(((string)res[2]).c_str()));
            Rationnel res(n, d);
            i = res.reduce();
        }
        else {
            i = nullptr;
        }
        return new Complexe(r, i);
    }
    else {
        return nullptr;
    }
}


QString literalTypeString(const Literal& v) {
    literal_type type = literalType(v);
    switch (type)
    {
    case entier:
    {
        return "Entier";
        break;
    }
    case reel:
    {
        return "Reel";
        break;
    }
    case rationnel:
    {
        return "Rationnel";
        break;
    }
    case complexe:
    {
        return "Complexe";
        break;
    }
    case expression:
    {
        return "Expression";
        break;
    }
    case programme:
    {
        return "Programme";
        break;
    }
    default:
    {
        return "Inconnu";
        //throw LitteralException("Erreur de type");
        break;
    }
    }
}

Literal* Literal::operator-(const Literal& other) const {
    Literal* tmp = other.NEG();
    return *tmp + *this;
}

Literal* Literal::operator!=(const Literal& other) const {
    Literal* e1 = *this==other;
    Literal* res = !(*e1);
    delete e1;
    return res;
}

Literal* Literal::operator<=(const Literal& other) const {
    Literal* e1 = *this>other;
    Literal* e2 = *this==other;
    Literal* res = *e2 || *(!(*e1));
    delete e1;
    delete e2;
    return res;
}

Literal* Literal::operator>=(const Literal& other) const {
    Literal* e1 = *this>other;
    Literal* e2 = *this==other;
    Literal* res = *e2 || *e1;
    delete e1;
    delete e2;
    return res;
}

Literal* Literal::operator<(const Literal& other) const {
    Literal* e1 = *this>other;
    Literal* e2 = *this==other;
    Literal* res = *(!(*e2)) && *(!(*e1));
    delete e1;
    delete e2;
    return res;
}
