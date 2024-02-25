#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    legend=first_run=false;
    ui->setupUi(this);

    QObject::connect(ui->comboBox_mode, SIGNAL(currentIndexChanged(int)), this, SLOT(update_Shema(int)));

    QObject::connect(ui->dial_ib, SIGNAL(valueChanged(int)), this, SLOT(update_value_dial_ik(int)));
    QObject::connect(ui->dial_Uke, SIGNAL(valueChanged(int)), this, SLOT(update_value_dial_uke(int)));

    ui->lineEdit_R->setText("350");
    y=350;
    ui->lineEdit_E->setText("3");
    E=3;

    ui->lineEdit_load_R->setText("0.03");
    y_2=0.03;
    ui->lineEdit_load_E->setText("1.5");
    E_2=1.5;

    if((ui->lineEdit_R->text().toDouble() > 0) && ((ui->lineEdit_E->text().toDouble() > 0)))
    {
        E = ui->lineEdit_E->text().toDouble();
        y = ui->lineEdit_R->text().toDouble();
        circuitLoadY1.append(E / y);
        circuitLoadY1.append(0);
        circuitLoadX1.append(0);
        circuitLoadX1.append(ui->lineEdit_E->text().toDouble());
    }

    if((ui->lineEdit_load_R->text().toDouble() > 0) && ((ui->lineEdit_load_E->text().toDouble() > 0)))
    {
        E_2 = ui->lineEdit_load_E->text().toDouble();
        y_2 = ui->lineEdit_load_R->text().toDouble();
        circuitLoadY2.append(50);//( E_2 / y_2);
        circuitLoadY2.append(0);
        circuitLoadX2.append(0);
        circuitLoadX2.append(1.5);
    }

    runningPointY1.append(3);
    runningPointX1.append(0);

    runningPointY2.append(50);
    runningPointX2.append(0);

    w = ui->label_Scheme->width();
    h = ui->label_Scheme->height();

    Ib.append(0);
    Ib.append(0.1);
    Ib.append(1);
    Ib.append(5);
    Ib.append(10);
    Ib.append(20);
    Ib.append(30);
    Ib.append(40);
    Ib.append(50);
    Ib.append(60);
    Ib.append(70);

    Ube.append(0);
    Ube.append(0.529);
    Ube.append(0.57);
    Ube.append(0.612);
    Ube.append(0.63);
    Ube.append(0.648);
    Ube.append(0.658);
    Ube.append(0.666);
    Ube.append(0.672);
    Ube.append(0.677);
    Ube.append(0.681);

    Ik_15.append(0);
    Ik_15.append(0.001);
    Ik_15.append(0.002836);
    Ik_15.append(0.003147);
    Ik_15.append(0.003157);
    Ik_15.append(0.00316);
    Ik_15.append(0.003164);
    Ik_15.append(0.003167);
    Ik_15.append(0.003176);
    Ik_15.append(0.003208);
    Ik_15.append(0.00324);
    Ik_15.append(0.00328);
    Ik_15.append(0.00332);
    Ik_15.append(0.00336);

    Ik_30.append(0);
    Ik_30.append(0.001);
    Ik_30.append(0.004846);
    Ik_30.append(0.005372);
    Ik_30.append(0.00539);
    Ik_30.append(0.005396);
    Ik_30.append(0.005401);
    Ik_30.append(0.005406);
    Ik_30.append(0.005423);
    Ik_30.append(0.005477);
    Ik_30.append(0.005532);
    Ik_30.append(0.00554);
    Ik_30.append(0.0056);
    Ik_30.append(0.00565);

    Ik_45.append(0);
    Ik_45.append(0.001);
    Ik_45.append(0.006483);
    Ik_45.append(0.007195);
    Ik_45.append(0.007219);
    Ik_45.append(0.007227);
    Ik_45.append(0.007236);
    Ik_45.append(0.007241);
    Ik_45.append(0.007263);
    Ik_45.append(0.007336);
    Ik_45.append(0.007409);
    Ik_45.append(0.0074);
    Ik_45.append(0.0075);
    Ik_45.append(0.0076);

    Ik_60.append(0);
    Ik_60.append(0.001);
    Ik_60.append(0.007894);
    Ik_60.append(0.008776);
    Ik_60.append(0.008806);
    Ik_60.append(0.008816);
    Ik_60.append(0.008825);
    Ik_60.append(0.008834);
    Ik_60.append(0.00886);
    Ik_60.append(0.008949);
    Ik_60.append(0.009031);
    Ik_60.append(0.0091);
    Ik_60.append(0.0092);
    Ik_60.append(0.0093);

    Uke.append(0);
    Uke.append(0.1);
    Uke.append(0.2);
    Uke.append(0.3);
    Uke.append(0.4);
    Uke.append(0.5);
    Uke.append(0.6);
    Uke.append(0.7);
    Uke.append(1);
    Uke.append(2);
    Uke.append(3);
    Uke.append(4);
    Uke.append(5);
    Uke.append(6);

    ui->label_Scheme->setPixmap(QPixmap(":/shema.jpg", 0, Qt::AutoColor).scaled(w,h,Qt::KeepAspectRatioByExpanding));
    ui->label_Scheme->setMinimumSize(1,1);

    ui->comboBox_mode->addItem("режим 1: входная характеристика IБ = f(UБЭ)| Uкэ-const");
    ui->comboBox_mode->addItem("режим 2: выходные характеристики IК = f(UКЭ)| Uб-const");

    ui->dial_ib->setRange(0,59);
    ui->dial_ib->setSingleStep(15);

    ui->dial_Uke->setRange(0,299);
    ui->dial_Uke->setSingleStep(1);

    ui->dial_ib_mode_1->setRange(0,699);
    ui->dial_ib_mode_1->setSingleStep(1);

    init_graph_0=init_graph_1=init_graph_2=init_graph_3=false;
    setupPlot();

    k = (circuitLoadY1[1] - circuitLoadY1[0]) / (circuitLoadX1[1] - circuitLoadX1[0]);
    b = circuitLoadY1[0] - circuitLoadX1[0] * k;

    k_2 = (circuitLoadY2[1] - circuitLoadY2[0]) / (circuitLoadX2[1] - circuitLoadX2[0]);
    b_2 = circuitLoadY2[0] - circuitLoadX2[0] * k_2;

    ui->horizontalSlider_load_point->setRange(0,E*1000);

    ui->horizontalSlider_load_point_2->setRange(0,E_2*1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupPlot()
{
    ui->graphic_Output_Characteristics->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->graphic_Output_Characteristics->legend->setFont(legendFont);
    ui->graphic_Output_Characteristics->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectPlottables);
    ui->graphic_Output_Characteristics->xAxis->setRange(0,3);
    ui->graphic_Output_Characteristics->yAxis->setRange(0,0.012);
    ui->graphic_Output_Characteristics->yAxis->setLabel("Iк , mA");
    ui->graphic_Output_Characteristics->xAxis->setLabel("Uке , В");
    ui->graphic_Output_Characteristics->axisRect()->setupFullAxesBox(true);

    ui->graphic_Input_Characteristics->xAxis->setRange(0,1.6);
    ui->graphic_Input_Characteristics->yAxis->setRange(-10,80);
    ui->graphic_Input_Characteristics->axisRect()->setupFullAxesBox(true);
    ui->graphic_Input_Characteristics->yAxis->setLabel("Ib , mкA");
    ui->graphic_Input_Characteristics->xAxis->setLabel("Uбэ , В");

    ui->graphic_Input_Characteristics->addGraph();
    ui->graphic_Input_Characteristics->graph(0)->setPen(QPen(Qt::blue));
    ui->graphic_Input_Characteristics->graph(0)->setData(Ube, Ib);
    ui->graphic_Input_Characteristics->graph(0)->setVisible(false);
    ui->graphic_Input_Characteristics->replot();

    ui->graphic_Input_Characteristics->addGraph();
    ui->graphic_Input_Characteristics->graph(1)->setPen(QPen(Qt::red));
    ui->graphic_Input_Characteristics->graph(1)->setData(circuitLoadX2, circuitLoadY2);
    ui->graphic_Input_Characteristics->graph(1)->setVisible(false);
    ui->graphic_Input_Characteristics->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 7));
    ui->graphic_Input_Characteristics->replot();

    ui->graphic_Input_Characteristics->addGraph();
    ui->graphic_Input_Characteristics->graph(2)->setPen(QPen(Qt::darkYellow));
    ui->graphic_Input_Characteristics->graph(2)->setData(runningPointX2, runningPointY2);
    ui->graphic_Input_Characteristics->graph(2)->removeFromLegend();
    ui->graphic_Input_Characteristics->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Input_Characteristics->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 10));
    ui->graphic_Input_Characteristics->graph(2)->setVisible(false);
    ui->graphic_Input_Characteristics->replot();

    ui->graphic_Output_Characteristics->addGraph();
    ui->graphic_Output_Characteristics->graph(0)->setPen(QPen(Qt::red));
    ui->graphic_Output_Characteristics->graph(0)->setData(Uke, Ik_15);
    ui->graphic_Output_Characteristics->graph(0)->setName("Ib1");
    ui->graphic_Output_Characteristics->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Output_Characteristics->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkRed, Qt::white, 7));
    ui->graphic_Output_Characteristics->graph(0)->setVisible(false);
    ui->graphic_Output_Characteristics->replot();

    ui->graphic_Output_Characteristics->addGraph();
    ui->graphic_Output_Characteristics->graph(1)->setPen(QPen(Qt::green));
    ui->graphic_Output_Characteristics->graph(1)->setData(Uke, Ik_30);
    ui->graphic_Output_Characteristics->graph(1)->setName("Ib2");
    ui->graphic_Output_Characteristics->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Output_Characteristics->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGreen, Qt::white, 7));
    ui->graphic_Output_Characteristics->graph(1)->setVisible(false);
    ui->graphic_Output_Characteristics->replot();

    ui->graphic_Output_Characteristics->addGraph();
    ui->graphic_Output_Characteristics->graph(2)->setPen(QPen(Qt::blue));
    ui->graphic_Output_Characteristics->graph(2)->setData(Uke, Ik_45);
    ui->graphic_Output_Characteristics->graph(2)->setName("Ib3");
    ui->graphic_Output_Characteristics->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Output_Characteristics->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkBlue, Qt::white, 7));
    ui->graphic_Output_Characteristics->graph(2)->setVisible(false);
    ui->graphic_Output_Characteristics->replot();

    ui->graphic_Output_Characteristics->addGraph();
    ui->graphic_Output_Characteristics->graph(3)->setPen(QPen(Qt::magenta));
    ui->graphic_Output_Characteristics->graph(3)->setData(Uke, Ik_60);
    ui->graphic_Output_Characteristics->graph(3)->setName("Ib4");
    ui->graphic_Output_Characteristics->graph(3)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Output_Characteristics->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkMagenta, Qt::white, 7));
    ui->graphic_Output_Characteristics->graph(3)->setVisible(false);
    ui->graphic_Output_Characteristics->replot();


    ui->graphic_Output_Characteristics->addGraph();
    ui->graphic_Output_Characteristics->graph(4)->setPen(QPen(Qt::darkYellow));
    ui->graphic_Output_Characteristics->graph(4)->setData(circuitLoadX1, circuitLoadY1);
    ui->graphic_Output_Characteristics->graph(4)->setName("Нагрузка");
    ui->graphic_Output_Characteristics->graph(4)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Output_Characteristics->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 7));
    ui->graphic_Output_Characteristics->graph(4)->setVisible(false);
    ui->graphic_Output_Characteristics->replot();

    ui->graphic_Output_Characteristics->addGraph();
    ui->graphic_Output_Characteristics->graph(5)->setPen(QPen(Qt::darkYellow));
    ui->graphic_Output_Characteristics->graph(5)->setData(runningPointX1, runningPointY1);
    ui->graphic_Output_Characteristics->graph(5)->removeFromLegend();
    ui->graphic_Output_Characteristics->graph(5)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Output_Characteristics->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 10));
    ui->graphic_Output_Characteristics->replot();
}

