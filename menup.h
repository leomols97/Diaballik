#ifndef MENUP_H
#define MENUP_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "plateau.h"

namespace Diaballik {

    class MenuP : public QWidget
    {
        Q_OBJECT
    public:
        MenuP();

    public slots:
        void openGame();

    private:
        QVBoxLayout *m_layout;
        QPushButton *m_bouton1;
        QPushButton *m_bouton2;
        //Plateau *game;
    };
}

#endif // MENUP_H
