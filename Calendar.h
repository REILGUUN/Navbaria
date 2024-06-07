#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar
{

public:
    Calendar(QWidget *widget);
    void create_calendar();
    void show_calendar();
    void hide_calendar();
    QWidget *calendar;
};

#endif // CALENDAR_H
