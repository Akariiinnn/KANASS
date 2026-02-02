# KANASS

Petit programme C++ pour s'entraîner aux **hiragana** et **katakana** avec une interface graphique simple.

## À propos

KANASS est un outil ludique pour apprendre et réviser les kana japonais.  
Il affiche des kana aléatoires et propose un mode quiz pour tester ta reconnaissance.

Fonctionnalités actuelles :
- Affichage aléatoire de kana (hiragana & katakana)
- Quiz interactif
- Interface graphique légère grâce à **FLTK**

## Technologies

- **Langage** : C++ (C++11 ou supérieur)
- **Interface graphique** : [FLTK](https://www.fltk.org/) (Fast Light Toolkit)
- **Build system** : CMake
- Pas d'autres dépendances externes

## Prérequis

**FLTK** doit être installé sur ton système :

- **Ubuntu / Debian**
  ```bash
  sudo apt update
  sudo apt install libfltk1.3-dev
  
- **Fedora**
  ```bash
  sudo dnf install fltk-devel

- **macOS (Homebrew)**
  ```bash
  brew install fltk
  
- **Windows** 
  Télécharge et compile FLTK depuis https://www.fltk.org
  ou utilise vcpkg :
  ```bash
  vcpkg install fltk 

## Compilation
```bash
git clone https://www.github.com/Akariiinnn/KANASS.git
cd KANASS

mkdir build && cd build
  
cmake..
cmake --build .
```
Si CMake ne trouve pas FLTK, verifie ton installation

## Utilisation
```bash
# Linux / macOS
./KANASS

#Windows
KANASS.exe
```

## Auteur

**Akariiinnn**
https://www.github.com/Akariiinnn

## LICENCE
MIT License

