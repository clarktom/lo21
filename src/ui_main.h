/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QComputer
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *calc;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *vueMessage;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *vueCmd;
    QTableWidget *vuePile;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkAnalyser;
    QLabel *label_5;
    QSpinBox *pNb;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *commande;
    QPushButton *suppr;
    QPushButton *enter;
    QGridLayout *gridLayout;
    QPushButton *soustraire;
    QPushButton *multiplier;
    QPushButton *point;
    QPushButton *diviser;
    QPushButton *space;
    QPushButton *additionner;
    QHBoxLayout *horizontalLayout;
    QPushButton *evaluer;
    QPushButton *stocker;
    QPushButton *trois;
    QPushButton *cinq;
    QPushButton *six;
    QPushButton *quatre;
    QPushButton *un;
    QPushButton *neuf;
    QPushButton *deux;
    QPushButton *zero;
    QPushButton *huit;
    QPushButton *sept;
    QWidget *bouton;
    QPushButton *boutonClavier;
    QWidget *clavierEtendu;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *dup;
    QPushButton *lastargs;
    QPushButton *dollar;
    QPushButton *lastop;
    QPushButton *clear;
    QPushButton *drop;
    QPushButton *neg;
    QPushButton *num;
    QPushButton *im;
    QPushButton *swap;
    QPushButton *den;
    QPushButton *re;
    QPushButton *mod;
    QPushButton *redo;
    QPushButton *div;
    QPushButton *diff;
    QPushButton *load;
    QPushButton *infeg;
    QPushButton *sup;
    QPushButton *egal;
    QPushButton *et;
    QPushButton *supeg;
    QPushButton *inf;
    QPushButton *ou;
    QPushButton *non;
    QPushButton *load_test;
    QPushButton *save;
    QLabel *label;
    QLabel *label_2;
    QPushButton *undo;
    QWidget *var;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *vueVar;
    QPushButton *majAtome;
    QWidget *tab;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *vueProg;
    QPushButton *progSaveButton;
    QLineEdit *progCopy;
    QTextEdit *progEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QComputer)
    {
        if (QComputer->objectName().isEmpty())
            QComputer->setObjectName(QStringLiteral("QComputer"));
        QComputer->resize(800, 600);
        QComputer->setMinimumSize(QSize(800, 600));
        QComputer->setMaximumSize(QSize(800, 600));
        QIcon icon;
        QString iconThemeName = QStringLiteral("icon.png");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        QComputer->setWindowIcon(icon);
        QComputer->setAutoFillBackground(true);
        centralwidget = new QWidget(QComputer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 761, 561));
        calc = new QWidget();
        calc->setObjectName(QStringLiteral("calc"));
        horizontalLayoutWidget_4 = new QWidget(calc);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 20, 741, 501));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        vueMessage = new QTextEdit(horizontalLayoutWidget_4);
        vueMessage->setObjectName(QStringLiteral("vueMessage"));
        vueMessage->setMinimumSize(QSize(0, 25));
        vueMessage->setMaximumSize(QSize(16777215, 20));
        vueMessage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vueMessage->setReadOnly(true);
        vueMessage->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(vueMessage);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        vueCmd = new QTableWidget(horizontalLayoutWidget_4);
        vueCmd->setObjectName(QStringLiteral("vueCmd"));
        vueCmd->setMaximumSize(QSize(80, 16777215));
        vueCmd->setEditTriggers(QAbstractItemView::NoEditTriggers);
        vueCmd->setAlternatingRowColors(false);

        horizontalLayout_4->addWidget(vueCmd);

        vuePile = new QTableWidget(horizontalLayoutWidget_4);
        vuePile->setObjectName(QStringLiteral("vuePile"));
        vuePile->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vuePile->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);
        vuePile->setAlternatingRowColors(true);
        vuePile->setSelectionMode(QAbstractItemView::NoSelection);
        vuePile->horizontalHeader()->setVisible(false);
        vuePile->horizontalHeader()->setDefaultSectionSize(80);
        vuePile->horizontalHeader()->setMinimumSectionSize(50);
        vuePile->verticalHeader()->setVisible(false);
        vuePile->verticalHeader()->setDefaultSectionSize(30);
        vuePile->verticalHeader()->setHighlightSections(true);
        vuePile->verticalHeader()->setMinimumSectionSize(19);

        horizontalLayout_4->addWidget(vuePile);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        checkAnalyser = new QCheckBox(horizontalLayoutWidget_4);
        checkAnalyser->setObjectName(QStringLiteral("checkAnalyser"));
        checkAnalyser->setChecked(true);

        horizontalLayout_8->addWidget(checkAnalyser);

        label_5 = new QLabel(horizontalLayoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5, 0, Qt::AlignRight);

        pNb = new QSpinBox(horizontalLayoutWidget_4);
        pNb->setObjectName(QStringLiteral("pNb"));
        pNb->setMaximumSize(QSize(80, 16777215));
        pNb->setMinimum(2);
        pNb->setMaximum(100);
        pNb->setValue(9);

        horizontalLayout_8->addWidget(pNb, 0, Qt::AlignLeft);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        commande = new QLineEdit(horizontalLayoutWidget_4);
        commande->setObjectName(QStringLiteral("commande"));
        commande->setMaximumSize(QSize(16777215, 20));
        commande->setReadOnly(false);

        horizontalLayout_5->addWidget(commande);

        suppr = new QPushButton(horizontalLayoutWidget_4);
        suppr->setObjectName(QStringLiteral("suppr"));
        suppr->setMaximumSize(QSize(25, 25));

        horizontalLayout_5->addWidget(suppr);

        enter = new QPushButton(horizontalLayoutWidget_4);
        enter->setObjectName(QStringLiteral("enter"));
        enter->setMinimumSize(QSize(50, 25));
        enter->setMaximumSize(QSize(50, 25));

        horizontalLayout_5->addWidget(enter);


        verticalLayout_2->addLayout(horizontalLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        soustraire = new QPushButton(horizontalLayoutWidget_4);
        soustraire->setObjectName(QStringLiteral("soustraire"));

        gridLayout->addWidget(soustraire, 1, 4, 1, 1);

        multiplier = new QPushButton(horizontalLayoutWidget_4);
        multiplier->setObjectName(QStringLiteral("multiplier"));

        gridLayout->addWidget(multiplier, 0, 4, 1, 1);

        point = new QPushButton(horizontalLayoutWidget_4);
        point->setObjectName(QStringLiteral("point"));

        gridLayout->addWidget(point, 3, 2, 1, 1);

        diviser = new QPushButton(horizontalLayoutWidget_4);
        diviser->setObjectName(QStringLiteral("diviser"));

        gridLayout->addWidget(diviser, 2, 4, 1, 1);

        space = new QPushButton(horizontalLayoutWidget_4);
        space->setObjectName(QStringLiteral("space"));

        gridLayout->addWidget(space, 3, 0, 1, 1);

        additionner = new QPushButton(horizontalLayoutWidget_4);
        additionner->setObjectName(QStringLiteral("additionner"));

        gridLayout->addWidget(additionner, 3, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        evaluer = new QPushButton(horizontalLayoutWidget_4);
        evaluer->setObjectName(QStringLiteral("evaluer"));
        evaluer->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(evaluer);

        stocker = new QPushButton(horizontalLayoutWidget_4);
        stocker->setObjectName(QStringLiteral("stocker"));
        stocker->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(stocker);


        gridLayout->addLayout(horizontalLayout, 4, 4, 1, 1);

        trois = new QPushButton(horizontalLayoutWidget_4);
        trois->setObjectName(QStringLiteral("trois"));

        gridLayout->addWidget(trois, 2, 2, 1, 1);

        cinq = new QPushButton(horizontalLayoutWidget_4);
        cinq->setObjectName(QStringLiteral("cinq"));

        gridLayout->addWidget(cinq, 1, 1, 1, 1);

        six = new QPushButton(horizontalLayoutWidget_4);
        six->setObjectName(QStringLiteral("six"));

        gridLayout->addWidget(six, 1, 2, 1, 1);

        quatre = new QPushButton(horizontalLayoutWidget_4);
        quatre->setObjectName(QStringLiteral("quatre"));

        gridLayout->addWidget(quatre, 1, 0, 1, 1);

        un = new QPushButton(horizontalLayoutWidget_4);
        un->setObjectName(QStringLiteral("un"));

        gridLayout->addWidget(un, 2, 0, 1, 1);

        neuf = new QPushButton(horizontalLayoutWidget_4);
        neuf->setObjectName(QStringLiteral("neuf"));

        gridLayout->addWidget(neuf, 0, 2, 1, 1);

        deux = new QPushButton(horizontalLayoutWidget_4);
        deux->setObjectName(QStringLiteral("deux"));

        gridLayout->addWidget(deux, 2, 1, 1, 1);

        zero = new QPushButton(horizontalLayoutWidget_4);
        zero->setObjectName(QStringLiteral("zero"));

        gridLayout->addWidget(zero, 3, 1, 1, 1);

        huit = new QPushButton(horizontalLayoutWidget_4);
        huit->setObjectName(QStringLiteral("huit"));

        gridLayout->addWidget(huit, 0, 1, 1, 1);

        sept = new QPushButton(horizontalLayoutWidget_4);
        sept->setObjectName(QStringLiteral("sept"));

        gridLayout->addWidget(sept, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        bouton = new QWidget(horizontalLayoutWidget_4);
        bouton->setObjectName(QStringLiteral("bouton"));
        bouton->setMinimumSize(QSize(50, 0));
        bouton->setMaximumSize(QSize(50, 16777215));
        boutonClavier = new QPushButton(bouton);
        boutonClavier->setObjectName(QStringLiteral("boutonClavier"));
        boutonClavier->setGeometry(QRect(10, 10, 31, 481));
        boutonClavier->setMaximumSize(QSize(500, 650));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferDefault);
        boutonClavier->setFont(font);

        horizontalLayout_2->addWidget(bouton);

        clavierEtendu = new QWidget(horizontalLayoutWidget_4);
        clavierEtendu->setObjectName(QStringLiteral("clavierEtendu"));
        clavierEtendu->setEnabled(true);
        clavierEtendu->setMinimumSize(QSize(300, 0));
        clavierEtendu->setMaximumSize(QSize(300, 16777215));
        gridLayoutWidget = new QWidget(clavierEtendu);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 271, 481));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        dup = new QPushButton(gridLayoutWidget);
        dup->setObjectName(QStringLiteral("dup"));

        gridLayout_2->addWidget(dup, 1, 0, 1, 1);

        lastargs = new QPushButton(gridLayoutWidget);
        lastargs->setObjectName(QStringLiteral("lastargs"));

        gridLayout_2->addWidget(lastargs, 2, 0, 1, 1);

        dollar = new QPushButton(gridLayoutWidget);
        dollar->setObjectName(QStringLiteral("dollar"));

        gridLayout_2->addWidget(dollar, 6, 0, 1, 1);

        lastop = new QPushButton(gridLayoutWidget);
        lastop->setObjectName(QStringLiteral("lastop"));

        gridLayout_2->addWidget(lastop, 2, 1, 1, 1);

        clear = new QPushButton(gridLayoutWidget);
        clear->setObjectName(QStringLiteral("clear"));

        gridLayout_2->addWidget(clear, 2, 2, 1, 1);

        drop = new QPushButton(gridLayoutWidget);
        drop->setObjectName(QStringLiteral("drop"));

        gridLayout_2->addWidget(drop, 1, 1, 1, 1);

        neg = new QPushButton(gridLayoutWidget);
        neg->setObjectName(QStringLiteral("neg"));

        gridLayout_2->addWidget(neg, 4, 2, 1, 1);

        num = new QPushButton(gridLayoutWidget);
        num->setObjectName(QStringLiteral("num"));

        gridLayout_2->addWidget(num, 5, 0, 1, 1);

        im = new QPushButton(gridLayoutWidget);
        im->setObjectName(QStringLiteral("im"));

        gridLayout_2->addWidget(im, 6, 2, 1, 1);

        swap = new QPushButton(gridLayoutWidget);
        swap->setObjectName(QStringLiteral("swap"));

        gridLayout_2->addWidget(swap, 1, 2, 1, 1);

        den = new QPushButton(gridLayoutWidget);
        den->setObjectName(QStringLiteral("den"));

        gridLayout_2->addWidget(den, 5, 1, 1, 1);

        re = new QPushButton(gridLayoutWidget);
        re->setObjectName(QStringLiteral("re"));

        gridLayout_2->addWidget(re, 6, 1, 1, 1);

        mod = new QPushButton(gridLayoutWidget);
        mod->setObjectName(QStringLiteral("mod"));

        gridLayout_2->addWidget(mod, 4, 1, 1, 1);

        redo = new QPushButton(gridLayoutWidget);
        redo->setObjectName(QStringLiteral("redo"));

        gridLayout_2->addWidget(redo, 10, 2, 1, 1);

        div = new QPushButton(gridLayoutWidget);
        div->setObjectName(QStringLiteral("div"));

        gridLayout_2->addWidget(div, 4, 0, 1, 1);

        diff = new QPushButton(gridLayoutWidget);
        diff->setObjectName(QStringLiteral("diff"));

        gridLayout_2->addWidget(diff, 7, 1, 1, 1);

        load = new QPushButton(gridLayoutWidget);
        load->setObjectName(QStringLiteral("load"));

        gridLayout_2->addWidget(load, 11, 2, 1, 1);

        infeg = new QPushButton(gridLayoutWidget);
        infeg->setObjectName(QStringLiteral("infeg"));

        gridLayout_2->addWidget(infeg, 8, 1, 1, 1);

        sup = new QPushButton(gridLayoutWidget);
        sup->setObjectName(QStringLiteral("sup"));

        gridLayout_2->addWidget(sup, 7, 2, 1, 1);

        egal = new QPushButton(gridLayoutWidget);
        egal->setObjectName(QStringLiteral("egal"));

        gridLayout_2->addWidget(egal, 7, 0, 1, 1);

        et = new QPushButton(gridLayoutWidget);
        et->setObjectName(QStringLiteral("et"));

        gridLayout_2->addWidget(et, 9, 0, 1, 1);

        supeg = new QPushButton(gridLayoutWidget);
        supeg->setObjectName(QStringLiteral("supeg"));

        gridLayout_2->addWidget(supeg, 8, 2, 1, 1);

        inf = new QPushButton(gridLayoutWidget);
        inf->setObjectName(QStringLiteral("inf"));

        gridLayout_2->addWidget(inf, 8, 0, 1, 1);

        ou = new QPushButton(gridLayoutWidget);
        ou->setObjectName(QStringLiteral("ou"));

        gridLayout_2->addWidget(ou, 9, 1, 1, 1);

        non = new QPushButton(gridLayoutWidget);
        non->setObjectName(QStringLiteral("non"));

        gridLayout_2->addWidget(non, 9, 2, 1, 1);

        load_test = new QPushButton(gridLayoutWidget);
        load_test->setObjectName(QStringLiteral("load_test"));

        gridLayout_2->addWidget(load_test, 12, 2, 1, 1);

        save = new QPushButton(gridLayoutWidget);
        save->setObjectName(QStringLiteral("save"));

        gridLayout_2->addWidget(save, 11, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 10, 0, 1, 1, Qt::AlignRight);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 11, 0, 1, 1, Qt::AlignRight);

        undo = new QPushButton(gridLayoutWidget);
        undo->setObjectName(QStringLiteral("undo"));

        gridLayout_2->addWidget(undo, 10, 1, 1, 1);


        horizontalLayout_2->addWidget(clavierEtendu);

        tabWidget->addTab(calc, QString());
        var = new QWidget();
        var->setObjectName(QStringLiteral("var"));
        verticalLayoutWidget_3 = new QWidget(var);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 731, 511));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        vueVar = new QTableWidget(verticalLayoutWidget_3);
        vueVar->setObjectName(QStringLiteral("vueVar"));
        vueVar->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(vueVar);

        majAtome = new QPushButton(verticalLayoutWidget_3);
        majAtome->setObjectName(QStringLiteral("majAtome"));

        verticalLayout_3->addWidget(majAtome);

        tabWidget->addTab(var, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayoutWidget_4 = new QWidget(tab);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 731, 511));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(verticalLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        vueProg = new QComboBox(verticalLayoutWidget_4);
        vueProg->setObjectName(QStringLiteral("vueProg"));

        horizontalLayout_6->addWidget(vueProg);

        progSaveButton = new QPushButton(verticalLayoutWidget_4);
        progSaveButton->setObjectName(QStringLiteral("progSaveButton"));

        horizontalLayout_6->addWidget(progSaveButton);


        verticalLayout_5->addLayout(horizontalLayout_6);

        progCopy = new QLineEdit(verticalLayoutWidget_4);
        progCopy->setObjectName(QStringLiteral("progCopy"));
        progCopy->setReadOnly(true);

        verticalLayout_5->addWidget(progCopy);

        progEdit = new QTextEdit(verticalLayoutWidget_4);
        progEdit->setObjectName(QStringLiteral("progEdit"));

        verticalLayout_5->addWidget(progEdit);

        tabWidget->addTab(tab, QString());
        QComputer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QComputer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QComputer->setStatusBar(statusbar);

        retranslateUi(QComputer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QComputer);
    } // setupUi

    void retranslateUi(QMainWindow *QComputer)
    {
        QComputer->setWindowTitle(QApplication::translate("QComputer", "UTComputer", 0));
        checkAnalyser->setText(QApplication::translate("QComputer", "Afficher l'analyseur de commandes", 0));
        label_5->setText(QApplication::translate("QComputer", "Taille de la pile :", 0));
        suppr->setText(QApplication::translate("QComputer", "C", 0));
        enter->setText(QApplication::translate("QComputer", "Ok", 0));
        soustraire->setText(QApplication::translate("QComputer", "-", 0));
        multiplier->setText(QApplication::translate("QComputer", "x", 0));
        point->setText(QApplication::translate("QComputer", ".", 0));
        diviser->setText(QApplication::translate("QComputer", "/", 0));
        space->setText(QApplication::translate("QComputer", "_", 0));
        additionner->setText(QApplication::translate("QComputer", "+", 0));
        evaluer->setText(QApplication::translate("QComputer", "EVAL", 0));
        stocker->setText(QApplication::translate("QComputer", "STO", 0));
        trois->setText(QApplication::translate("QComputer", "3", 0));
        cinq->setText(QApplication::translate("QComputer", "5", 0));
        six->setText(QApplication::translate("QComputer", "6", 0));
        quatre->setText(QApplication::translate("QComputer", "4", 0));
        un->setText(QApplication::translate("QComputer", "1", 0));
        neuf->setText(QApplication::translate("QComputer", "9", 0));
        deux->setText(QApplication::translate("QComputer", "2", 0));
        zero->setText(QApplication::translate("QComputer", "0", 0));
        huit->setText(QApplication::translate("QComputer", "8", 0));
        sept->setText(QApplication::translate("QComputer", "7", 0));
        boutonClavier->setText(QApplication::translate("QComputer", ">", 0));
        dup->setText(QApplication::translate("QComputer", "DUP", 0));
        lastargs->setText(QApplication::translate("QComputer", "LASTARGS", 0));
        dollar->setText(QApplication::translate("QComputer", "$", 0));
        lastop->setText(QApplication::translate("QComputer", "LASTOP", 0));
        clear->setText(QApplication::translate("QComputer", "CLEAR", 0));
        drop->setText(QApplication::translate("QComputer", "DROP", 0));
        neg->setText(QApplication::translate("QComputer", "NEG", 0));
        num->setText(QApplication::translate("QComputer", "NUM", 0));
        im->setText(QApplication::translate("QComputer", "IM", 0));
        swap->setText(QApplication::translate("QComputer", "SWAP", 0));
        den->setText(QApplication::translate("QComputer", "DEN", 0));
        re->setText(QApplication::translate("QComputer", "RE", 0));
        mod->setText(QApplication::translate("QComputer", "MOD", 0));
        redo->setText(QApplication::translate("QComputer", "REDO", 0));
        div->setText(QApplication::translate("QComputer", "DIV", 0));
        diff->setText(QApplication::translate("QComputer", "!=", 0));
        load->setText(QApplication::translate("QComputer", "LOAD XML", 0));
        infeg->setText(QApplication::translate("QComputer", "=<", 0));
        sup->setText(QApplication::translate("QComputer", ">", 0));
        egal->setText(QApplication::translate("QComputer", "=", 0));
        et->setText(QApplication::translate("QComputer", "AND", 0));
        supeg->setText(QApplication::translate("QComputer", ">=", 0));
        inf->setText(QApplication::translate("QComputer", "<", 0));
        ou->setText(QApplication::translate("QComputer", "OR", 0));
        non->setText(QApplication::translate("QComputer", "NOT", 0));
        load_test->setText(QApplication::translate("QComputer", "LOAD Test", 0));
        save->setText(QApplication::translate("QComputer", "SAVE XML", 0));
        label->setText(QApplication::translate("QComputer", "Memento :", 0));
        label_2->setText(QApplication::translate("QComputer", "Sauvegarde :", 0));
        undo->setText(QApplication::translate("QComputer", "UNDO", 0));
        tabWidget->setTabText(tabWidget->indexOf(calc), QApplication::translate("QComputer", "Calculatrice", 0));
        majAtome->setText(QApplication::translate("QComputer", "Mettre \303\240 jour les variables", 0));
        tabWidget->setTabText(tabWidget->indexOf(var), QApplication::translate("QComputer", "Variables", 0));
        label_3->setText(QApplication::translate("QComputer", "S\303\251lectionnez un programme \303\240 \303\251diter :", 0));
        progSaveButton->setText(QApplication::translate("QComputer", "Save", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QComputer", "Programmes", 0));
    } // retranslateUi

};

namespace Ui {
    class QComputer: public Ui_QComputer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
