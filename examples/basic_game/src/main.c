#include "game.h"

int main(int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;
    game_t *game = init(envp);
    if (!game) {
        return 1;
    }

    AsmEvent event;
    while (AsmIsOpenWindow(game->window)) {
        while (AsmPollEvent(&event, game->window)) {
            analyze_event(event, game);
        }
        if (AsmTickTimer(game->update_timer)) {
            update(game);
        }
        if (AsmTickTimer(game->display_timer)) {
            display(game);
        }
    }

    destroy(game);
    return 0;
}