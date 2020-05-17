#ifndef PLATEAU_H
#define PLATEAU_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "Game.h"
#include "Observer/Subject.h"
#include "Observer/Observer.h"

namespace Diaballik
{

    class Plateau :
            public QWidget
    {
        public:

            Plateau(unsigned int windowLength, int typeOfGame, string currentPlayer);

            void windowLength (unsigned int windowLength);

        private:
            QGraphicsView *m_view;
            QGraphicsView *m_view1;
            QGraphicsScene *m_plateau;
            QHBoxLayout *m_layout;
            QGraphicsRectItem *m_rect;
            QGraphicsRectItem *m_rect1;
            QGraphicsScene *m_options;
            QGraphicsEllipseItem *m_circle;
            QPushButton *m_bouton1;
            QLabel *m_text1;
            QPushButton *m_boutonJeu;
    };
}

#endif // PLATEAU_H
