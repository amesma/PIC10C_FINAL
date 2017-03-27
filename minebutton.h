<<<<<<< HEAD
#ifndef MINEBUTTON_H
#define MINEBUTTON_H

#endif // MINEBUTTON_H

#include <QPushButton>

class mineButton: public QPushButton{

public:
    mineButton();
    ~mineButton();
private:
};
=======
#ifndef MINEBUTTON_H
#define MINEBUTTON_H

#endif // MINEBUTTON_H

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
>>>>>>> 57ba17f1bcd65f64ccdd5d1cdc8f329f58da0ba0
