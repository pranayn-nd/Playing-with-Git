#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h> // for usleep()
#include <ctime>    // for srand(time(0))
using namespace std;

// Game board size
const int width = 40;
const int height = 20;

// Snake head position
int x = width / 2;
int y = height / 2;

// Snake body
int bodyX[100], bodyY[100];
int nTail = 0;

// Food position
int foodX, foodY;

// Score
int score = 0;

// Direction enum
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir = STOP;

// Draw function
void draw() {
    clear(); // clear screen

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printw("#"); // border
            }
            else if (i == y && j == x) {
                printw("O"); // head
            }
            else if (i == foodY && j == foodX) {
                printw("*"); // food
            }
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (bodyX[k] == j && bodyY[k] == i) {
                        printw("o"); // body
                        print = true;
                    }
                }
                if (!print) printw(" "); // empty space
            }
        }
        printw("\n");
    }
    printw("Score: %d\n", score);
    refresh();
}

// Input function
void input() {
    int ch = getch(); // non-blocking
    switch(ch) {
        case KEY_LEFT:  if(dir != RIGHT) dir = LEFT; break;
        case KEY_RIGHT: if(dir != LEFT) dir = RIGHT; break;
        case KEY_UP:    if(dir != DOWN) dir = UP; break;
        case KEY_DOWN:  if(dir != UP) dir = DOWN; break;
        case 'q':       // quit
            endwin();
            exit(0);
    }
}

// Logic function
void logic() {
    // Move tail
    int prevX = bodyX[0], prevY = bodyY[0];
    int prev2X, prev2Y;
    bodyX[0] = x;
    bodyY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = bodyX[i];
        prev2Y = bodyY[i];
        bodyX[i] = prevX;
        bodyY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move head
    switch(dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default: break;
    }

    // Check wall collision
    if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1) {
        endwin();
        cout << "Game Over! Final Score: " << score << endl;
        exit(0);
    }

    // Check self-collision
    for (int i = 0; i < nTail; i++) {
        if (bodyX[i] == x && bodyY[i] == y) {
            endwin();
            cout << "Game Over! You hit yourself. Final Score: " << score << endl;
            exit(0);
        }
    }

    // Check if food eaten
    if (x == foodX && y == foodY) {
        score++;
        nTail++;

        // Spawn new food
        foodX = rand() % (width - 2) + 1;
        foodY = rand() % (height - 2) + 1;
    }
}

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    // Initialize random seed
    srand(time(0));
    foodX = rand() % (width - 2) + 1;
    foodY = rand() % (height - 2) + 1;

    dir = STOP;

    while (true) {
        draw();
        input();
        logic();

        // Speed control
        usleep(200000 - score * 5000); // snake speeds up with score
        if (200000 - score * 5000 < 50000) // min speed
            usleep(50000);
    }

    endwin();
    return 0;
}
