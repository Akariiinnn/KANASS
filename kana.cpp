//
// Created by rober on 31/01/2026.
//

#include "kana.h"
#include <cstring>
#include <iostream>
using namespace std;

bool is_shorter_than_2(const char* s) {
    return !s || s[0] == '\0' || s[1] == '\0';
}

bool is_2(const char* s) {
    return s && s[1] != '\0' && s[2] == '\0';
}

bool is_3(const char* s) {
    return s && s[1] != '\0' && s[2] != '\0' && s[3] == '\0';
}

Kana::Kana() {
    setKatakanas();
    setHiraganas();
    setRomajis();
    setSpecialRomajis();
    setSpecialHiraganas();
    setSpecialKatakanas();
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

void Kana::setSpecialHiraganas() {
    this->specialHiraganas[0] = {"きゃ","きゅ","きょ"};
    this->specialHiraganas[1] = {"ぎゃ","ぎゅ","ぎょ"};
    this->specialHiraganas[2] = {"しゃ","しゅ","しょ"};
    this->specialHiraganas[3] = {"じゃ","じゅ","じょ"};
    this->specialHiraganas[4] = {"ちゃ","ちゅ","ちょ"};
    this->specialHiraganas[5] = {"にゃ","にゅ","にょ"};
    this->specialHiraganas[6] = {"ひゃ","ひゅ","ひょ"};
    this->specialHiraganas[7] = {"びゃ","びゅ","びょ"};
    this->specialHiraganas[8] = {"ぴゃ","ぴゅ","ぴょ"};
    this->specialHiraganas[9] = {"みゃ","みゅ","みょ"};
    this->specialHiraganas[10] = {"りゃ","りゅ","りょ"};
}

void Kana::setSpecialRomajis() {
    this->specialRomajis[0] = {"kya","kyu","kyo"};
    this->specialRomajis[1] = {"gya","gyu","gyo"};
    this->specialRomajis[2] = {"sha","shu","sho"};
    this->specialRomajis[3] = {"jya","jyu","jyo"};
    this->specialRomajis[4] = {"cha","chu","cho"};
    this->specialRomajis[5] = {"nya","nyu","nyo"};
    this->specialRomajis[6] = {"hya","hyu","hyo"};
    this->specialRomajis[7] = {"bya","byu","byo"};
    this->specialRomajis[8] = {"pya","pyu","pyo"};
    this->specialRomajis[9] = {"mya","myu","myo"};
    this->specialRomajis[10] = {"rya","ryu","ryo"};
}

void Kana::setSpecialKatakanas() {
    this->specialKatakanas[0] = {"キャ","キュ","キョ"};
    this->specialKatakanas[1] = {"ギャ","ギュ","ギョ"};
    this->specialKatakanas[2] = {"シャ","シュ","ショ"};
    this->specialKatakanas[3] = {"ジャ","ジュ","ジョ"};
    this->specialKatakanas[4] = {"チャ","チュ","チョ"};
    this->specialKatakanas[5] = {"ニャ","ニュ","ニョ"};
    this->specialKatakanas[6] = {"ヒャ","ヒュ","ヒョ"};
    this->specialKatakanas[7] = {"ビャ","ビュ","ビョ"};
    this->specialKatakanas[8] = {"ピャ","ピュ","ピョ"};
    this->specialKatakanas[9] = {"ミャ","ミュ","ミョ"};
    this->specialKatakanas[10] = {"リャ","リュ","リョ"};
}

array<const char*,2> Kana::getKana(const char* c, bool katakana, bool special) const {
    if (!special) {
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 5; j++) {
                if (std::strcmp(c, this->romajis[i][j]) == 0) {
                    return {katakana ? this->katakanas[i][j] : this->hiraganas[i][j]};
                }
            }
        }
    } else {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 3; j++) {
                if (std::strcmp(c, this->specialRomajis[i][j]) == 0) {
                    return {katakana ? this->specialKatakanas[i][j] : this->specialHiraganas[i][j]};
                }
            }
        }
    }
    return {"This kana doesn't exist"};
}

