#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Stopwatch *sw;

private slots:
    void rcv_TimeSignal();
    void rcv_StartStopSignal();
    void rcv_LoopSignal();
    void rcv_ClearSignal();
};
#endif // MAINWINDOW_H
