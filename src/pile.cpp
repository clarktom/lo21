#include <regex>
#include <QRegExp>

#include "pile.h"
#include "qcomputer.h"
#include "expression.h"

int Pile::estUnOperateur(const QString& s)const {
    if (s == "+") return 2;
    if (s == "-") return 2;
    if (s == "*") return 2;
    if (s == "/") return 2;
    if (s == "=") return 2;
    if (s == "!=") return 2;
    if (s == "=<") return 2;
    if (s == ">=") return 2;
    if (s == ">") return 2;
    if (s == "<") return 2;
    if (s == "AND") return 2;
    if (s == "OR") return 2;
    if (s == "NOT") return 1;
    if (s == "DIV") return 2;
    if (s == "MOD") return 2;
    if (s == "IFT") return 3;
    if (s == "NEG") return 1;
    if (s == "NUM") return 1;
    if (s == "DEN") return 1;
    if (s == "$") return 2;
    if (s == "RE") return 1;
    if (s == "IM") return 1;
    if (s == "DUP") return 3;
    if (s == "DROP") return 3;
    if (s == "SWAP") return 3;
    if (s == "CLEAR") return 3;
    if (s == "UNDO") return 3;
    if (s == "REDO") return 3;
    if (s == "STO") return 3;
    if (s == "EVAL") return 3;
    if (s == "LASTARGS") return 3;
    if (s == "LASTOP") return 3;
    return 0;
}

