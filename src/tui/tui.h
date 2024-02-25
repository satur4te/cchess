#pragma once

#include <stdio.h>
#include <stdbool.h>

#define PAWN_CHAR 'p'
#define ROOK_CHAR 'r'
#define KNIGHT_CHAR 'n'
#define BISHOP_CHAR 'b'
#define QUEEN_CHAR 'q'
#define KING_CHAR 'k'

void draw_board( void );
void print_context( void );

char* move_prompt( void );
bool clear_stream(FILE* fp);
