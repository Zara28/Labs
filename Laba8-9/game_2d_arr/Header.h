#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h"
#define WIN32_LEAN_AND_MEAN            
#include <stdlib.h>

#include "framework.h"

void moveDown();
void moveToLeft();
void moveUp();
void moveToRight();
void Create_wall_left();

void Create_wall_right();
void Destroy_wall_right();
void Destroy_wall(int ras);
void Destroy_wall_D();
void Double();
void Again();
void to_end();
void DrawField(HDC hdc);
void MoveMonsters(); 
void generateLevel();
void addGold();
bool EndGame();
void randomMove();
void WriteInFile(); 
void ReadFromFile();