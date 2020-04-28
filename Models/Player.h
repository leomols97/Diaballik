/**
 * Project Diaballik
 */


#ifndef PLAYER_H
#define PLAYER_H

#include "Direction.h"
#include "Piece.h"
#include <vector>

using namespace std;
using namespace Diaballik;


namespace Diaballik
{

    class Player
    {

        private:

            /**
             * @brief color_ the color of the player
             */
            Color color_;

            /**
             * @brief pieces_ the list of pieces of the player
             */
            vector<Piece> pieces_;

            /**
             * @brief nbMoves_ the number of moves of the player
             */
            int nbMoves_;

            /**
             * @brief hasPass_ a boolean to know if the player still has the possibility to do a pass
             */
            bool hasPass_;

        public:

            /**
             * @param color the color of the player constructed
             * constructs a player characterized by its color
             */
            Player(Color color_);

            /**
             * @brief getHasPass
             * @return true if the player can still do a pass. false otherwise
             */
            inline bool getHasPass()
            {
                return this->hasPass_;
            }

            /**
             * @brief setHasPass
             * @param hasPass a boolean to know if the player still has the possibility to do a pass
             * sets the value of hasPass
             */
            inline void setHasPass(bool hasPass)
            {
                this->hasPass_ = hasPass;
            }

            /**
             * @brief getColor
             * @return the color the of the player
             */
            inline Color getColor() const
            {
                return this->color_;
            }

            /**
             * @brief getPieces
             * @return the list of pieces of the player
             */
            inline vector<Piece> getPieces()
            {
                return this->pieces_;
            }

           /**
            * @param nbMoves
            * sets the value of nbMoves
            */
            void setNbMoves(int nbMoves);

            /**
             * @brief isReal
             * @param color_ the color of the player
             * @return true if the color given as argument is Black or White. false otherwise
             */
            bool isReal(Color color_);

            /**
             * @brief allDirections
             * @return a list of all the directions
             */
            vector<Direction> allDirections();

            /**
             * @brief setColor
             * @param color the color of the player`
             * sets the value of color
             */
            void setColor(Color color);

            void addPieceToPlayer(Piece piece);
    };
}

#endif //_PLAYER_H
