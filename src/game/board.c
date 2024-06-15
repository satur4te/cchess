#include "game/board.h"
#include "common/log.h"

// Main game board. 0 - A1 square, 7 - A2 square, 63 - H8.  
chess_piece board[64];
game_context context;

// Init global context to start the game
void init_context( void )
{
    context.game_type = REGULAR;
    context.game_state = ACTIVE;
    context.current_color = WHITE;

    LOG_INFO("global context initiated\n", 0);
}

void init_board( void )
{
    if (context.game_type == REGULAR)
    {

        // init whites side
        board[A1].type = ROOK;
        board[A1].color = WHITE;

        board[B1].type = KNIGHT;
        board[B1].color = WHITE;
        
        board[C1].type = BISHOP;
        board[C1].color = WHITE;
        
        board[D1].type = QUEEN;
        board[D1].color = WHITE;

        board[E1].type = KING;
        board[E1].color = WHITE;

        board[F1].type = BISHOP;
        board[F1].color = WHITE;

        board[G1].type = KNIGHT;
        board[G1].color = WHITE;

        board[H1].type = ROOK;
        board[H1].color = WHITE;

        for(int i = A2; i <= H2; i++)
        {
            board[i].type = PAWN;
            board[i].color = WHITE;
        }

        // init black side
        board[A8].type = ROOK;
        board[A8].color = BLACK;

        board[B8].type = KNIGHT;
        board[B8].color = BLACK;
        
        board[C8].type = BISHOP;
        board[C8].color = BLACK;
        
        board[D8].type = QUEEN;
        board[D8].color = BLACK;

        board[E8].type = KING;
        board[E8].color = BLACK;

        board[F8].type = BISHOP;
        board[F8].color = BLACK;

        board[G8].type = KNIGHT;
        board[G8].color = BLACK;

        board[H8].type = ROOK;
        board[H8].color = BLACK;

        for(int i = A7; i <= H7; i++)
        {
            board[i].type = PAWN;
            board[i].color = BLACK;
        }
    }
}

const char* get_game_state( void )
{
    switch(context.game_state)
    {
        case ACTIVE:
            return "Active";
        case WHITE_CHECKED:
            return "White's king is in check";
        case BLACK_CHECKED:
            return "Black's king is in check";
        case WHITE_MATED:
            return "White's king is mated";
        case BLACK_MATED:
            return "Black's king is mated";
        case WHITE_RESIGNED:
            return "White has resigned";
        case BLACK_RESIGNED:
            return "Black has resigned";
        case STALEMATE:
            return "Stalemate";
        default:
            return "Unknown state";
    }
}

const char* get_game_type( void )
{
    switch(context.game_state)
    {
        case REGULAR:
            return "Regular";
        default:
            return "Unknown game type";
    }
}

const char* get_current_color( void )
{
    switch(context.current_color)
    {
        case WHITE:
            return "White";
        case BLACK:
            return "Black";
        default:
            return "Unknown color";
    }
}

void cleanup( void )
{
    return;
}

bool update_context( void )
{
    // switch color
    if(context.current_color == WHITE)
        context.current_color = BLACK;
    else
        context.current_color = WHITE;
    
    context.move_count++;
    return true;
}
