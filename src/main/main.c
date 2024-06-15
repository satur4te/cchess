#include "common/log.h"
#include "game/board.h"
#include "game/move.h"
#include "tui/tui.h"
#include "tui/parser.h"
#include <stdlib.h>
#include <stdio.h>

int main( void )
{
    log_init(); 
    init_context();
    init_board();

    LOG_INFO("test log info\n", 0);
    LOG_WARNING("test log warning\n", 0);
    LOG_ERROR("test log error\n", 0);
    while(true)
    {
        draw_board();
        print_context();
        char* input;
        input = move_prompt();
        move* current_move = str_to_move(input);

        if (current_move == NULL)
        {
            printf("Couldn't parse the move\n");
            continue;
        }

        if(make_move(current_move))
        {
            update_context();

            // printf("\e[1;1H\e[2J");
        }
        else
        {
            printf("Couldn't make a move\n");
            if(input)
                free(input);
            if(current_move)
                free(current_move);
            break;
        }

    }
    
    log_close();
    return 0;
}
