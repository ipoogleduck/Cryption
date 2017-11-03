// Test project.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" //if using visual cpp
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

using namespace std;
//All strings
string key;
string decOrEnc;
string cryptMessage;
string cryptable = "qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM1234567890#:><(){}[]-?!@^&=+";
string uncyrptable = "ravLNcED!Yhe5ZQq2Sb?U lBRGCdgA7mn8413tpjuKFMJHzxoPX,W6wfOVI.Ty0iks9*_";
int keyChar = 0; //for kepping track of char in code
int cryptChar = 0; //for keeping track of how many chars have been crypted
				   //All func
void toClipboard(HWND hwnd, const std::string &s);
void encryption() {
	do while (cryptMessage[cryptChar] != '*') {
		keyChar = 0;
		do while (uncyrptable[keyChar] != '_') {
			if (uncyrptable[keyChar] == '*') { // also for caps
				cout << "ERROR: THE CHARACTER " << cryptMessage[cryptChar] << " IS NOT SUPPORTED. " <<
					"There may be an error when decrypting..." << endl;
			}
			if (cryptMessage[cryptChar] == uncyrptable[keyChar]) { // also for caps
				cryptMessage[cryptChar] = key[keyChar];
				keyChar = 67;
			}
			keyChar++;

		} while (uncyrptable[keyChar] != '_');

		cout << ".";
		cryptChar++;
	} while (cryptMessage[cryptChar] != '*');

}


void decryption() {

	do while (cryptMessage[cryptChar] != '*') {
		keyChar = 0;
		do while (uncyrptable[keyChar] != '_') {
			if (cryptMessage[cryptChar] == key[keyChar]) { // also for caps
				cryptMessage[cryptChar] = uncyrptable[keyChar];
				keyChar = 67;
			}
			keyChar++;

		} while (uncyrptable[keyChar] != '_');
		cout << ".";
		cryptChar++;
	} while (cryptMessage[cryptChar] != '*');

}
void toClipboard(HWND hwnd, const std::string &s) { //copy to clipboard
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}
void encrypt() {

	cout << "\nType or paste the message you want to encrypt" << endl;
	cout << "Note that this service does currently only supports the special characters of . , ! ?" << endl;
	getline(cin, cryptMessage);
	//add * to end of crypt
	cryptMessage += "*";
	encryption();
	cout << "\nEncryption has been copied to clipboard" << endl << "Click enter to continue";

	size_t len = strlen(cryptMessage.c_str());
	// get desktop windows and the call toClipboard
	HWND hwnd = GetDesktopWindow();
	toClipboard(hwnd, cryptMessage);
	cin.clear();
	cin.ignore(255, '\n');
	cryptMessage = "";
}



void decrypt() {

	cout << "Paste the encrypted message (ctrl v)" << endl;
	getline(cin, cryptMessage);
	decryption();
	cryptMessage.pop_back();
	cout << "\n" << cryptMessage << endl;
	cryptMessage = "";
}

void startAsk() { //for the beginning question
	cryptChar = 0;
	cout << "\nPlease type 'e' to encrypt a string of text, 'd' to decrypt one, and 'c' to cancel" << endl;
	getline(cin, decOrEnc);

	do while (decOrEnc == "e") {

		encrypt();
		decOrEnc = "N/A";

	} while (decOrEnc == "e");

	do while (decOrEnc == "d") {

		decrypt();
		decOrEnc = "N/A";

	} while (decOrEnc == "d");

	do while (decOrEnc != "e" && decOrEnc != "c" && decOrEnc != "d" && decOrEnc != "N/A") {

		cout << "\nError in text" << endl;
		decOrEnc = "N/A";
		startAsk(); //to repeate again

	} while (decOrEnc != "e" && decOrEnc != "c" && decOrEnc != "d" && decOrEnc != "N/A");


}

int main() {
	cout << "\n";

	cout << "Welcome to Cryption 2.1.3: stronger, faster, sleeker, more secure" << endl;
	cout << "To create a cryption key type 'create', otherwise paste the code below" << endl;
	cout << "If you don't know what a cryption key is type 'help'" << endl;
	key = "help";
	do while (key == "help") {
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
			do while (keyChar != 67) { //while its not on *
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
			} while (keyChar != 67);

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
	} while (key == "help");

	do while (decOrEnc != "c") {

		startAsk(); //yes goes back to encrypt

	} while (decOrEnc != "c");
	cout << "Type 'credits' for credits, otherwise click enter" << endl;
	getline(cin, decOrEnc);
	while (decOrEnc == "credits") {
		cout << "Service developed in Cpp and designed for Windows" << endl <<
			"Code created by iPoogleDuck (Oliver)" << endl << "Original encryption key by Sleeperpad32" << endl <<
			"Cryption 2.0 introduces a randomized cryption key to improve security" << endl <<
			"This code cannot be redistributed or copied and reused in any way without a verified license" << endl <<
			"To acquire a verified license please visit ipooglecodes.weebly.com" << endl;
		decOrEnc = "";
	}
	cout << "\nClick enter to close";
	cin.ignore();
}