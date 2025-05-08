#include "Input.h"
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

void Input::init() {
#ifndef _WIN32
    // Unix: Set terminal to non-canonical mode
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Set stdin to non-blocking
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
#endif
    // Windows: No initialization needed for _getch
}

void Input::cleanup() {
#ifndef _WIN32
    // Unix: Restore terminal settings
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    oldt.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    // Restore blocking mode
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) & ~O_NONBLOCK);
#endif
    // Windows: No cleanup needed
}

Input::Key Input::getKey() {
#ifdef _WIN32
    if (_kbhit()) {
        int c = _getch();
        if (c == 224 || c == 0) { // Extended key (arrow keys in Windows)
            c = _getch();
            switch (c) {
                case 72: return UP;    // Up arrow
                case 80: return DOWN;  // Down arrow
                case 75: return LEFT;  // Left arrow
                case 77: return RIGHT; // Right arrow
            }
        } else if (c == 'q' || c == 'Q') {
            return QUIT;
        }
    }
    return NONE;
#else
    char c;
    int nread = read(STDIN_FILENO, &c, 1);
    if (nread <= 0) {
        return NONE;
    }

    // Unix: Check for escape sequence (arrow keys)
    if (c == 27) { // ESC
        char seq[2];
        if (read(STDIN_FILENO, &seq[0], 1) <= 0) return NONE;
        if (read(STDIN_FILENO, &seq[1], 1) <= 0) return NONE;
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': return UP;
                case 'B': return DOWN;
                case 'C': return RIGHT;
                case 'D': return LEFT;
            }
        }
    } else if (c == 'q' || c == 'Q') {
        return QUIT;
    }
    return NONE;
#endif
}