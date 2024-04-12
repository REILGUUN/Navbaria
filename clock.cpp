#include "Including.h"
#include <QLabel>
Clock_me::Clock_me(QWidget &widget)
{
    label = new QLabel(&widget);
}

void Clock_me::create_clock(QWidget &widget)
{
    TimeString = QTime::currentTime().toString();
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

//                   LABEL                   //
// Label setup
    label->setText(TimeString);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setStyleSheet("color: white;");
    int center_with_label = (screenGeometry.width() - label->width() / 2)/ 2;
    label->setGeometry(center_with_label, 0, 50, screenGeometry.height()*0.026);

    qDebug() << TimeString;
    label->show();
}

void Clock_me::update_clock() // Function witch update label based on current time
{
    TimeString = QTime::currentTime().toString();
    label->setText(TimeString);
    qDebug() << TimeString;
    label->show();
}


