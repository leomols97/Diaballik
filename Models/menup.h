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
            //QGraphicsView *window;
            //QGraphicsScene *scene;
            QVBoxLayout *m_layout;
            QPushButton *play;
            QPushButton *leave;
            QComboBox *choixTaille;
            QLabel *taille;
            QComboBox *gameType;
            QLabel *type;
            QString name;
            QLineEdit *player1Name;
            QLineEdit *player2Name;
            //Plateau *game;


        public:
            MenuP(/*Board board*/);

            inline QComboBox* getChoixTaille()
            {
                return choixTaille;
            }

            inline QLineEdit* getPlayer1Name()
            {
                return player1Name;
            }

            inline QLineEdit* getPlayer2Name()
            {
                return player2Name;
            }

            inline QComboBox* getGameType()
            {
                return gameType;
            }

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
            void openGame();
    };
}

#endif // MENUP_H
