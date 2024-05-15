/*

 -Author: Wasim Algamal

 -Creation Date: 10/14/2019

 -Modification Date: 10/14/2019

 -Purpose: Project1 - Calculator

*/


using namespace std;
#include <iostream>
#include <string>

string WelcomeMessage();
int Menu();
float ComputeSum(float num1, float num2);
float ComputeSub(float num1, float num2);
float ComputeMul(float num1, float num2);
float ComputeDiv(float num1, float num2);
float ComputePower(float x, int n);
float ComputeRoot(float root, int index);
float ComputePerc(float num1, float perc);
int computeGCD(int a, int b);
int computeLCM(int a, int b);
int ComputeMod(int num1, int num2);
string ExitMessage();

int main(){

	Menu();

}

string WelcomeMessage(){

	string startMessage;

	cout << "--------------------------------------------------------" << endl
		<< "           WELCOME TO THE CALCULATOR PROJECT            " << endl
		<< "--------------------------------------------------------" << endl << endl
		<< "A.) Addition" << endl
		<< "B.) Subtraction" << endl
		<< "C.) Multiplication" << endl
		<< "D.) Division" << endl
		<< "E.) Roots (only positive number)" << endl
		<< "F.) Power (only positive number)" << endl
		<< "G.) Percentage" << endl
		<< "H.) Least Common Multiplier" << endl
		<< "I.) Greatest Common Divisor" << endl
		<< "J.) Modulus" << endl
		<< "K.) Display function execution*" << endl
		<< "L.) Quit" << endl
		<< "--------------------------------------------------------" << endl << endl
		<< "Please select an operation: ";

	return "Nothing";
}


float ComputeSum(float num1, float num2){
	float ans;

	ans = num1 + num2;

	return ans;
}

float ComputeSub(float num1, float num2){
	float ans;

	ans = num1 - num2;

	return ans;
}

float ComputeMul(float num1, float num2){
	float ans;

	ans = num1 * num2;

	return ans;
}

float ComputeDiv(float num1, float num2){
	float ans;

	ans = num1 / num2;

	return ans;
}

float ComputePower(float x, int n){
	float numProduct = 1.0;
	int i;

	for (i = 0; i < n; i++)
		numProduct *= x;

	return numProduct;
}

float ComputeRoot(float root, int index){
	float tp, mid, low = 0.0, high = root;

	do {
		mid = (low + high) / 2;
		if (ComputePower(mid, index) > root)
			high = mid;
		else
			low = mid;

		mid = (low + high) / 2;
		tp = (ComputePower(mid, index) - root);

		if (tp < 0)
		{//grab absolute value
			tp = -tp;
		}
	} while (tp > .000005);	//accuracy of our root

	return mid;
}

float ComputePerc(float num1, float perc){

	return 0;
}

int computeGCD(int a, int b){
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}

	return a;
}

int computeLCM(int a, int b){
	//int tmp_lcm;
	//tmp_lcm = ((a * b) / GCD(a, b));
	//return tmp_lcm;
	return ((a * b) / computeGCD(a, b));
}

int ComputeMod(int num1, int num2){

	return 0;
}

string ExitMessage(){

	return "FIX ME: MAKE IT THE PROPER EXIT MESSAGE";
}

int Menu() {

	char userSelection;
	string validString;
	float num1 = 0;
	float num2 = 0;
	int userInt1 = 0;
	int userInt2 = 0;
	float perc = 0;
	int n = 0;
	int index = 0;

	WelcomeMessage();

	cin >> userSelection;

	while (getline(cin, validString)) {
		if (validString.size() == 0) {
			switch (userSelection) {
			case 'A':
			case 'a':
				cout << "Please provide the first number: ";
				cin >> num1;

				cout << "Please provide the second number: ";
				cin >> num2;

				cout << "Operation: " << num1 << " + " << num2 << " = " << ComputeSum(num1, num2) << endl << endl;

				Menu();
				break;
			case 'B':
			case 'b':
				cout << "Please provide the first number: ";
				cin >> num1;

				cout << "Please provide the second number: ";
				cin >> num2;

				cout << "Operation: " << num1 << " - " << num2 << " = " << ComputeSub(num1, num2) << endl << endl;

				Menu();
				break;
			case 'C':
			case 'c':
				cout << "Please provide the first number: ";
				cin >> num1;

				cout << "Please provide the second number: ";
				cin >> num2;

				cout << "Operation: " << num1 << " * " << num2 << " = " << ComputeMul(num1, num2) << endl << endl;

				Menu();
				break;
			case 'D':
			case 'd':
				cout << "Please provide the first number: ";
				cin >> num1;

				cout << "Please provide the second number: ";
				cin >> num2;
				for (num2; num2 == 0;) {
					cout << "Sorry, you cannot divide by 0. Please try another number: ";
					cin >> num2;
				}

				cout << "Operation: " << num1 << " / " << num2 << " = " << ComputeDiv(num1, num2) << endl << endl;

				Menu();
				break;
			case 'E':
			case 'e':
				ComputeRoot(num1, n);
				break;
			case 'F':
			case 'f':
				cout << "Please provide a number: ";
				cin >> num1;

				cout << "Please provide the number you would like to raise this to the power of: ";
				cin >> index;

				cout << num1 << "^" << index << " = " << ComputePower(num1, index) << endl << endl;
				break;
			case 'G':
			case 'g':
				ComputePerc(num1, perc);
				break;
			case 'H':
			case 'h':
				computeLCM(userInt1, userInt2);
				break;
			case 'I':
			case 'i':
				computeGCD(userInt1, userInt2);
				break;
			case 'J':
			case 'j':
				ComputeMod(userInt1, userInt2);
				break;
			case 'K':
			case 'k':
				cout << "FIXME: EXTRA CREDIT PAGE";
				break;
			case 'L':
			case 'l':
				cout << "FIXME: QUIT";
				break;
			default:
				cout << "Invalid selection! Please make a selection from the menu below: " << endl;
				Menu()
			}
		}
		else {
			cout << "Invalid selection! Please make a selection from the menu below: " << endl;
			Menu()
		}
	}

	return 0;
}
