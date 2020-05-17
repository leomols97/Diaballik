#include "iostream"
#include "menup.h"
#include "Plateau.h"
#include "Game.h"

using namespace Diaballik;

MenuP::MenuP(/*Board board*/) : QWidget()
{
    //scene = new QGraphicsScene();
    //window = new QGraphicsView(scene);

    player1Name = new QLineEdit("Nom du joueur 1");
    player2Name = new QLineEdit("Nom du joueur 2");
    m_layout = new QVBoxLayout(this);
    m_layout->addWidget(player1Name);
    m_layout->addWidget(player2Name);
    play = new QPushButton("Nouvelle Partie", this);
    leave = new QPushButton("Quitter", this);
    choixTaille = new QComboBox(this);
    taille = new QLabel("Taille du Plateau : ", this);
    m_layout->addWidget(taille);
    m_layout->addWidget(choixTaille);
    choixTaille->insertItem(7, "7");
    choixTaille->insertItem(5, "5");
    choixTaille->insertItem(9, "9");
    gameType = new QComboBox(this);
    type = new QLabel("Type de Partie : ", this);
    m_layout->addWidget(type);
    m_layout->addWidget(gameType);
    gameType->insertItem(1, "Normale");
    gameType->insertItem(2, "Variante");
    m_layout->addWidget(play);
    m_layout->addWidget(leave);
    QObject::connect(play, SIGNAL(clicked()), this, SLOT(openGame()));
    QObject::connect(play, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(leave, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MenuP::openGame(/*Board board*/)
{
    // Ici, faire un if avec une condition qui définit s'il faut donner en paramètre le nom du joueur 1 ou celui du joueur 2
    Plateau *plateau = new Plateau(this->getChoixTaille()->currentText().toInt(), this->getGameType()->currentIndex(), this->getPlayer1Name()->text().toStdString()/*board*/);
    plateau->show();
}
