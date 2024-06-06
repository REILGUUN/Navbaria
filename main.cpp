#include "Including.h"
#include "Calendar.h"

void Updating(Clock_me tester)
{
    while(true)
    {
      tester.update_clock();
      Sleep(100);
    }
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    QWidget calendar;
    QWidget *replicant = &widget;
    QWidget *replicant_calendar = &calendar;

    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // Taskbar style
      int navbar_height = screenGeometry.height() * 0.03;
      widget.setGeometry(0, 0, screenGeometry.width(), navbar_height);
      widget.setMaximumHeight(navbar_height);
      widget.setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); //Qt::WindowStaysOnTopHint
      widget.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
      widget.setWindowOpacity(0.75);
      widget.setStyleSheet("background-color:black;");


//      QGraphicsBlurEffect* p_blur = new QGraphicsBlurEffect;
//      p_blur->setBlurRadius(2);
//      p_blur->setBlurHints(QGraphicsBlurEffect::QualityHint);
//      widget.setGraphicsEffect(p_blur);

      // Call a creation of the clock on task bar
      Clock_me tester(*replicant);
        tester.create_clock(*replicant);
        Calendar OCL_calendar;
        OCL_calendar.create_calendar(*replicant_calendar);

      // Call thread in infinity loop to update clock each second
        std::thread idinaxuy (Updating, tester);

        // Create a system tray icon
        QSystemTrayIcon trayIcon(QIcon(":/_ccdff14b-7660-4960-920a-28d4f44789e0.ico"));
        trayIcon.setToolTip("Linux Navbar"); // Set the tooltip text

        // Create a context menu for the system tray icon
        QMenu *trayMenu = new QMenu;
        QAction *quitAction = trayMenu->addAction("Quit");
        QObject::connect(quitAction, &QAction::triggered, &app, &QCoreApplication::quit);
        trayIcon.setContextMenu(trayMenu);

      // Show widget and do thread detached
        widget.show();
        calendar.show();
        idinaxuy.detach();
        trayIcon.show();



    return app.exec();
}
