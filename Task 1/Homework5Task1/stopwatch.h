#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QString>

class Stopwatch : public QObject
{
    Q_OBJECT

private:
    QTimer *timer = nullptr;
    double interval = 100;
    double time = 0.0;
    int loop = 1;
    double loop_time = 0.0;
    bool started = false;

public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

    void startTimer();
    void stopTimer();
    void clear();
    void nextLoop();

    int getInterval();
    double getTime();
    int getLoop();
    double getLoopTime();
    bool getStarted();

    QString timeToString();
    QString loopToString();
    QString loopTimeToString();

signals:
    void sig_sendTimeSignal();

public slots:
    void rcv_receiveTimeUpdateSignal();
};

#endif // STOPWATCH_H
