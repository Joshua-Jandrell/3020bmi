#include <iostream>
#include <fstream>
#include <string>
#include "../bmi/bmi.h"

using namespace std;


// Methods for testing unit conversions
void test_ounces2pounds(double in, double expectedOut);
void test_stones2pounds(double in, double expectedOut);
void test_weight2kg(double stonesIn, double poundsIn, double ouncesIn, double expectedOut);
void test_height2metres(double feetIn, double inchesIn, double expectedOut);

// other testes
void test_categorise(double kgIn, double mIn, char expectedOut);

int main(){
	cout.precision(7);
	
	// tests ounces to pounts
	test_ounces2pounds(16,1); 		// by defination
	test_ounces2pounds(12,0.75);	// Arbitray case
	test_ounces2pounds(24,1.5);		// Nonsensical case
	test_ounces2pounds(0,0);		// Zero case
	
	// test stones to pounds
	test_stones2pounds(1,14);		// by definition
	test_stones2pounds(4,56);		// Arbitray case
	test_stones2pounds(0,0);		// zeor case
	
	// test weight to kg
	test_weight2kg(1,1,16, (16/2.2));		// trivial case
	test_weight2kg(2,0,0, (28/2.2));		// stone only
	test_weight2kg(0,110,0, 110/2.2);	// Pounds only
	test_weight2kg(0,0,12, (0.75/2.2));// ounces only
	test_weight2kg(0,0,0, 0);		// zero case
	
	// test hight to meters
	test_height2metres(6,6, (6.5/3.28));	//trivial
	test_height2metres(5,0, (5/3.28));	// feet only
	test_height2metres(0,3, (0.25/3.28));	// inches only
	test_height2metres(0, 0, 0);		// zero case
	
	// test categries (1 uses as height for ease of calculation
	test_categorise(14,1,'A');
	test_categorise(19,1,'B');		// fringe case 
	test_categorise(21,1,'B');
	test_categorise(25,1,'C');		// finge case
	test_categorise(28,1,'C');
	test_categorise(30,1,'D');
	test_categorise(72,1,'D');
	
	cout << "=========================" << endl;
	cout << "----- TEST COMPLETE -----" << endl;
	cout << "=========================" << endl;

	
	return 0;
}





// method implamnetation
void test_ounces2pounds(double in, double expectedOut){
	if(ounces2pounds(in) !=  expectedOut){
		cout << "=========================" << endl;
		cout << "ounces2pounds test FAIL" << endl;
		cout << "Input " << in << " gives " << ounces2pounds(in) << endl;
		cout << "Expected output is " << expectedOut << endl;
		cout << "=========================" << endl;
	}
}
void test_stones2pounds(double in, double expectedOut){
		if(stones2pounds(in) !=  expectedOut){
		cout << "=========================" << endl;
		cout << "stones2pounds test FAIL" << endl;
		cout << "Input " << in << " gives " << stones2pounds(in) << endl;
		cout << "Expected output is " << expectedOut << endl;
		cout << "=========================" << endl;
	}
}
void test_weight2kg(double stonesIn, double poundsIn, double ouncesIn, double expectedOut){
	if(weight2kg(stonesIn, poundsIn, ouncesIn) != expectedOut){
		cout << "=========================" << endl;
		cout << "weight2kg test FAIL" << endl;
		cout << "Input " << stonesIn << " stone, " <<  poundsIn << " pound, " << ouncesIn << " ounce " << " gives " << weight2kg(stonesIn, poundsIn, ouncesIn) << endl;
		cout << "Expected output is " << expectedOut << endl;
		cout << "=========================" << endl;
	}
}
void test_height2metres(double feetIn, double inchesIn, double expectedOut){
	if(height2metres(feetIn, inchesIn) != expectedOut){
		cout << "=========================" << endl;
		cout << "height2metres test FAIL" << endl;
		cout << "Input " << feetIn << " feet, " <<  inchesIn << " inch " << " gives " << height2metres(feetIn, inchesIn) << endl;
		cout << "Expected output is " << expectedOut << endl;
		cout << "=========================" << endl;
	}
}
void test_categorise(double kgIn, double mIn, char expectedOut){
	char out = categorise(kgIn, mIn);
	if(out != expectedOut){
		cout << "=========================" << endl;
		cout << "categorise test FAIL" << endl;
		cout << "Input " << kgIn << " kg, " <<  mIn << " m " << " gives " << out << endl;
		cout << "Expected output is " << expectedOut << endl;
		cout << "=========================" << endl;
	}
}



