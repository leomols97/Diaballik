#include "View/View.h"

using namespace Diaballik;


View::View(){}

void View::initialize()
{
    cout << "" << endl;
    cout << "Bonjour et Bienvenue dans le jeu de Diaballik" << endl;
    cout << "" << endl;
}

void View::displayQuit()
{
    cout << "Au Revoir" << endl;
    cout << "" << endl;
}

void View::displayError(string message)
{
    cout << message << endl;
    cout << "" << endl;
}

void View::displayHelpInit()
{
    cout << "Liste de commandes : " << endl;
    cout << " - select <ligne> <colonne> : permet de sélectionner la pièce à la position mentionnée et affiche la liste des mouvements possibles avec chacune des pièces" << endl;
    cout << " - quit : permet de quitter le jeu" << endl;
}

void View::displayHelpMove()
{
    cout << "Liste de commandes : " << endl;
    cout << " - apply <numéro du déplacement> : permet de déplacer la pièce sélectionnée" << endl;
    cout << " - quit : permet de quitter le jeu" << endl;
}

void View::displayHelpPass()
{
    cout << "Liste de commandes : " << endl;
    cout << " - pass <numéro de passes> : permet d'éffectuer une passe avec la pièce sélectionnée" << endl;
    cout << " - quit : permet de quitter le jeu" << endl;
}

string View::askCommand()
{
    string command;
    cout << "Entrez votre commande : " << endl;
    getline(cin, command);
    return command;
}

void View::displayLine(unsigned int row, Board board)
{
    for (unsigned int j = 0; j < board.getBoard().size(); j++)
    {
        Position pos(row, j);
        cout << " |";
        displayPiece(board.getPiece(pos));
        cout << "| ";
    }
}

void View::displayBoard(Board board)
{
    cout << " col#\t||  | 0 |  | 1 |  | 2 |  | 3 |  | 4 |  | 5 |  | 6 |" << endl; // à mettre dans un for dans une autre fonction
    cout << "===========================================================" << endl; // à mettre dans le même for
    for (unsigned int i = 0; i < board.getBoard().size(); i++)
    {
        cout << "row#" << i << "\t|| ";
        displayLine(i, board);
        cout << endl;
    }
}

void View::displayPiece(Piece piece)
{
    if (piece.getColor() == WhiteWithBall)
    {
        cout << "_W_";
    }
    else if (piece.getColor() == BlackWithBall)
    {
        cout << "_B_";
    }
    if (piece.getColor() == None)
    {
        cout << "   ";
    }
    if (piece.getColor() == White)
    {
        cout << " W ";
    }
    else if (piece.getColor() == Black)
    {
        cout << " B ";
    }
}

/*void displayOver()
{
    for (Player winner : winners)
    {
        if(winner.getColor() == White)
        {
            cout << "Bravo au joueur Blanc, vous avez gagné!" << endl;
        }
        else if(winner.getColor() == Black)
        {
            cout << "Bravo au joueur Noir, vous avez gagné!" << endl;
        }
    }
    cout << endl;
    displayQuit();
}*/

void View::displayMoves(vector<Move> moves)
{
    cout << moves.size() << " mouvement(s) possible(s)" << endl;
    for (unsigned int i = 0; i < moves.size(); i++)
    {
        cout << i << "la piece sélectionnée peut se déplacer vers la ligne " << moves[i].getEnd().getRow() << "et le colonne " << moves[i].getEnd().getColumn() << endl;
    }
}

void View::displayCurrentPlayer(Player player)
{
    if(player.getColor() == White)
        cout << "\nAu tour des Blancs\n" << endl;
    else if(player.getColor() == Black)
        cout << "\nAu tour des Noirs\n" << endl;
}
