//
// Created by rober on 31/01/2026.
//

#ifndef KANASS_KANA_H
#define KANASS_KANA_H

#include <array>
using namespace std;


class Kana {
public:
    Kana();
    array<const char*, 2> getKana(const char* c, bool katakana, bool special) const;
    array<std::array<const char*, 5>, 15> hiraganas{};
    array<std::array<const char*, 5>, 15> katakanas{};
    array<std::array<const char*, 3>, 11> specialKatakanas{};
    array<std::array<const char*, 3>, 11> specialHiraganas{};
    array<std::array<const char*, 3>, 11> specialRomajis{};
    array<std::array<const char*, 5>, 15> romajis{};
private:
    void setKatakanas();
    void setHiraganas();
    void setSpecialHiraganas();
    void setSpecialKatakanas();
    void setSpecialRomajis();
    void setRomajis();
};


#endif //KANASS_KANA_H
