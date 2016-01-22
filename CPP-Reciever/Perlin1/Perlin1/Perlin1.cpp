#include "stdafx.h"
#include <iostream>
#include "RTD.h"
using namespace std;
int indata[181];
int sum = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	if (sum = 180){
		sum = 0;
	}
	int i;
	for (i = 0; i <= 180; i += 1){
		if (sum<181){
			indata[sum] = i; //replace i with the data read from the serial
			sum++;
		}
		else{
			cout << "ERROR!!!" << endl;
		}
	}
	for (int j = 0; j <= 180; j++){
		cout << indata[j] << endl;
	}
	/*
	double test_t = 120;
	double test_r = 2;
	double resultx = rtdx(test_t, test_r);
	double resulty = rtdy(test_t, test_r);
	cout << resultx << endl;
	cout << resulty << endl;
	system("pause");
	return 0;
	*/
}