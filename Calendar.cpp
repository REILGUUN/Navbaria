#include "Including.h"
#include "Calendar.h"
#include <QCalendarWidget>

Calendar::Calendar(QWidget *widget) // Constructor who link outside widget to class widget
{
    calendar = widget;
}

void Calendar::create_calendar() // Create a style and other property
{
    //QWidget calendar_widget;
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    calendar->setStyleSheet("background-color: black;");
    calendar->setGeometry(screenGeometry.width() * 0.4, screenGeometry.height() * 0.05, screenGeometry.width() * 0.2, screenGeometry.height() * 0.25);
    calendar->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); //Qt::WindowStaysOnTopHint
    calendar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    calendar->setWindowOpacity(0.75);

    QCalendarWidget *cll = new QCalendarWidget(calendar);
    cll->setSelectedDate(QDate::currentDate());
    cll->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    QFile file(":/Styles/styles/CSS-QML/style.css"); // Assuming the file is in the resources
    if(file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString stylesheet = stream.readAll();
        cll->setStyleSheet(stylesheet);
        file.close();
    }
    cll->setFixedWidth(calendar->width());
    cll->setFixedHeight(calendar->height()*1.1);
    cll->setFirstDayOfWeek(Qt::Monday);
    QTextCharFormat weekendFormat;
    weekendFormat.setForeground(Qt::white); // Set the text color to red
    cll->setWeekdayTextFormat(Qt::Saturday, weekendFormat);
    cll->setWeekdayTextFormat(Qt::Sunday, weekendFormat);

// Set front
    int id = QFontDatabase::addApplicationFont(":/Fronts/styles/Fronts/RobotoMono-Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont myfont(family);
    cll->setFont(myfont);

    cll->show();
}

void Calendar::show_calendar()
{
    calendar->show();
}
void Calendar::hide_calendar()
{
    calendar->hide();
}
