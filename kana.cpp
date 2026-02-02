//
// Created by rober on 31/01/2026.
//

#include "kana.h"
#include <cstring>
using namespace std;

bool is_shorter_than_2(const char* s) {
    return s == nullptr
           || s[0]== '\0'
           || s[1] == '\0';
}

bool is_2(const char* s) {
    return s == nullptr
           || (s[2] == '\0' && s[1] != '\0');
}

bool is_3(const char* s) {
    return s == nullptr
           || (s[3] == '\0' && (s[1] != '\0' && s[2] != '\0'));
}

Kana::Kana() {
    setKatakanas();
    setHiraganas();
    setRomajis();
}

void Kana::setRomajis() {
    this->romajis[0] = {"a","i","u","e","o"};
    this->romajis[1] = {"ka","ki","ku","ke","ko"};
    this->romajis[2] = {"sa","shi","su","se","so"};
    this->romajis[3] = {"ta","chi","tsu","te","tu"};
    this->romajis[4] = {"na","ni","nu","ne","no"};
    this->romajis[5] = {"ha","hi","fu","he","ho"};
    this->romajis[6] = {"ma","mi","mu","me","mo"};
    this->romajis[7] = {"ya","","yu","","yo"};
    this->romajis[8] = {"ra","ri","ru","re","ro"};
    this->romajis[9] = {"wa","","n","","wo"};
    this->romajis[10] = {"ga","gi","gu","ge","go"};
    this->romajis[11] = {"za","ji","zu","ze","zo"};
    this->romajis[12] = {"da","dji","dzu","de","do"};
    this->romajis[13] = {"ba","bi","bu","be","bo"};
    this->romajis[14] = {"pa","pi","pu","pe","po"};
}

void Kana::setHiraganas() {
    this->hiraganas[0] = {"あ","い","う","え","お"};
    this->hiraganas[1] = {"か","き","く","け","こ"};
    this->hiraganas[2] = {"さ","し","す","せ","そ"};
    this->hiraganas[3] = {"た","ち","つ","て","と"};
    this->hiraganas[4] = {"な","に","ぬ","ね","の"};
    this->hiraganas[5] = {"は","ひ","ふ","へ","ほ"};
    this->hiraganas[6] = {"ま","み","む","め","も"};
    this->hiraganas[7] = {"や","","ゆ","","よ"};
    this->hiraganas[8] = {"ら","り","る","れ","ろ"};
    this->hiraganas[9] = {"わ","","ん","","を"};
    this->hiraganas[10] = {"が","ぎ","ぐ","げ","ご"};
    this->hiraganas[11] = {"ざ","じ","ず","ぜ","ぞ"};
    this->hiraganas[12] = {"だ","ぢ","づ","で","ど"};
    this->hiraganas[13] = {"ば","び","ぶ","べ","ぼ"};
    this->hiraganas[14] = {"ぱ","ぴ","ぷ","ぺ","ぽ"};
}

void Kana::setKatakanas() {
    this->katakanas[0] = {"ア","イ","ウ","エ","オ"};
    this->katakanas[1] = {"カ","キ","ク","ケ","コ"};
    this->katakanas[2] = {"サ","シ","ス","セ","ソ"};
    this->katakanas[3] = {"タ","チ","ツ","テ","ト"};
    this->katakanas[4] = {"ナ","ニ","ヌ","ネ","ノ"};
    this->katakanas[5] = {"ハ","ヒ","フ","ヘ","ホ"};
    this->katakanas[6] = {"マ","ミ","ム","メ","モ"};
    this->katakanas[7] = {"ヤ"," ","ユ"," ","ヨ"};
    this->katakanas[8] = {"ラ","リ","ル","レ","ロ"};
    this->katakanas[9] = {"ワ"," ","ン"," ","ヲ"};
    this->katakanas[10] = {"ガ","ギ","グ","ゲ","ゴ"};
    this->katakanas[11] = {"ザ","ジ","ズ","ゼ","ゾ"};
    this->katakanas[12] = {"ダ","ヂ","ヅ","デ","ド"};
    this->katakanas[13] = {"バ","ビ","ブ","ベ","ボ"};
    this->katakanas[14] = {"パ","ピ","プ","ペ","ポ"};
}

array<const char*, 2> Kana::getKana(const char* c) const {
    constexpr char vowels[6] = {'a','i','u','e','o', 'n'};
    constexpr char consonants[14] = {'k', 's', 't', 'n', 'h','m','y', 'r', 'w', 'g', 'z', 'd', 'b', 'p'};
    const char* specialKanas[7] = {"shi","chi","tsu", "ji", "fu", "dji", "dzu"};

    array<const char*, 2> result = {"This kana doesn't exist"};

    for(int i = 0; i<7; i++) {
        if(strcmp(specialKanas[i],c) == 0) {
            int specialKanasPlaces[2][7] = {
                {2,3,3,11,5,12,12}, // x position
                {1,1,2,1,2,1,2} // y position
            };
            const char* h = this->hiraganas[specialKanasPlaces[0][i]][specialKanasPlaces[1][i]];
            const char* k = this->katakanas[specialKanasPlaces[0][i]][specialKanasPlaces[1][i]];
            return {h, k};
        }
    }

    const char* hira = nullptr;
    const char* kata = nullptr;

    if(is_shorter_than_2(c)) {
        const int vowel = c[0];
        if(vowel == 'n') {
            hira = this->hiraganas[9][2];
            kata = this->katakanas[9][2];
        }
        for(int i = 0; i<5; i++)
        {
            if(vowel == vowels[i]) {
                hira = this->hiraganas[0][i];
                kata = this->katakanas[0][i];
            }
        }
    }
    else if(is_2(c)) {
        const int vowel = c[1];
        const int consonant = c[0];
        for(int i = 0; i<14; i++) {
            if(consonant == consonants[i]) {
                for(int k = 0; k<5; k++) {
                    if(vowel == vowels[k]) {
                        hira = this->hiraganas[i+1][k];
                        kata = this->katakanas[i+1][k];
                    }
                }
            }
        }
    }
    else if(is_3(c)) {
        result = {"three characters kanas not implemented yet"};
    }

    if(hira != nullptr && kata != nullptr) {
        if(strlen(hira) > 0 && strlen(kata) > 0) {
            result = {hira, kata};
        }
    }

    //Reject romaji when it's a special kana and not written correctly (for example di, ti, zi) by comparing result with
    //the first kana it gives so a hiragana and with the special kana itself using the specialkanasplaces array and looking
    //in the hiraganas array
    for(int i = 0; i<7; i++) {
        int specialKanasPlaces[2][7] = {
            {2,3,3,11,5,12,12}, // x position
            {1,1,2,1,2,1,2} // y position
        };
        const char* h = this->hiraganas[specialKanasPlaces[0][i]][specialKanasPlaces[1][i]];
        const char* k = this->katakanas[specialKanasPlaces[0][i]][specialKanasPlaces[1][i]];
        array expectedResult = {h, k};
        if(strcmp(c, specialKanas[i]) != 0 && result[0] == expectedResult[0]) {
            result = {"This kana doesn't exist"};
        }
    }

    return {result};
}