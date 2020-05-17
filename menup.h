#ifndef MENUP_H
#define MENUP_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "Plateau.h"
#include "Observer/Subject.h"
#include "Observer/Observer.h"

namespace Diaballik
{

    class MenuP : public QWidget
    {
            Q_OBJECT
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

            inline QComboBox* getGameType()
            {
                return gameType;
            }

        public slots:
            void openGame(/*Board board*/);

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
    };
}

#endif // MENUP_H
