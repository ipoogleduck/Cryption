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
void encryption() {
	while (cryptMessage[cryptChar] != '*') {
		keyChar = 0;
		while (uncyrptable[keyChar] != '_') {
			if (uncyrptable[keyChar] == '*') { // also for caps
				cout << "ERROR: THE CHARACTER " << cryptMessage[cryptChar] << " IS NOT SUPPORTED. " <<
					"There may be an error when decrypting..." << endl;
			}
			if (cryptMessage[cryptChar] == uncyrptable[keyChar]) { // also for caps
				cryptMessage[cryptChar] = key[keyChar];
				keyChar = 67;
			}
			keyChar++;

		}

		cout << ".";
		cryptChar++;
	}

}