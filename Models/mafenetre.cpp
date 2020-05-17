#include "mafenetre.h"

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(200, 200);

    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(170, 20);

    m_label = new QLabel(this);
    m_label->setGeometry(170, 30, 50, 15);

    m_bar = new QProgressBar(this);
    m_bar->setGeometry(10, 30, 150, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setRange(200, 600);
    m_slider->setGeometry(10, 60, 150, 20);

    m_slider1 = new QSlider(Qt::Vertical, this);
    m_slider1->setRange(200, 600);
    m_slider1->setGeometry(160, 10, 20, 150);

    m_button = new QPushButton("reset", this);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));

    QObject::connect(m_slider1, SIGNAL(valueChanged(int)), this, SLOT(changerHauteur(int)));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_bar, SLOT(setValue(int)));
    QObject::connect(m_button, SIGNAL(clicked()), m_bar, SLOT(reset()));


    setFixedSize(1000, 600);
    QPainter painter(this);
    QPen pen;
    pen.setColor (Qt::red);
    pen.setWidth (4);
    painter.setPen(pen);
    //m_rectangle = new QRect(100,300,100,300);
    painter.drawRect(100,300,100,300);
}

void MaFenetre::changerLargeur(int largeur)
{
    setFixedSize(largeur, height());
}

void MaFenetre::changerHauteur(int hauteur)
{
    setFixedSize(width(), hauteur);
}


