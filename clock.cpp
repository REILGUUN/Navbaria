#include "Including.h"
#include "Calendar.h"
#include "Clock.h"

Clock_me::Clock_me(QWidget *widget) : QObject(widget) // Constructer of class, who create button and connect click with slot
{
    button = new QPushButton("MMM dd HH:mm:ss", widget);
    QObject::connect(button, &QPushButton::clicked, this, &Clock_me::handleButton);
}
void Clock_me::create_link(Calendar *obj) // Linking outside other class object with private class object in this class
{
    obj_clock = obj;
}

void Clock_me::create_clock(QWidget &widget) // Creating clock and make them style
{
    QDateTime dateTime = dateTime.currentDateTime();
    TimeString = dateTime.toString("MMM dd HH:mm:ss");
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int id = QFontDatabase::addApplicationFont(":/Fronts/styles/Fronts/RobotoMono-Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    QFontDatabase::addApplicationFont(":/Fronts/styles/Fronts/RobotoMono-Bold.ttf");

//                   BUTTON                   //
    button->setText(TimeString);
    button->setFont(font);
    button->setFlat(true);
    button->setAttribute(Qt::WA_TranslucentBackground);
    QFile file(":/Styles/styles/CSS-QML/button.style.css"); // Assuming the file is in the resources
    if(file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString stylesheet = stream.readAll();
        button->setStyleSheet(stylesheet);
        file.close();
    }

    int size = screenGeometry.width() * 0.103;
    button->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); //Qt::WindowStaysOnTopHint
    int center_with_label = (screenGeometry.width() - size) / 2;
    button->setGeometry(center_with_label, 0, size, screenGeometry.height()*0.029);
    qDebug() << TimeString;
    button->show();
}

void Clock_me::handleButton() // Function who called when click on button and show the calendar or hide
{
    clickCheker = !clickCheker;
    if(clickCheker)
    {
        obj_clock->show_calendar();
    }else
    {
        obj_clock->hide_calendar();
    }
}

void Clock_me::update_clock() // Function witch update label based on current time
{
    QDateTime dateTime = dateTime.currentDateTime();
    TimeString = dateTime.toString("MMM dd HH:mm:ss");
    button->setText(TimeString);
    button->show();

}

