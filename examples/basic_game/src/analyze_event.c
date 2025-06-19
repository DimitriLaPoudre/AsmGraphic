#include "game.h"

void analyze_event(AsmEvent event, game_t *game)
{
    switch (event.info.type) {
        case AsmEventKeyPressed:
            AsmPrint("Key pressed: %b\n", event.key.keycode);
            break;
        case AsmEventKeyRelease:
            AsmPrint("Key release: %b\n", event.key.keycode);
            break;
        case AsmEventMouseButtonPressed:
            AsmPrint("Button pressed: %b at x: %w, y: %w\n", event.mouse.button, event.mouse.pos_window.x, event.mouse.pos_window.y);
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
            AsmPrint("Mouse moved at x: %w, y: %w\n", event.mouse.pos_window.x, event.mouse.pos_window.y);
            break;
        case AsmEventMouseButtonRelease:
            AsmPrint("Button release: %b\n", event.mouse.button);
            if (game->clicked_state == 1 && event.mouse.button == 1) {
                game->clicked_state = 0;
                AsmSetColorCircle(game->target, AsmGreen);
                AsmSetDimensionCircle(game->target, (AsmPosSize){400 - 100 / 2, 300 - 100 / 2, 100, 100});
            }
            break;
        case AsmEventGetFocus:
            AsmPutlstr("Window get focus");
            break;
        case AsmEventLostFocus:
            AsmPutlstr("Window lost focus");
            break;
        case AsmEventWindowModified:
            AsmPutlstr("Window modified");
            if (AsmHasMovedWindow(game->window))
                AsmPutlstr("Window moved");
            if (AsmHasResizedWindow(game->window))
                AsmPutlstr("Window resized");
            break;
        case AsmEventClose:
            if (AsmCloseWindow(game->window))
                AsmPutlstr("AsmCloseWindow error");
            break;
        default:
            AsmPrint("Event unknow: %d\n", event.info.type);
    }
}