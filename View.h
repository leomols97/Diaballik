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

        void displayBoard(vector<vector<Square>>, Player player);

        void displayBoardHint(vector<vector<Square>>, Player player) ;

        void displayPieceHint(Square square, string a, string b, string c, Color color, Color color2) ;

        void displayPiece(Square square, string a, string b, Color color1, Color color2) ;

        void displayOver(vector<Player> winners) ;

        void displaySelected(Piece piece) ;

        void displayMoves(vector<Move> moves) ;

        void displayCurrentPlayer(Player player) ;

    };
}

#endif // VIEW_H
