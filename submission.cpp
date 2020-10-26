#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <array>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int set = 0;
	int alg = argv[3];
	double weights[5][1000];
	double profits[5][1000];
	double ratios[5][1000];
	int items[5];
 	int knapcaps[5];
	vector<int> knapsack;
	
	fstream file(argv[1], fstream::in);
	ofstream output;
	output.open(argv[2]);
	
	if(file.is_open()){  
		while(!file.eof() && !file.fail()) {
			int item = 0;
			int knapcap = 0;
			file >> item;
			file >> knapcap;
			items[set] = item;
			knapcaps[set] = knapcap;
			for(int i = 0; i<item; i++) {
				double w, p, r;
				file >> w;
				file >> p;
				r = p/w;
				weights[set][i] = w;
				profits[set][i] = p;
				ratios[set][i] = r;
			}
	      		set++;
		}
	file.close();
	}
	if(alg==0) {
		for(int i = 0; i<set-1; i++) {
			for int j = 0; j<	
		}
	}
	else if(alg==1) {
		
	}
	else {
		
	}
	//output.close();
}
