#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QDebug>
#include <QPixmap>
#include "qcustomplot.h"
#include <iostream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupPlot();

public slots:
    void update_Shema(int index);
    void update_value_dial_ik(int index);
    void update_value_dial_uke(int index);

private slots:
    void on_remove_Graphs_clicked();
    void on_nagruzka_clicked();
    void on_lineEdit_R_returnPressed();
    void on_createGraphics_clicked();
    void on_dial_ib_mode_1_valueChanged(int value);
    void on_lineEdit_E_returnPressed();
    void on_horizontalSlider_nagruzka_point_valueChanged(int value);
    void on_comboBox_mode_currentIndexChanged(int index);

    void on_horizontalSlider_nagruzka_point_2_valueChanged(int value);

    void on_lineEdit_nagruzka_R_returnPressed();

    void on_lineEdit_nagruzka_E_returnPressed();

    void on_checkBox_nagruzka_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> Ik_15, Ik_30, Ik_45, Ik_60, Uke;
    QVector<double> Ib, Ube;
    QVector<double> nagruz_x, nagruz_y;
    QVector<double> running_point_x, running_point_y;
    int last_index_of_graph, func_0, func_1, func_2, func_3, w, h;
    bool init_graph_0, init_graph_1, init_graph_2, init_graph_3, legend, first_run;
    double y, E, X, Y;
    double k,b;

    double y_2, E_2, X_2, Y_2;
    double k_2,b_2;
    QVector<double> running_point_x_2, running_point_y_2;
    QVector<double> nagruz_x_2, nagruz_y_2;
};

#endif // MAINWINDOW_H