void MainWindow::update_Shema(int index)
{
    w = ui->label_Scheme->width();
    h = ui->label_Scheme->height();
    if(index == 0)
        ui->label_Scheme->setPixmap(QPixmap(":/shema.jpg", 0, Qt::AutoColor).scaled(w, h, Qt::KeepAspectRatioByExpanding));
    else
        ui->label_Scheme->setPixmap(QPixmap(":/shema2.jpg", 0, Qt::AutoColor).scaled(w, h, Qt::KeepAspectRatioByExpanding));

    if(ui->comboBox_mode->currentIndex() == 0)
    {
        ui->load->hide();
        ui->lineEdit_R->hide();
        ui->dial_ib->hide();
        ui->dial_Uke->hide();
        ui->label_dial_value_Ib->hide();
        ui->label_dial_value_Uke->hide();
        ui->label_dial_value_Ik->hide();
        ui->lineEdit_E->hide();
        ui->horizontalSlider_load_point->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->load->hide();
        ui->label_load_const->hide();
        ui->label_Ib_const->hide();
        ui->label_13->hide();
        ui->label_14->hide();
        ui->label_15->hide();
        ui->label_16->hide();

        ui->label_Ube->show();
        ui->dial_ib_mode_1->show();
        ui->label_Ub->show();
        ui->label_Uke->show();
        ui->label_B_const->show();
        ui->label_OM_const->show();
        ui->label_R_const->show();
        ui->label_E_const->show();
        ui->lineEdit_load_E->show();
        ui->lineEdit_load_R->show();
        ui->label_12->show();
        ui->label_11->show();
        ui->horizontalSlider_load_point_2->show();
        ui->label_load_const_3->show();
        ui->checkBox_load->show();
        ui->label_10->show();
        ui->label_9->show();
    }
    else
    {
        ui->label_Ube->hide();
        ui->dial_ib_mode_1->hide();
        ui->label_Ub->hide();
        ui->label_Uke->hide();
        ui->label_B_const->hide();
        ui->label_OM_const->hide();
        ui->label_R_const->hide();
        ui->label_E_const->hide();
        ui->lineEdit_load_E->hide();
        ui->lineEdit_load_R->hide();
        ui->label_12->hide();
        ui->label_11->hide();
        ui->horizontalSlider_load_point_2->hide();
        ui->checkBox_load->hide();
        ui->label_load_const_3->hide();
        ui->label_10->hide();
        ui->label_9->hide();

        ui->load->show();
        ui->lineEdit_R->show();
        ui->dial_ib->show();
        ui->dial_Uke->show();
        ui->label_dial_value_Ib->show();
        ui->label_dial_value_Uke->show();
        ui->label_dial_value_Ik->show();
        ui->lineEdit_E->show();
        ui->load->show();
        ui->horizontalSlider_load_point->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_5->show();
        ui->label_6->show();
        ui->label_7->show();
        ui->label_load_const->show();
        ui->label_8->show();
        ui->label_Ib_const->show();
        ui->label_13->show();
        ui->label_14->show();
        ui->label_15->show();
        ui->label_16->show();
    }
}

