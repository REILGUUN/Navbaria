#include "Including.h"

Clock_me::Clock_me(QWidget *widget) : QObject(widget)
{
    label = new QLabel();
    button = new QPushButton("MMM dd HH:mm:ss", widget);
    QObject::connect(button, &QPushButton::clicked, this, &Clock_me::handleButton);
    widget->setStyleSheet("background-color: transparent;");
}

void Clock_me::create_clock(QWidget &widget)
{
    QDateTime dateTime = dateTime.currentDateTime();
    TimeString = dateTime.toString("MMM dd HH:mm:ss");
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int id = QFontDatabase::addApplicationFont(":/RobotoMono-Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    QFontDatabase::addApplicationFont(":/RobotoMono-Bold.ttf");

//                   LABEL                   //
// Label setup
    button->setText(TimeString);
    button->setFont(font);
    //button->setFlat(true);
    button->setAttribute(Qt::WA_TranslucentBackground);
    button->setStyleSheet("QPushButton {background-color: transparent; color: white; border-radius: 10;}"
                         "QPushButton:hover { background-color : #595959; color: white;}");
    int size = screenGeometry.width() * 0.105;
    button->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); //Qt::WindowStaysOnTopHint
    int center_with_label = (screenGeometry.width() - size) / 2;
    button->setGeometry(center_with_label, 0, size, screenGeometry.height()*0.029);
    qDebug() << TimeString;
    button->show();
}

void Clock_me::handleButton() {
    qDebug() << "Button clicked!";
}

void Clock_me::update_clock() // Function witch update label based on current time
{
    QDateTime dateTime = dateTime.currentDateTime();
    TimeString = dateTime.toString("MMM dd HH:mm:ss");
    button->setText(TimeString);
    button->show();


}


