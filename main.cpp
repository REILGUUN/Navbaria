#include "Including.h"
#include "Calendar.h"
#include "Clock.h"
#include "PC_Menu.h"

void Updating(Clock_me *tester) // Function to update clock
{
    while(true)
    {
      tester->update_clock();
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    QWidget calendar;

    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

// Taskbar style
      int navbar_height = screenGeometry.height() * 0.03;
      widget.setGeometry(0, 0, screenGeometry.width(), navbar_height);
      widget.setMaximumHeight(navbar_height);
      widget.setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); //Qt::WindowStaysOnTopHint
      widget.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
      widget.setWindowOpacity(0.7);
      widget.setStyleSheet("background-color:black;");

// Create a class object who will caling after
      Calendar OCL_calendar(&calendar);
        OCL_calendar.create_calendar();

      Clock_me tester(&widget);
        Navbaria_Menu zhora(&widget);
        tester.create_clock(widget);
        tester.create_link(&OCL_calendar);

// Create a thread who will update clock
        std::thread updater (Updating, &tester);

// Create a system tray icon
        QSystemTrayIcon trayIcon(QIcon(":/Icons/styles/Icons/_ccdff14b-7660-4960-920a-28d4f44789e0.ico"));
        trayIcon.setToolTip("Linux Navbar"); // Set the tooltip text

// Create a context menu for the system tray icon
        QMenu *trayMenu = new QMenu;
        QAction *quitAction = trayMenu->addAction("Quit");
        QObject::connect(quitAction, &QAction::triggered, &app, &QCoreApplication::quit);
        trayIcon.setContextMenu(trayMenu);

// Show widget and do thread detached
        widget.show();
        updater.detach();
        calendar.hide();
        trayIcon.show();


    return app.exec();
}

//    QGraphicsBlurEffect* p_blur = new QGraphicsBlurEffect;
//    p_blur->setBlurRadius(2);
//    p_blur->setBlurHints(QGraphicsBlurEffect::QualityHint);
//    calendar.setGraphicsEffect(p_blur);