void Controleur::commande(const QString& c) {
    pile.setMessage("");
    Literal* tmp;
    QString type = regexType(c);
    if(factories.find(type) != factories.end())
        tmp = factories.at(type)->getLiteral(c);
    else
        tmp = nullptr;
    //Literal* tmp = regexType(c);
    if(tmp != nullptr) {
        try {
            Gardien::getInstance().razNbUndo();
            //pile.setMessage(literalTypeString(*tmp));
            pile.push_back(tmp);
        }
        catch (const ComputerException(e)) {
            pile.setMessage(e.getInfo());
        }
    }
    else {
        if (c != "UNDO")
            Gardien::getInstance().razNbUndo();
        int n = pile.estUnOperateur(c); //Renvoie une valeur qui correspond au nombre d'arg a dépilé, renvoi 0 si l'operateur n'est pas reconnu
        switch (n)
        {
        case 1: //Operateur unaires
        {
            lastOp = c;
            if(pile.size()>=1) {
                Literal& v1 = *pile.back(); pile.pop_back();

                lastArgs.clear();
                lastArgs.push_back(v1.clone());

                Literal* res = nullptr;
                try {
                    if (c == "NEG") { res = v1.NEG(); pile.push_back(res); delete &v1; }
                    /*else if (c == "TEST") {qDebug()<<"TEST"; QComputer::getInstance().getAtome().remove("V"); for (QMap<QString,Literal*>::const_iterator it = QComputer::getInstance().getAtome().constBegin(); it != QComputer::getInstance().getAtome().constEnd(); ++it){
                            qDebug()<<it.key();
                            qDebug()<<it.value()->toString(); }qDebug()<<"TEST";}*/
                    else if (c == "NUM") { res = v1.NUM(); pile.push_back(res); delete &v1; }
                    else if (c == "DEN") { res = v1.DEN(); pile.push_back(res); delete &v1; }
                    else if (c == "NOT") { res = !v1; pile.push_back(res); delete &v1; }
                    else if (c == "RE") { res = v1.RE(); pile.push_back(res); delete &v1; }
                    else if (c == "IM") { res = v1.IM(); pile.push_back(res); delete &v1; }
                    else { pile.setMessage("Commande non reconnue"); }
                }catch (const LiteralException& e) {
                    pile.setMessage(e.getInfo());
                    pile.push_back(&v1);
                }
            }
            else {
                pile.setMessage("Erreur : pas assez d'arguments");
            }
            break;
        }
        case 2: //Operateurs binaires
        {
            lastOp = c;
            if (pile.size() >= 2) {
                Literal& v2 = *pile.back(); pile.pop_back();
                Literal& v1 = *pile.back(); pile.pop_back();

                lastArgs.clear();
                lastArgs.push_back(v1.clone());
                lastArgs.push_back(v2.clone());

                Literal* res = nullptr;
                try {
                    if (c == "+") { res = v1 + v2; pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "-") { res = v1 - v2; pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "*") { res = v1 * v2; pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "=") { res = (v1 == v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "!=") { res = (v1 != v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == ">=") { res = (v1 >= v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "=<") { res = (v1 <= v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == ">") { res = (v1 > v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "<") { res = (v1 < v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "AND") { res = (v1 && v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "OR") { res = (v1 || v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "/") { if(v2.toString().compare("0")!=0){ res = v1 / v2; pile.push_back(res); delete &v1; delete &v2; }else{throw LiteralException("Erreur : division par zero !");}}
                    else if (c == "DIV") { if(v2.toString().compare("0")!=0){ res = v1.DIV(v2); pile.push_back(res); delete &v1; delete &v2; }else{throw LiteralException("Erreur : DIV par zero !");}}
                    else if (c == "MOD") { res = v1.MOD(v2); pile.push_back(res); delete &v1; delete &v2; }
                    else if (c == "$") { res = v1.$(v2); pile.push_back(res); delete &v1; delete &v2; }
                    else { pile.setMessage("Commande non reconnue"); }
                }
                catch (const LiteralException& e) {
                    pile.setMessage(e.getInfo());
                    pile.push_back(&v1);
                    pile.push_back(&v2);
                }
            }
            else {
                pile.setMessage("Erreur : pas assez d'arguments");
            }
            break;
        }
        case 3: //Commandes consoles
        {
            if (c != "LASTOP") lastOp = c;
            if (c == "CLEAR") {
                pile.clear();
                pile.setMessage("Stack cleared");
            }
            if (c == "SWAP") {
                if (pile.size() >= 2) {
                    Literal& v2 = *pile.back(); pile.pop_back();
                    Literal& v1 = *pile.back(); pile.pop_back();
                    lastArgs.clear();
                    lastArgs.push_back(v1.clone());
                    lastArgs.push_back(v2.clone());
                    pile.push_back(&v2);
                    pile.push_back(&v1);
                    pile.setMessage(v1.toString() + " " + v2.toString() + " swapped");
                }
                else
                    pile.setMessage("Erreur : pas assez d'arguments");
            }
            if (c == "DUP") {
                if (pile.size() >= 1) {
                    Literal* v2 = pile.back()->clone();
                    lastArgs.clear();
                    lastArgs.push_back(v2->clone());
                    pile.push_back(v2);
                    pile.setMessage(pile.back()->toString() + " duplicated");
                }
                else
                    pile.setMessage("Erreur : pas assez d'arguments");
            }
            if (c == "DROP") {
                if (pile.size() >= 1) {
                    Literal& v1 = *pile.back(); pile.pop_back();
                    lastArgs.clear();
                    lastArgs.push_back(v1.clone());
                    pile.setMessage(v1.toString() + " dropped");
                    delete &v1;
                }
                else
                    pile.setMessage("Erreur : pas assez d'arguments");
            }
            if (c == "LASTARGS") {
                for(unsigned int i=0; i<lastArgs.size(); i++)
                    cmd << lastArgs[i]->toString();
            }
            if (c == "LASTOP") {
                cmd << lastOp;
            }
            if (c == "REDO") {
                if(Gardien::getInstance().getNbRedo()!=0){
                    QComputer::getInstance().restoreFromMemento(Gardien::getInstance().getMemento(Gardien::getInstance().getIndRet()));
                    pile.setMessage("reloaded");
                    Gardien::getInstance().decNbRedo();
                }
                else
                    pile.setMessage("Redo impossible : pas d'undo");
            }
            if (c == "UNDO") {
                qDebug()<<"test";
                if (pile.size() >= 1) {
                    qDebug()<<Gardien::getInstance().getSavedStates().size();
                    if (Gardien::getInstance().getSavedStates().size()<=1){
                        qDebug()<<"test";
                        pile.setMessage("Erreur : aucun etat enregistre");}
                    else{
                        qDebug()<<"non vide";
                        Gardien::getInstance().incNbUndo();
                        Gardien::getInstance().setNbRedo(Gardien::getInstance().getNbUndo());
                        Gardien::getInstance().setIndRet(Gardien::getInstance().getNbUndo());
                        QComputer::getInstance().restoreFromMemento(Gardien::getInstance().getMemento(Gardien::getInstance().getNbUndo()));
                        pile.setMessage("undone");
                        /*qDebug()<<"UNDO";
                    for (QMap<QString,Literal*>::const_iterator it = QComputer::getInstance().getAtome().constBegin(); it != QComputer::getInstance().getAtome().constEnd(); ++it){
                        qDebug()<<it.key();
                        qDebug()<<it.value()->toString(); }
                    qDebug()<<"UNDO";*/
                    }
                }
                else
                    pile.setMessage("Erreur : pas assez d'arguments");
            }
            if (c == "EVAL") {
                qDebug() << "EVAL";
                if (pile.size() >= 1) {
                    Literal& v1 = *pile.back(); pile.pop_back();
                    lastArgs.clear();
                    lastArgs.push_back(v1.clone());
                    if(literalType(v1)==expression) {
                        const Expression& tmp = dynamic_cast<const Expression&>(v1);
                        QStringList exp;
                        QRegExp expression("((?:\[.*\])|(?:[A-Z]+(?:[A-Z]|[0-9])*)|(?:'.*')|(?:\\()|(?:\\))|(?:\\+)|(?:\\-)|(?:\\*)|(?:\\/)|(?:(?:[1-9][0-9]*)\\/(?:[1-9][0-9]*))|(?:(?:[0-9]*)?\\.(?:[0-9]*)?)|(?:[0-9]+))");
                        if (expression.isValid()) {
                            int pos = 0;
                            while ((pos = expression.indexIn(tmp.getExpression(), pos)) != -1) {
                                exp << expression.cap(1).replace(QRegExp("\\s+"),"");
                                pos += expression.matchedLength();
                            }
                        } else
                            pile.setMessage("Erreur Regex !");
                        delete &v1;
                        qDebug()<<exp;
                        QRegExp nomVar("^[A-Z]+([A-Z]|[0-9])*$"); //On teste si ce qui est rentré n'est pas un identificateur de variable
                        QStringList res;
                        bool atm = true;
                        while(!exp.empty() && atm) {
                            if(nomVar.exactMatch(exp.first())) {
                                if(atome.find(exp.first())!=atome.end()) {
                                    qDebug() << atome.value(exp.first())->toString();
                                    res << atome.value(exp.first())->toString();
                                }else{
                                    atm = false;
                                }
                            }else{
                                res << exp.first();

                            }
                            exp.removeFirst();
                        }
                        qDebug()<<res;
                        if(atm){
                            res = expPostFix(res);
                            qDebug() << res;
                            while(!res.empty()) {
                                cmd << res.first();
                                res.removeFirst();
                            }
                        }else{
                            pile.setMessage(exp.first() + " introuvable !");
                        }
                    } else {
                        pile.setMessage("Pas d'expression à évaluer !");
                        pile.push_back(&v1);
                    }
                } else
                    pile.setMessage("Pas assez d'arguements !");
            }
            if (c == "STO") {
                qDebug() << "STO";
                if(pile.size() >= 2) {
                    Literal& v2 = *pile.back(); pile.pop_back();
                    Literal& v1 = *pile.back(); pile.pop_back();
                    lastArgs.clear();
                    lastArgs.push_back(v1.clone());
                    lastArgs.push_back(v2.clone());
                    QString name = v2.toString();
                    QRegExp nomVar("^'[A-Z]+([A-Z]|[0-9])*'$"); //Rajouter filtrage nom operateur existant
                    if(nomVar.exactMatch(name)) {
                       atome.insert(name.replace(QRegExp("'+"),""), &v1);
                    }else{
                        pile.setMessage("Nom de variable invalide !");
                        pile.push_back(&v1);
                        pile.push_back(&v2);
                    }
                }else
                    pile.setMessage("Pas assez d'arguments!");
            }
            if (c == "IFT") {
                qDebug() << "IFT";
                if(pile.size() >= 2) {
                    Literal& op2 = *pile.back(); pile.pop_back();
                    Literal& op1 = *pile.back(); pile.pop_back();
                    lastArgs.clear();
                    lastArgs.push_back(op1.clone());
                    lastArgs.push_back(op2.clone());
                    if(op1.toString() == "0"){
                        qDebug() << "0";
                        delete &op1;
                        delete &op2;
                    }else if(op1.toString() == "1"){
                        qDebug() << "1";
                        QString prog = op2.toString();
                        prog = prog.replace(QRegExp("^\\[|\\]$"),"");
                        QRegExp expression("((?:\\[.*\\])|(?:[A-Z]+([A-Z]|[0-9])*)|(?:'.*')|(?:\\()|(?:\\))|(?:\\+)|(?:\\-)|(?:\\*)|(?:\\/)|(?:(?:[1-9][0-9]*)\\/(?:[1-9][0-9]*))|(?:(?:[0-9]*)?\\.(?:[0-9]*)?)|(?:[0-9]+)|(?:>)|(?:<)|(?:>=)|(?:<=)|(?:=)|(?:!=))");
                        if (expression.isValid()) {
                            int pos = 0;
                            while ((pos = expression.indexIn(prog, pos)) != -1) {
                                cmd << expression.cap(1);
                                pos += expression.matchedLength();
                            }
                            delete &op1;
                            delete &op2;
                        } else
                            pile.setMessage("Erreur Expression !");
                    } else {
                        pile.setMessage("Resultat du test logique non trouvé !");
                        pile.push_back(&op1);
                        pile.push_back(&op2);
                    }
                }else
                    pile.setMessage("Pas assez d'arguments!");
            }
            break;
        }
        default:
        {
            qDebug() << "Default";
            QRegExp regVar("^[A-Z]+([A-Z]|[0-9])*$"); //On teste si ce qui est rentré n'est pas un identificateur de variable
            if(regVar.exactMatch(c)) {
                if(atome.find(c)!=atome.end()) {
                    QString tmp = atome.value(c)->toString();
                    QRegExp regProg("^\\[.*\\]$");
                    if(regProg.exactMatch(tmp)) {
                        tmp = tmp.replace(QRegExp("^\\[|\\]$"),"");
                        QRegExp expression("((?:\\[.*\\])|(?:[A-Z]+([A-Z]|[0-9])*)|(?:'.*')|(?:\\()|(?:\\))|(?:\\+)|(?:\\-)|(?:\\*)|(?:\\/)|(?:(?:[1-9][0-9]*)\\/(?:[1-9][0-9]*))|(?:(?:[0-9]*)?\\.(?:[0-9]*)?)|(?:[0-9]+)|(?:>)|(?:<)|(?:>=)|(?:<=)|(?:=)|(?:!=))");
                        if (expression.isValid()) {
                            int pos = 0;
                            while ((pos = expression.indexIn(tmp, pos)) != -1) {
                                cmd << expression.cap(1);
                                pos += expression.matchedLength();
                            }
                        } else
                            pile.setMessage("Erreur Expression !");
                    } else {
                        cmd << tmp;
                    }
                } else {
                    cmd << "'" + c + "'";
                }
                break;
            }
        }
        }
    }
    //modificationEtat();
}


int Controleur::getPriorite(const QString& ch) const {
    if(ch.compare("/")==0 || ch.compare("*")==0)
        return 2;
    else if(ch.compare("+")==0 || ch.compare("-")==0)
        return 1;
    else
        return 0;
}

QStringList Controleur::expPostFix(const QStringList& c) {
    QStringList exp;
    QStack<QString> s;
    int weight;
    int i = 0;
    QString ch;
    while (i < c.size()) {
        ch = c[i];
        if (ch == "(") {
            s.push(ch);
            i++;
            continue;
        }
        if (ch == ")") {
            while (!s.empty() && s.top() != "(") {
                exp.push_back(s.top());
                s.pop();

            }
            if (!s.empty()) {
                s.pop();
            }
            i++;
            continue;
        }
        weight = getPriorite(ch);
        if (weight == 0) {
            exp.push_back(ch);
        }
        else {
            if (s.empty()) {
                s.push(ch);
            }
            else {
                while (!s.empty() && s.top() != "(" &&
                       weight <= getPriorite(s.top())) {
                    exp.push_back(s.top());
                    s.pop();

                }
                s.push(ch);
            }
        }
        i++;
    }
    while (!s.empty()) {
        exp.push_back(s.top());
        s.pop();
    }
    return exp;
}

