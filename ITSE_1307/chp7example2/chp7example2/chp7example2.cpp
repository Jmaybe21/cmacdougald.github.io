// chp7example2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strName = "Chris";

	cout << strName.at(0) << endl;
	strName.append(" MacDougald");
	cout << strName << endl;
	cout << strName.length() << endl;
	cout << strName.size() << endl;

    return 0;
}

