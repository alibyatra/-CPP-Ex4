#include "Board.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"

namespace WarGame 
{
    Soldier*& Board::operator[](std::pair<int,int> location){
            Board::check(location);
            return Board::board[location.first][location.second];
        }

        Soldier* Board::operator[](std::pair<int,int> location) const{
            Board::check(location);
            return Board::board[location.first][location.second];
        }

        void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) 
        {
            if (!has_soldiers(player_number)) 
            {
                return;
            }
            Board::check(source);
            if (board[source.first][source.second] == nullptr)
            {
                throw std::invalid_argument("ERROR! the given source location is null");
            }
            else if (board[source.first][source.second]->team != player_number) 
            {
            throw std::invalid_argument("ERROR! this soldier belongs to the opposing team");
            }
            std::pair<int, int> move (source);
		    switch (direction)
		    {
		    case Left:
                if (move.second - 1 < 0) 
                {
                    throw std::invalid_argument("ERROR! An illegal move");
                }
                move.second -= 1;
                break;
            case Right:
                if (move.second + 1 == Board::board[0].size()) 
                {
                    throw std::invalid_argument("ERROR! An illegal move");
                }
                move.second += 1;
                break;
            case Up:
                if (move.first + 1 == Board::board.size()) 
                {
                    throw std::invalid_argument("ERROR! An illegal move");
                }
                move.first += 1;
                break;
            case Down:
                if (move.first - 1 < 0) 
                {
                    throw std::invalid_argument("ERROR! An illegal move");
                }
                move.first -= 1;
                break;
		    }
            if (board[move.first][move.second] != nullptr) {
            throw std::invalid_argument("ERROR! there is already another soldier at the move");
        }
        board[move.first][move.second] = board[source.first][source.second];
        board[source.first][source.second] = nullptr;
        if (board[move.first][move.second]->commander) 
        {
            board[move.first][move.second]->activate(board, move);
            board[move.first][move.second]->activateTogether(board);
        } 
        else 
        {
            board[move.first][move.second]->activate(board, move);
        }
    }

    bool Board::has_soldiers(uint player_number) const 
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == nullptr)
                {
                    continue;
                }
                if (board[i][j]->team == player_number)
                {
                    return true;
                }
            }
        }
        return false;
    }
    void Board::check(std::pair<int,int> location) const 
    {
        if (location.first < 0 | location.first >= board.size()) 
        {
            throw std::runtime_error("ERROR! the given location is out of bounds");
        }
        else if (location.second < 0 | location.second >= board[0].size()) 
        {
            throw std::runtime_error("ERROR! the given location is out of bounds");
        }
    }
};