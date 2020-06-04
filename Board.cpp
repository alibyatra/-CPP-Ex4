#include "Board.hpp"
#include <map>

using namespace std;

namespace WarGame 
{
    std::map<int, int> m;
    Soldier *&Board :: operator[](std::pair<int,int> location){
             return board[location.first][location.second];
        }

        Soldier *Board:: operator[](std::pair<int,int> location) const{
            return  board[location.first][location.second];
        }

        void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) 
        {
            if ((*this)[source] == nullptr)
            {
                throw runtime_error("No soldier at the source point");
            }
            Soldier *sol = (*this)[source];
            if (sol->getPlayerNum() != player_number)
            {
                throw runtime_error("Illegal Move");
            }
            std::pair<int, int> move;
		    switch (direction)
		    {
		    case Left:
                move.first = source.first;
                move.second = source.second - 1;
                break;
            case Right:
                move.first = source.first;
                move.second = source.second + 1;
                break;
            case Up:
                move.first = source.first + 1;
                move.second = source.second;
                break;
            case Down:
                move.first = source.first - 1;
                move.second = source.second;
                break;
		    }
            if(move.first >= board.size() || move.first < 0 || move.second >= board[0].size() || move.second < 0) 
			throw invalid_argument("got out from the board");
            if((*this)[move] = nullptr)
            {
                throw runtime_error("Dest has a soldier already");
            }
		    (*this)[move] = sol;
            (*this)[source] = nullptr;
		    sol->activate(board, move);
        }

         bool Board::has_soldiers(uint player_number) const 
        {
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[i].size(); j++)
                {
                    Soldier *check = this->board[i][j];
                    if (check != nullptr)
                    {
                        if (check->getPlayerNum() == player_number)
                        return true;
                    }
                }
            }
            return false;
        }
}