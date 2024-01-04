#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _case {
    unsigned occupe : 1;
    unsigned char color;
} Case;


Case * initCase();

void setOccupeCase(Case * c);

void setLibereCase(Case * c);

void setColorCase(Case * c, unsigned char color);

char getColorCase(Case * c);

unsigned isOccupedCase(Case *c);