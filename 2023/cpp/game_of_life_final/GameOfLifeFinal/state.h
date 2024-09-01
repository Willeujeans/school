#ifndef STATE_H_DEFINED
#define STATE_H_DEFINED

#include <string>

struct State {
    std::string game_board;
    char live;
    char dead;
    State(const std::string& board = "", char liveChar = '\0', char deadChar = '\0') : game_board(board), live(liveChar), dead(deadChar) {}
};

#endif // GAME_SAVE_STATE_HPP
