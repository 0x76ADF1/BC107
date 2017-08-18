/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_Scheme;
    QLabel *label_Ube;
    QComboBox *comboBox_mode;
    QPushButton *remove_Graphs;
    QCheckBox *nagruzka;
    QCustomPlot *graphic_Output_Characteristics;
    QCustomPlot *graphic_Input_Characteristics;
    QPushButton *createGraphics;
    QLabel *label_mode_const;
    QLabel *label_nagruzka_const;
    QLabel *label_Ub;
    QLabel *label_R_const;
    QLineEdit *lineEdit_R;
    QDial *dial_ib;
    QLabel *label_dial_value_Ib;
    QDial *dial_Uke;
    QLabel *label_dial_value_Uke;
    QLabel *label_dial_value_Ik;
    QLabel *label_E_const;
    QLineEdit *lineEdit_E;
    QDial *dial_ib_mode_1;
    QLabel *label_Uke;
    QLabel *label_OM_const;
    QLabel *label_B_const;
    QLabel *label_Ib_const;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *horizontalSlider_nagruzka_point;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_nagruzka_R;
    QLineEdit *lineEdit_nagruzka_E;
    QCheckBox *checkBox_nagruzka;
    QSlider *horizontalSlider_nagruzka_point_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_nagruzka_const_3;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 667);
        MainWindow->setMinimumSize(QSize(1300, 667));
        MainWindow->setMaximumSize(QSize(1300, 667));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_Scheme = new QLabel(centralWidget);
        label_Scheme->setObjectName(QStringLiteral("label_Scheme"));
        label_Scheme->setGeometry(QRect(700, 0, 600, 300));
        label_Scheme->setStyleSheet(QStringLiteral(""));
        label_Ube = new QLabel(centralWidget);
        label_Ube->setObjectName(QStringLiteral("label_Ube"));
        label_Ube->setGeometry(QRect(888, 141, 81, 16));
        comboBox_mode = new QComboBox(centralWidget);
        comboBox_mode->setObjectName(QStringLiteral("comboBox_mode"));
        comboBox_mode->setGeometry(QRect(10, 40, 551, 31));
        remove_Graphs = new QPushButton(centralWidget);
        remove_Graphs->setObjectName(QStringLiteral("remove_Graphs"));
        remove_Graphs->setGeometry(QRect(0, 230, 301, 71));
        nagruzka = new QCheckBox(centralWidget);
        nagruzka->setObjectName(QStringLiteral("nagruzka"));
        nagruzka->setGeometry(QRect(510, 150, 21, 21));
        graphic_Output_Characteristics = new QCustomPlot(centralWidget);
        graphic_Output_Characteristics->setObjectName(QStringLiteral("graphic_Output_Characteristics"));
        graphic_Output_Characteristics->setGeometry(QRect(650, 300, 650, 370));
        graphic_Input_Characteristics = new QCustomPlot(centralWidget);
        graphic_Input_Characteristics->setObjectName(QStringLiteral("graphic_Input_Characteristics"));
        graphic_Input_Characteristics->setGeometry(QRect(0, 300, 650, 370));
        createGraphics = new QPushButton(centralWidget);
        createGraphics->setObjectName(QStringLiteral("createGraphics"));
        createGraphics->setGeometry(QRect(300, 230, 351, 71));
        label_mode_const = new QLabel(centralWidget);
        label_mode_const->setObjectName(QStringLiteral("label_mode_const"));
        label_mode_const->setGeometry(QRect(10, 10, 111, 31));
        label_nagruzka_const = new QLabel(centralWidget);
        label_nagruzka_const->setObjectName(QStringLiteral("label_nagruzka_const"));
        label_nagruzka_const->setGeometry(QRect(390, 150, 91, 21));
        label_Ub = new QLabel(centralWidget);
        label_Ub->setObjectName(QStringLiteral("label_Ub"));
        label_Ub->setGeometry(QRect(824, 44, 81, 16));
        label_R_const = new QLabel(centralWidget);
        label_R_const->setObjectName(QStringLiteral("label_R_const"));
        label_R_const->setGeometry(QRect(390, 100, 71, 21));
        lineEdit_R = new QLineEdit(centralWidget);
        lineEdit_R->setObjectName(QStringLiteral("lineEdit_R"));
        lineEdit_R->setGeometry(QRect(460, 98, 101, 21));
        dial_ib = new QDial(centralWidget);
        dial_ib->setObjectName(QStringLiteral("dial_ib"));
        dial_ib->setGeometry(QRect(730, 130, 51, 51));
        label_dial_value_Ib = new QLabel(centralWidget);
        label_dial_value_Ib->setObjectName(QStringLiteral("label_dial_value_Ib"));
        label_dial_value_Ib->setGeometry(QRect(831, 59, 81, 20));
        dial_Uke = new QDial(centralWidget);
        dial_Uke->setObjectName(QStringLiteral("dial_Uke"));
        dial_Uke->setGeometry(QRect(1220, 90, 50, 51));
        label_dial_value_Uke = new QLabel(centralWidget);
        label_dial_value_Uke->setObjectName(QStringLiteral("label_dial_value_Uke"));
        label_dial_value_Uke->setGeometry(QRect(1038, 140, 81, 16));
        label_dial_value_Ik = new QLabel(centralWidget);
        label_dial_value_Ik->setObjectName(QStringLiteral("label_dial_value_Ik"));
        label_dial_value_Ik->setGeometry(QRect(1130, 10, 81, 16));
        label_E_const = new QLabel(centralWidget);
        label_E_const->setObjectName(QStringLiteral("label_E_const"));
        label_E_const->setGeometry(QRect(390, 120, 71, 21));
        lineEdit_E = new QLineEdit(centralWidget);
        lineEdit_E->setObjectName(QStringLiteral("lineEdit_E"));
        lineEdit_E->setGeometry(QRect(460, 118, 101, 21));
        dial_ib_mode_1 = new QDial(centralWidget);
        dial_ib_mode_1->setObjectName(QStringLiteral("dial_ib_mode_1"));
        dial_ib_mode_1->setGeometry(QRect(730, 130, 50, 51));
        label_Uke = new QLabel(centralWidget);
        label_Uke->setObjectName(QStringLiteral("label_Uke"));
        label_Uke->setGeometry(QRect(1035, 126, 81, 20));
        label_OM_const = new QLabel(centralWidget);
        label_OM_const->setObjectName(QStringLiteral("label_OM_const"));
        label_OM_const->setGeometry(QRect(570, 100, 41, 20));
        label_B_const = new QLabel(centralWidget);
        label_B_const->setObjectName(QStringLiteral("label_B_const"));
        label_B_const->setGeometry(QRect(570, 120, 31, 20));
        label_Ib_const = new QLabel(centralWidget);
        label_Ib_const->setObjectName(QStringLiteral("label_Ib_const"));
        label_Ib_const->setGeometry(QRect(800, 40, 21, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(740, 110, 21, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1110, 30, 21, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1030, 120, 31, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1230, 70, 21, 20));
        horizontalSlider_nagruzka_point = new QSlider(centralWidget);
        horizontalSlider_nagruzka_point->setObjectName(QStringLiteral("horizontalSlider_nagruzka_point"));
        horizontalSlider_nagruzka_point->setGeometry(QRect(10, 140, 291, 22));
        horizontalSlider_nagruzka_point->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 110, 61, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 110, 59, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 110, 71, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(190, 110, 59, 21));
        lineEdit_nagruzka_R = new QLineEdit(centralWidget);
        lineEdit_nagruzka_R->setObjectName(QStringLiteral("lineEdit_nagruzka_R"));
        lineEdit_nagruzka_R->setGeometry(QRect(460, 100, 101, 20));
        lineEdit_nagruzka_E = new QLineEdit(centralWidget);
        lineEdit_nagruzka_E->setObjectName(QStringLiteral("lineEdit_nagruzka_E"));
        lineEdit_nagruzka_E->setGeometry(QRect(460, 120, 101, 20));
        checkBox_nagruzka = new QCheckBox(centralWidget);
        checkBox_nagruzka->setObjectName(QStringLiteral("checkBox_nagruzka"));
        checkBox_nagruzka->setGeometry(QRect(510, 150, 21, 21));
        horizontalSlider_nagruzka_point_2 = new QSlider(centralWidget);
        horizontalSlider_nagruzka_point_2->setObjectName(QStringLiteral("horizontalSlider_nagruzka_point_2"));
        horizontalSlider_nagruzka_point_2->setGeometry(QRect(10, 140, 291, 22));
        horizontalSlider_nagruzka_point_2->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(100, 110, 61, 21));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(260, 110, 61, 21));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 110, 71, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(190, 110, 61, 21));
        label_nagruzka_const_3 = new QLabel(centralWidget);
        label_nagruzka_const_3->setObjectName(QStringLiteral("label_nagruzka_const_3"));
        label_nagruzka_const_3->setGeometry(QRect(390, 150, 91, 21));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(390, 99, 47, 20));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(390, 120, 47, 20));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(570, 100, 47, 20));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(570, 120, 47, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\265\321\200\320\270\320\274\320\265\320\275\321\202\320\260\320\273\321\214\320\275\320\276\320\265 \320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\321\217 \321\201\321\202\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272 \320\261\320\270\320\277\320\276\320\273\321\217\321\200\320\275\320\276\320\263\320\276 \321\202\321\200\320\260\320\275\320\267\320\270\321\201\321\202\320\276\321\200\320\260", 0));
        label_Scheme->setText(QString());
        label_Ube->setText(QString());
        remove_Graphs->setText(QApplication::translate("MainWindow", "\320\243\320\261\321\200\320\260\321\202\321\214 \320\262\321\201\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0));
        nagruzka->setText(QString());
        createGraphics->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\222\320\220\320\245", 0));
        label_mode_const->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\261\320\276\321\202\321\213:", 0));
        label_nagruzka_const->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\262\321\213\321\205\320\276\320\264:", 0));
        label_Ub->setText(QString());
        label_R_const->setText(QApplication::translate("MainWindow", "R:", 0));
        label_dial_value_Ib->setText(QString());
        label_dial_value_Uke->setText(QString());
        label_dial_value_Ik->setText(QString());
        label_E_const->setText(QApplication::translate("MainWindow", "E:", 0));
        label_Uke->setText(QApplication::translate("MainWindow", "      3 B", 0));
        label_OM_const->setText(QApplication::translate("MainWindow", "\320\236M", 0));
        label_B_const->setText(QApplication::translate("MainWindow", "\320\222", 0));
        label_Ib_const->setText(QApplication::translate("MainWindow", "I\320\261", 0));
        label->setText(QApplication::translate("MainWindow", "I\320\276", 0));
        label_2->setText(QApplication::translate("MainWindow", "I\320\272", 0));
        label_3->setText(QApplication::translate("MainWindow", "U\320\272\320\265", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\225\320\276", 0));
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Uke:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Ik:", 0));
        checkBox_nagruzka->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "U\320\261\321\215:", 0));
        label_12->setText(QApplication::translate("MainWindow", "Ib:", 0));
        label_nagruzka_const_3->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\262\321\205\320\276\320\264:", 0));
        label_13->setText(QApplication::translate("MainWindow", "R:", 0));
        label_14->setText(QApplication::translate("MainWindow", "E:", 0));
        label_15->setText(QApplication::translate("MainWindow", "OM", 0));
        label_16->setText(QApplication::translate("MainWindow", "B", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
