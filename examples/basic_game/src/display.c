#include "game.h"

void display(game_t *game)
{
    if (AsmClearWindow(game->window, (AsmColor){0, 0, 0, 0}))
        AsmPutlstr("AsmClearWindow error");
    if (AsmDrawText(game->window, game->clicked_text))
        AsmPutlstr("AsmDrawText error");
    if (AsmDrawRectangle(game->window, game->title.rectangle))
        AsmPutlstr("AsmDrawRectangle error");
    if (AsmDrawText(game->window, game->title.text))
        AsmPutlstr("AsmDrawText error");
    if (AsmDrawCircle(game->window, game->target))
        AsmPutlstr("AsmDrawCircle error");
    if (AsmDisplayWindow(game->window))
        AsmPutlstr("AsmDisplayWindow error");
}