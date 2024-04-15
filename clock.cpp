#include "Including.h"
#include <QLabel>
#include <QFont>

Clock_me::Clock_me(QWidget &widget)
{
    label = new QLabel(&widget);
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
    label->setText(TimeString);
    label->setFont(font);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setStyleSheet("QLabel { background-color : black; color: white; border-radius: 10;}"
                         "QLabel:hover { background-color : #595959; color: white;}");
    int size = label->width()+20;
    int center_with_label = (screenGeometry.width() - size) / 2;
    label->setGeometry(center_with_label, 0, size, screenGeometry.height()*0.029);
    qDebug() << TimeString;
    label->show();
}

void Clock_me::update_clock() // Function witch update label based on current time
{
    QDateTime dateTime = dateTime.currentDateTime();
    TimeString = dateTime.toString("MMM dd HH:mm:ss");
    label->setText(TimeString);
    label->show();
}


