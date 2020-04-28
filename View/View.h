#ifndef VIEW_H
#define VIEW_H
#include "Models/Game.h"

namespace Diaballik
{

    class View
    {

    public:

        /**
         * @brief View constructor of Class View
         */
        View();

        /**
         * @brief Initialize prints a welcoming sentence
         */
        void initialize();

        /**
         * @brief displayQuit prints a goodbye sentence
         */
        void displayQuit();

        /**
         * @brief displayError prints an error message
         * @param message the message to be printed
         */
        void displayError(string message);

        /**
         * @brief displayHelpInit prints the list of commands the player can do initialy
         */
        void displayHelpInit();

        /**
         * @brief displayHelpMove prints the list of commands the player can do when a piece is selected
         */
        void displayHelpMove();

        /**
         * @brief displayHelpPass prints the list of commands the player can do when a piece is selected and this piece has the ball
         */
        void displayHelpPass();

        /**
         * @brief askCommand asks a command to the user
         * @return a string which is the input of the user
         */
        string askCommand();

        /**
         * @brief displayBoard prints the board
         */
        void displayBoard(Board board);

        /**
         * @brief displayPiece prints the piece
         * @param square the square where you must print the piece
         */
        void displayPiece(Square square) ;

        //void displayOver(vector<Player> winners) ;

        /*
          @brief displaySelected
          @param piece

        void displaySelected(Piece piece) ;*/

        /**
         * @brief displayMoves prints the list of moves
         * @param moves list of possible moves
         */
        void displayMoves(vector<Move> moves) ;

        /**
         * @brief displayCurrentPlayer prints the player that must play
         * @param player the player to print
         */
        void displayCurrentPlayer(Player player) ;

    };
}

#endif // VIEW_H
