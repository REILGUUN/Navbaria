#include "Including.h"
#include "Calendar.h"

Clock_me::Clock_me(QWidget *widget) : QObject(widget)
{
    //label = new QLabel();
    button = new QPushButton("MMM dd HH:mm:ss", widget);
    QObject::connect(button, &QPushButton::clicked, this, &Clock_me::handleButton);
}
void Clock_me::create_link(Calendar *obj)
{
    obj_clock = obj;
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
    button->setFlat(true);
    button->setAttribute(Qt::WA_TranslucentBackground);
    QFile file(":/styles/CSS-QML/button.style.css"); // Assuming the file is in the resources
    if(file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString stylesheet = stream.readAll();
        button->setStyleSheet(stylesheet);
        file.close();
    }
//    button->setStyleSheet("QPushButton {background-color:  rgba(0, 0, 0, 0);; border: 0px; color: white; border-radius: 10;}"
//                         "QPushButton:hover { background-color: #595959; color: white;}");
    int size = screenGeometry.width() * 0.103;
    button->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); //Qt::WindowStaysOnTopHint
    int center_with_label = (screenGeometry.width() - size) / 2;
    button->setGeometry(center_with_label, 0, size, screenGeometry.height()*0.029);
    qDebug() << TimeString;
    button->show();
}

void Clock_me::handleButton() {
    qDebug() << "Button clicked!";
    clickCheker = !clickCheker;
    qDebug() << clickCheker;
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

