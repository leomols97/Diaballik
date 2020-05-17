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

Plateau::Plateau(unsigned int boardLength, int typeOfGame, string currentPlayer) : QWidget()
{
    Game game;
    game.initialize(typeOfGame);
    windowLength(boardLength);
    m_black = new QGraphicsRectItem();
    m_white = new QGraphicsRectItem();
    m_jeu = new QGraphicsScene();
    m_plateau = new QGraphicsView(m_plateau);
    m_layout = new QHBoxLayout(this);
    //if (typeOfGame == 1)
    {
        initializeOriginal(boardLength);
    }
    infosJeu(currentPlayer);
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
}

void Plateau::initializeOriginal(unsigned int boardLength)
{
    vector<vector<QPushButton*>> cases;
    for (unsigned int i = 0; i < boardLength/*game.getBoard().getBoardLength()*/; i++)
    {
        vector<QPushButton*> lignes;
        for (unsigned int j = 0; j < boardLength/*game.getBoard().getBoardLength()*/; j++)
        {
            string nom = "m_rect";
            if (i != boardLength/2 && j == 0)
            {
                m_boutonsJeu = boutons(i, j, "background-color:black; border:0.5px solid white;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(i == boardLength/2 && j == 0)
            {
                m_boutonsJeu = boutons(i, j, "background-color:black; border:0.5px solid white; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(i != boardLength/2 && j == boardLength-1)
            {
                m_boutonsJeu = boutons(i, j, "background-color:white; border:0.5px solid black;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else if(i == boardLength/2 && j == boardLength-1)
            {
                m_boutonsJeu = boutons(i, j, "background-color:white; border:0.5px solid black; border-radius: 50px;", true);
                lignes.push_back(m_boutonsJeu);
            }
            else
            {
                m_boutonsJeu = boutons(i, j, "background-color:grey; border:0.5px solid black;", false);
                lignes.push_back(m_boutonsJeu);
            }
        }
        cases.push_back(lignes);
    }
}

void Plateau::initializeVariante(unsigned int boardLength)
{
    vector<vector<QPushButton*>> cases;
    for (unsigned int i = 0; i < boardLength/*game.getBoard().getBoardLength()*/; i++)
    {
        vector<QPushButton*> lignes;
        for (unsigned int j = 0; j < boardLength/*game.getBoard().getBoardLength()*/; j++)
        {
            /*if (i == 0 && j == 3)
            {
                Piece p(BlackWithBall);
                //p.changeHasBall(true);
                this->board_[i][j].setColor(BlackWithBall);
                //this->opponent_.addPieceToPlayer(p);
                //cout << p.getColor() << endl;
            }
            else if (i == boardLength_ - 1 && j == 3)
            {
                Piece p(WhiteWithBall);
                //p.changeHasBall(true);
                this->board_[i][j].setColor(WhiteWithBall);
                //this->current_.addPieceToPlayer(p);
            }
            else if ((i == 0 && j == 1) || (i == 0 && j == boardLength_ - 2))
            {
                Piece p(White);
                this->board_[i][j].setColor(White);
                //this->current_.addPieceToPlayer(p);
            }
            else if ((i == boardLength_ - 1 && j == 1) || (i == boardLength_ - 1 && j == boardLength_ - 2))
            {
                Piece p(Black);
                this->board_[i][j].setColor(Black);
                //this->current_.addPieceToPlayer(p);
            }
            else if (i == 0 && j != 3)
            {
                Piece p(Black);
                this->board_[i][j].setColor(Black);
                //this->opponent_.addPieceToPlayer(p);
            }
            else if (i == boardLength_ - 1 && j != 3)
            {
                Piece p(White);
                this->board_[i][j].setColor(White);
                //this->current_.addPieceToPlayer(p);
            }
            else
            {
                Piece p(None);
                this->board_[i][j].setColor(None);
            }*/

            //m_rect = m_plateau->addRect(QRectF(i*100 + 10, j*100 + 10, 100, 100), QPen(Qt::black, 2), QBrush(Qt::gray));
            string nom = "m_rect";
            if (i != boardLength/2 && j == 0)
            {
                //nom = nom + i + j;
                //QGraphicsRectItem *nom = new QGraphicsRectItem();
                m_boutonsJeu = new QPushButton(m_plateau);
                m_boutonsJeu->setGeometry(i*100 + 10, j*100 + 10, 100, 100);
                m_boutonsJeu->setCursor(Qt::PointingHandCursor);
                m_boutonsJeu->setStyleSheet("background-color:black; border:0.5px solid white;");
                lignes.push_back(m_boutonsJeu);
                //nom = m_plateau->addRect(QRectF(i*100 + 10, j*100 + 10, 100, 100), QPen(Qt::black), QBrush(Qt::black));
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 22.5, j*100 + 22.5, 75, 75),QPen(Qt::white), QBrush(Qt::white));
            }
            else if(i == boardLength/2 && j == 0)
            {
                //m_rect = m_plateau->addRect(QRectF(i*100 + 10, j*100 + 10, 100, 100), QPen(Qt::black), QBrush(Qt::white));

                m_boutonsJeu = new QPushButton(m_plateau);
                m_boutonsJeu->setGeometry(i*100+10, j*100+10, 100, 100);
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 75, 75));
                //m_boutonJeu->setIcon(QIcon("/Users/simon/Downloads/kindpng_1528880.png"));
                m_boutonsJeu->setCursor(Qt::PointingHandCursor);
                m_boutonsJeu->setStyleSheet("background-color:black; border:0.5px solid white; border-radius: 50px;");
                lignes.push_back(m_boutonsJeu);
            }
            else if(i != boardLength/2 && j == boardLength-1)
            {
                m_boutonsJeu = new QPushButton(m_plateau);
                m_boutonsJeu->setGeometry(i*100+10, j*100+10, 100, 100);
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 75, 75));
                m_boutonsJeu->setCursor(Qt::PointingHandCursor);
                m_boutonsJeu->setStyleSheet("background-color:white; border:0.5px solid black;");
                lignes.push_back(m_boutonsJeu);
            }
            else if(i == boardLength/2 && j == boardLength-1)
            {
                m_boutonsJeu = new QPushButton(m_plateau);
                m_boutonsJeu->setGeometry(i*100+10, j*100+10, 100, 100);
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 75, 75));
                //m_boutonJeu->setIcon(QIcon("/Users/simon/Downloads/plain-circle-pngrepo-com.png"));
                m_boutonsJeu->setCursor(Qt::PointingHandCursor);
                m_boutonsJeu->setStyleSheet("background-color:white; border:0.5px solid black; border-radius: 50px;");
                lignes.push_back(m_boutonsJeu);
            }
            else
            {
                m_boutonsJeu = new QPushButton(m_plateau);
                m_boutonsJeu->setGeometry(i*100+10, j*100+10, 100, 100);
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 75, 75));
                //m_boutonJeu->setCursor(Qt::PointingHandCursor);
                m_boutonsJeu->setStyleSheet("background-color:grey; border:0.5px solid black;");
                lignes.push_back(m_boutonsJeu);
            }
        }
        cases.push_back(lignes);
    }
}

void Plateau::infosJeu(string currentPlayer/*, QGraphicsRectItem currentPlayerColor*/)
{
    m_infosScene = new QGraphicsScene(QRectF(720, 0, 100, 720));
    m_infosJeu = new QGraphicsView(m_infosScene);
    // rajouter les boutons nécessaires et le texte dans m_options
    m_finDeTour = new QPushButton("Fin de tour", m_infosJeu);
    m_finDeTour->move(45, 50);
    m_finDeTour->setMinimumWidth(120);
    m_finDeTour->setMinimumWidth(120);
    QLabel *playerName = new QLabel(currentPlayer.c_str());
    m_texteTour = new QLabel("Au tour de " + playerName->text() , m_infosJeu);
    m_texteTour->move(55, 30);
    QObject::connect(m_finDeTour, SIGNAL(clicked()), qApp, SLOT(quit()));
    m_layout->addWidget(m_plateau, 780);
    m_layout->addWidget(m_infosJeu, 320);
}
