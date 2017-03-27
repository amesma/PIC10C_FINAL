#include <minebutton.h>

mineButton::mineButton(QString q) : QPushButton(q)
{
    pushed = false;
}

mineButton::~mineButton(){

}

bool mineButton::is_pushed(){
    return pushed;
}

void mineButton::set_pushed(bool push)
{
    pushed = push;
}
