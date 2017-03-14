#include "qcomputer.h"
#include "expression.h"
#include "xmlsave.h"
#include "pile.h"

QComputer* QComputer::QCinstance=0;
Gardien* Gardien::Ginstance=0;

QComputer::QComputer(QWidget* parent) : QMainWindow(parent), m_ui(new Ui::QComputer) {
    m_ui->setupUi(this);

    pile = new Pile();
    cmd = new QStringList;
    atome = new QMap<QString,Literal*>;
    controleur = new Controleur(*pile, *cmd, *atome);

    Gardien::getInstance().addMemento(saveToMemento());

    m_ui->vueMessage->setReadOnly(true);
    m_ui->vueMessage->setText(pile->getMessage());

    m_ui->vuePile->setRowCount(pile->getNb());
    m_ui->vuePile->setColumnCount(1);
    for(unsigned int i=0; i < pile->getNb()+1;i++)
        m_ui->vuePile->setItem(i,0,new QTableWidgetItem(""));
    m_ui->vuePile->horizontalHeader()->setVisible(false);
    m_ui->vuePile->horizontalHeader()->setStretchLastSection(true);
    m_ui->vuePile->verticalHeader()->setVisible(true);

    m_ui->vueCmd->setRowCount(cmd->size());
    m_ui->vueCmd->setColumnCount(1);
    for(unsigned int i=0; i < m_ui->vueCmd->rowCount()+1;i++)
        m_ui->vueCmd->setItem(i,0,new QTableWidgetItem(""));
    m_ui->vueCmd->horizontalHeader()->setVisible(false);
    m_ui->vueCmd->horizontalHeader()->setStretchLastSection(false);
    connect(m_ui->commande,SIGNAL(textChanged(const QString&)),this,SLOT(cmdAnalyser()));

    m_ui->vueVar->setRowCount(atome->size());
    m_ui->vueVar->setColumnCount(1);
    for(unsigned int i=0; i < atome->size()+1;i++)
        m_ui->vueVar->setItem(i,0,new QTableWidgetItem(""));
    m_ui->vueVar->horizontalHeader()->setVisible(false);
    m_ui->vueVar->horizontalHeader()->setStretchLastSection(true);

    QFont font;
    font.setFamily("Courier");
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(10);
    m_ui->progEdit->setFont(font);
    QFontMetrics metrics(font);
    m_ui->progEdit->setTabStopWidth(3*metrics.width(' '));

    connect(m_ui->boutonClavier,SIGNAL(clicked()),this,SLOT(afficherClavier()));
    connect(m_ui->checkAnalyser,SIGNAL(toggled(bool)),this,SLOT(afficherCmd(bool)));

    connect(m_ui->vueProg,SIGNAL(activated(QString)),this, SLOT(selectionProg(QString)));
    connect(m_ui->progEdit,SIGNAL(textChanged()),this, SLOT(refresh()));
    connect(m_ui->progSaveButton,SIGNAL(clicked()),this,SLOT(modifierProg()));

    connect(m_ui->majAtome,SIGNAL(clicked()),this,SLOT(modifierAtome()));

    connect(m_ui->save,SIGNAL(clicked()),this,SLOT(saveCalculator()));
    connect(m_ui->load,SIGNAL(clicked()),this,SLOT(loadSave()));
    connect(m_ui->load_test,SIGNAL(clicked()),this,SLOT(loadSaveTest()));

    connect(m_ui->pNb,SIGNAL(valueChanged(int)),this,SLOT(modifierNbPile(int)));

    connect(m_ui->commande,SIGNAL(textChanged(const QString&)),this,SLOT(refresh()));
    connect(controleur,SIGNAL(modificationEtat()),this,SLOT(refresh()));

    connect(m_ui->commande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
    connect(m_ui->suppr,SIGNAL(clicked()),this,SLOT(suppr()));
    connect(m_ui->enter,SIGNAL(clicked()),this,SLOT(getNextCommande()));
    //connect(m_ui->additionner,SIGNAL(clicked()),this,SLOT(getNextCommande()));
    //connect(m_ui->soustraire,SIGNAL(clicked()),this,SLOT(getNextCommande()));

    signalMapper = new QSignalMapper(this);
    connect(m_ui->un,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->deux,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->trois,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->quatre,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->cinq,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->six,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->sept,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->huit,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->neuf,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->zero,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->diviser,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->multiplier,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->additionner,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->soustraire,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->space,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->point,SIGNAL(clicked()),signalMapper,SLOT(map()));
    //connect(m_ui->apost,SIGNAL(clicked()),signalMapper,SLOT(map()));
    //connect(m_ui->pOuv,SIGNAL(clicked()),signalMapper,SLOT(map()));
    //connect(m_ui->pFerm,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->div,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->mod,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->neg,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->num,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->den,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->dollar,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->re,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->im,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->egal,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->diff,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->infeg,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->supeg,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->inf,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->sup,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->et,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->ou,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->non,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->dup,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->drop,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->swap,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->lastop,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->lastargs,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->clear,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->undo,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->redo,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->evaluer,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(m_ui->stocker,SIGNAL(clicked()),signalMapper,SLOT(map()));

    QString str;
    signalMapper->setMapping(m_ui->un, str.fromLatin1("1"));
    signalMapper->setMapping(m_ui->deux, str.fromLatin1("2"));
    signalMapper->setMapping(m_ui->trois, str.fromLatin1("3"));
    signalMapper->setMapping(m_ui->quatre, str.fromLatin1("4"));
    signalMapper->setMapping(m_ui->cinq, str.fromLatin1("5"));
    signalMapper->setMapping(m_ui->six, str.fromLatin1("6"));
    signalMapper->setMapping(m_ui->sept, str.fromLatin1("7"));
    signalMapper->setMapping(m_ui->huit, str.fromLatin1("8"));
    signalMapper->setMapping(m_ui->neuf, str.fromLatin1("9"));
    signalMapper->setMapping(m_ui->zero, str.fromLatin1("0"));
    signalMapper->setMapping(m_ui->diviser, str.fromLatin1("/"));
    signalMapper->setMapping(m_ui->additionner, str.fromLatin1("+"));
    signalMapper->setMapping(m_ui->multiplier, str.fromLatin1("*"));
    signalMapper->setMapping(m_ui->soustraire, str.fromLatin1("-"));
    signalMapper->setMapping(m_ui->space, str.fromLatin1(" "));
    signalMapper->setMapping(m_ui->point, str.fromLatin1("."));
    //signalMapper->setMapping(m_ui->apost, str.fromLatin1("'"));
    //signalMapper->setMapping(m_ui->pOuv, str.fromLatin1("("));
    //signalMapper->setMapping(m_ui->pFerm, str.fromLatin1(")"));
    signalMapper->setMapping(m_ui->div, str.fromLatin1("DIV"));
    signalMapper->setMapping(m_ui->mod, str.fromLatin1("MOD"));
    signalMapper->setMapping(m_ui->neg, str.fromLatin1("NEG"));
    signalMapper->setMapping(m_ui->num, str.fromLatin1("NUM"));
    signalMapper->setMapping(m_ui->den, str.fromLatin1("DEN"));
    signalMapper->setMapping(m_ui->dollar, str.fromLatin1("$"));
    signalMapper->setMapping(m_ui->re, str.fromLatin1("RE"));
    signalMapper->setMapping(m_ui->im, str.fromLatin1("IM"));
    signalMapper->setMapping(m_ui->egal, str.fromLatin1("="));
    signalMapper->setMapping(m_ui->diff, str.fromLatin1("!="));
    signalMapper->setMapping(m_ui->infeg, str.fromLatin1("=<"));
    signalMapper->setMapping(m_ui->supeg, str.fromLatin1(">="));
    signalMapper->setMapping(m_ui->inf, str.fromLatin1("<"));
    signalMapper->setMapping(m_ui->sup, str.fromLatin1(">"));
    signalMapper->setMapping(m_ui->et, str.fromLatin1("AND"));
    signalMapper->setMapping(m_ui->ou, str.fromLatin1("OR"));
    signalMapper->setMapping(m_ui->non, str.fromLatin1("NOT"));
    signalMapper->setMapping(m_ui->dup, str.fromLatin1("DUP"));
    signalMapper->setMapping(m_ui->drop, str.fromLatin1("DROP"));
    signalMapper->setMapping(m_ui->swap, str.fromLatin1("SWAP"));
    signalMapper->setMapping(m_ui->lastop, str.fromLatin1("LASTOP"));
    signalMapper->setMapping(m_ui->lastargs, str.fromLatin1("LASTARGS"));
    signalMapper->setMapping(m_ui->clear, str.fromLatin1("CLEAR"));
    signalMapper->setMapping(m_ui->undo, str.fromLatin1("UNDO"));
    signalMapper->setMapping(m_ui->redo, str.fromLatin1("REDO"));
    signalMapper->setMapping(m_ui->evaluer, str.fromLatin1("EVAL"));
    signalMapper->setMapping(m_ui->stocker, str.fromLatin1("STO"));

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(buttonToString(QString)));

    /*
    m_ui->un->setShortcut(QKeySequence(Qt::Key_1));
    m_ui->deux->setShortcut(QKeySequence(Qt::Key_2));
    m_ui->trois->setShortcut(QKeySequence(Qt::Key_3));
    m_ui->quatre->setShortcut(QKeySequence(Qt::Key_4));
    m_ui->cinq->setShortcut(QKeySequence(Qt::Key_5));
    m_ui->six->setShortcut(QKeySequence(Qt::Key_6));
    m_ui->sept->setShortcut(QKeySequence(Qt::Key_7));
    m_ui->huit->setShortcut(QKeySequence(Qt::Key_8));
    m_ui->neuf->setShortcut(QKeySequence(Qt::Key_9));
    m_ui->zero->setShortcut(QKeySequence(Qt::Key_0));
    */
    m_ui->additionner->setShortcut(QKeySequence(Qt::Key_Plus));
    m_ui->soustraire->setShortcut(QKeySequence(Qt::Key_Minus));
    m_ui->diviser->setShortcut(QKeySequence(Qt::Key_Slash));
    m_ui->multiplier->setShortcut(QKeySequence(Qt::Key_Asterisk));
    m_ui->enter->setShortcut(QKeySequence(Qt::Key_Enter));
    m_ui->suppr->setShortcut(QKeySequence(Qt::Key_Backspace));
    m_ui->space->setShortcut(QKeySequence(Qt::Key_Space));
    m_ui->point->setShortcut(QKeySequence(Qt::Key_Period));
}

