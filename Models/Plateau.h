#ifndef PLATEAU_H
#define PLATEAU_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QMouseEvent>
#include "Game.h"
#include "Observer/Subject.h"
#include "Observer/Observer.h"

namespace Diaballik
{

    class Plateau :
            public QWidget
    {
            // Ceci transforme cette classe en QObject afin d'ajouter des slots personnalisés
            Q_OBJECT


        private:

                        /**
                         * @brief m_plateau view where we see the board
                        */
                       QGraphicsView *m_plateau;

                       /**
                        * @brief m_infosJeu view where we see the info of the player
                        */
                       QGraphicsView *m_infosJeu;

                       /**
                        * @brief m_jeu scene where the baord is
                        */
                       QGraphicsScene *m_jeu;

                       /**
                        * @brief m_layout layout to horizontally align the items within
                        */
                       QHBoxLayout *m_layout;

                       //QGraphicsRectItem *m_rect;

                       //QGraphicsRectItem *m_rect1;

                       /**
                        * @brief m_infosScene scene where we see the info of the player
                        */
                       QGraphicsScene *m_infosScene;

                       //QGraphicsEllipseItem *m_circle;

                       /**
                        * @brief m_abandon button to abandon and lose the game. opens a pop-up to ask for a new game
                        */
                       QPushButton *m_abandon;

                       /**
                        * @brief m_texteTour text to know whose turn it is
                        */
                       QLabel *m_texteTour;

                       /**
                        * @brief m_boutonsJeu buttons of the game (each square)
                        */
                       QPushButton *m_boutonsJeu;

                       /**
                        * @brief m_currentPlayer name of the current player
                        */
                       QLabel *m_currentPlayer;

                       /**
                        * @brief organiser layout to vertically align the infosJeu
                        */
                       QVBoxLayout *organiser;

                       /**
                        * @brief m_finDeTour button to pass turn
                        */
                       QPushButton *m_finDeTour;

            void onMouseEvent(const QString &eventName);
            Diaballik::Plateau *ui;

        protected:
            void mouseDoubleClickEvent(QMouseEvent *event) override;
            void mouseMoveEvent(QMouseEvent *event) override;
            void mousePressEvent(QMouseEvent *event) override;
            void mouseReleaseEvent(QMouseEvent *event) override;

            /**
             * @brief addLign
             * @param i index of row
             * @param j index of column
             * @param lignes vector of squares as buttons
             * @param game game in which we play
             * adds a lign of buttons (squares)
             */
            void addLign(unsigned int i, unsigned int j, vector<QPushButton*> lignes, Game &game);

            /**
             * @brief boutons
             * @param i index of row
             * @param j index of column
             * @param style styleSheet to change the output of the buttons
             * @param clickable true if it belongs to a player
             * @return
             */
            QPushButton *boutons(unsigned int i, unsigned int j, QString style, bool clickable);

            /**
             * @brief buttons outputs the board as a vector of vector of buttons
             * @param game the game in which we play
             */
            void buttons(Game &game);

            /**
             * @brief windowLength sets the size of the window according to the size of the board
             * @param windowLength size of the window according to the size of the board
             */
            void windowLength (unsigned int windowLength);

            /**
             * @brief infosJeu displays the right side of the window where you can find info about the player
             * @param m_currentPlayer the name of the current player
             */
            void infosJeu(string m_currentPlayer);

        public:

                   /**
                    * @brief Plateau constructs a graphic board
                    * @param game the game in which we play
                    * @param player1 the name of player 1
                    * @param player2 the name of player 2
                    */
                   Plateau(Game &game, const string &player1, const string &player2/*unsigned int windowLength, int typeOfGame, string m_currentPlayer*/);

                   explicit Plateau(QWidget *parent = nullptr);

                   ~Plateau();

                   /**
                    * @brief getCurrent
                    * @return the name of the current player
                    */
                   QLabel * getCurrent()
                   {
                       return m_currentPlayer;
                   }

                   /**
                    * @brief setCurrent sets the name of the player
                    * @param playerName the name of the player
                    */
                   void setCurrent(QLabel *playerName)
                   {
                       m_currentPlayer = playerName;
                   }

                   /**
                    * @brief selectPiece
                    * @param game the game in which we play
                    * @param position the position of the piece we select
                    */
                   void selectPiece(Game &game, Position &position);

        public slots:

                   //void swapPlayer();

                   /**
                    * @brief showWinner opens a pop-up to know who won and to ask for a new game
                    * @param game the game in which we play
                    */
                   void showWinner(Game &game);
    };
}

#endif // PLATEAU_H
