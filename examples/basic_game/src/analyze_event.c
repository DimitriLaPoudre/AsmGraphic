#include "game.h"

void analyze_event(AsmEvent event, game_t *game)
{
    switch (event.info.type) {
        case AsmEventKeyPressed:
            break;
        case AsmEventKeyRelease:
            break;
        case AsmEventMouseButtonPressed:
            if (event.mouse.button == 1
            && (event.mouse.pos_window.x - 400) * (event.mouse.pos_window.x - 400)
            + (event.mouse.pos_window.y - 300) * (event.mouse.pos_window.y - 300) <= 50 * 50) {
                game->clicked++;
                game->clicked_state = 1;
                AsmSetColorCircle(game->target, AsmRed);
                AsmSetDimensionCircle(game->target, (AsmPosSize){400 - 96 / 2, 300 - 96 / 2, 96, 96});
                if (AsmBell(game->link, 100))
                    AsmPutlstr("AsmBell error");
            }
            break;
        case AsmEventMouseMoved:
            break;
        case AsmEventMouseButtonRelease:
            if (game->clicked_state == 1 && event.mouse.button == 1) {
                game->clicked_state = 0;
                AsmSetColorCircle(game->target, AsmGreen);
                AsmSetDimensionCircle(game->target, (AsmPosSize){400 - 100 / 2, 300 - 100 / 2, 100, 100});
            }
            break;
        case AsmEventGetFocus:
            break;
        case AsmEventLostFocus:
            break;
        case AsmEventWindowModified:
            break;
        case AsmEventClose:
            if (AsmCloseWindow(game->window))
                AsmPutlstr("AsmCloseWindow error");
            break;
        default:
            AsmPrint("Event unknow: %d\n", event.info.type);
    }
}