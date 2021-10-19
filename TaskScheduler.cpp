#include "TaskScheduler.h"

TaskScheduler::TaskScheduler(QList<genericTask*> tasks, QDialog *parent)
    : QDialog(parent)
{
    _tasks = tasks;

    QGridLayout *layout = new QGridLayout;
    int counter = 0;
    QLabel *windowLabel = new QLabel(tr("When this window is closed the program will keep running in the "
                                        "system tray."));
    layout->addWidget(windowLabel,0,0,Qt::AlignLeft);
    foreach(genericTask* task, _tasks) {
        QGroupBox *tmp_tasksGroupBox = new QGroupBox();
        QGridLayout *tmp_tasksLayout = new QGridLayout;
        tmp_tasksLayout->addWidget(task, 0, 0, Qt::AlignCenter);
        tmp_tasksGroupBox->setLayout(tmp_tasksLayout);
        layout->addWidget(tmp_tasksGroupBox, counter+1, 0);
        counter++;
    }
    setLayout(layout);
    setWindowTitle("TaskScheduler");

    createActions();
    createTrayIcon();

    connect(trayIcon, &QSystemTrayIcon::messageClicked, this, &TaskScheduler::messageClicked);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &TaskScheduler::iconActivated);
    trayIcon->show();
}

void TaskScheduler::run()
{
    foreach(genericTask* task, _tasks) {
        task->run();
    }
}

void TaskScheduler::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        if(!this->isVisible()){
            this->show();
        } else {
            this->hide();
        }
        break;
    default:
        break;
    }
}

void TaskScheduler::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        QMessageBox::information(this, tr("Systray"),
                                 tr("The program will keep running in the "
                                    "system tray. To terminate the program, "
                                    "choose <b>Quit</b> in the context menu "
                                    "of the system tray entry."));
        hide();
        event->ignore();
    }
}

void TaskScheduler::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, this, &QCoreApplication::quit);
}

void TaskScheduler::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setContextMenu(trayIconMenu);
}

void TaskScheduler::messageClicked()
{
    QMessageBox::information(0, tr("Systray"),
                             tr("Sorry, I already gave what help I could.\n"
                                "Maybe you should try asking a human?"));
}


