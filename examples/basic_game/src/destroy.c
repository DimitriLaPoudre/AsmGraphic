#include "game.h"

void destroy(game_t *game)
{
    if (AsmDestroyTimer(game->display_timer))
        AsmPutlstr("AsmDestroyTimer error");
    if (AsmDestroyTimer(game->update_timer))
        AsmPutlstr("AsmDestroyTimer error");
    if (AsmDestroyCircle(game->target))
        AsmPutlstr("AsmDestroyCircle error");
    if (AsmDestroyText(game->title.text))
        AsmPutlstr("AsmDestroyText error");
    if (AsmDestroyRectangle(game->title.rectangle))
        AsmPutlstr("AsmDestroyRectangle error");
    if (AsmDestroyText(game->clicked_text))
        AsmPutlstr("AsmDestroyText error");
    if (AsmDestroyFont(game->font))
        AsmPutlstr("AsmDestroyFont error");
    if (AsmDestroyWindow(game->window))
        AsmPutlstr("AsmDestoyWindow error");
    if (AsmCloseLink(game->link))
        AsmPutlstr("AsmCloseLink error");
    AsmDalloc(game);
    AsmShowMemory();
}