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

            Board board_;
            Player current_;
            Player opponent_;
            Position selected_;


        public:

            Game();

            // ATTENTION IL NE FAUT PAS OUBLIER LES DESTRUCTEURS !!!!!!!!!

            /**
             * @return Board
             */
            inline Board getBoard() const
            {
                return board_;
            }

            /**
             * @brief getSelected
             * @return
             */
            inline Position getSelected() const
            {
                return selected_;
            }

            /**
             * @brief getCurrent
             * @return
             */
            inline Player getCurrent() const
            {
                return current_;
            }

            /**
             * @brief getOpponent
             * @return
             */
            inline Player getOpponent() const
            {
                return opponent_;
            }

            Player getWinner();


            /**
        * @param row
        * @param column
        */
            void select(int row , int column);

            void swapPlayers();


            void start();

            void initialize();

            bool fairPlay();

            Piece getSelected(int row, int column);

            /**
        * @param player
        */
            bool foulGame(Player player );

            bool isOver();

            vector<Move> getMoves();

            /**
        * @param selected
        */
            vector<Move> getMoves(Position selected_);

            vector<Piece> getPossiblePasses(Position selected_);

            int getNbMoves(Player player);

            /**
        * @param move
        */
            void apply(Move move );

            void applyPass(Move move);

            /**
        * @param player
        */
            bool hasMoves(Player player);

            vector<Direction> allDirections ();
    };
}
#endif //_GAME_H