void MainWindow::on_remove_Graphs_clicked()
{
    if (ui->graphic_Output_Characteristics->graphCount() > 0)
    {
        for (int i = 0; i<ui->graphic_Output_Characteristics->graphCount(); i++)
        {
            ui->graphic_Output_Characteristics->graph(i)->setVisible(false);
        }
        ui->graphic_Output_Characteristics->replot();
        init_graph_0=init_graph_1=init_graph_2=init_graph_3=false;
    }

    if (ui->graphic_Input_Characteristics->graphCount() > 0)
    {
        for (int j = 0; j<ui->graphic_Input_Characteristics->graphCount(); j++)
        {
            ui->graphic_Input_Characteristics->graph(j)->setVisible(false);
        }
        ui->graphic_Input_Characteristics->replot();
    }
}

void MainWindow::on_load_clicked()
{
    if(ui->load->isChecked())
    {
        ui->graphic_Output_Characteristics->graph(4)->setVisible(true);
        ui->graphic_Output_Characteristics->replot();
    }
    else
    {
        ui->graphic_Output_Characteristics->graph(4)->setVisible(false);
        ui->graphic_Output_Characteristics->replot();
    }
}

void MainWindow::on_lineEdit_R_returnPressed()
{
    if((ui->lineEdit_R->text().toDouble() > 0) && ((ui->lineEdit_E->text().toDouble() > 0)))
    {
        bool visible = ui->graphic_Output_Characteristics->graph(4)->visible();
        E = ui->lineEdit_E->text().toDouble();
        y = ui->lineEdit_R->text().toDouble();
        circuitLoadY1.clear();
        circuitLoadX1.clear();
        circuitLoadY1.append(E/y);
        circuitLoadY1.append(0);
        circuitLoadX1.append(0);
        circuitLoadX1.append(E);

        k = (circuitLoadY1[1] - circuitLoadY1[0]) / (circuitLoadX1[1] - circuitLoadX1[0]);
        b = circuitLoadY1[0] - circuitLoadX1[0] * k;

        double value = E*1000;

        ui->horizontalSlider_load_point->setRange(0,value);

        ui->graphic_Output_Characteristics->removeGraph(5);
        ui->graphic_Output_Characteristics->removeGraph(4);
        ui->graphic_Output_Characteristics->addGraph();
        ui->graphic_Output_Characteristics->graph(4)->setPen(QPen(Qt::darkYellow));
        ui->graphic_Output_Characteristics->graph(4)->setData(circuitLoadX1, circuitLoadY1);
        ui->graphic_Output_Characteristics->graph(4)->setName("Нагрузка");
        ui->graphic_Output_Characteristics->graph(4)->setLineStyle(QCPGraph::lsLine);
        ui->graphic_Output_Characteristics->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 7));

        ui->graphic_Output_Characteristics->addGraph();
        ui->graphic_Output_Characteristics->graph(5);
        ui->graphic_Output_Characteristics->graph(5)->setPen(QPen(Qt::darkYellow));
        ui->graphic_Output_Characteristics->graph(5)->setData(runningPointX1, runningPointY1);
        ui->graphic_Output_Characteristics->graph(5)->removeFromLegend();
        ui->graphic_Output_Characteristics->graph(5)->setLineStyle(QCPGraph::lsLine);
        ui->graphic_Output_Characteristics->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 10));

        if(!visible)
        {
            ui->graphic_Output_Characteristics->graph(4)->setVisible(false);
            ui->graphic_Output_Characteristics->replot();
        }
        else
        {
            ui->graphic_Output_Characteristics->graph(4)->setVisible(true);
            ui->graphic_Output_Characteristics->replot();
        }
    }
}

