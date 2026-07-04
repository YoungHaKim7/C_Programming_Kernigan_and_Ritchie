#ifndef CONIO_H
#define CONIO_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

static struct termios orig_termios;

static inline void terminal_init(void) {
    struct termios new_termios;

    // Get current terminal settings
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;

    // Disable canonical mode and echo
    new_termios.c_lflag &= ~(ICANON | ECHO);
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

static inline void terminal_restore(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

static bool terminal_initialized = false;

static inline void ensure_terminal_init(void) {
    if (!terminal_initialized) {
        terminal_init();
        terminal_initialized = true;
        atexit(terminal_restore);
    }
}

static inline int kbhit(void) {
    ensure_terminal_init();

    int byteswaiting;
    ioctl(STDIN_FILENO, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}

static inline int getch(void) {
    ensure_terminal_init();

    char ch;
    read(STDIN_FILENO, &ch, 1);
    return (int)ch;
}

#endif /* CONIO_H */
