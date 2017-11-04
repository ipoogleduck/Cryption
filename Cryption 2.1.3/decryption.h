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

void decryption() {

	while (cryptMessage[cryptChar] != '*') {
		keyChar = 0;
		while (uncyrptable[keyChar] != '_') {
			if (cryptMessage[cryptChar] == key[keyChar]) { // also for caps
				cryptMessage[cryptChar] = uncyrptable[keyChar];
				keyChar = 67;
			}
			keyChar++;

		}
		cout << ".";
		cryptChar++;
	}

}