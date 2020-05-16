#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <bitset>

using namespace std;

int getProcess();
int binaryToDecimal(unsigned long);
int decimalToBinary(unsigned int);

int main(){

	int process;
  	unsigned long convertNum;

	do {

    process = getProcess();
    cout << "\n";

	switch (process) {

    	case 0:
        	break;
		case 1:
    		cout << "Enter a binary number: ";
        	cin >> convertNum;
        	cout << "Converted decimal number: " << binaryToDecimal(convertNum);
			break;
		case 2:
        	cout << "Enter a decimal number: ";
        	cin >> convertNum;
        	cout << "Converted binary number: " << decimalToBinary(convertNum);
			break;
		default:
			cout << "Not a valid process number";
			break;

	}

    cout << "\n\n";

	} while (process);

}

int getProcess(){

	int process;
	cout << "Choose data conversion process or enter 0 to quit.\n" 
		<< "1. Binary to decimal\n"
		<< "2. Decimal to binary\n";
	cin >> process;
  return process;
}

int binaryToDecimal(unsigned long num){

	unsigned long returnNum = 0;
	unsigned long temp;
	unsigned long powerOfTwo = 0;

	while (num != 0){

		temp = num % 10;
		returnNum += (long)pow(2, powerOfTwo)*temp;

		powerOfTwo++;
		num = num / 10;
	}

	return returnNum;
}

int decimalToBinary(unsigned int num){

  	string returnNum;
  
  	int arr[32];
  	int i;

  	for (i=0; num>0; i++){
    	arr[i] = num%2;
    	num = num/2;
  	}
  	for (i=i-1; i>=0; i--){
    	returnNum += to_string(arr[i]);
  	}

  	return stol(returnNum);
}