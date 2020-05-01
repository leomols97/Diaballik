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
    while (!endCom)
    {
        if (!this->game_.isOver())
        {
            cout << "AZERTYUIOP";
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
        while(game_.getCurrent().getHasPass() || game_.hasMoves(game_.getCurrent()))
        {
            this->view_.displayBoard(this->game_.getBoard());
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
                int row;
                int col;
                Position position(row, col); // Lorsque je fais appel à "position" plus tard, il faut utiliser "this->game_.getPositionSelected();"
                try
                {
                    row = stoi(commandStrings.at(1), nullptr, 16);
                    col = stoi(commandStrings.at(2), nullptr, 16);
                    position.setRow(row);
                    position.setColumn(col);
                    try
                    {
                        this->game_.select(row, col);
                    }
                    catch (exception &e)
                    {
                        cerr << e.what() << endl;
                    }
                }
                catch (const invalid_argument& e)
                {
                    cerr << "Vous n'avez pas entré que des nombre pour sélectionner une pièce à une ligne et une colonne. Réessayez : " << endl;
                }
                catch (const exception e)
                {
                    //cout << endl << endl;
                    cerr << "Vous n'avez pas sélectionné une de vos pièces. Réessayez ! " << endl;
                }
                istringstream(commandStrings.at(1)) >> row;
                istringstream(commandStrings.at(2)) >> col;
                //row = stoi(commandStrings.at(1));
                //col = stoi(commandStrings.at(2));
                if(game_.getCurrent().getHasPass() && (game_.getPieceSelected().getColor() == BlackWithBall || game_.getPieceSelected().getColor() == WhiteWithBall))     // il faut travailler avec les couleurs
                {
                    cout << endl;
                    //this->view_.displayBoard(this->game_.getBoard());
                    this->view_.displayPasses(this->game_.getPossiblePasses(position));
                    cout << endl;
                    if(game_.canPassBall(position))
                    {
                        view_.displayHelpPass();
                        cout << endl << endl;
                        command = this->view_.askCommand();
                        commandStrings.clear();
                        com = "";
                        i = 0;
                        while (i < command.size())
                        {
                            c = command[i];
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
                        cout << commandStrings.at(0) << endl << endl;
                        if(commandStrings.at(0) == "quit")
                        {
                            endCom = true;
                        }
                        else if (commandStrings.at(0) == "pass ")
                        {
                            try
                            {
                                this->game_.applyPass(position, this->game_.getPossiblePasses(position).at(stoi(commandStrings.at(1))));
                            }
                            catch (const exception e)
                            {
                                cerr << "La passe que vous avez sélectionnée n'est pas valide ! Réessayez";
                            }

                            //this->game_.applyPass(this->game_.getBoard().getPiece(position), this->game_.getPossiblePasses(position).at(stoi(commandStrings.at(1))));
                            //this->game_.applyPass(this->game_.getBoard().getPiece(position), this->game_.getPossiblePasses(position).at(stoi(commandStrings.at(1))));
                            this->game_.changePlayer();
                        }
                    }
                    else
                    {
                        cout << "Veuillez selectionner une autre piece" << endl;
                    }
                }
                else if(game_.hasMoves(game_.getCurrent()) && game_.getPieceSelected().getColor() == game_.getCurrent().getColor())     // il faut travailler avec les couleurs
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
                        }
                    }
                    else
                    {
                        cout << "Veuillez selectionner une autre piece" << endl;
                    }
                }
                cout << endl;
                //view_.displayBoard(this->game_.getBoard());
                //break;
            }
            else
            {
                cout << "Vous avez mal entré votre commande. Veuillez respecter l'orthographe en l'entrant une fois de plus : " << endl << endl;
            }
        }
        game_.swapPlayers();
    }
    if (endCom == true)
    {
        this->view_.displayQuit();
    }
}
