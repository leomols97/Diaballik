/**
 * Project Diaballik
 */


#ifndef _GAME_H
#define _GAME_H

#include "Model.h"
#import "Player.h"
#import "Move.h"
#import "Board.h"


class Game: public Model {
public: 
    
Game();
    
void initialize();
    
/**
 * @param player
 */
bool foulGame(Player player );
    
bool isOver();
    
/**
 * @param row 
 * @param column
 */
void select(int row , int column);
    
void swapPlayers();
    
void start();
    
/**
 * @param selected
 */
List<Move> getMoves(Position selected );
    
/**
 * @param move
 */
void apply(Move move );
    
/**
 * @param player
 */
bool hasMoves(Player player);
    
Player getWinner();
    
Board getBoard();
    
Position getSelected();
    
Player getCurrent();
    
Player getOpponent();
private: 
    Board board;
    Player current;
    Player opponent;
    Position selected;
};

#endif //_GAME_H
