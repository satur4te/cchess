#pragma once

#include <stdbool.h>
#include "common/types.h"

typedef struct {
    u32 src;
    u32 dest;
} move;

typedef enum {
    PAWN_REGULAR = 8,
    PAWN_CAPTURE_LEFT = 7,
    PAWN_CAPTURE_RIGHT = 9,
    PAWN_DOUBLE_JUMP = 16
} PAWN_OFFSET;

typedef enum {
    ROOK_HORIZONTAL = 8,
    ROOK_VERTICAL = 1,
} ROOK_OFFSET;

typedef enum {
    KNIGHT1 = 17,
    KNIGHT2 = 10,
    KNIGHT3 = -6,
    KNIGHT4 = -15,
    KNIGHT5 = -17,
    KNIGHT6 = -10,
    KNIGHT7 = 6,
    KNIGHT8 = 15
} KNIGHT_OFFSET;

typedef enum {
    BISHOP_DIAGONAL1 = 7,
    BISHOP_DIAGONAL2 = 9
} BISHOP_OFFSET;

typedef enum {
    KING1 = 7,
    KING2 = 8,
    KING3 = 9,
    KING4 = 1
} KING_OFFSET;

bool make_move(move* current_move);
