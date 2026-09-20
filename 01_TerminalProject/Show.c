#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <locale.h>
#include <string.h>

#define DX 7
#define DY 3

#define SPACE_KEY 32
#define ESC_KEY 27

int
main(int argc, char *argv[]) {

    if (argc == 1) {
        printf("No file passed!\n");
        return 0;
    } 

    FILE *file = fopen(argv[1], "r");
    
    if (file == NULL) {
        return 1;
    }

    WINDOW *frame, *win;
    int c = 0;

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    refresh();

    frame = newwin(LINES - 2 * DY, COLS - 2 * DX, DY, DX);
    box(frame, 0, 0);
    mvwaddstr(frame, 0, (int)((COLS - 2 * DX - 5) / 2), argv[1]);
    wrefresh(frame);

    int NLINES = LINES - 2 * DY - 2;
    int NCOLS  = COLS - 2 * DX- 2;

    win = newwin(NLINES, NCOLS, DY + 1, DX + 1);
    keypad(win, TRUE);
    scrollok(win, TRUE);

    char buffer[NCOLS];

    for (int ln_idx = 0; ln_idx < NLINES; ++ln_idx) {
        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            wprintw(win, "%s", buffer);
        }
    }

    while (1) {
        c = wgetch(win);
        if (c == ESC_KEY)
            break;
        if (c != SPACE_KEY)
            continue;

        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            wprintw(win, "%s", buffer);
        }
    }

    delwin(win);
    delwin(frame);
    endwin();

    fclose(file);

    return 0;
}