void MainWindow::update_value_dial_ik(int index)
{
    if(index<=15)      ui->label_dial_value_Ib->setText("15 mkA");
    else if(index<=30) ui->label_dial_value_Ib->setText("30 mkA");
    else if(index<=45) ui->label_dial_value_Ib->setText("45 mkA");
    else if(index<=60) ui->label_dial_value_Ib->setText("60 mkA");
    emit ui->dial_Uke->valueChanged(ui->dial_Uke->value());
}

void MainWindow::update_value_dial_uke(int index)
{
    if(index<5)
    {
        index = 0;
        ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
    }
    else if(index<=30)
    {
        index = 1;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=60)
    {
        index = 2;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=90)
    {
        index = 3;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=120)
    {
        index = 4;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=150)
    {
        index = 5;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=180)
    {
        index = 6;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=210)
    {
        index = 7;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=240)
    {
        index = 8;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=270)
    {
        index = 9;                           ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
    else if(index<=300)
    {
        index = 10;                          ui->label_dial_value_Uke->setText(QString::number(Uke[index])+" B");
        if      (ui->dial_ib->value() <= 15) ui->label_dial_value_Ik->setText(QString::number(Ik_15[index])+" mA");
        else if (ui->dial_ib->value() <= 30) ui->label_dial_value_Ik->setText(QString::number(Ik_30[index])+" mA");
        else if (ui->dial_ib->value() <= 45) ui->label_dial_value_Ik->setText(QString::number(Ik_45[index])+" mA");
        else if (ui->dial_ib->value() <= 60) ui->label_dial_value_Ik->setText(QString::number(Ik_60[index])+" mA");
    }
}

void MainWindow::on_createGraphics_clicked()
{
    ui->graphic_Input_Characteristics->graph(0)->setVisible(true);
    ui->graphic_Input_Characteristics->replot();

    if(ui->comboBox_mode->currentIndex() == 1)
    {
        int index = ui->dial_ib->value() / 15;
        //ui->graphic_Output_Characteristics->graph(4)->setVisible(true);
        switch (index) {
        case 0:
            if(!init_graph_0)
            {
                ui->graphic_Output_Characteristics->graph(0)->setVisible(true);
                ui->graphic_Output_Characteristics->replot();
                init_graph_0=true;
            }
            break;
        case 1:
            if(!init_graph_1)
            {
                ui->graphic_Output_Characteristics->graph(1)->setVisible(true);
                ui->graphic_Output_Characteristics->replot();
                init_graph_1=true;
            }
            break;
        case 2:
            if(!init_graph_2)
            {
                ui->graphic_Output_Characteristics->graph(2)->setVisible(true);
                ui->graphic_Output_Characteristics->replot();
                init_graph_2=true;
            }
            break;
        case 3:
            if(!init_graph_3)
            {
                ui->graphic_Output_Characteristics->graph(3)->setVisible(true);
                ui->graphic_Output_Characteristics->replot();
                init_graph_3=true;
            }
            break;
        default:
            break;
        }
    }
}

void MainWindow::on_dial_ib_mode_1_valueChanged(int value)
{
    if(value<=5){
        value = 0;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=70){
        value = 1;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=140){
        value = 2;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=210){
        value = 3;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=280){
        value = 4;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=350){
        value = 5;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=420){
        value = 6;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=490){
        value = 7;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=560){
        value = 8;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<=630){
        value = 9;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
    else if(value<700){
        value = 10;
        ui->label_Ube->setText(QString::number(Ube[value])+" B");
        ui->label_Ub->setText(QString::number(Ib[value])+" mkA");
    }
}

void MainWindow::on_lineEdit_E_returnPressed()
{
    if((ui->lineEdit_R->text().toDouble() > 0) && ((ui->lineEdit_E->text().toDouble() > 0)))
    {
        bool visible = ui->graphic_Output_Characteristics->graph(4)->visible();
        E = ui->lineEdit_E->text().toDouble();
        y = ui->lineEdit_R->text().toDouble();
        circuitLoadY1.clear();
        circuitLoadX1.clear();
        circuitLoadY1.append(E / y);
        circuitLoadY1.append(0);
        circuitLoadX1.append(0);
        circuitLoadX1.append(E);

        k = (circuitLoadY1[1] - circuitLoadY1[0]) / (circuitLoadX1[1] - circuitLoadX1[0]);
        b = circuitLoadY1[0] - circuitLoadX1[0] * k;

        double value = E*1000;
        
        ui->horizontalSlider_load_point->setRange(0,value);

        ui->graphic_Output_Characteristics->removeGraph(5);
        ui->graphic_Output_Characteristics->removeGraph(4);
        ui->graphic_Output_Characteristics->addGraph();
        ui->graphic_Output_Characteristics->graph(4)->setPen(QPen(Qt::darkYellow));
        ui->graphic_Output_Characteristics->graph(4)->setData(circuitLoadX1, circuitLoadY1);
        ui->graphic_Output_Characteristics->graph(4)->setName("Нагрузка");
        ui->graphic_Output_Characteristics->graph(4)->setLineStyle(QCPGraph::lsLine);
        ui->graphic_Output_Characteristics->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 7));

        ui->graphic_Output_Characteristics->addGraph();
        ui->graphic_Output_Characteristics->graph(5);
        ui->graphic_Output_Characteristics->graph(5)->setPen(QPen(Qt::darkYellow));
        ui->graphic_Output_Characteristics->graph(5)->setData(runningPointX1, runningPointY1);
        ui->graphic_Output_Characteristics->graph(5)->removeFromLegend();
        ui->graphic_Output_Characteristics->graph(5)->setLineStyle(QCPGraph::lsLine);
        ui->graphic_Output_Characteristics->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 10));

        if(!visible)
        {
            ui->graphic_Output_Characteristics->graph(4)->setVisible(false);
            ui->graphic_Output_Characteristics->replot();
        }
        else
        {
            ui->graphic_Output_Characteristics->graph(4)->setVisible(true);
            ui->graphic_Output_Characteristics->replot();
        }
    }
}