QComputer::~QComputer() {
    delete controleur;
    delete pile;
    delete cmd;
    delete atome;
}

void QComputer::refresh() {
    m_ui->vueMessage->setText(pile->getMessage());
    m_ui->vuePile->clear();
    m_ui->vuePile->setRowCount(pile->getNb());
    for(unsigned int i=0; i < pile->getNb()+1;i++)
        m_ui->vuePile->setItem(i,0,new QTableWidgetItem(""));
    QStringList pileLabels;
    if (!pile->empty())
        for(unsigned int i = 0; i < pile->size() && i < pile->getNb()-1; i++) {
            m_ui->vuePile->item(i,0)->setText((*pile->at(pile->size()-i-1)).toString());
            //qDebug() << literalTypeString(*(pile->at(pile->size()-i-1)));
            QString type = QString::number(i+1) + " | " + literalTypeString(*(pile->at(pile->size()-i-1)));
            //qDebug() << type;
            pileLabels.insert(i, type);
        }
    m_ui->vuePile->setVerticalHeaderLabels(pileLabels);
    if(pile->size() >= pile->getNb())
        m_ui->vuePile->item(m_ui->vuePile->rowCount()-1,0)->setText("...");

    m_ui->vueCmd->clear();
    m_ui->vueCmd->setRowCount(cmd->size());
    for(unsigned int i=0; i < cmd->size()+1;i++)
        m_ui->vueCmd->setItem(i,0,new QTableWidgetItem(""));
    for(unsigned int i = 0; i < cmd->size(); i++) {
        m_ui->vueCmd->item(i,0)->setText((*cmd)[i]);
    }

    m_ui->vueVar->clear();
    m_ui->vueVar->setRowCount(atome->size());
    for(unsigned int i=0; i < atome->size()+1;i++)
        m_ui->vueVar->setItem(i,0,new QTableWidgetItem(""));
    unsigned int i=0;
    QStringList labels;
    QMapIterator<QString,Literal*> it(*atome);
    while(it.hasNext()) {
        it.next();
        m_ui->vueVar->item(i,0)->setText(it.value()->toString());
        labels.insert(i, it.key());
        i++;
    }
    m_ui->vueVar->setVerticalHeaderLabels(labels);

    QStringList atomeProg;
    it.toFront();
    while(it.hasNext()) {
        it.next();
        if(literalType(*(it.value()))==programme && !atomeProg.contains(it.key())) {
            atomeProg.insert(i, it.key());
            i++;
        }
    }
    m_ui->vueProg->clear();
    m_ui->vueProg->addItems(atomeProg);
    QString prog = m_ui->progEdit->toPlainText();
    prog = prog.replace(QRegExp("\t+"),"");
    prog = prog.replace(QRegExp("^\\[\n"),"[");
    prog = prog.replace(QRegExp("\n\\]$"),"]");
    m_ui->progCopy->setText(prog);
}

