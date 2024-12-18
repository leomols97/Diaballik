/**
 * Project Diaballik
 */


#include "Game.h"

using namespace Diaballik;


/**
 * Game implementation
 */
Game::Game(unsigned int size) :
    board_(size),
    current_(White),
    opponent_(Black),
    selected_(0, 0)
{}

/*Game::~Game()
{
    delete &current_;
    delete &opponent_;
    delete &board_;
}*/

void Game::getPlayerPieces(Color &playerColor, Position &piecePosition)
{
    if (playerColor == White)
    {
        if (this->board_.getBoard()[piecePosition.getRow()][piecePosition.getColumn()].getColor() == White)
        {
            Piece p(White);
            this->current_.addPieceToPlayer(p);
        }
        else if (this->board_.getBoard()[piecePosition.getRow()][piecePosition.getColumn()].getColor() == WhiteWithBall)
        {
            Piece p(WhiteWithBall);
            this->current_.addPieceToPlayer(p);
        }
    }
    else if (playerColor == Black)
    {
        if (this->board_.getBoard()[piecePosition.getRow()][piecePosition.getColumn()].getColor() == Black)
        {
            Piece p(Black);
            this->current_.addPieceToPlayer(p);
        }
        else if (this->board_.getBoard()[piecePosition.getRow()][piecePosition.getColumn()].getColor() == BlackWithBall)
        {
            Piece p(BlackWithBall);
            this->current_.addPieceToPlayer(p);
        }
    }
}

/**
 * This initializes a Game by initializing a board
 */
void Game::initialize(int typeOfGame)
{
    this->setTypeOfGame(typeOfGame);
    if (typeOfGame == 1)
    {
        this->board_.initializeOriginal();
    }
    else if (typeOfGame == 2)
    {
        this->board_.initializeVariante();
    }
    for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
    {
        for (unsigned int j = 0; j < this->board_.getBoard()[i].size(); j++)
        {
            Position position (i, j);
            //getPlayerPieces(this->current_.getColor(), position);
            //getPlayerPieces(this->opponent_.getColor(), position);
        }
    }
}

void Game::getPasses(vector<Position> list)
{
    for (int dirInt = 1; dirInt <= 8; dirInt++)
    {
        bool ok = true;
        const Direction dir = static_cast<Direction>(dirInt);
        Position posNext = selected_.next(selected_, dir);

        while (ok)
        {
            ok = this->board_.isInside(posNext) && !this->board_.isMyOwn(posNext, opponent_.getColor());

            if (ok && this->board_.isMyOwn(posNext, current_.getColor()))
            {
                list.push_back(Position(posNext.getRow(), posNext.getColumn()));
                posNext = posNext.next(posNext, dir);
                ok = this->board_.isInside(posNext) && !this->board_.isMyOwn(posNext, opponent_.getColor());
            }

            if (ok && this->board_.isFree(posNext))
            {
                posNext = posNext.next(posNext, dir);
            }
        }
    }
}

bool Game::canPassBall(Position &pos)
{
    bool found = false;
    for (unsigned i = 0; i < allDirections().size(); i++)
        //for (size_t i {0}; i < (passPositions.size()) && !found; i++)
    {
        Position posNext = pos;
        Position posEnd = posNext.next(posNext, allDirections().at(i));
        if (this->board_.getPiece(pos).getColor() == WhiteWithBall)
        {
            do
            {
                if (this->board_.getPiece(posNext).getColor() == White)
                {
                    found = true;
                }
                posNext = pos.next(pos, allDirections().at(i));
                posEnd = posEnd.next(posEnd, allDirections().at(i));
            }
            while (this->board_.isInside(posEnd));
        }
        if (this->board_.getPiece(pos).getColor() == BlackWithBall)
        {
            do
            {
                if (this->board_.getPiece(posNext).getColor() == Black)
                {
                    found = true;
                }
                posNext = pos.next(pos, allDirections().at(i));
                posEnd = posEnd.next(posEnd, allDirections().at(i));
            }
            while (this->board_.isInside(posEnd));
        }
    }
    return found; //&& current_.getHasPass();
}


