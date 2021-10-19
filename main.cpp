#include "TaskScheduler.h"
#include "genericTask.h"
#include "task1.h"
#include "task2.h"

#include <QMenu>
#include <QApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<genericTask*> tasks;
    tasks << new task1("task1", 10);
    tasks << new task2("task2", 30);
    TaskScheduler ts(tasks);
    ts.show();
    return a.exec();
}
