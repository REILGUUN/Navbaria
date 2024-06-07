#include "Including.h"
#include "Calendar.h"

void Updating(Clock_me *tester, QWidget *calendar)
{
    while(true)
    {
      tester->update_clock();
      //Sleep(100);
      //calendar->setVisible(tester->clickCheker);
      //calendar->setHidden(tester->clickCheker);


    }
}

void Calendar_call(QWidget calendar, Clock_me tester)
{
    while(true)
    {
      if(tester.clickCheker == true)
      {
          calendar.show();
      }else
      {
          calendar.hide();
      }
    }
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    //QObject* widget = new QObject;
    //QWidget* widget = new QWidget;
    QWidget calendar;
    //QWidget *replicant = &widget;
    //QWidget bbb = &widget;
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


      Calendar OCL_calendar(&calendar);
        OCL_calendar.create_calendar();

      Clock_me tester(&widget);
        tester.create_clock(widget);
        tester.create_link(&OCL_calendar);

      // Call thread in infinity loop to update clock each second
        std::thread updater (Updating, &tester, &calendar);
        //std::thread click_check(Calendar_call);

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
        updater.detach();
        //click_check.detach();
        calendar.hide();
        trayIcon.show();



    return app.exec();
}
