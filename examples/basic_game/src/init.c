#include "game.h"

static game_t *create_game(char **envp)
{
    game_t *game = AsmCalloc(sizeof(game_t), 0);
    if (!game) {
        AsmPutlstr("AsmAlloc error");
        return (void *)0;
    }
    game->link = AsmCreateLink(envp);
    if (!game->link)
        AsmPutlstr("AsmCreateLink error");
    game->window = AsmCreateWindow(game->link, (AsmSize){800, 600}, "AsmGraphic Rework");
    if (!game->window)
        AsmPutlstr("AsmCreateWindow error");
    game->font = AsmCreateFont(game->link, "fixed");
    if (!game->font)
        AsmPutlstr("AsmCreateFont error");
    game->title.rectangle = AsmCreateRectangle(game->link, (AsmPosSize){355, 30, 90, 30}, AsmPurple);
    if (!game->title.rectangle)
        AsmPutlstr("AsmCreateRectangle error");
    game->title.text = AsmCreateText(game->link, "Mini-Clicker", game->font, (AsmPos){365, 50});
    if (!game->title.text)
        AsmPutlstr("AsmCreateText error");
    game->clicked_text = AsmCreateText(game->link, "Clicked: 0", game->font, (AsmPos){20, 90});
    if (!game->clicked_text)
        AsmPutlstr("AsmCreateText error");
    game->target = AsmCreateCircle(game->link, (AsmPosSize){400 - 100 / 2, 300 - 100 / 2, 100, 100}, (AsmAngle){0.0, 360.0}, AsmGreen);
    if (!game->target)
        AsmPutlstr("AsmCreateCircle error");
    game->update_timer = AsmInitTimer(1 / 60.0);
    if (!game->update_timer)
        AsmPutlstr("AsmInitTimer error");
    game->display_timer = AsmInitTimer(1 / 60.0);
    if (!game->display_timer)
        AsmPutlstr("AsmInitTimer error");
    return game;
}

static void setup_game(game_t *game)
{
    if (AsmOpenWindow(game->window))
        AsmPutlstr("AsmOpenWindow error");
    if (AsmSetColorText(game->title.text, AsmPurple))
        AsmPutlstr("AsmSetColorText error");
}

game_t *init(char **envp)
{
    game_t *game = create_game(envp);
    if (!game)
        return (void *)0;
    
    setup_game(game);

    return game;
}