bool Game::fairPlay()
{
    Position pos(0,0);
    bool foulGame = false;
    bool found = false;
    int count = 0;
    for(unsigned int i = 0; i < this->board_.getBoard().size() && !found; i++)
    {
        pos.setRow(i);
        pos.setColumn(0);
        if(this->board_.isMyOwn(pos, opponent_.getColor()))
        {
            pos = {static_cast<unsigned int>(i), 0};
            found = true;
            if(this->board_.isInside(Position(pos.getRow()+1, 0))
                    && this->board_.isMyOwn(Position(pos.getRow()+1, 0), current_.getColor()))
            {
                count++;
            }
            if(this->board_.isInside({static_cast<unsigned int>(i)-1, 0})
                    && this->board_.isMyOwn({static_cast<unsigned int>(i)-1, 0}, current_.getColor()))
            {
                count++;
            }
        }
    }

    for(unsigned int i = 1; i < this->board_.getBoard().size() && found; i++)
    {
        found = false;
        for(unsigned int j = 0; j < this->board_.getBoard().size(); j++)
        {
            pos.setRow(j);
            pos.setRow(i);
            if(this->board_.isMyOwn(pos, opponent_.getColor()))
            {
                if(pos.getColumn()!=static_cast<unsigned int>(i)
                        && (pos.getRow()==static_cast<unsigned int>(j)
                            || pos.getRow()==static_cast<unsigned int>(j)+1
                            || pos.getRow()==static_cast<unsigned int>(j)-1))
                {

                    pos = {static_cast<unsigned int>(j),static_cast<unsigned int>(i)};
                    found = true;
                    if(this->board_.isInside({static_cast<unsigned int>(j)+1,static_cast<unsigned int>(i)})
                            && this->board_.isMyOwn({static_cast<unsigned int>(j)+1, static_cast<unsigned int>(i)}, current_.getColor()))
                    {
                        count++;
                    }
                    if(this->board_.isInside({static_cast<unsigned int>(j)-1, static_cast<unsigned int>(i)})
                            && this->board_.isMyOwn({static_cast<unsigned int>(j)-1, static_cast<unsigned int>(i)}, current_.getColor()))
                    {
                        count++;
                    }
                }
                if(i==this->board_.getBoard().size()-1
                        && found
                        && count>=3)
                {
                    foulGame=true;
                }
            }
        }
    }
    return foulGame;
}

bool Game::isOver()
{
    for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
    {
        Position posW(0, i);
        Position posB(this->board_.getBoard().size() - 1, i);
        if (this->board_.getPiece(posW).getColor() == White
                || this->board_.getPiece(posB).getColor() == Black)
        {
            return true;
        }
    }
    return false;
}

void Game::select(unsigned int row ,unsigned  int column)
{
    Position p(row, column);
    if(!this->board_.isInside(p))
    {
        throw invalid_argument("the square is not inside the board");
    }
    else if(!isMyPiece(p))
    {
        throw logic_error("Cette pièce ne vous appartient pas ! Réessayez");
    }
    this->selected_ = Position(row, column);
}

void Game::swapPlayers()
{
    Player provisoire = current_;
    current_ = opponent_;
    opponent_ = provisoire;
}

/**
 * @return void
 */
void Game::start()
{
    if (!isOver() && this->board_.isEmpty())
    {
        throw invalid_argument("il y a déjà une parti en cours");
    }
}

vector<Direction> Game::allDirections ()
{
    vector<Direction> dirs;
    dirs.push_back(Direction::N);
    dirs.push_back(Direction::S);
    dirs.push_back(Direction::E);
    dirs.push_back(Direction::O);
    dirs.push_back(Direction::NE);
    dirs.push_back(Direction::SE);
    dirs.push_back(Direction::NO);
    dirs.push_back(Direction::SO);
    return dirs;
}

