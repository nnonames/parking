#pragma warning(disable:4996)
#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

time_t realTime;
int useTime; // second
struct tm *now;

string answer, disabled;

bool isDisabled = false;
bool isCarExist = false;
bool isExit = false;
bool isCarSet = false;

int x = 0, y = 0;
int hourPrice = 2000;
int halfHourPrice = 1000;
int tenMinPrice = 400;