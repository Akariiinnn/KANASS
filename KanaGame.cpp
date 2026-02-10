//
// Created by rober on 01/02/2026.
//
#define _HAS_STD_BYTE 0
#include "KanaGame.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <iostream>

using namespace std;

KanaGame::KanaGame(int argc, char** argv) {
    srand(static_cast<unsigned>(time(nullptr)));

    win = new Fl_Window(500, 400, "KANASS");
    win->begin();

    main_menu = new Fl_Group(0, 0, 500, 400, "");
    main_menu->begin();
    Fl_Box* title = new Fl_Box(75, 50, 350, 200, "今日は！！\nWelcome to KANASS!");
    title->labelfont(FL_HELVETICA_BOLD);
    title->labelsize(35);
    title->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    auto* start_button = new Fl_Button(100, 280, 300, 70, "Commencer!");
    start_button->labelfont(FL_HELVETICA);
    start_button->labelsize(40);
    start_button->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    start_button->callback(start_cb, this);

    main_menu->end();

    main_game = new Fl_Group(0,0,500,400,"");
    main_game->begin();

    kana_game = new Kana();


    kana_display = new Fl_Box(50,40,400,120, "");
    kana_display->box(FL_FLAT_BOX);
    kana_display->labelfont(FL_HELVETICA_BOLD);
    kana_display->labelsize(96);
    kana_display->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    auto* instr = new Fl_Box(50, 170, 400, 30, "Tape le Romaji et appuie sur Check!");
    instr->align(FL_ALIGN_CENTER);

    romaji_input = new Fl_Input(150, 210, 200, 35, "Romaji: ");
    romaji_input->textsize(24);
    romaji_input->when(FL_WHEN_ENTER_KEY);

    auto* check_btn = new Fl_Button(150, 260, 100, 40, "Check");
    check_btn->callback(check_cb, this);

    auto* next_btn = new Fl_Button(260, 260, 100, 40, "Next!");
    next_btn->callback(next_cb, this);

    feedback = new Fl_Output(50,320,400,40,"");
    feedback->box(FL_DOWN_BOX);
    feedback->textsize(18);
    feedback->textcolor(FL_DARK_GREEN);

    main_game->end();
    win->end();
    win->resizable(win);


    win->show(argc, argv);
    main_game->hide();
    next_cb(nullptr, this);
}

void KanaGame::start_cb(Fl_Widget* w, void* data) {
    auto* self = static_cast<KanaGame*>(data);
    self->main_menu->hide();
    self->main_game->show();
}

void KanaGame::check_cb(Fl_Widget* w, void* data) {
    auto* self = static_cast<KanaGame*>(data);
    bool nope = false;
    string user = self->romaji_input->value();
    if (user.empty()) return;

    // Use your existing getKana function
    auto result = self->kana_game->getKana(user.c_str(), !self->is_hiragana, self->is_special_kana);

    std::cout << result[0] << std::endl;

    if (result[0] == "This kana doesn't exist") {
        string msg = "Ce kana n'existe pas!!";
        self->feedback->value(msg.c_str());
        self->feedback->textcolor(FL_RED);
        return;
    }

    if (strcmp(result[0], self->current_kana.c_str()) == 0) {
        self->feedback->value("Correct! ✓");
        self->feedback->textcolor(FL_DARK_GREEN);
    } else{
        string msg = "Incorrect! C'était: " + self->current_romaji;
        self->feedback->value(msg.c_str());
        self->feedback->textcolor(FL_RED);
    }

    self->romaji_input->value("");           // Clear input
    self->romaji_input->take_focus();        // Put cursor back
}

void KanaGame::next_cb(Fl_Widget* w, void* data) {
    auto* self = static_cast<KanaGame*>(data);
    // Reuse your original randomization logic
    int hira_or_kata = rand() % 2;
    int special_kana = rand() % 10;
    self->is_hiragana = (hira_or_kata == 0);
    self->is_special_kana = (special_kana == 0);

    int row, col;

    bool valid = false;

    while (!valid) {
        if (self->is_special_kana) {
            row = rand() % 11;
            col = rand() % 3;

            cout << row << " " << col << endl;

            self->current_kana = self->is_hiragana
                ? self->kana_game->specialHiraganas[row][col]
                : self->kana_game->specialKatakanas[row][col];

            cout << "crash before get special romaji" << endl;

            self->current_romaji = self->kana_game->specialRomajis[row][col];
        } else {
            row = rand() % 15;
            col = rand() % 5;

            self->current_kana = self->is_hiragana
                ? self->kana_game->hiraganas[row][col]
                : self->kana_game->katakanas[row][col];

            self->current_romaji = self->kana_game->romajis[row][col];
        }

        // Check if we got something usable
        if (!self->current_kana.empty() &&
            self->current_kana != " " &&
            self->current_kana != "") {
            valid = true;
            }
    }

    self->kana_display->copy_label(self->current_kana.c_str());
    self->feedback->value("");
    self->romaji_input->value("");
    self->romaji_input->take_focus();
}

KanaGame::~KanaGame() {
    delete this->kana_game;
}

int KanaGame::run() {
    return Fl::run();
}

