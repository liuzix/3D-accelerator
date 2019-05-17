#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string line;
	string v, valuesX[8], valuesY[8], valuesZ[8];
	int n = 0;

	ifstream myfile ("dragon.obj");
	while(!myfile.eof()){
		getline (myfile,line);
		if (line[0] == 'v'){
			myfile >> v >> valuesX[n]>> valuesY[n]>> valuesZ[n];
			cout << valuesX[n] << "\t" << valuesY[n] << "\t" << valuesZ[n] << endl;
			n++;
		}
	}
	return 0;
}
