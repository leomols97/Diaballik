/**
 * Project Diaballik
 */


#include "Game.h"
#include <iostream>

using namespace std;
using namespace GameSpace;

/**
 * Game implementation
 */


 Game::Game() {

}

/**
 * @return void
 */
void Game::initialize() {
    return;
}

/**
 * @param player 
 * @return boolean
 */
bool Game::foulGame(Player player ) {
    return false;
}

/**
 * @return boolean
 */
bool Game::isOver() {
    return false;
}

/**
 * @param row 
 * @param column
 * @return void
 */
void Game::select(int row , int column) {
    return;
}

/**
 * @return void
 */
void Game::swapPlayers() {
    return;
}

/**
 * @return void
 */
void Game::start() {
    return;
}

/**
 * @param selected 
 * @return List<Move>
 */

vector<Move> Game::getMoves(Position selected ) {
    return null;
}

/**
 * @param move 
 * @return void
 */
void Game::apply(Move move ) {
    return;
}

/**
 * @param player
 * @return boolean
 */
bool Game::hasMoves(Player player) {
    return false;
}

/**
 * @return Player
 */
Player Game::getWinner() {
    return null;
}

/**
 * @return Board
 */
Board Game::getBoard() {
    return null;
}

/**
 * @return Position
 */
Position Game::getSelected() {
    return null;
}

/**
 * @return Player
 */
Player Game::getCurrent() {
    return null;
}

/**
 * @return Player
 */
Player Game::getOpponent() {
    return null;
}
