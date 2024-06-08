#ifndef CLOCK_H
#define CLOCK_H
#include "Including.h"
#include "Calendar.h"

class Clock_me : public QObject
{
    Q_OBJECT
public:

    Clock_me(QWidget *widget = nullptr);

    void create_link(Calendar *obj);

    void create_clock(QWidget &widget);
    void update_clock();
    bool clickCheker = false;

public slots:
    void handleButton();

private:
    QLabel *label;
    QPushButton *button;
    QString TimeString;
    Calendar *obj_clock;

};


#endif // CLOCK_H
