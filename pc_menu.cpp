#include "PC_Menu.h"
#include "Including.h"

Navbaria_Menu::Navbaria_Menu(QWidget *widget) : QObject(widget) // Constructer of class, who create button and connect click with slot
{
    main_button = new QPushButton(" ", widget);

    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int place = (screenGeometry.width() - screenGeometry.width() * 0.05) - 10;
    main_button->setGeometry(place, 0, screenGeometry.width() * 0.05, screenGeometry.height()*0.029);
    QFile file(":/Styles/styles/CSS-QML/main_button.css"); // Assuming the file is in the resources
    if(file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString stylesheet = stream.readAll();
        main_button->setStyleSheet(stylesheet);
        file.close();
    }

    QHBoxLayout *iconLayout = new QHBoxLayout(main_button);
    iconLayout->setContentsMargins(0,0,0,0);


    QPixmap icon1(":/Icons/styles/Icons/volume_up.svg");
    QPixmap icon2(":/Icons/styles/Icons/bluetooth.svg");
    QPixmap icon3(":/Icons/styles/Icons/power_settings_new.svg");
    icon1 = icon1.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    icon2 = icon2.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    icon3 = icon3.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QLabel *label1 = new QLabel;
    label1->setPixmap(icon1);
    label1->setAlignment(Qt::AlignCenter);
    label1->setStyleSheet("background-color: transparent;");


    QLabel *label2 = new QLabel;
    label2->setPixmap(icon2);
    label2->setAlignment(Qt::AlignCenter);
    label2->setStyleSheet("background-color: transparent;");

    QLabel *label3 = new QLabel;
    label3->setPixmap(icon3);
    label3->setAlignment(Qt::AlignCenter);
    label3->setStyleSheet("background-color: transparent;");

    iconLayout->addWidget(label1);
    iconLayout->addWidget(label2);
    iconLayout->addWidget(label3);


    main_button->setLayout(iconLayout);

    main_button->show();
}
