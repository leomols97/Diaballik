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

            Plateau(unsigned int windowLength, int typeOfGame, string m_currentPlayer);

            void windowLength (unsigned int windowLength);

            void infosJeu(string m_currentPlayer);

            QLabel * getCurrent()
            {
                return m_currentPlayer;
            }

            void setCurrent(QLabel *playerName)
            {
                m_currentPlayer = playerName;
            }

            QPushButton *boutons(unsigned int i, unsigned int j, QString style, bool clickable);

            void initializeOriginal(unsigned int boardLength);

            void initializeVariante(unsigned int boardLength);


        private:

            QGraphicsView *m_plateau;
            QGraphicsView *m_infosJeu;
            QGraphicsScene *m_jeu;
            QHBoxLayout *m_layout;
            //QGraphicsRectItem *m_rect;
            //QGraphicsRectItem *m_rect1;
            QGraphicsScene *m_infosScene;
            //QGraphicsEllipseItem *m_circle;
            QPushButton *m_finDeTour;
            QLabel *m_texteTour;
            QPushButton *m_boutonsJeu;
            QGraphicsRectItem *m_black;
            QGraphicsRectItem *m_white;
            QLabel *m_currentPlayer;
    };
}

#endif // PLATEAU_H
