#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include "source.h"
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

void menu();
void show(char **maze, int rozmiar);
void wyswietl_wyniki();
void nowy_wynik(int wymiar, int ruchy);
class Maze_Generator
{
public:
    void border(char **maze, int rozmiar);
    void correct_road(char **maze, int rozmiar);
    void inside(char **maze, int rozmiar);

};

class Player
{
public:
    void movement(char** maze, int rozmiar);
};

class wyniki {
public:
    string imie;
    int punkty;
};


#endif // SOURCE_H_INCLUDED
