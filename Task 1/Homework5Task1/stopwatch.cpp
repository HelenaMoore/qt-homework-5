#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) : QObject{parent}
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::rcv_receiveTimeUpdateSignal);
}

Stopwatch::~Stopwatch()
{
    delete timer;
}

void Stopwatch::startTimer()
{
    timer->start(interval);
    started = true;
}

void Stopwatch::stopTimer()
{
    timer->stop();
    started = false;
}

void Stopwatch::clear()
{
    time = 0.0;
    loop_time = 0.0;
    loop = 1;
}
void Stopwatch::nextLoop()
{
    ++loop;
    loop_time = 0;
}

int Stopwatch::getInterval() { return interval; }
double Stopwatch::getTime() { return time; }
int Stopwatch::getLoop() { return loop; }
double Stopwatch::getLoopTime() { return loop_time; }
bool Stopwatch::getStarted() { return started; }

QString Stopwatch::timeToString()
{
    return QString("%1").arg(time);
}

QString Stopwatch::loopToString()
{
    return QString("%1").arg(loop);
}

QString Stopwatch::loopTimeToString()
{
    return QString("%1").arg(loop_time);
}

void Stopwatch::rcv_receiveTimeUpdateSignal()
{
    time += interval/1000;
    loop_time += interval/1000;
    emit sig_sendTimeSignal();
}
