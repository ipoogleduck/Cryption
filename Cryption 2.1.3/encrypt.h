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