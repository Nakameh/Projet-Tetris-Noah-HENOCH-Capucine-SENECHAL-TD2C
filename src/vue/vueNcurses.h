#pragma once
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../modele/partie.h"
#include "../controler/ncursesControler.h"

void createWindowNcurses(unsigned char ligne, unsigned char colonne);

void updateWindowNcurses(Partie * p);

void closeWindowNcurses();