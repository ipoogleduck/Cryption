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

void startAsk() { //for the beginning question
	cryptChar = 0;
	cout << "\nPlease type 'e' to encrypt a string of text, 'd' to decrypt one, and 'c' to cancel" << endl;
	getline(cin, decOrEnc);

	while (decOrEnc == "e") {

		encrypt();
		decOrEnc = "N/A";

	}

	while (decOrEnc == "d") {

		decrypt();
		decOrEnc = "N/A";

	}

	while (decOrEnc != "e" && decOrEnc != "c" && decOrEnc != "d" && decOrEnc != "N/A") {

		cout << "\nError in text" << endl;
		decOrEnc = "N/A";
		startAsk(); //to repeate again

	}


}
