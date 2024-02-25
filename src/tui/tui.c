#include <stdlib.h>
#include <stdio.h>
#include "common/types.h"
#include "common/log.h"
#include "game/board.h"
#include "tui/tui.h"

extern chess_piece board[];

static char piece_to_char(chess_piece piece);

static char piece_to_char(chess_piece piece)
{
    char piece_char;
    switch (piece.type)
    {
        case PAWN:
            piece_char = PAWN_CHAR;
            break;
        case ROOK:
            piece_char = ROOK_CHAR;
            break;
        case KNIGHT:
            piece_char = KNIGHT_CHAR;
            break;
        case BISHOP:
            piece_char = BISHOP_CHAR;
            break;
        case QUEEN:
            piece_char = QUEEN_CHAR;
            break;
        case KING:
            piece_char = KING_CHAR;
            break;
        default:
            piece_char = ' ';
            break;
    }

    if (piece.color == WHITE && piece_char != ' ')
    {
        piece_char -= 32;
    }


    return piece_char;
}

void draw_board( void )
{
    for(int i = 7; i >= 0; i--)
    {
        for(int j = 0; j < 8; j++)
        {
            chess_piece piece = board[i * 8 + j];
            if (piece.type != 0 && piece.color != 0)
            {
                printf("%c ", piece_to_char(piece));
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void print_context( void )
{
    printf("\nCurrent game state: %s\n", get_game_state());
    printf("Game type: %s\n", get_game_type());
    printf("Current color: %s\n", get_current_color());
}

char* move_prompt( void )
{
    printf("Input the move: ");
    char* input = (char *)malloc(sizeof(char) * 5);
    scanf("%4s", input);

    if(!clear_stream(stdin))
    {
        LOG_WARNING("clear_stream returned false!\n", 0);
    }

    printf("\n");
    return input;
}

bool clear_stream(FILE* fp)
{
    int ch;
    while((ch = getc(fp)) != EOF && ch != '\n')
    {
        continue;
    }
    return ch == EOF;
}
