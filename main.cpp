#include <FL/Fl.h>
#include <FL/Fl_Window.H>
#include "KanaGame.h"

using namespace std;

int main(int argc, char** argv) {

    KanaGame game(argc, argv);
    return game.run();
}