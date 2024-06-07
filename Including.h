#ifndef INCLUDING_H
#define INCLUDING_H

#include <QApplication>
#include <QWidget>
#include <QScreen>
#include <QRect>
#include <QList>
#include <QWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsBlurEffect>
#include <QCloseEvent>
#include <QProcess>
#include <QScreen>
#include<QDebug>
#include <QTimer>
#include <QDateTime>
#include <thread>
#include <QLabel>
#include <QApplication>
#include <QtWidgets>
#include <QGuiApplication>
#include <QWindow>
#include <windows.h>
#include <QtWidgets>
#include <QQuickWidget>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QLabel>
#include <QFont>
#include <QMouseEvent>
#include <QApplication>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QMetaObject>
#include "Calendar.h"


class Clock_me : public QObject
{
    Q_OBJECT
public:

    Clock_me(QWidget *widget = nullptr);

    void create_link(Calendar *obj);

    void create_clock(QWidget &widget);
    void update_clock();
    bool clickCheker = false;

public slots:
    void handleButton();

private:
    QLabel *label;
    QPushButton *button;
    QString TimeString;
    Calendar *obj_clock;

};

#endif // INCLUDING_H

