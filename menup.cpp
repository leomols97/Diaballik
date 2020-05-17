#include "menup.h"
#include "Plateau.h"
#include "Game.h"

using namespace Diaballik;

MenuP::MenuP(/*Board board*/) : QWidget()
{
    scene = new QGraphicsScene();
    window = new QGraphicsView(scene);
    /*player1Name = new QGraphicsSimpleTextItem();
    player2Name = new QGraphicsSimpleTextItem();
    player1Name->setPos(-20, -10);
    player2Name->setPos(-50, -10);
    player1Name->setText("Nom du joueur 1");
    player2Name->setText("Nom du joueur 2");
    player1Name->setVisible(false);
    player2Name->setVisible(false);
    scene->addText(tr("Nom du joueur 1"))->setDefaultTextColor(Qt::gray);
    scene->addText(tr("Nom du joueur 2"))->setDefaultTextColor(Qt::gray);*/
    player1Name = new QTextEdit("Nom du joueur 1", window);
    player2Name = new QTextEdit("Nom du joueur 2", window);
    scene->addWidget(player1Name);
    scene->addWidget(player2Name);
    //player1Name->setFont(QPainter::background()
    //scene->addItem(player1Name);
    //m_layout->addWidget(player1Name);
    m_layout = new QVBoxLayout(this);
    m_layout->addWidget(window);
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
    //m_layout->addItem(player1Name.);
    QObject::connect(play, SIGNAL(clicked()), this, SLOT(openGame()));
    QObject::connect(play, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(leave, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MenuP::openGame(/*Board board*/)
{
    cout << choixTaille->currentIndex() << endl;
    Plateau *game = new Plateau(this->getChoixTaille()->currentIndex()/*board*/);
    game->show();
}