vector<Move> Game::getMoves(){
    return getMoves(selected_);
}
/**
 * @param selected
 * @return List<Move>
 */
vector<Move> Game::getMoves(Position &selected)
{
    try
    {
        this->board_.isInside(selected);
    }
    catch (const exception e)
    {
        cerr << "La position sélectionnée ne fait pas partie du plateau de jeu. Réessayez : ";
    }
    try
    {
        this->board_.isFree(selected);
    }
    catch (const exception e)
    {
        cerr << "La position selectionnée ne contient pas de pièce. Réessayez : ";
    }
    try
    {
        //this->board_.getSquare(selected).isMyOwn(getCurrent().getColor());
        this->board_.isMyOwn(selected, this->getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }

    Piece piece(this->board_.getPiece(selected).getColor());
    vector<Move> possibleEndingPositions;
    vector<Direction> directions;
    for (unsigned int i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    //if(getNbMoves(selected) == 1)
    {
        for (unsigned int i = 0; i < directions.size(); i++)
        {
            if (this->board_.isInside(selected.next(selected, directions.at(i)))
                    && this->board_.isFree(selected.next(selected, directions.at(i))))
            {
                Move move(this->board_.getPiece(selected), selected, selected.next(selected, directions.at(i)));
                possibleEndingPositions.push_back(move);
            }
        }
    }
    /*else if(getNbMoves(getCurrent()) == 2)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            for (unsigned int i = 0; i < 8; i++) //Car il y a 8 Moves possibles
            {
                if (this->board_.isInside(selected.next(selected, directions.at(i))))
                {
                    Move move(this->board_.getPiece(selected), selected, selected.next(selected, directions.at(i)));
                    possibleEndingPositions.push_back(move);
                }
            }
        }
    }*/
    return possibleEndingPositions;

}

vector<Position> Game::getPossiblePasses(Position &selected)
{
    try
    {
        this->board_.isInside(selected);
    }
    catch (const exception e)
    {
        cerr << "La position sélectionnée ne fait pas partie du plateau de jeu. Réessayez : ";
    }
    try
    {
        this->board_.isFree(selected);
    }
    catch (const exception e)
    {
        cerr << "La position selectionnée ne contient pas de pièce. Réessayez : ";
    }
    try
    {
        this->board_.isMyOwn(selected, getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }
    vector<Position> passPositions;
    for (unsigned i = 0; i < allDirections().size(); i++)
    {
        Position posNext = selected;
        if (this->board_.getPiece(selected).getColor() == WhiteWithBall)
        {
            do
            {
                if (this->board_.getPiece(posNext).getColor() == White)
                {
                    passPositions.push_back(posNext);
                }
                posNext = posNext.next(posNext, allDirections().at(i));
            }
            while (this->board_.isInside(posNext) && (this->board_.isMyOwn(posNext, White) || this->board_.isFree(posNext)));
        }
        if (this->board_.getPiece(selected).getColor() == BlackWithBall)
        {
            do
            {
                if (this->board_.getPiece(posNext).getColor() == Black)
                {
                    passPositions.push_back(posNext);
                }
                posNext = posNext.next(posNext, allDirections().at(i));
            }
            while (this->board_.isInside(posNext) && (this->board_.isMyOwn(posNext, Black) || this->board_.isFree(posNext)));
        }
    }
    return passPositions;
}


/**
 * @return int
 */
int Game::getNbMoves(Player &player)
{
    int nbMoves = 0;
    Position selected(0, 0);
    vector<Direction> directions;
    for (unsigned int i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
    {
        for (unsigned int i = 0; i < this->board_.getBoard()[i].size(); i++)
        {
            for (unsigned int i = 0; i < 8; i++)
            {
                if (this->board_.isInside(selected.next(selected, directions.at(i)))
                        && this->board_.isFree(selected.next(selected, directions.at(i)))
                        && this->board_.isMyOwn(selected, player.getColor()))
                {
                    nbMoves++;
                }
                if (this->board_.isInside(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && this->board_.isFree(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && this->board_.isMyOwn(selected, player.getColor()))
                {
                    nbMoves++;
                }
            }
        }
    }
    return nbMoves;
}

int Game::getNbMoves(Position &selected)
{
    int nbMoves = 0;
    vector<Direction> directions;
    for (unsigned int i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    for (unsigned int i = 0; i < 8; i++)
    {
        if (this->board_.isInside(selected.next(selected, directions.at(i)))
                && this->board_.isFree(selected.next(selected, directions.at(i))))
        {
            nbMoves++;
        }
        if (this->board_.isInside(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                && this->board_.isFree(selected.next(selected.next(selected, directions.at(i)), directions.at(i))))
        {
            nbMoves++;
        }
    }
    return nbMoves;
}

/**
 * @param move
 * @return void
 */
void Game::apply(Move &move)
{
    Piece piece(this->board_.getPiece(move.getStart()).getColor());
    if (this->board_.isFree(move.getEnd()))
    {
        this->board_.put(piece.getColor(), move.getEnd());
        this->board_.remove(move.getStart());
        current_.setNbMoves(current_.getNbMoves()-1);
    }
}

/**
 * @param move
 * @return void
 */
void Game::applyPass(Position &positionThatGives, Position &positionThatReceives)
{
    if (canPassBall(positionThatGives))
    {
        this->board_.applyPass(positionThatGives, positionThatReceives, this->getCurrent().getColor());
    }
}


Piece Game::getPieceSelected()
{
    cout << "getPieceSelected colo : " << this->board_.getPiece(selected_).getColor();
    return this->board_.getPiece(selected_);
}

/**
 * @param player
 * @return boolean
 */
bool Game::hasMoves(Player &player)
{
    return player.getNbMoves() > 0;
}

/**
 * @return Player
 */
Player Game::getWinner()
{
    Player winner(None); //Ajoute condition de anti-jeu
    if (!fairPlay())
    {
        for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
        {
            if (this->board_.getBoard()[0][i].getColor() == White)
            {
                winner.setColor(White);
            }
            if (this->board_.getBoard()[0][i].getColor() == Black)
            {
                winner.setColor(Black);
            }
        }
    }
    return winner;
}

void Game::changePlayer()
{
    if (current_.getColor() == White)
    {
        Player tmp(White);
        tmp = opponent_;
        opponent_ = current_;
        current_ = tmp;
    }
    else
    {
        Player tmp(Black);
        tmp = opponent_;
        opponent_ = current_;
        current_ = tmp;
    }
}

bool Game::sameColors(Color &pieceColor, Color color)
{
    return pieceColor == color;
}

bool Game::isMyPiece(Position &pos)
{
    if (this->getCurrent().getColor() == White)
    {
        if (sameColors(board_.getPiece(pos).getColor(), White)
                || sameColors(board_.getPiece(pos).getColor(), WhiteWithBall))
        {
            return true;
        }
    }
    else if (this->getCurrent().getColor() == Black)
    {
        if (sameColors(board_.getPiece(pos).getColor(), Black)
                || sameColors(board_.getPiece(pos).getColor(), BlackWithBall))
        {
            return true;
        }
    }
    return false;
}

/*int Diaballik::typeOfGame(View view)
{
    string typeOfGame = view.askCommand();
    cout << "boardLength : " << this->getBoard().getBoardLength();
    while (true)
    {
        if (typeOfGame == "1" || typeOfGame == "2") { break; }
        else
        {
            cout << "Vous n'avez pas correctement sélectionné de type de jeu ! Réessayez :" << endl;
            typeOfGame = view.askCommand();
            //break;
        }
    }
    return stoi(typeOfGame.c_str(), nullptr, 16);
}*/