void QComputer::cmdAnalyser() {
    cmd->clear();
    QString str = m_ui->commande->text();
    QRegExp expression("((?:\\[.*\\])|(?:[A-Z]+([A-Z]|[0-9])*)|(?:'.*')|(?:\\()|(?:\\))|(?:\\+)|(?:\\-)|(?:\\*)|(?:\\/)|(?:(?:[1-9][0-9]*)\\/(?:[1-9][0-9]*))|(?:(?:[0-9]*)?\\.(?:[0-9]*)?)|(?:[0-9]+)|(?:>)|(?:<)|(?:>=)|(?:<=)|(?:=)|(?:!=)|(?:\\$))");
    if (expression.isValid()) {
        int pos = 0;
        while ((pos = expression.indexIn(str, pos)) != -1) {
            (*cmd) << expression.cap(1);
            pos += expression.matchedLength();
        }
    } else
        m_ui->vueMessage->setText("Erreur Expression !");
}

void QComputer::getNextCommande() {
    while(!cmd->empty()){
        QString tmp = cmd->first();
        cmd->removeFirst();
        controleur->commande(tmp);
        if (pile->isUpdated(Gardien::getInstance().getMementoPrec()->getSavedPile())||*atome!=Gardien::getInstance().getMementoPrec()->getSavedAtome()){
            Gardien::getInstance().addMemento(saveToMemento());
        }
    }
    m_ui->commande->clear();
}

