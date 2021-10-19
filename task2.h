#ifndef TASK2_H
#define TASK2_H

#include "genericTask.h"
#include <QWidget>
#include <QFile>

class task2 : public genericTask
{
public:
    task2(const QString title, int frequency, QWidget *parent = 0);

public slots:
    void run();
    void selectedFile();

private:
    int frequency; // seconds
    QTimer *timer;
    QString file="C:/ESEMPIO.txt";
};

#endif // TASK2_H
