#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QMouseEvent>

class Dialog : public QWidget
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

protected:
    int previous_x;
    int previous_y;

};

#endif // DIALOG_H
