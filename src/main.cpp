#include "literal.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "pile.h"
#include "qcomputer.h"
#include "xmlsave.h"

#include <QApplication>
#include <QtGui>
#include <QtXml>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QComputer& fenetre = QComputer::getInstance();

    fenetre.show();
    return app.exec();

    QComputer::freeInstance();
    Gardien::freeInstance();
    XmlSave::freeInstance();
}
