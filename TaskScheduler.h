#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QAction>
#include <QStyle>
#include <QMessageBox>
#include <QMenu>
#include <QCoreApplication>
#include "genericTask.h"

class TaskScheduler : public QDialog
{
    Q_OBJECT

public:
    TaskScheduler(QList<genericTask*> tasks, QDialog *parent = nullptr);

protected:
    void closeEvent(QCloseEvent * event);

private slots:
    void run();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void messageClicked();

private:
    QList<genericTask*> _tasks;
    void createActions();
    void createTrayIcon();

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

};

#endif // SCHEDULER_H
