#include "menup.h"
#include "Plateau.h"
#include "Game.h"

using namespace Diaballik;

MenuP::MenuP() : QWidget()
{
    m_layout = new QVBoxLayout(this);
    m_bouton1 = new QPushButton("Nouvelle Partie", this);
    m_bouton2 = new QPushButton("Quitter", this);
    m_layout->addWidget(m_bouton1);
    m_layout->addWidget(m_bouton2);
    QObject::connect(m_bouton1, SIGNAL(clicked()), this, SLOT(openGame()));
    QObject::connect(m_bouton1, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(m_bouton2, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MenuP::openGame()
{
    Plateau *game = new Plateau();
    game->show();
}
