#include "PageAppli.h"

#include <QFileDialog>
#include <QAction>
#include <QMessageBox>
#include <QPrintDialog>
#include <QScrollBar>

PageAppli::PageAppli(){

    widget = new QWidget(this);
    view = new QGraphicsView(widget);
    QGridLayout *layout = new QGridLayout(widget);

    QGroupBox *boxButton = new QGroupBox(widget);
    QGridLayout *boxLayout = new QGridLayout(boxButton);
    boxButton->setFixedSize(200,768);
    layout->addWidget(boxButton,0,0,1,1);
    boxLayout->setAlignment(Qt::AlignTop);


    QPushButton* ouvrir = new QPushButton("Ouvrir image");
    boxLayout->addWidget(ouvrir,0,0,1,1);

    QPushButton* ouvrirMotif = new QPushButton("Ouvrir motif");
    boxLayout->addWidget(ouvrirMotif,1,0,1,1);

    QPushButton* valider = new QPushButton("Valider");
    boxLayout->addWidget(valider,6,0,1,1);

    QLabel* opaciteText = new QLabel("Opacité : ",boxButton);
    QSlider* opacite = new QSlider(Qt::Horizontal,boxButton);
    opacite->setMinimum(0);
    opacite->setMaximum(100);

    boxLayout->addWidget(opaciteText,3,0,1,1);
    boxLayout->addWidget(opacite,4,0,1,1);

    widget->setFixedSize(1366,768);
    widget->setMaximumSize(1366,768);
    widget->setLayout(layout);

    imageLabel = new QLabel;
         imageLabel->setBackgroundRole(QPalette::Base);
         imageLabel->setScaledContents(true);

    imageMotif = new QLabel;
         imageMotif->setBackgroundRole(QPalette::Base);
         imageMotif->setScaledContents(true);

         scrollArea = new QGraphicsScene(this);
         view->setScene(scrollArea);

         //scrollArea->setStyleSheet("background-color:transparent;");
         //scrollArea->setWidgetResizable(true);
         //scrollArea->addWidget(imageLabel);




    layout->addWidget(view,0,1,1,1);

    connect(ouvrir, SIGNAL(clicked()), this, SLOT(open()));
    connect(ouvrirMotif,SIGNAL(clicked()),this,SLOT(openMotif()));
    connect(opacite,SIGNAL(valueChanged(int)),this, SLOT(setOpacity(int)));
    connect(valider,SIGNAL(clicked()),this, SLOT(valider()));

    widget->show();
}

void PageAppli::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, QDir::currentPath());
         if (!fileName.isEmpty()) {
             QImage image(fileName);
             if (image.isNull()) {
                 QMessageBox::information(this, tr("Image Viewer"),
                                          tr("Impossible d'ouvrir le fichier"));
                 return;
             }
            image = image.convertToFormat(QImage::Format_ARGB32);
            imageLabel->setPixmap(QPixmap::fromImage(image).scaled(1116,728));
            scrollArea->addPixmap(*imageLabel->pixmap());

    }
}

void PageAppli::openMotif()
{
    QString fileName2 = QFileDialog::getOpenFileName(this, QDir::currentPath());
         if (!fileName2.isEmpty()) {
             QImage image2(fileName2);
             if (image2.isNull()) {
                 QMessageBox::information(this, tr("Image Viewer"),
                                          tr("Impossible d'ouvrir le fichier"));
                 return;
             }
             imageTest = image2.convertToFormat(QImage::Format_ARGB32);
             imageMotif->setPixmap(QPixmap::fromImage(imageTest));
    }
}

void PageAppli::setOpacity(int id)
{
    opacity = (double)id/100;
    qDebug()<<opacity<<endl;
}

void PageAppli::mousePressEvent(QMouseEvent *e)
{
    listMotifs.addPoint(e->x(),e->y());
}

void PageAppli::paintEvent(QPaintEvent *event)
{
    //painter1.setOpacity(opacity);

    //QRect rect = polygon.boundingRect();

   // QImage res(polygon.boundingRect().size());
   // painter1.drawPixmap(0,0,*imageMotif->pixmap()); // puts TopMammogram image into img
    //scrollArea->addPolygon(polygon);
     //scrollArea->addItem(*imageMotif->pixmap());

}

void PageAppli::valider(){

    QVector<QPoint> points;

    for (int i=0;i<listMotifs.getSize();i++)
    {
        QPoint p(listMotifs.returnPoint(i).x()-238,listMotifs.returnPoint(i).y()-20);
        points.push_back(p);
    }

    QPolygon cutZone(points);

        QImage pix(1116,728,QImage::Format_ARGB32);
        pix.fill(Qt::transparent);
        QImage motif = imageMotif->pixmap()->toImage();
        QPainter p(&pix);
        {
            p.save();
                p.setPen(Qt::NoPen);
                p.setBrush(motif);
                p.setOpacity(opacity);
                p.translate(0,0);
                p.drawPolygon(cutZone);
            p.restore();
        }

        QLabel* imageM = new QLabel;
        imageM->setPixmap(QPixmap::fromImage(pix));
        scrollArea->addPixmap(*imageM->pixmap());
        listMotifs.clear();
}
