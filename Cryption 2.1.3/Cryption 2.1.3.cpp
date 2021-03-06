// Test project.cpp : Defines the entry point for the console application.
//

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
#include <ctime>
#include "strings.h"
#include "encryption.h"
#include "decryption.h"
#include "toClipboard.h"
#include "encrypt.h"
#include "decrypt.h"
#include "startAsk.h"

using namespace std;
//All strings


int main() {
	cout << "\n";

	cout << "Welcome to Cryption 2.1.3: stronger, faster, sleeker, more secure" << endl;
	cout << "To create a cryption key type 'create', otherwise paste the code below" << endl;
	cout << "If you don't know what a cryption key is type 'help'" << endl;
	key = "help";
	while (key == "help") {
		getline(cin, key);
		if (key == "help") {

			cout << "A cryption key is used to determine how your text is encrypted" << endl
				<< "This is to ensure that your text is encrypted and decrypted securely" << endl
				<< "Only people who have access to the key can decrypt your messages" << endl
				<< "The key is used throughout the entire program, so you won't" << endl
				<< "have to paste it every time you encrypt/decrypt something" << endl
				<< "The cryption key usually takes a couple of minutes to generate" << endl
				<< "There are 5,360 possible cryption key combinations." << endl
				<< "If you are creating the key type 'create'" << endl
				<< "Otherwise paste a pre-created code" << endl;

		}
		else if (key == "create") {

			cout << "Creating key... (usually takes a couple of minutes)" << endl;
			key = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ .?!,0123456789";
			while (keyChar != 67) { //while its not on *
				srand(time(0)); // This will ensure a really randomized number by help of time.
				cryptChar = rand() % 79 + 1; //rand char
				if (cryptable[cryptChar] == '_') { //will read _ if char is already used

				}
				else if (cryptable[cryptChar] != '_') {
					key[keyChar] = cryptable[cryptChar]; //transfer encrypted char
					cryptable[cryptChar] = '_'; //will put _ if char is already used
					keyChar++; //goes to next char for key
					cout << "."; //to show progress
				}
			}

			cout << "\n" << key;
			cout << "\nKey has been copied to clipboard (please share it now)" << endl;
			cout << "Click enter to continue" << endl;
			size_t len = strlen(key.c_str());
			// get desktop windows and the call toClipboard
			HWND hwnd = GetDesktopWindow();
			toClipboard(hwnd, key);
			cin.clear();
			cin.ignore(255, '\n');
		}
	}

	while (decOrEnc != "c") {

		startAsk(); //yes goes back to encrypt

	}
	cout << "Type 'credits' for credits, otherwise click enter" << endl;
	getline(cin, decOrEnc);
	while (decOrEnc == "credits") {
		cout << "Service developed in Cpp and designed for Windows" << endl <<
			"Code created by iPoogleDuck (Oliver)" << endl << "Original encryption key by Sleeperpad32" << endl <<
			"Cryption 2.0 introduces a randomized cryption key to improve security" << endl;
		decOrEnc = "";
	}
	cout << "If you are using more then 15 lines of this code please get permission." << endl <<
		"To acquire a permission please visit ipooglecodes.weebly.com" << endl;
	cout << "\nClick enter to close";
	cin.ignore();
	return 0;
}