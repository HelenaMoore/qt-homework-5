#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sw = new Stopwatch(this);

    connect(sw, &Stopwatch::sig_sendTimeSignal, this, &MainWindow::rcv_TimeSignal);

    ui->pBtn_start_stop->setCheckable(true);
    ui->pBtn_loop->setEnabled(false);

    connect(ui->pBtn_start_stop, &QPushButton::clicked, this, &MainWindow::rcv_StartStopSignal);

    connect(ui->pBtn_loop, &QPushButton::clicked, this, &MainWindow::rcv_LoopSignal);

    connect(ui->pBtn_clear, &QPushButton::clicked, this, &MainWindow::rcv_ClearSignal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rcv_TimeSignal()
{
    ui->lb_time->setText(sw->timeToString());
}

void MainWindow::rcv_StartStopSignal()
{
    if(!sw->getStarted())
    {
        sw->startTimer();
        ui->pBtn_start_stop->setText("Стоп");
        ui->pBtn_loop->setEnabled(true);
    } else
    {
        sw->stopTimer();
        ui->pBtn_start_stop->setText("Старт");
        ui->pBtn_loop->setEnabled(false);
    }
}

void MainWindow::rcv_LoopSignal()
{
    ui->txtBr_loopData->append("Круг " + sw->loopToString() + ", время: " + sw->loopTimeToString() + " сек");
    sw->nextLoop();
}

void MainWindow::rcv_ClearSignal()
{
    sw->clear();
    ui->txtBr_loopData->clear();
    ui->lb_time->setText("0.0");
}

