/**
 * Project Diaballik
 */


#include "Player.h"
#include <iostream>

using namespace std;
using namespace PlayerSpace;

/**
 * Player implementation
 */


/**
 * @param color
 */
Player::Player(Color color) {

}

/**
 * @return boolean
 */
bool Player::canPass() {
    return false;
}

/**
 * @return int
 */
int Player::getNbMoves() {
    return 0;
}

/**
 * @param nbMoves
 * @return void
 */
void Player::setNbMoves(int nbMoves) {
    return;
}

/**
 * @return Color
 */
Color Player::getColor() {
    return null;
}

/**
 * @return List<Piece>
 */
vector<Piece> Player::getPieces() {
    return null;
}
