#include <ncurses.h>  // Ncurses library
#include "color_class.hpp"  // Custom color class
#include "input_class.hpp"   // Input handling class
#include "logger_class.hpp"  // Logger utility
#include "game_manager_class.hpp"  // GameManager class
#include "player_class.hpp" // Player class
#include "dice_class.hpp" // Dice class
#include <fstream>           // File I/O
#include <iostream>          // Input/Output
#include <string>            // String data structure

using namespace std;

int main() {
    int height, width;
    int color;
    
    initscr();  // Start ncurses mode

    // Get terminal size
    getmaxyx(stdscr, height, width);
    Logger::log("height x width", vector<string>({to_string(height), to_string(width)}));

    noecho();     // Don't echo input
    cbreak();     // Disable line buffering
    curs_set(0);  // Hide the cursor

    setlocale(LC_ALL, "");  // Enable Unicode support
    start_color();  // Enable colors in ncurses

    Input input("Enter text: ", 3, 30, height - 1, (width + 30) / 2);
    colorful();  // Custom color function to generate random colors
    keypad(stdscr, TRUE);               // Enable keypad for special keys
    mousemask(ALL_MOUSE_EVENTS, NULL);  // Enable mouse events

    clear();    // Clear screen to prevent scrolling
    refresh();  // Refresh / redraw screen

    color = rand() % 32 + 1;
    attron(COLOR_PAIR(color));  // Set color pair
    printw("Welcome to the Dice Game!\n");
    refresh();
    attroff(COLOR_PAIR(color));  // Unset color pair

    string player1Name, player2Name;
    mvprintw(height / 2, (width - 20) / 2, "Enter Player 1's name: ");
    refresh();
    char name[30];
    echo();
    getstr(name);
    player1Name = string(name);

    mvprintw(height / 2 + 2, (width - 20) / 2, "Enter Player 2's name: ");
    refresh();
    getstr(name);
    player2Name = string(name);

    GameManager game(player1Name, player2Name);  // Create GameManager with two players
    game.start();  // Start the game

    while (true) {
        int ch = getch();

        input.printBorder();
        input.printInput(height - 1, (width - 30) / 2 + 15);
        input.captureInput();

        if (ch == 'q')  // Exit on 'q'
            break;
        else if (ch == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_CLICKED) {
                    mvprintw(event.y, event.x, "Clicked at %d, %d", event.y, event.x);
                    Logger::log("Mouse clicked at", vector<int>({event.x, event.y}));
                }
            }
        } else if (ch == KEY_BACKSPACE || ch == 127) {
            Logger::log("You hit the backspace", "true");
        } else if (ch >= 32 && ch <= 126) {  // Printable characters
            // Handle characters as input
            string inputText;
            inputText += ch;
            Logger::log("Input string:", inputText);
        } else if (ch == '\n' || ch == KEY_ENTER) {
            Logger::log("You hit the enter key", "true");
        }

        // Refresh the display with latest status
        Colorly::randColor();
        Colorly::colorOn();
        Logger::printLastLine(stdscr);
        Colorly::colorOff();
        refresh();
    }

    endwin();  // End ncurses mode

    return 0;
}
