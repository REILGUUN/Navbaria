#ifndef PC_MENU_H
#define PC_MENU_H
#include "Including.h"

class Navbaria_Menu : public QObject
{
    Q_OBJECT
public:

    Navbaria_Menu(QWidget *widget = nullptr);
private:
    QPushButton *main_button;
};

#endif // PC_MENU_H
