#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <qwidget.h>
#include <qpainter.h>
#include <QWidget>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QPainter>
#include <QRectF>
#include <QGraphicsRectItem>
#include <QLineF>
#include <QPaintDevice>
#include <QPaintEngine>
#include <QtWidgets>

class MaFenetre : public QWidget
{
    Q_OBJECT

    public:
    MaFenetre();

    public slots:
    void changerLargeur(int largeur);
    void changerHauteur(int hauteur);

    private:
    QLCDNumber *m_lcd;
    QLabel *m_label;
    QProgressBar *m_bar;
    QPushButton *m_button;
    QSlider *m_slider;
    QSlider *m_slider1;
    QPushButton  *m_boutonDialogue;
    QRect *m_rectangle;
};

#endif
