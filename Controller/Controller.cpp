#include "Controller/Controller.h"

using namespace Diaballik;


Controller::Controller(Game game, View view) :
    game_(game),
    view_(view)
{
    //this->game_ = game;
    //this->view_ = view;
}

Controller::~Controller()
{
    delete &game_;
}

void Controller::initialize()
{
    this->view_.initialize();
    this->game_.initialize();
}

void Controller::startGame()
{
    this->initialize();
    bool endCom = false;
    //cout << "row : " << this->game_.getBoard().getTakenSquares(this->game_.getCurrent()).size();
    //cout << "col : " << this->game_.getBoard().getTakenSquares(this->game_.getCurrent()).at(0).getColumn();
    /*for (unsigned int i = 0; i < this->game_.getCurrent().getPieces().size(); i++)
    {
        cout << "row : " << this->game_.getBoard().getTakenSquares(this->game_.getCurrent()).at(i).getRow();
        cout << "col : " << this->game_.getBoard().getTakenSquares(this->game_.getCurrent()).at(i).getColumn();
    }*/
    this->view_.displayBoard(this->game_.getBoard());
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
        this->view_.displayCurrentPlayer(game_.getCurrent());
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
            //if(game_.getCurrent().getHasPass() && game_.getSelected(row, col).getHasBall())     // il faut travailler avec les couleurs
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
            //else if(game_.hasMoves(game_.getCurrent()) && !game_.getSelected(row, col).getHasBall())     // il faut travailler avec les couleurs
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
