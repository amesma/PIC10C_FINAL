#ifndef MINEBUTTON_H
#define MINEBUTTON_H

#include <QPushButton>

class mineButton: public QPushButton{

Q_OBJECT

public:
    mineButton(QString);
    mineButton():pushed(false){}
    ~mineButton();
    void set_pushed(bool push);
    bool is_pushed();
private:
    bool pushed;
};

#endif // MINEBUTTON_H
