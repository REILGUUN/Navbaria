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


class Clock_me
{
public:
    Clock_me(QWidget &widget);
    void create_clock(QWidget &widget);
    void update_clock();
public slots:
    void handleButton();

private:
    QLabel *label;
    QPushButton *button;
    QString TimeString;
};



#endif // INCLUDING_H

