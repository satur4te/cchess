#pragma once

#include "common/types.h"

typedef enum {
    KING = 1,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN
} CHESS_PIECES;

typedef enum {
    WHITE = 1,
    BLACK
} CHESS_COLOR;

typedef enum {
    ACTIVE,
    WHITE_CHECKED,
    BLACK_CHECKED,
    WHITE_MATED,
    BLACK_MATED,
    WHITE_RESIGNED,
    BLACK_RESIGNED,
    STALEMATE
} GAME_STATE;

typedef enum {
    REGULAR
} GAME_TYPE;

typedef struct {
   u32 type;
   u32 color;
} chess_piece;

typedef enum {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
} SQUARES; 

typedef struct {
    GAME_TYPE game_type;
    GAME_STATE game_state;
    CHESS_COLOR current_color;
    u32 move_count;
} game_context;


void init_context( void );
void init_board( void );

const char* get_game_state( void );
const char* get_game_type( void );
const char* get_current_color( void );

void cleanup( void );
bool update_context( void );
