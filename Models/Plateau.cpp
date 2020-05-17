#include "Plateau.h"
#include "Game.h"
#include "menup.h"
#include <string>

using namespace std;
using namespace Diaballik;

Plateau::Plateau(unsigned int boardLength/*Board board*/) : QWidget()
{
    setFixedSize(1000, 780);
    m_plateau = new QGraphicsScene();
    m_view = new QGraphicsView(m_plateau);
    m_layout = new QHBoxLayout(this);
    m_rect = new QGraphicsRectItem();
    //m_rect1 = new QGraphicsRectItem();
    m_circle = new QGraphicsEllipseItem();
    //m_rect1 = m_plateau->addRect(QRectF(0, 0, 720, 720), QPen(Qt::black), QBrush(Qt::gray));
    //vector<vector<QGraphicsRectItem>> boardG;
    //QGraphicsRectItem() rect;
    for (unsigned int i = 0; i < boardLength; i++)
    {
        for (unsigned int j = 0; j < boardLength; j++)
        {
            //nom+=i+=j;
            m_rect = m_plateau->addRect(QRectF(i*100 + 10, j*100 + 10, 100, 100), QPen(Qt::black, 2), QBrush(Qt::gray));
            //boardG.at(i).push_back(m_rect);
            //m_circle = m_plateau->addEllipse(QRectF(i*100 + 22.5, j*100 + 22.5, 75, 75),QPen(Qt::white), QBrush(Qt::white));
            //m_rect = m_plateau->addRect(QRectF(i*100 + 10, j*100 + 10, 100, 100), QPen(Qt::black), QBrush(Qt::white));
            //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 100, 100));
        }
    }
    m_options = new QGraphicsScene(QRectF(720, 0, 100, 720));
    m_view1 = new QGraphicsView(m_options);
    m_bouton1 = new QPushButton("fin de tour", m_view1);
    m_bouton1->move(45, 50);
    m_bouton1->setMinimumWidth(120);
    m_text1 = new QLabel("au tour de ...", m_view1);
    m_text1->move(55, 30);
    QObject::connect(m_bouton1, SIGNAL(clicked()), qApp, SLOT(quit()));
    m_layout->addWidget(m_view, 780);
    m_layout->addWidget(m_view1, 220);



    /*
     * setFixedSize(1000, 780);
    m_plateau = new QGraphicsScene();
    m_view = new QGraphicsView(m_plateau);
    m_layout = new QHBoxLayout(this);
    m_rect = new QGraphicsRectItem();
    //m_rect1 = new QGraphicsRectItem();
    m_circle = new QGraphicsEllipseItem();
    //m_rect1 = m_plateau->addRect(QRectF(0, 0, 720, 720), QPen(Qt::black), QBrush(Qt::gray));

    for (unsigned int i = 0; i < 7; i++)
    {
        for (unsigned int j = 0; j < 7; j++)
        {
            string nom = "m_rect";
            if((i!=3 && j==0))
            {
                //nom = nom + i + j;
                //QGraphicsRectItem *nom = new QGraphicsRectItem();
                m_boutonJeu = new QPushButton(m_view);
                m_boutonJeu->setGeometry(i*100 + 10, j*100 + 10, 100, 100);
                m_boutonJeu->setCursor(Qt::PointingHandCursor);
                m_boutonJeu->setStyleSheet("background-color:black; border:0.5px solid white;");
                //nom = m_plateau->addRect(QRectF(i*100 + 10, j*100 + 10, 100, 100), QPen(Qt::black), QBrush(Qt::black));
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 22.5, j*100 + 22.5, 75, 75),QPen(Qt::white), QBrush(Qt::white));
            }
            else if(i == 3 && j == 0)
            {
                //m_rect = m_plateau->addRect(QRectF(i*100 + 10, j*100 + 10, 100, 100), QPen(Qt::black), QBrush(Qt::white));

                m_boutonJeu = new QPushButton(m_view);
                m_boutonJeu->setGeometry(i*100+10, j*100+10, 100, 100);
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 75, 75));
                //m_boutonJeu->setIcon(QIcon("/Users/simon/Downloads/kindpng_1528880.png"));
                m_boutonJeu->setCursor(Qt::PointingHandCursor);
                m_boutonJeu->setStyleSheet("background-color:black; border:0.5px solid white; border-radius: 50px;");
            }
            else if(j!=0 && j!=6)
            {
                m_boutonJeu = new QPushButton(m_view);
                m_boutonJeu->setGeometry(i*100+10, j*100+10, 100, 100);
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 75, 75));
                m_boutonJeu->setCursor(Qt::PointingHandCursor);
                m_boutonJeu->setStyleSheet("background-color:grey; border:0.5px solid black;");
            }
            else if(j == 6 && i != 3)
            {
                m_boutonJeu = new QPushButton(m_view);
                m_boutonJeu->setGeometry(i*100+10, j*100+10, 100, 100);
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 75, 75));
                m_boutonJeu->setCursor(Qt::PointingHandCursor);
                m_boutonJeu->setStyleSheet("background-color:white; border:0.5px solid black;");
            }
            else if(j == 6 && i == 3)
            {
                m_boutonJeu = new QPushButton(m_view);
                m_boutonJeu->setGeometry(i*100+10, j*100+10, 100, 100);
                //m_circle = m_plateau->addEllipse(QRectF(i*100 + 10, j*100 + 10, 75, 75));
                //m_boutonJeu->setIcon(QIcon("/Users/simon/Downloads/plain-circle-pngrepo-com.png"));
                m_boutonJeu->setCursor(Qt::PointingHandCursor);
                m_boutonJeu->setStyleSheet("background-color:white; border:0.5px solid black; border-radius: 50px;");
            }
        }
    }
    m_options = new QGraphicsScene(QRectF(720, 0, 100, 720));
    m_view1 = new QGraphicsView(m_options);
    // rajouter les boutons nécessaires et le texte dans m_options
    m_bouton1 = new QPushButton("fin de tour", m_view1);
    m_bouton1->move(45, 50);
    m_bouton1->setMinimumWidth(120);
    m_text1 = new QLabel("au tour de ...", m_view1);
    m_text1->move(55, 30);
    QObject::connect(m_bouton1, SIGNAL(clicked()), qApp, SLOT(quit()));
    m_layout->addWidget(m_view, 780);
    m_layout->addWidget(m_view1, 220);

    */
}
