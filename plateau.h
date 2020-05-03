#ifndef PLATEAU_H
#define PLATEAU_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "Models/Game.h"

namespace Diaballik {

    class Plateau : public QWidget
    {
    public:
        Plateau();
    private:
        QGraphicsView *m_view;
        QGraphicsView *m_view1;
        QGraphicsScene *m_plateau;
        QHBoxLayout *m_layout;
        QGraphicsRectItem *m_rect;
        //QGraphicsRectItem *m_rect1;
        QGraphicsScene *m_options;
        QGraphicsEllipseItem *m_circle;
        QPushButton *m_bouton1;
        QLabel *m_text1;
    };
}

#endif // PLATEAU_H
