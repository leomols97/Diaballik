#include "View/View.h"

using namespace Diaballik;


View::View(Game game) :
    game_(game)
{}

void View::initialize()
{
    cout << endl << "Bonjour et bienvenue dans le jeu de Diaballik" << endl;
    askWhichGame();
}

void View::askWhichGame()
{
    cout << endl << "Voulez vous jouer au jeu original ou à la variante (uniquement les positions de départ changent) ?" << endl << endl;
    cout << "1 - Original" << endl;
    cout << "2 - Variante" << endl << endl;
}

void View::askBoardLength()
{
    cout << endl << "Avec quelle taille de plateau de jeu voulez-vous jouer ?" << endl << endl;
    cout << "5, 7 ou 9 (25, 49 ou 81 cases) " << endl << endl;
}

void View::displayQuit()
{
    cout << endl << "Au Revoir" << endl << endl;
}

void View::displayError(string message)
{
    cout << message << endl << endl;
}

void View::displayHelpInit()
{
    cout << "Liste de commandes : " << endl;
    cout << " - select <ligne> <colonne> : permet de sélectionner la pièce à la position mentionnée et affiche la liste des mouvements possibles avec chacune des pièces" << endl;
    cout << " - end turn : permet de finir le tour même s'il reste des mouvements à faire" << endl;
    cout << " - quit : permet de quitter le jeu" << endl;
}

void View::displayHelpMove()
{
    cout << "Liste de commandes : " << endl;
    cout << " - apply <numéro du déplacement> : permet de déplacer la pièce sélectionnée" << endl;
    cout << " - quit : permet d'arrêter votre tour" << endl;
}

void View::displayHelpPass()
{
    cout << "Liste de commandes : " << endl;
    cout << " - pass <numéro de passes> : permet d'éffectuer une passe avec la pièce sélectionnée" << endl;
    cout << " - quit : permet d'arrêter votre tour" << endl;
}

string View::askCommand()
{
    string command;
    cout << "Entrez votre commande : ";
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

void displayTopLines(Board board)
{
    cout << " col#\t|| ";
    for (unsigned int i = 0; i < board.getBoard().size(); i++)
    {
        cout << " | " << i << " | ";
    }
    cout << endl;
    cout << "===========";
    for (unsigned int i = 0; i < board.getBoard().size(); i++)
    {
        cout << "=======";
    }
    cout << endl;
}

void View::displayBoard(Board board)
{
    //cout << " col#\t||  | 0 |  | 1 |  | 2 |  | 3 |  | 4 |  | 5 |  | 6 |" << endl; // à mettre dans un for dans une autre fonction
    //cout << "===========================================================" << endl; // à mettre dans le même for
    displayTopLines(board);
    for (unsigned int i = 0; i < board.getBoard().size(); i++)
    {
        cout << "row#" << i << "\t|| ";
        displayLine(i, board);
        cout << endl;
    }
    cout << endl;
}

void View::displayPiece(Piece piece)
{
    // je voudrais afficher la piece séelctionnée de manière différente (par exemple "=W=" au lieu de " W ")
    // ==> si la piece "piece" est la piece sélectionnée alors...

    //piece.setSelected(true);
    if (piece.getColor() == WhiteWithBall)
    {
        cout << "_B_";
    }
    else if (piece.getColor() == BlackWithBall)
    {
        cout << "_N_";
    }
    else if (piece.getColor() == None)
    {
        cout << "   ";
    }
    else if (piece.getColor() == White)
    {
        cout << " B ";
    }
    else if (piece.getColor() == Black)
    {
        cout << " N ";
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
        cout << i << " - la piece sélectionnée peut se déplacer vers la ligne " << moves[i].getEnd().getRow() << " et le colonne " << moves[i].getEnd().getColumn() << endl;
    }
}

void View::displayPasses(vector<Position> passes)
{
    cout << passes.size() << " passe(s) possible(s)" << endl;
    for (unsigned int i = 0; i < passes.size(); i++)
    {
        cout << i << " - la piece sélectionnée peut faire une passe vers la ligne " << passes[i].getRow() << " et le colonne " << passes[i].getColumn() << endl;
    }
}

void View::displayCurrentPlayer(Player player)
{
    if(player.getColor() == White)
        cout << "\nAu tour des Blancs\n" << endl;
    else if(player.getColor() == Black)
        cout << "\nAu tour des Noirs\n" << endl;
}
