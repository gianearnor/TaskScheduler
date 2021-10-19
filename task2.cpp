#include "task2.h"

task2::task2(const QString title, int frequency, QWidget *parent)
    : genericTask(title, parent)
{
    this->frequency = frequency;
    QLabel *labelTask = new QLabel(title);
    QLabel *labelText = new QLabel(tr("File to be checked"));
    QString string = "Task frequency: " + QString::number(frequency) + " seconds";
    QLabel *labelPeriod = new QLabel(string);
    QPushButton *textButton = new QPushButton(tr("click to insert file"));
    connect(textButton, &QAbstractButton::clicked, this, &task2::selectedFile);
//    textLineEdit->setPlaceholderText("");
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(labelTask, 0, 0, Qt::AlignLeft);
    layout->addWidget(labelText, 1, 0);
    layout->addWidget(textButton, 1, 1);
    layout->addWidget(labelPeriod, 2, 0);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &task2::run);
    timer->start(1000*frequency);
    setLayout(layout);
}

void task2::run()
{
    if (!QFile::exists(file))
        qDebug() << "Warning: file " + file + " not found!";
}

void task2::selectedFile()
{
    bool ok;
    file = QInputDialog::getText(this, tr("Insert a file"), "", QLineEdit::Normal, file, &ok);

}
