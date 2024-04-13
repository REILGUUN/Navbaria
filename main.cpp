#include "Including.h"
#include <windows.h>
#include <QtWidgets>

void Updating(Clock_me tester)
{
    while(true)
    {
      tester.update_clock();
      Sleep(1000);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    QWidget *replicant = &widget;
    widget.setWindowTitle("iduravbafd");

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

      // Call thread in infinity loop to update clock each second
        std::thread idinaxuy (Updating, tester);

      // Show widget and do thread detached
        widget.show();
        idinaxuy.detach();


    return a.exec();
}