void QComputer::buttonToString(const QString& s) {
    qDebug()<<s;
    m_ui->commande->setText(s);
    getNextCommande();
}

void QComputer::suppr() {
    m_ui->commande->backspace();
}

void QComputer::modifierNbPile(int n) {
    pile->setNb(n);
    refresh();
}

void QComputer::afficherClavier() {
    if(m_ui->boutonClavier->text() == ">") {
        m_ui->clavierEtendu->setFixedWidth(0);
        m_ui->boutonClavier->setText("<");
    }else if(m_ui->boutonClavier->text() == "<") {
        m_ui->clavierEtendu->setFixedWidth(300);
        m_ui->boutonClavier->setText(">");
    }
}

void QComputer::afficherCmd(bool b) {
    if(b) {
        m_ui->vueCmd->show();
    }else {
        m_ui->vueCmd->hide();
    }

}

void QComputer::selectionProg(QString c) {
    if(atome->find(c) != atome->end()) {
        QString prog = atome->value(c)->toString();
        prog = prog.replace(QRegExp("^\\["),"[\n");
        prog = prog.replace(QRegExp("\\]$"),"\n]");
        prog = prog.replace(QRegExp("\\s+"),"\n");
        m_ui->progEdit->clear();
        m_ui->progEdit->setPlainText(prog);
    }
}

void QComputer::modifierAtome() {
    QString nameVar;
    QString val;
    for(unsigned int i = 0; i<m_ui->vueVar->rowCount(); i++) {
        qDebug() << m_ui->vueVar->model()->headerData(i, Qt::Vertical).toString() + " & " + "|" + m_ui->vueVar->item(i,0)->text() + "|";
        nameVar = m_ui->vueVar->model()->headerData(i, Qt::Vertical).toString();
        val = m_ui->vueVar->item(i,0)->text();
        if(val.compare("")==0) {
            atome->remove(nameVar);
        } else {
            controleur->commande(val);
            atome->insert(nameVar,pile->last());
            if(!pile->empty()) pile->removeLast();
        }
        //atome->insert(m_ui->vueVar->model()->headerData(i, Qt::Vertical).toString(),m_ui->vueVar->item(i,0));
    }
    refresh();
}

void QComputer::modifierProg() {
    QString prog = m_ui->progCopy->text();
    if(prog != "") {
        controleur->commande(prog.replace(QRegExp("\n+"), " "));
        if(!pile->empty()) {
            atome->insert(m_ui->vueProg->currentText(), pile->last());
            if(!pile->empty()) pile->removeLast();
        }
    }
    refresh();
}

void QComputer::saveCalculator() {
    XmlSave::getInstance().SaveXMLFile();
}

void QComputer::loadSaveTest() {
    XmlSave::getInstance().ReadXMLFile("test.xml");
    refresh();
}

void QComputer::loadSave() {
    XmlSave::getInstance().ReadXMLFile("save.xml");
    refresh();
}

void QComputer::closeEvent(QCloseEvent *event){
    saveCalculator();
}

void QComputer::showEvent(QShowEvent *event){
    loadSave();
    refresh();
}
