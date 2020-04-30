#include "Controller/Controller.h"

using namespace Diaballik;


Controller::Controller(Game game, View view) :
    game_(game),
    view_(view)
{
    //this->game_ = game;
    //this->view_ = view;
}

/*Controller::~Controller()
{
    delete &game_;
}*/

void Controller::initialize()
{
    this->view_.initialize();
    this->game_.initialize();
}

void Controller::startGame()
{
    this->initialize();
    bool endCom = false;
    this->view_.displayBoard(this->game_.getBoard());
    while (!endCom)
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
        while(game_.hasMoves(game_.getCurrent()) && game_.getCurrent().getHasPass())
        {
            this->view_.displayCurrentPlayer(game_.getCurrent());
            game_.getOpponent().setNbMoves(2);
            game_.getOpponent().setHasPass(true);
            this->view_.displayHelpInit();
            cout << endl;
            string command = this->view_.askCommand();
            vector<string> commandStrings;
            unsigned int i = 0;
            char c;
            string com = "";

            //le while réécrit la commande ==> à corriger
            while (i < command.size())
            {
                c=command[i];
                putchar (tolower(c));
                com += c;
                if (command[i] == ' ')
                {
                    commandStrings.push_back(com);
                    com.clear();
                }
                i++;
            }
            cout << endl;
            commandStrings.push_back(com);
            //split(com, words);
            //copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
            //string separate[] = command.toLower().split(" ");
            if (command == "quit")
            {
                endCom = true;
                break;
            }
            else if (command == "end turn")
            {
                view_.displayBoard(game_.getBoard());
                game_.swapPlayers();
            }
            else if(commandStrings.at(0) == "select ")
            {
                if(!game_.hasMoves(game_.getCurrent()) && !game_.getCurrent().getHasPass())
                {
                    view_.displayError("Le joueur n'a plus de mouvement ou de passes possible");
                    game_.swapPlayers();
                    break;
                }

                int row = stoi(commandStrings.at(1));
                int col = stoi(commandStrings.at(2));
                Position position(row, col);
                //this->game_.getBoard().getPiece(position).setSelected(true);
                //this->game_.getBoard().getBoard()[row][col].setSelected(true);
this->game_.getCurrent().getPieces().at(col).setSelected(true);
                if(game_.getCurrent().getHasPass() && (game_.getSelected(row, col).getColor() == BlackWithBall || game_.getSelected(row, col).getColor() == WhiteWithBall))     // il faut travailler avec les couleurs
                {
                    cout << endl;
                    view_.displayPasses(game_.getPossiblePasses(position));
                    cout << endl;
                    if(game_.getPossiblePasses(position).size() != 0)
                    {
                        view_.displayHelpPass();
                        cout << endl;
                        command = this->view_.askCommand();
                        com = "";
                        i = 0;
                        while (i < command.size())
                        {
                            c=command[i];
                            putchar (tolower(c));
                            com += c;
                            if (command[i] == ' ')
                            {
                                commandStrings.push_back(com);
                                com.clear();
                            }
                            i++;
                        }
                        commandStrings.push_back(com);
                        cout << endl;
                        if(commandStrings.at(0) == "quit")
                        {
                            endCom = true;
                        }
                        else if (commandStrings.at(0) == "pass ")
                        {
                            game_.applyPass(game_.getMoves().at(stoi(commandStrings.at(1))));
                            //game_.getSelected(row, col).setSelected(false);
                        }
                    }
                    else
                    {
                        cout << "Veuillez selectionner une autre piece" << endl;
                    }
                }
                else if(game_.hasMoves(game_.getCurrent()) && game_.getSelected(row, col).getColor() == game_.getCurrent().getColor())     // il faut travailler avec les couleurs
                {
                    cout << endl;
                    vector<Move> moves = this->game_.getMoves(position);
                    view_.displayMoves(moves);
                    cout << endl;
                    if(game_.getMoves().size() != 0)
                    {
                        view_.displayBoard(this->game_.getBoard());
                        cout << endl;
                        view_.displayHelpMove();
                        cout << endl;
                        commandStrings.clear();
                        command = this->view_.askCommand();
                        com = "";
                        i = 0;
                        while (i < command.size())
                        {
                            c=command[i];
                            putchar (tolower(c));
                            com += c;
                            if (command[i] == ' ')
                            {
                                commandStrings.push_back(com);
                                com.clear();
                            }
                            i++;
                        }
                        commandStrings.push_back(com);
                        if(commandStrings.at(0) == "quit")
                        {
                            endCom = true;
                        }
                        else if(commandStrings.at(0) == "apply ")
                        {
                            game_.apply(moves.at(stoi(commandStrings.at(1))));
                            //game_.getSelected(row, col).setSelected(false);
                        }
                    }
                    else
                    {
                        cout << "Veuillez selectionner une autre piece" << endl;
                    }
                }
                cout << endl;
                view_.displayBoard(this->game_.getBoard());
                //break;
            }
        }
        game_.swapPlayers();
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
