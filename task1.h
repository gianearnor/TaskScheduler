#ifndef TASK1_H
#define TASK1_H

#include "genericTask.h"
#include <QWidget>

class task1 : public genericTask
{
public:
    task1(const QString title, int frequency, QWidget *parent = 0);

public slots:
    void run();
    void selectedText();

private:
    int frequency; // seconds
    QTimer *timer;
    QInputDialog *text;
    QString out_text="Default Text!";
};

#endif // TASK1_H
