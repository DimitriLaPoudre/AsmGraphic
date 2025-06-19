#include "game.h"

void update(game_t *game)
{
    char clicked_str[9 + 10 + 1] = "Clicked: ";
    char *clicked_value = AsmGetstr(game->clicked);
    if (clicked_value != (void *)0) {
        AsmStrcat(clicked_str, clicked_value);
        AsmDalloc(clicked_value);
        if (AsmDestroyText(game->clicked_text))
            AsmPutlstr("AsmDestroyText error");
        AsmCreateText(game->link, clicked_str, game->font, (AsmPos){20, 90});
        if (!game->clicked_text)
            AsmPutlstr("AsmCreateText error blabla");
    }
}