/**
 * Project Diaballik
 */


#include "Square.h"
#include <iostream>

using namespace std;

/**
 * Square implementation
 */


Square::Square() {

}

/**
 * @return boolean
 */
bool Square::isFree() {
    return false;
}

/**
 * @param color
 * @return boolean
 */
bool Square::isMyOwn(Color color) {
    return false;
}

/**
 * @return Piece
 */
Piece Square::getPiece() {
    return NULL;
}

/**
 * @param piece
 * @return void
 */
void Square::put(Piece piece) {
    return;
}

/**
 * @return void
 */
void Square::remove() {
    return;
}
