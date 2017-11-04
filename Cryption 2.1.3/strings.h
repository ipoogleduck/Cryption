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
string key;
string decOrEnc;
string cryptMessage;
string cryptable = "qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM1234567890#:><(){}[]-?!@^&=+";
string uncyrptable = "ravLNcED!Yhe5ZQq2Sb?U lBRGCdgA7mn8413tpjuKFMJHzxoPX,W6wfOVI.Ty0iks9*_";
int keyChar = 0; //for kepping track of char in code
int cryptChar = 0; //for keeping track of how many chars have been crypted
				   //All func