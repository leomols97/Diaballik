#include "Controller/Controller.h"

using namespace Diaballik;


Controller::Controller(Game &game, View &view) :
    game_(game),
    view_(view)
{}

void registerObserver()
{

}

void Controller::startGame()
{
    bool endCom = false;
    this->view_.initialize();
    string typeOfGame = this->view_.askCommand();
    while (true)
    {
        {
            cout << "Vous n'avez pas correctement sélectionné de type de jeu ! Réessayez :" << endl;
            typeOfGame = this->view_.askCommand();
            //break;
        }
    }
    this->view_.askBoardLength();
    string boardLength = this->view_.askCommand();
    while (true)
    {
        if (boardLength == "5" || boardLength == "7" || boardLength == "9") { break; }
        else
        {
            cout << "Vous n'avez pas de valeur possible pour la taille du plateau de jeu ! Réessayez :" << endl;
            boardLength = this->view_.askCommand();
            //break;
        }
    }
    this->game_.getBoard().setBoardLength(stoi(boardLength, nullptr, 16));
    this->game_.initialize(stoi(typeOfGame.c_str(), nullptr, 16));
    while (!endCom)
    {
        if (this->game_.isOver())
        {
            endCom = true;
            this->game_.getWinner();
            this->view_.displayQuit();
        }
        while(game_.hasMoves(game_.getCurrent()) && game_.getCurrent().getHasPass())
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
                try
                {
                    row = stoi(commandStrings.at(1), nullptr, 16);
                    col = stoi(commandStrings.at(2), nullptr, 16);
                    this->game_.getPositionSelected().setRow(row);
                    this->game_.getPositionSelected().setColumn(col);
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
                catch (const out_of_range& e)
                {
                    cerr << "Vous n'avez pas sélectionné une de vos pièces. Réessayez !" << endl;
                }
                istringstream(commandStrings.at(1)) >> row;
                istringstream(commandStrings.at(2)) >> col;
                if(game_.getCurrent().getHasPass() && (game_.getPieceSelected().getColor() == BlackWithBall || game_.getPieceSelected().getColor() == WhiteWithBall))     // il faut travailler avec les couleurs
                {
                    cout << endl;
                    this->view_.displayPasses(this->game_.getPossiblePasses(this->game_.getPositionSelected()));
                    cout << endl;
                    if(game_.canPassBall(this->game_.getPositionSelected()))
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
                                this->game_.applyPass(this->game_.getPositionSelected(), this->game_.getPossiblePasses(this->game_.getPositionSelected()).at(stoi(commandStrings.at(1))));
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
                    vector<Move> moves = this->game_.getMoves(this->game_.getPositionSelected());
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
