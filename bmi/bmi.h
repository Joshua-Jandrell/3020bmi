#include <iostream>
#include <fstream>
#include <string>

// Using a headder file is better practice and makes testing easier
using namespace std;

double ounces2pounds(double x)
{
    return(x/16);
}

double stones2pounds(double x)
{
    return(x*14);
}

double weight2kg(double stones, double pounds, double ounces)
{
    return (stones2pounds(stones)+pounds+ounces2pounds(ounces))/2.2;
}

double height2metres(double feet, double inches)
{
	double totalfeet = feet + (inches/12);
    return(totalfeet/3.28);
}

char categorise(double kg, double metre)
{
    double bmi = kg/(metre*metre);
    //cout << "DEBUG bmi " << bmi << " kg " << kg << " m " << metre << endl; 
    char cat;
    if (bmi<19)
        cat='A';
    else if (bmi<25)
        cat='B';
    else if (bmi<30)
        cat='C';
    else
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
	if(input_file == nullptr || output_file == nullptr){
		cout << "Fatal Error: Insufficent arguments" << endl;
		return;
	}
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    double pounds, stones, ounces, feet, inches;
    double kg, m;
    char cat;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    while (f_in >> person_id >> stones >> pounds >> ounces >> feet >> inches)
    {
        kg=weight2kg(double(stones),double(pounds),double(ounces));
        m =height2metres(double(feet),double(inches));
        cat=categorise(kg,m);
	f_out << person_id << " " << cat << endl;
    }
    f_in.close();
    f_out.close();
}
