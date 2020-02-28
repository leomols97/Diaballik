/**
 * Project Diaballik
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#import "Color.h"
#import "Piece.h"

class Player {
public: 
    
/**
 * @param color
 */
Player(Color color);
    
bool canPass();
    
int getNbMoves();
    
/**
 * @param nbMoves
 */
void setNbMoves(int nbMoves);
    
Color getColor();
    
List<Piece> getPieces();
private: 
    Color color;
    int nbMoves;
    List<Piece> pieces;
};

#endif //_PLAYER_H
