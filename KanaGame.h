//
// Created by rober on 01/02/2026.
//

#ifndef KANASS_KANAGAME_H
#define KANASS_KANAGAME_H


#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <string>
#include "kana.h"

class KanaGame {
public:
    KanaGame(int argc, char** argv);
    ~KanaGame();
    static void check_cb(Fl_Widget*, void*);
    static void next_cb(Fl_Widget*, void*);
    static void start_cb(Fl_Widget*, void*);
    int run();

private:
    Kana* kana_game;
    string current_kana;
    bool is_special_kana;
    bool is_hiragana;
    Fl_Box* kana_display;
    Fl_Input* romaji_input;
    Fl_Output* feedback;
    Fl_Group* main_menu;
    Fl_Group* main_game;
    Fl_Window* win;
    string current_romaji;
};


#endif //KANASS_KANAGAME_H
