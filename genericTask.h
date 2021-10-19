#ifndef GENERICTASK_H
#define GENERICTASK_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QInputDialog>
#include <QPushButton>
#include <QTimer>
#include <QtDebug>

class genericTask : public QWidget
{
    Q_OBJECT

public:
    genericTask(const QString title, QWidget *parent = 0);

public slots:
    virtual void run()=0;

private:
    QLineEdit *textLineEdit;
};

#endif // GENERICTASK_H
