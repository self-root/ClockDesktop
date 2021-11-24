#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::ApplicationModal);
}

void Dialog::mouseMoveEvent(QMouseEvent *e)
{
    if (previous_y < 40)
    {
        QCursor curs(Qt::SizeAllCursor);
        setCursor(curs);
        move(e->globalX() - previous_x, e->globalY() - previous_y);
    }
}

void Dialog::mousePressEvent(QMouseEvent *e)
{
    previous_x = e->x();
    previous_y = e->y();
}

void Dialog::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->y() < 40 && e->button() == Qt::LeftButton)
        setCursor(Qt::ArrowCursor);
}
