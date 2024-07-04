#ifndef PC_MENU_H
#define PC_MENU_H
#include "Including.h"

class Navbaria_Menu : public QObject
{
    Q_OBJECT
public:

    Navbaria_Menu(QWidget *widget = nullptr);
    void Call_widget();

public slots:
    void clickButton();

private:
    QPushButton *main_button;
    QWidget *WMenu;
    bool clickCheker = false;
};

#endif // PC_MENU_H
