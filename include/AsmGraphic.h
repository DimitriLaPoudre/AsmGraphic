/*
** EPITECH PROJECT, 2023
** assembly_projects
** File description:
** AsmLib.h
*/

#ifndef AsmGraphic_
    #define AsmGraphic_

    #include "AsmLibrary.h"

#define AsmEventRequestError 0
#define AsmEventReplyError 1
#define AsmEventKeyPressed 2
#define AsmEventKeyRelease 3
#define AsmEventMouseButtonPressed 4
#define AsmEventMouseButtonRelease 5
#define AsmEventMouseMoved 6
#define AsmEventGetFocus 9
#define AsmEventLostFocus 10
#define AsmEventWindowModified 22
#define AsmEventSpecial 33
#define AsmEventClose 35

#define AsmRed (AsmColor){0, 255, 0, 0}
#define AsmGreen (AsmColor){0, 0, 255, 0}
#define AsmBlue (AsmColor){0, 0, 0, 255}
#define AsmYellow (AsmColor){0, 255, 255, 0}
#define AsmMagenta (AsmColor){0, 0, 255, 255}
#define AsmCyan (AsmColor){0, 255, 0, 255}
#define AsmPurple (AsmColor){0, 200, 0, 255}
#define AsmWhite (AsmColor){0, 255, 255, 255}
#define AsmBlack (AsmColor){0, 0, 0, 0}

//link: +0 4byte fd socket | +4 8byte thread_info | +12 8byte header | +20 request body
// thread_info: +0 1byte futex | +1 1byte conditionnal variable | +2 4byte thread id | +6 8byte thread_stack | +14 8byte event_queue
// event_queue: +0 8byte next_event | +8 32byte event_body
typedef struct AsmLink AsmLink;

// +0 4byte window_id | +4 4byte pixmap_id | +8 8byte link_fd | +16 4byte window_pos | +20 4byte window_size | +24 1byte window_depth | +25 1byte window_event (1 == move | 2 == resize) | +26 4byte window_gc | +30 4byte color
typedef struct AsmWindow AsmWindow;

// +0 4byte font_id | +4 8byte link
typedef struct AsmFont AsmFont;

// +0 8byte string of 255 char max | +8 8byte link | +16 4byte gc_id | +20 4byte pos | +24 4byte foreground color
typedef struct AsmText AsmText;

// +0 4byte pos | +4 4byte size | +8 8byte link | +16 4byte gc_id | +20 4byte color
typedef struct AsmRectangle AsmRectangle;

// +0 4byte pos | +4 4byte size | +8 8byte link | +16 4byte gc_id | +20 4byte color | +24 2byte start_angle | +26 2byte end_angle
typedef struct AsmCircle AsmCircle;

typedef struct AsmColor{
    unsigned char unused;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} AsmColor;

typedef struct AsmPos{
    short x;
    short y;
} AsmPos;

typedef struct AsmSize{
    unsigned short width;
    unsigned short heigth;
} AsmSize;

typedef struct AsmPosSize{
    short x;
    short y;
    unsigned short width;
    unsigned short height;
} AsmPosSize;

typedef struct AsmAngle{
    double start_angle;
    double end_angle;
} AsmAngle;

typedef struct AsmEvent{
    union {
        struct {
            unsigned char type;
            unsigned char keycode;
            char data1[18];
            AsmPos pos_global;
            AsmPos pos_window;
            char data2[4];
        } key;
        struct {
            unsigned char type;
            unsigned char button;
            char data1[18];
            AsmPos pos_global;
            AsmPos pos_window;
            char data2[4];
        } mouse;
        struct {
            unsigned char type;
            unsigned char data[31];
        } info;
    };
} AsmEvent;

typedef struct AsmTimer AsmTimer;

// Resources Gestion

// // AsmLink

AsmLink *AsmCreateLink(char **env);

char AsmPollEvent(AsmEvent *event, AsmWindow *window);

char AsmCloseLink(AsmLink *link);

// // AsmWindow

AsmWindow *AsmCreateWindow(AsmLink *link, AsmSize size, char *name);

char AsmOpenWindow(AsmWindow *window);

char AsmIsOpenWindow(AsmWindow *window);

char AsmHasMovedWindow(AsmWindow *window);

char AsmHasResizedWindow(AsmWindow *window);

AsmPos AsmGetPositionWindow(AsmWindow *window);

AsmSize AsmGetSizeWindow(AsmWindow *window);

char AsmSetPositionWindow(AsmWindow *window, AsmPos position);

char AsmSetSizeWindow(AsmWindow *window, AsmSize size);

char AsmClearWindow(AsmWindow *window, AsmColor color);

char AsmDisplayWindow(AsmWindow *window);

char AsmRenameWindow(AsmWindow *window, char *name);

char AsmCloseWindow(AsmWindow *window);

char AsmDestroyWindow(AsmWindow *window);

// // AsmText

AsmFont *AsmCreateFont(AsmLink *link, char *font);

char AsmDestroyFont(AsmFont *font);

AsmText *AsmCreateText(AsmLink *link, char *string, AsmFont *font, AsmPos pos);

AsmColor AsmGetColorText(AsmText *text);

AsmPos AsmGetPositionText(AsmText *text);

char AsmSetColorText(AsmText *text, AsmColor color);

char AsmSetPositionText(AsmText *text, AsmPos position);

char AsmDrawText(AsmWindow *window, AsmText *text);

char AsmDestroyText(AsmText *text);

// // AsmRectangle

AsmRectangle *AsmCreateRectangle(AsmLink *link, AsmPosSize dimension, AsmColor color);

AsmColor AsmGetColorRectangle(AsmRectangle *rectangle);

AsmPosSize AsmGetDimensionRectangle(AsmRectangle *rectangle);

char AsmSetColorRectangle(AsmRectangle *rectangle, AsmColor color);

char AsmSetDimensionRectangle(AsmRectangle *rectangle, AsmPosSize dimension);

char AsmDrawRectangle(AsmWindow *window, AsmRectangle *rectangle);

char AsmDestroyRectangle(AsmRectangle *rectangle);

// // AsmCircle

AsmCircle *AsmCreateCircle(AsmLink *link, AsmPosSize dimension, AsmAngle angle, AsmColor color);

AsmAngle AsmGetAngleCircle(AsmCircle *circle);

AsmColor AsmGetColorCircle(AsmCircle *circle);

AsmPosSize AsmGetDimensionCircle(AsmCircle *circle);

char AsmSetAngleCircle(AsmCircle *circle, AsmAngle Angle);

char AsmSetColorCircle(AsmCircle *circle, AsmColor color);

char AsmSetDimensionCircle(AsmCircle *circle, AsmPosSize dimension);

char AsmDrawCircle(AsmWindow *window, AsmCircle *circle);

char AsmDestroyCircle(AsmCircle *circle);

// // AsmTask

AsmTimer *AsmInitTimer(double delay);

char AsmTickTimer(AsmTimer *timer);

char AsmDestroyTimer(AsmTimer *timer);

// // Fun

char AsmBell(AsmLink *link, unsigned char volume);

#endif