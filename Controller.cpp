#include "Controller.h"
#include "Game.h"
#include "View.h"
#include "sstream"
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;
using namespace Diaballik;

Controller::Controller() {}

Controller::Controller(Game game, View view)
{
    this->game_ = game;
    this->view_ = view;
}

/*constexpr unsigned int str2int(char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}*/

void Controller::startGame()
{
    initialize();
    bool endCom = false;
    //bool newTurn = false;
    game_.start();
    view_.displayBoard(game_.getBoard().getBoard());
    while (!this->game_.isOver())
    {
        if (this->game_.isOver())
        {
            endCom = true;
            this->game_.getWinner();
            this->view_.displayQuit();
        }
        /*if (newTurn)
        {
            Position pos; // position de la piece qui a la balle
            int row = pos.getRow();
            int col = pos.getColumn();
            if (!game_.hasMoves(game_.getCurrent()))
            {
                this->view_.displayError("Ce joueur ne peut pas jouer lors de ce tour.");
                game_.swapPlayers();
            }
        }*/
        view_.displayCurrentPlayer(game_.getCurrent());
        this->view_.displayHelpInit();
        string command = this->view_.askCommand();
        vector<string> commandStrings;
        unsigned int i = 0;
        char c;
        string com = "";
        while (i < command.size())
        {
            c=command[i];
            putchar (tolower(c));
            com += c;
            if (command[i] == ' ')
            {
                commandStrings.push_back(com);
                com.erase();
            }
            i++;
        }
        //split(com, words);
        //copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
        //string separate[] = command.toLower().split(" ");
        if (commandStrings.at(0) == "quit")
        {
            endCom = true;
            break;
        }
        else if(commandStrings.at(0) == "move")
        {
            if(!game_.hasMoves(game_.getCurrent()) && !game_.getCurrent().getHasPass())
            {
                view_.displayError("Le joueur n'a plus de mouvement ou de passes possible");
                game_.swapPlayers();
                break;
            }
            int row = command[1];
            int col = command[2];
            Position position(row, col);
            if(game_.getCurrent().getHasPass() && game_.getSelected(row, col).getHasBall())
            {
                //affiche la liste de passes possibles
                view_.displayHelpPass();
                command = this->view_.askCommand();
                while (i < command.size())
                {
                    c=command[i];
                    putchar (tolower(c));
                    com += c;
                    if (command[i] == ' ')
                    {
                        commandStrings.push_back(com);
                        com.erase();
                    }
                    i++;
                }

                if(commandStrings.at(0) == "quit")
                {
                    endCom = true;
                }
                else if (commandStrings.at(0) == "pass")
                {
                    //game_.applyPass(game_.getMoves().at(stoi(commandStrings.at(1))));
                    game_.getCurrent().setHasPass(false);
                }


            }
            else if(game_.hasMoves(game_.getCurrent()) && !game_.getSelected(row, col).getHasBall())
            {
                vector<Move> moves = this->game_.getMoves(position);
                view_.displayMoves(moves);
                view_.displayHelpMove();
                command = this->view_.askCommand();
                while (i < command.size())
                {
                    c=command[i];
                    putchar (tolower(c));
                    com += c;
                    if (command[i] == ' ')
                    {
                        commandStrings.push_back(com);
                        com.erase();
                    }
                    i++;
                }

                if(commandStrings.at(0) == "quit")
                {
                    endCom = true;
                }
                else if(commandStrings.at(0) == "apply")
                {
                    //game_.apply(moves.at(stoi(commandStrings.at(1))));
                }
            }
            break;

        }
        /*string commmmmmm = commandStrings.at(0);
        switch(str2int(commmmmmm))
        {
            case "quit" :
                endCom = true;
                break;
            case "move" :
                if(!game_.hasMoves(game_.getCurrent()) && !game_.getCurrent().getHasPass())
                {
                    view_.displayError("Le joueur n'a plus de mouvement ou de passes possible");
                    game_.swapPlayers();
                    break;
                }
                int row = command[1];
                int col = command[2];
                Position position(row, col);
                if(game_.getCurrent().getHasPass() && game_.getSelected(row, col).getHasBall())
                {
                    //affiche la liste de passes possibles
                    view_.displayHelpPass();
                    command = this->view_.askCommand();
                    switch (command[0]) {
                        case 'quit' :
                            endCom = true;
                            break;
                        case 'pass':
                            game_.applyPass(game_.getMoves()[command[1]]);
                            game_.getCurrent().setHasPass(false);
                            break;
                    }
                }
                else if(game_.hasMoves(game_.getCurrent()) && !game_.getSelected(row, col).getHasBall())
                {
                    vector<Move> moves = this->game_.getMoves(position);
                    view_.displayMoves(moves);
                    view_.displayHelpMove();
                    command = this->view_.askCommand();
                    switch (command[0]) {
                        case 'quit' :
                            endCom = true;
                            break;
                        case 'apply' :
                            game_.apply(moves[command[1]]);
                            break;
                    }
                }
                break;*/

        /*case '' :
                Position pos;
                try
            {
                pos = new Position(Integer.parseInt(separate[1]) - 1, Integer.parseInt(separate[2]) - 1);
                this.game.play(pos);
                newTurn = true;
                turn();
            }
                catch (NumberFormatException e)
                {
                    System.out.println("Les 2 derniers arguments ne sont pas des chiffres !");
                }
                catch (ArrayIndexOutOfBoundsException e)
                {
                    System.out.println("La commande comporte pas assez ou trop d'arguments !");
                }
                catch (Exception e)
                {
                    view.displayError(e.getMessage());
                }
                break;
            case 'show' :
                this.view.displayBoard(this.game.getBoard());
                break;*/
        /*default :
                cout << "zut" << endl;
                cout <<"La commande n'est pas correctement entrée" << endl;*/
    }
    if (endCom == true)
    {
        this->view_.displayQuit();
    }
}


/*int Controller::stringToInteger(int index, stringstream com, vector<int> list)
{
    int number;
    try
    {
        string token;
        while(getline(com, token, ' '))
        {
            stringstream(token) << number;
            list.push_back(number);
        }
    }
    catch (const exception e)
    {
        cout << "ce n'est pas un entier";
    }
   return list[index];
}*/

void Controller::initialize()
{
    this->game_.initialize();
}
