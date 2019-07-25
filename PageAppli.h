#ifndef PAGEAPPLI_H
#define PAGEAPPLI_H

#include <QtGui>

#include <QApplication>
#include <QMainWindow>

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QString>
#include <string>
#include <QPrinter>
#include <QSlider>
#include <QStackedWidget>
#include <math.h>

#include "GrilleManuel.h"
#include "Point.h"


class PageAppli : public QWidget {
    Q_OBJECT

public:
    PageAppli();

private slots:
    void open();
    void openMotif();
    void setOpacity(int id);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *event);
    void valider();

private :
    int count = 0;
    double opacity;
    QWidget* widget;
    QGraphicsView *view;
    QGraphicsScene *scrollArea;
    QLabel *imageLabel;
    QLabel *imageMotif;
    GrilleManuel listMotifs;
    QImage imageTest;

};

#endif // PAGEAPPLI_H
