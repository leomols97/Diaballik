#ifndef VIEW_H
#define VIEW_H
#import "Game.h"

using namespace std;


namespace Vue {

    class View
    {

    public:

        View();

        void Initialize();

        void Quit();

        void displayError();

        void displayHelpInit();

        void displayHelpWhenSelected();

        void displayHelpWhenMoves();

        string askCommand();

        void displayBoard(vector<vector<Square>>);

        void displayPiece(Square square) ;

        void displayOver(vector<Player> winners) ;

        void displaySelected(Piece piece) ;

        void displayMoves(vector<Move> moves) ;

        void displayCurrentPlayer(Player player) ;

    };
}

#endif // VIEW_H
