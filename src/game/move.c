#include "game/board.h"
#include "common/types.h"
#include "tui/parser.h"

extern chess_piece board[];
extern game_context context;

bool make_move(move* current_move)
{
    // check if piece exists
    if (board[current_move->src].color == 0 && board[current_move->src].type == 0)
    {
        return false;
    }
    // check if correct color
    if (board[current_move->src].color != context.current_color)
    {
        return false;
    }

    // make a move
    board[current_move->dest] = board[current_move->src];
    board[current_move->src].type = 0;
    board[current_move->src].color = 0;

    return true;
}
