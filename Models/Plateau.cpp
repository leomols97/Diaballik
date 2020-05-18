#include "Plateau.h"
#include "Game.h"
#include "menup.h"
#include <string>

using namespace std;
using namespace Diaballik;

void Plateau::windowLength(unsigned int boardLength)
{
    if (boardLength == 5)
    {
        setFixedSize(800, 600);
    }
    else if (boardLength == 7)
    {
        setFixedSize(1100, 800);
    }
    else if (boardLength == 9)
    {
        setFixedSize(1400, 1000);
    }
}

Plateau::Plateau(Game &game, string player1, string player2/*unsigned int boardLength, int typeOfGame, string currentPlayer*/) : QWidget()
{
    windowLength(game.getBoard().getBoardLength());
    m_black = new QGraphicsRectItem();
    m_white = new QGraphicsRectItem();
    m_jeu = new QGraphicsScene();
    m_plateau = new QGraphicsView(m_plateau);
    m_layout = new QHBoxLayout(this);
    //buttons(game);
    vector<vector<QPushButton*>> cases;
    for (unsigned int i = 0; i < game.getBoard().getBoardLength(); i++)
    {
        vector<QPushButton*> lignes;
        for (unsigned int j = 0; j < game.getBoard().getBoardLength(); j++)
        {
            //addLign(i, j, lignes, game);
            Position pos(i, j);
            cout << "1111 " << game.getBoard().getPiece(pos).getColor() << endl;
            if (game.getBoard().getPiece(pos).getColor() == Black)
            {
                m_boutonsJeu = boutons(j, i, "background-color:black; border:0.5px solid white;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == BlackWithBall)
            {
                m_boutonsJeu = boutons(j, i, "background-color:black; border:0.5px solid white; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == White)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == WhiteWithBall)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == WhiteSelected)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == WhiteWithBallSelected)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == BlackSelected)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == BlackWithBallSelected)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == PassBlack)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == PassWhite)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(game.getBoard().getPiece(pos).getColor() == Destination)
            {
                m_boutonsJeu = boutons(j, i, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else
            {
                m_boutonsJeu = boutons(j, i, "background-color:grey; border:0.5px solid black;", false);
                lignes.push_back(m_boutonsJeu);
            }
            cout << "1111 " << game.getBoard().getPiece(pos).getColor() << endl;
        }
        cases.push_back(lignes);
    }
    infosJeu(game.getCurrent().getPlayerColor());
}

void Plateau::buttons(Game game)
{
    vector<vector<QPushButton*>> cases;
    for (unsigned int i = 0; i < game.getBoard().getBoardLength(); i++)
    {
        vector<QPushButton*> lignes;
        for (unsigned int j = 0; j < game.getBoard().getBoardLength(); j++)
        {
            addLign(i, j, lignes, game);
        }
        cases.push_back(lignes);
    }
}

void Plateau::infosJeu(string currentPlayer/*, QGraphicsRectItem currentPlayerColor*/)
{
    m_infosScene = new QGraphicsScene(QRectF(720, 0, 100, 720));
    m_infosJeu = new QGraphicsView(m_infosScene);
    // rajouter les boutons nécessaires et le texte dans m_options
    organiser = new QVBoxLayout(m_infosJeu);
    m_finDeTour = new QPushButton("Fin de Tour", m_infosJeu);
    m_abandon = new QPushButton("Abandonner", m_infosJeu);
    QLabel *playerName = new QLabel(currentPlayer.c_str());
    m_texteTour = new QLabel("Au tour de " + playerName->text() , m_infosJeu);
    QObject::connect(m_finDeTour, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_abandon, SIGNAL(clicked()), this, SLOT(showWinner()));//au lieu de quitter, il doit ouvrir un pop-up pour afficher le nom du vainqueur et proposer une nouvelle partie
    m_layout->addWidget(m_plateau, 780);
    m_layout->addWidget(m_infosJeu, 320);
    organiser->addWidget(m_texteTour, 0, 0);
    organiser->addWidget(m_finDeTour, 120);
    organiser->addWidget(m_abandon, 120);
    organiser->addStretch();
}

/*void Plateau::swapPlayer()
{
    Player provisoire = getCurrent();
    getCurrent() = getOpponent();
    getOpponent = provisoire;
}*/

void Plateau::showWinner(Game game)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Recommencer");
    msgBox.setText(game.getWinner().getPlayerColor().c_str());
    msgBox.setText("Bravo à gagnant. Voulez-vous recommencer");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes)
    {
        MenuP *menu = new MenuP;
        this->close();
        menu->show();
    }
    else
    {
        QApplication::quit();
    }
}

QPushButton *Plateau::boutons(unsigned int i, unsigned int j, QString style, bool clickable)
{
    m_boutonsJeu = new QPushButton(m_plateau);
    m_boutonsJeu->setGeometry(i*100+10, j*100+10, 100, 100);
    if (clickable)
    {
        m_boutonsJeu->setCursor(Qt::PointingHandCursor);
    }
    m_boutonsJeu->setStyleSheet(style);
    return m_boutonsJeu;
}

void Plateau::addLign(unsigned int colonne, unsigned int ligne, vector<QPushButton*> lignes, Game game)
{
    Position pos(ligne, colonne);
    if (game.getBoard().getPiece(pos).getColor() == Black)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:black; border:0.5px solid white;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == BlackWithBall)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:black; border:0.5px solid white; border-radius: 50px;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == White)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:white; border:0.5px solid black;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == WhiteWithBall)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == WhiteSelected)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:white; border:5px solid yellow;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == WhiteWithBallSelected)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:white; border:5px solid yellow; border-radius: 50px;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == BlackSelected)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:black; border:5px solid yellow;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == BlackWithBallSelected)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:black; border:0.5px solid yellow; border-radius: 50px;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == PassBlack)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:black; border:5px solid red;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == PassWhite)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:white; border:5px solid red;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else if(game.getBoard().getPiece(pos).getColor() == Destination)
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:grey; border:5px solid red;", true);
        lignes.push_back(m_boutonsJeu);
    }
    else
    {
        m_boutonsJeu = boutons(colonne, ligne, "background-color:grey; border:0.5px solid black;", false);
        lignes.push_back(m_boutonsJeu);
    }
    //return lignes;
}
