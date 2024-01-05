#pragma once
#include <ncurses.h>
#include <stdio.h>
#include <locale.h>
#include "../modele/partie.h"
#include "../controler/ncursesControler.h"

void createWindowNcurses(Partie * p);

void updateWindowNcurses(Partie * p);

void closeWindowNcurses();