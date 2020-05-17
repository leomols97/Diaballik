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

        public slots:
            void openGame(/*Board board*/);

        private:
            QGraphicsView *window;
            QGraphicsScene *scene;
            QVBoxLayout *m_layout;
            QPushButton *play;
            QPushButton *leave;
            QComboBox *choixTaille;
            QLabel *taille;
            QComboBox *gameType;
            QLabel *type;
            QString name;
            QTextEdit *player1Name;
            QTextEdit *player2Name;
            //Plateau *game;
            //QGraphicsSimpleTextItem *player1Name;
            //QGraphicsSimpleTextItem *player2Name;
    };
}

#endif // MENUP_H
