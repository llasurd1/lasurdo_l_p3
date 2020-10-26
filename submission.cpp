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
	string tempstring = argv[3];
	int alg = stoi(tempstring);
	
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
	for(int u = 0; u<set-1; u++) {
		//greedy algorithm 1
		if(alg==0) {
			for(int i = 0; i<items[u]; i++) {
				for(int j = 1; j<items[u]; j++) {
					if(ratios[set][j] > ratios[set][i]) {
						int temp = ratios[set][i];
						ratios[set][i] = ratios[set][j];
						ratios[set][j] = temp;
						
						temp = weights[set][i];
						weights[set][i] = weights[set][j];
						weights[set][j] = weights;
						
						temp = profits[set][i];
						profits[set][i] = profits[set][j];
						profits[set][j] = profits;
					}
				}
			}
			int totalWeight = 0;
			int maxProfit = 0;
			int iter = 0;
			while(totalWeight+weights[set][iter]<=knapcaps[set]) {
				totalWeight+=weights[set][iter];
				maxProfit+=profits[set][iter];
				knapsack.push_back(profits[set][iter]);
				iter++;
			}
			cout << knapcaps[set] << " "<< totalWeight<< " " << maxProfit;
		}
		//greedy algorithm 2
		else if(alg==1) {

		}
		//backtracking
		else {

		}	
	}
	
	//output.close();
}
