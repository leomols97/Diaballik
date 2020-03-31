#include "View.h"
#include "Player.h"

using namespace std;


View::View(){}

void Initialize()
{
    cout << "" << endl;
    cout << "Bonjour et Bienvenue dans le jeu de Diaballik" << endl;
    cout << "" << endl;
}

void displayQuit()
{
    cout << "Au Revoir" << endl;
    cout << "" << endl;
}

void displayError(string message)
{
    cout << message << endl;
    cout << "" << endl;
}

void displayHelpInit()
{
    cout << "Liste de commandes : " << endl;
    cout << " * move <ligne> <colonne> : permet de sélectionner la pièce à la position mentionnée et affiche la liste des mouvements possibles avec chacune des pièces" << endl;
    cout << " * quit : permet de quitter le jeu" << endl;
}

void displayHelpMove()
{
    cout << "Liste de commandes : " << endl;
    cout << " * apply <numéro du déplacement> : permet de déplacer la pièce sélectionnée" << endl;
    cout << " * quit : permet de quitter le jeu" << endl;
}

void displayHelpPass()
{
    cout << "Liste de commandes : " << endl;
    cout << " * pass <numéro de passes> : permet d'éffectuer une passe avec la pièce sélectionnée" << endl;
    cout << " * quit : permet de quitter le jeu" << endl;
}

vector<char> askCommand()
{
    string commande;
    cout << "Entrez votre commande : " << endl;
    getline(cin, commande);
}

void displayBoard(vector<vector<Square>> board)
{
    cout << " col#\t||  | 00 |  | 01 |  | 02 |  | 03 |  | 04 |  | 05 |  | 06 |" << endl;
    cout << "==================================================================" << endl;
    for (unsigned i = 0; i < board.size(); i++)
    {
        cout << "row#0" << i << "\t|| " << endl;
        for (Square square : board[i])
        {
            cout << " | " << endl;
            View().displayPiece(square);
            cout << " | " << endl;
        }
    }
}

void displayPiece(Square square)
{
    if(square.getPiece().getHasBall())
    {
        if (square.getPiece().getColor() == White)
        {
            cout << "_W_" << endl;
        }
        else if (square.getPiece().getColor() == Black)
        {
            cout << "_B_" << endl;
        }
        else if (square.isFree()){
            cout << "   " << endl;
        }
    }
    else
    {
        if (square.getPiece().getColor() == White)
        {
            cout << " W " << endl;
        }
        else if (square.getPiece().getColor() == Black)
        {
            cout << " B " << endl;
        }
        else if (square.isFree()){
            cout << "   " << endl;
        }
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
    Quit();
}*/

void displayMoves(vector<Move> moves)
{
    cout << moves.size() << " mouvement(s) possible(s)" << endl;
    for (unsigned i = 0; i < moves.size(); i++)
    {
       cout << i << "la piece sélectionnée peut se déplacer vers la ligne " << moves[i].getEnd().getRow() << "et le colonne " << moves[i].getEnd().getColumn() << endl;
    }
}

void displayCurrentPlayer(Player player)
{
    if(player.getColor() == White)
        cout << "Au tour des Blancs" << endl;
    else if(player.getColor() == Black)
        cout << "Au tour des Noirs" << endl;
}
