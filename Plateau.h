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
            // Afin d'ajouter des slots personnalisés
            Q_OBJECT


        private:

            QGraphicsView *m_plateau;
            QGraphicsView *m_infosJeu;
            QGraphicsScene *m_jeu;
            QHBoxLayout *m_layout;
            //QGraphicsRectItem *m_rect;
            //QGraphicsRectItem *m_rect1;
            QGraphicsScene *m_infosScene;
            //QGraphicsEllipseItem *m_circle;
            QPushButton *m_abandon;
            QLabel *m_texteTour;
            QPushButton *m_boutonsJeu;
            QGraphicsRectItem *m_black;
            QGraphicsRectItem *m_white;
            QLabel *m_currentPlayer;
            QVBoxLayout *organiser;
            QPushButton *m_finDeTour;


        public:

            Plateau(Game game, string player1, string player2/*unsigned int windowLength, int typeOfGame, string m_currentPlayer*/);

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

            void addLign(unsigned int i, unsigned int j, vector<QPushButton*> lignes, Game game);

            void buttons(Game game);

        public slots:

            //void swapPlayer();

            void showWinner();
    };
}

#endif // PLATEAU_H
