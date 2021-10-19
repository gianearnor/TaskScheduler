#include "task1.h"

task1::task1(const QString title, int frequency, QWidget *parent)
    : genericTask(title, parent)
{
    this->frequency = frequency;
    QLabel *labelTask = new QLabel(title);
    QLabel *labelText = new QLabel(tr("Text to be printed"));
    QString string = "Task frequency: " + QString::number(frequency) + " seconds";
    QLabel *labelPeriod = new QLabel(string);
    //text = new QInputDialog();
    //connect(text, &QInputDialog::textValueSelected, this, &task1::selectedText);
    QPushButton *textButton = new QPushButton(tr("click to insert text"));
    connect(textButton, &QAbstractButton::clicked, this, &task1::selectedText);
    //QInputDialog *seconds = new QInputDialog;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(labelTask, 0, 0, Qt::AlignLeft);
    layout->addWidget(labelText, 1, 0);
    layout->addWidget(textButton, 1, 1);
    layout->addWidget(labelPeriod, 2, 0);
    //layout->addWidget(seconds, 2, 1);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &task1::run);
    timer->start(1000*frequency);
    setLayout(layout);
}

void task1::run()
{
    qDebug() << out_text;
}

void task1::selectedText()
{
    bool ok;
    out_text = QInputDialog::getText(this, tr("Insert a text"),
                                     "", QLineEdit::Normal,
                                     out_text, &ok);

}

