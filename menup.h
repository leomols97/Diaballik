#ifndef MENUP_H
#define MENUP_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "Models/Plateau.h"
#include "Observer/Subject.h"
#include "Observer/Observer.h"

namespace Diaballik
{

    class MenuP : public QWidget
    {
            Q_OBJECT

        private:
        /**
             * @brief m_layout layout that vertically aligns the menu
             */
            QVBoxLayout *m_layout;

            /**
             * @brief play a button to launch a new game
             */
            QPushButton *play;

            /**
             * @brief leave a button to exit the menu
             */
            QPushButton *leave;

            /**
             * @brief choixTaille a scrolling menu to choose the size of the board
             */
            QComboBox *choixTaille;

            /**
             * @brief taille displays the size of the board
             */
            QLabel *taille;

            /**
             * @brief gameType a scrolling menu to choose the type of game
             */
            QComboBox *gameType;

            /**
             * @brief type displays the type of game (variant or normal)
             */
            QLabel *type;

            /**
             * @brief player1Name input of the name of player 1
             */
            QLineEdit *player1Name;

            /**
             * @brief player2Name input of the name of player 2
             */
            QLineEdit *player2Name;


        public:
            /**
             * @brief MenuP constructs and displays a menu in a new window
             */
            MenuP(/*Board board*/);

            /**
             * @brief getChoixTaille
             * @return the size of the board
             */
            inline QComboBox* getChoixTaille()
            {
                return choixTaille;
            }

            /**
             * @brief getPlayer1Name
             * @return the name of player 2
             */
            inline QLineEdit* getPlayer1Name()
            {
                return player1Name;
            }

            /**
             * @brief getPlayer2Name
             * @return the name of player 2
             */
            inline QLineEdit* getPlayer2Name()
            {
                return player2Name;
            }

            /**
             * @brief getGameType
             * @return the type of game (normal or variant)
             */
            inline QComboBox* getGameType()
            {
                return gameType;
            }

            /**
             * @brief typeOfGame
             * @param typeOfGame the type of game (normal or variant)
             * @return 1 for normal and 2 for variant
             */
            int typeOfGame(string typeOfGame)
            {
                if (typeOfGame == "Normale")
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }

        public slots:
            /**
             * @brief openGame opens a new game
             */
            void openGame();
    };
}

#endif // MENUP_H
