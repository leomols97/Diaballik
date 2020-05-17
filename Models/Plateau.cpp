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
}
