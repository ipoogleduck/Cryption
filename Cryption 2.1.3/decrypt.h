#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include <Windows.h> // use < > for all system and library headers
#include <winuser.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string>

using namespace std;

void decrypt() {

	cout << "Paste the encrypted message (ctrl v)" << endl;
	getline(cin, cryptMessage);
	decryption();
	cryptMessage.pop_back();
	cout << "\n" << cryptMessage << endl;
	cryptMessage = "";
}