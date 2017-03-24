#ifndef MINEBUTTON_H
#define MINEBUTTON_H

#endif // MINEBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>

class mineButton: public QPushButton{

Q_OBJECT

public:
    mineButton(QWidget* parent = 0);
    mineButton(QString);

    ~mineButton();
    //void mousePressEvent(QMouseEvent*);

};
