#pragma once
#include <string>
#include <chrono>
#include <iomanip> 
#include <sstream> 
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include "Logs.h"
#include "Client.h"

void openDB();
void parseDB();
void setupDB();
void addClientToDB();