void MainWindow::on_horizontalSlider_load_point_valueChanged(int value)
{
    double point;
    double val = 1000;

    point = value/val;

    runningPointX1.clear();
    runningPointY1.clear();

    runningPointY1.append(k*point+b);
    double rez = (runningPointY1[0] - b) / k;
    runningPointX1.append(rez);
    ui->label_5->setText(QString::number(rez));
    ui->label_6->setText(QString::number(k*point+b));

    ui->graphic_Output_Characteristics->removeGraph(5);
    ui->graphic_Output_Characteristics->addGraph();
    ui->graphic_Output_Characteristics->graph(5);

    ui->graphic_Output_Characteristics->graph(5)->setPen(QPen(Qt::darkYellow));
    ui->graphic_Output_Characteristics->graph(5)->setData(runningPointX1, runningPointY1);
    ui->graphic_Output_Characteristics->graph(5)->removeFromLegend();
    ui->graphic_Output_Characteristics->graph(5)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Output_Characteristics->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 10));
    ui->graphic_Output_Characteristics->replot();
}

void MainWindow::on_comboBox_mode_currentIndexChanged(int index)
{
    if (ui->graphic_Output_Characteristics->graphCount() > 0)
    {
        for (int i = 0; i<ui->graphic_Output_Characteristics->graphCount(); i++)
        {
            ui->graphic_Output_Characteristics->graph(i)->setVisible(false);
        }
        ui->graphic_Output_Characteristics->replot();
        init_graph_0=init_graph_1=init_graph_2=init_graph_3=false;
    }
}

