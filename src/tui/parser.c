#include "tui/parser.h"
#include <stdlib.h>
#include <stdio.h>

// Guaranteed 4-characters wide input string is required
move* str_to_move(char* input)
{
    // check if input is valid
    if (input[0] < 'a' || input[0] > 'z')
        return (move*) NULL;
    else if (input[1] < '1' || input[1] > '8')
        return (move*) NULL;
    else if (input[2] < 'a' || input[2] > 'z')
        return (move*) NULL;
    else if (input[3] < '1' || input[3] > '8')
        return (move*) NULL;

    move* new_move = (move *) malloc(sizeof(move));

    new_move->src = ((i32)input[0] - 0x61) + ((i32)input[1] - 0x31) * 8;
    new_move->dest = ((i32)input[2] - 0x61) + ((i32)input[3] - 0x31) * 8;
    
    printf("src_move: %lu\n", new_move->src);
    printf("dest_move: %lu\n", new_move->dest);

    return new_move;
}
