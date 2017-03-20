#ifndef MINEBUTTON_H
#define MINEBUTTON_H

#endif // MINEBUTTON_H

#include <QPushButton>

class mineButton: public QPushButton{
Q_OBJECT

public:
    mineButton(QWidget* parent);
    mineButton();
    ~mineButton();
    void mousePressEvent(QMouseEvent *e);
private:

};