void MainWindow::on_horizontalSlider_load_point_2_valueChanged(int value)
{
    double point;
    double val = 1000;

    point = value/val;

    runningPointX2.clear();
    runningPointY2.clear();

    runningPointY2.append(k_2*point+b_2);
    double rez = (runningPointY2[0] - b_2) / k_2;
    runningPointX2.append(rez);
    ui->label_9->setText(QString::number(rez));
    ui->label_10->setText(QString::number(k_2*point+b_2));

    ui->graphic_Input_Characteristics->removeGraph(2);
    ui->graphic_Input_Characteristics->addGraph();
    ui->graphic_Input_Characteristics->graph(2)->setPen(QPen(Qt::darkYellow));
    ui->graphic_Input_Characteristics->graph(2)->setData(runningPointX2, runningPointY2);
    ui->graphic_Input_Characteristics->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->graphic_Input_Characteristics->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 10));
    ui->graphic_Input_Characteristics->replot();
}

void MainWindow::on_lineEdit_load_R_returnPressed()
{
    if((ui->lineEdit_load_R->text().toDouble() > 0) && ((ui->lineEdit_load_E->text().toDouble() > 0)))
    {
        bool visible = ui->graphic_Input_Characteristics->graph(1)->visible();
        E_2 = ui->lineEdit_load_E->text().toDouble();
        y_2 = ui->lineEdit_load_R->text().toDouble();
        circuitLoadY2.clear();
        circuitLoadX2.clear();
        circuitLoadY2.append(E_2 / y_2);
        circuitLoadY2.append(0);
        circuitLoadX2.append(0);
        circuitLoadX2.append(E_2);

        k_2 = (circuitLoadY2[1] - circuitLoadY2[0]) / (circuitLoadX2[1] - circuitLoadX2[0]);
        b_2 = circuitLoadY2[0] - circuitLoadX2[0] * k_2;

        double value = E_2*1000;

        ui->horizontalSlider_load_point_2->setRange(0,value);

        ui->graphic_Input_Characteristics->removeGraph(2);
        ui->graphic_Input_Characteristics->removeGraph(1);
        ui->graphic_Input_Characteristics->addGraph();
        ui->graphic_Input_Characteristics->graph(1)->setPen(QPen(Qt::red));
        ui->graphic_Input_Characteristics->graph(1)->setData(circuitLoadX2, circuitLoadY2);
        ui->graphic_Input_Characteristics->graph(1)->setName("Нагрузка");
        ui->graphic_Input_Characteristics->graph(1)->setLineStyle(QCPGraph::lsLine);
        ui->graphic_Input_Characteristics->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 7));

        ui->graphic_Input_Characteristics->addGraph();
        ui->graphic_Input_Characteristics->graph(2)->setPen(QPen(Qt::red));
        ui->graphic_Input_Characteristics->graph(2)->setData(runningPointX2, runningPointY2);
        ui->graphic_Input_Characteristics->graph(2)->setLineStyle(QCPGraph::lsLine);
        ui->graphic_Input_Characteristics->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 10));

        if(!visible)
        {
            ui->graphic_Input_Characteristics->graph(1)->setVisible(false);
            ui->graphic_Input_Characteristics->replot();
        }
        else
        {
            ui->graphic_Input_Characteristics->graph(1)->setVisible(true);
            ui->graphic_Input_Characteristics->replot();
        }
    }
}

