#include "View.h"

using namespace std;
using namespace Vue;


View::View(){}

void Initialize(){
    cout << "";
    cout << "Bonjour et Bienvenue dans le jeu de Diaballik";
    cout << "";
}

void Quit(){
    cout << "Au Revoir";
    cout << "";
}

void displayError(string e){
    cout << e;
    cout << "";
}

void displayHelpInit(){
    cout << "Liste de commandes : ";
    cout << " * select <ligne> <colonne> : permet de séléctionner la pièce à la position mentionnée : ";
    cout << " * quit : permet de quitter le jeu";
}

void displayHelpWhenSelected(){
    cout << "Liste de commandes : ";
    cout << " * moves : affiche la liste des mouvements possibles de la piece à la position selectionée";
    cout << " * quit : permet de quitter le jeu";
}

void displayHelpWhenMoves(){
    cout << "Liste de commandes : ";
    cout << " * apply <numéro du déplacement>: permet de déplacer une pièce sélectionnée";
    cout << " * quit : permet de quitter le jeu";
}

string askCommand(){

}

void displayBoard(vector<vector<Square>> board, Player player){

}

void displayPiece(Square square, string a, string b, Color color1, Color color2) {

}

void displayOver(vector<Player> winners) {

}

void displayMoves(vector<Move> moves) {

}

void displayCurrentPlayer(Player player) {
    if(player.getColor() == White)
        cout << "Au tour des Blancs";
    else if(player.getColor() == Black)
        cout << "Au tour des Noirs";
}
