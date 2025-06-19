#ifndef GAME_H
    #define GAME_H

    #include "AsmGraphic.h"

typedef struct game_s game_t;
typedef struct button_s button_t;

struct button_s {
    AsmRectangle *rectangle;
    AsmText *text;
};

struct game_s {
    AsmLink *link;
    AsmWindow *window;
    AsmFont *font;
    AsmText *clicked_text;
    unsigned long clicked;
    unsigned char clicked_state;
    button_t title;
    AsmCircle *target;
    AsmTimer *update_timer;
    AsmTimer *display_timer;
};

game_t *init(char **envp);
void analyze_event(AsmEvent event, game_t *game);
void update(game_t *game);
void display(game_t *game);
void destroy(game_t *game);

#endif // GAME_H