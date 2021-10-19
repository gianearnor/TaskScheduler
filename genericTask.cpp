#include "genericTask.h"

genericTask::genericTask(const QString title, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(title);

    //resize(200, 200);
}
