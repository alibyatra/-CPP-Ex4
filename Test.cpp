#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;
using namespace WarGame;

TEST_CASE("First Game")
{
    Board board(5, 5);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new FootSoldier(1);
    board[{0, 2}] = new Sniper(1);
    board[{0, 4}] = new Paramedic(1);

    CHECK(board.has_soldiers(1)); 
    CHECK(!board.has_soldiers(2));
    board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new FootSoldier(2);
    board[{7, 2}] = new Sniper(2);
    board[{7, 4}] = new Paramedic(2);

    CHECK(board.has_soldiers(2));
    board.move(1, {0, 1}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 3}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 4}, Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 1}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 3}, Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 4}, Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    }

TEST_CASE("Second Game")
{
    Board board(7, 7);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new FootSoldier(1);
    board[{0, 2}] = new Sniper(1);
    board[{0, 4}] = new SniperCommander(1);
    board[{0, 6}] = new ParamedicCommander(1);
    board[{0, 7}] = new Paramedic(1);

    CHECK(board.has_soldiers(1)); 
    CHECK(!board.has_soldiers(2));
    board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new FootSoldier(2);
    board[{7, 2}] = new Sniper(2);
    board[{7, 4}] = new SniperCommander(2);
    board[{7, 6}] = new ParamedicCommander(2);
    board[{7, 7}] = new Paramedic(2);

    CHECK(board.has_soldiers(2));
    board.move(1, {0, 1}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 3}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 5}, Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 7}, Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 1}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 3}, Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 5}, Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 7}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {3, 3}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {4, 4}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {5, 5}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 6}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {2, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {3, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {4, 4}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {5, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {6,6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
}
