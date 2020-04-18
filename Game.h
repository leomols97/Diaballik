/**
 * Project Diaballik
 */


#ifndef GAME_H
#define GAME_H

#include "Model.h"
#include "Player.h"
#include "Move.h"
#include "Board.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Game: public Model
    {

        private:

            /**
             * @brief board_ the board on which we play
             */
            Board board_;

            /**
             * @brief current_ the player currently playing
             */
            Player current_;

            /**
             * @brief opponent_ the opponent of current_
             */
            Player opponent_;

            /**
             * @brief selected_ the position selected by the user
             */
            Position selected_;


        public:

            /**
             * @brief Game constructs a game
             */
            Game();

            // ATTENTION IL NE FAUT PAS OUBLIER LES DESTRUCTEURS !!!!!!!!!

            /**
             * @brief getBoard
             * @return the board on which we play
             */
            inline Board getBoard()
            {
                return board_;
            }

            /**
             * @brief getSelected
             * @return the position selected by the user
             */
            inline Position getSelected()
            {
                return selected_;
            }

            /**
             * @brief getCurrent
             * @return the player currently playing
             */
            inline Player getCurrent()
            {
                return current_;
            }

            /**
             * @brief getOpponent
             * @return the opponent of current_
             */
            inline Player getOpponent()
            {
                return opponent_;
            }

            /**
             * @brief getWinner
             * @return the player which has won
             */
            Player getWinner();


            /**
            * @brief select selects the position chosen by the user
            * @param row the row of the position
            * @param column the column of the position
            */
            void select(int row , int column);

            /**
             * @brief swapPlayers swaps the player at the end of the turn
             */
            void swapPlayers();

            /**
             * @brief start starts a new game
             */
            void start();

            /**
             * @brief initialize initializes the board
             */
            void initialize();

            /**
             * @brief fairPlay
             * @return true if opponent_ didn't block current_
             */
            bool fairPlay();

            /**
             * @brief getSelected
             * @param row the row of the position
             * @param column the column of the position
             * @return the position selected by the user
             */
            Piece getSelected(int row, int column);

            /**
             * @brief isOver
             * @return true if the game is finished. false otherwise
             */
            bool isOver();

            /**
             * @brief getMoves
             * @return the list of moves available for current_
             */
            vector<Move> getMoves();

            /**
             * @brief getMoves
             * @param selected_ the position selected by the user
             * @return the list of moves available for current_
             */
            vector<Move> getMoves(Position selected_);

            /**
             * @brief getPossiblePasses
             * @param selected_ the position selected by the user
             * @return the list of positions where we can throw the ball
             */
            vector<Position> getPossiblePasses(Position selected_);

            /**
             * @brief getNbMoves
             * @param player the player we want to verify
             * @return the number of moves of a player
             */
            int getNbMoves(Player player);

            /**
             * @brief apply applies the move
             * @param move the move we have to apply
             */
            void apply(Move move);

            /**
             * @brief applyPass applies the pass
             * @param move the pass we have to apply
             */
            void applyPass(Move move);

            /**
             * @brief hasMoves
             * @param player the player we want to verify
             * @return true if the player still has moves to do
             */
            bool hasMoves(Player player);

            /**
             * @brief allDirections
             * @return the list of all directions
             */
            vector<Direction> allDirections ();

            //bool canPassBall(const Position &position) const;

            //bool canPassBall(Piece pieceThatGives, Position pos);

            /**
             * @brief canPassBall
             * @param pos the position we want to verify
             * @return true if a pass is possible at this position
             */
            bool canPassBall(Position pos);


            //void passBall(Position pos);

            //void getPasses(vector<Position> list) const;
    };
}
#endif //_GAME_H