void MainWindow::on_lineEdit_load_E_returnPressed()
{
    if((ui->lineEdit_load_R->text().toDouble() > 0) && ((ui->lineEdit_load_E->text().toDouble() > 0)))
    {
        bool visible = ui->graphic_Input_Characteristics->graph(1)->visible();
        E_2 = ui->lineEdit_load_E->text().toDouble();
        y_2 = ui->lineEdit_load_R->text().toDouble();
        circuitLoadY2.clear();
        circuitLoadX2.clear();
        circuitLoadY2.append(E_2 / y_2);
        circuitLoadY2.append(0);
        circuitLoadX2.append(0);
        circuitLoadX2.append(E_2);

        k_2 = (circuitLoadY2[1] - circuitLoadY2[0]) / (circuitLoadX2[1] - circuitLoadX2[0]);
        b_2 = circuitLoadY2[0] - circuitLoadX2[0] * k_2;

        double value = E_2*1000;

        ui->horizontalSlider_load_point_2->setRange(0,value);

        ui->graphic_Input_Characteristics->removeGraph(2);
        ui->graphic_Input_Characteristics->removeGraph(1);
        ui->graphic_Input_Characteristics->addGraph();
        ui->graphic_Input_Characteristics->graph(1)->setPen(QPen(Qt::red));
        ui->graphic_Input_Characteristics->graph(1)->setData(circuitLoadX2, circuitLoadY2);
        ui->graphic_Input_Characteristics->graph(1)->setName("Нагрузка");
        ui->graphic_Input_Characteristics->graph(1)->setLineStyle(QCPGraph::lsLine);
        ui->graphic_Input_Characteristics->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 7));

        ui->graphic_Input_Characteristics->addGraph();
        ui->graphic_Input_Characteristics->graph(2)->setPen(QPen(Qt::red));
        ui->graphic_Input_Characteristics->graph(2)->setData(runningPointX2, runningPointY2);
        ui->graphic_Input_Characteristics->graph(2)->setLineStyle(QCPGraph::lsLine);
        ui->graphic_Input_Characteristics->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::darkGray, Qt::gray, 10));

        if(!visible)
        {
            ui->graphic_Input_Characteristics->graph(1)->setVisible(false);
            ui->graphic_Input_Characteristics->replot();
        }
        else
        {
            ui->graphic_Input_Characteristics->graph(1)->setVisible(true);
            ui->graphic_Input_Characteristics->replot();
        }
    }
}

void MainWindow::on_checkBox_load_clicked()
{
    if(ui->checkBox_load->isChecked())
    {
        ui->graphic_Input_Characteristics->graph(1)->setVisible(true);
        ui->graphic_Input_Characteristics->replot();
    }
    else
    {
        ui->graphic_Input_Characteristics->graph(1)->setVisible(false);
        ui->graphic_Input_Characteristics->replot();
    }
}
