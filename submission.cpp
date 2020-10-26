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
				//cout << " weight "<< weights[set][i] << endl;
				profits[set][i] = p;
				//cout << " profit" << profits[set][i] << endl;
				ratios[set][i] = r;
				//cout << "ratios " << ratios[set][i] << endl;
			}
	      		set++;
		}
	file.close();
	}
	for(int u = 0; u<set; u++) {
		//greedy algorithm 1
		if(alg==0) {
			for(int i = 0; i<items[u]; i++) {
				for(int j = 1; j<items[u]; j++) {
					if(ratios[u][j] > ratios[u][i]) {
						int temp = ratios[u][i];
						ratios[u][i] = ratios[set][j];
						ratios[u][j] = temp;
						
						temp = weights[u][i];
						weights[u][i] = weights[u][j];
						weights[u][j] = temp;
						
						temp = profits[u][i];
						profits[u][i] = profits[u][j];
						profits[u][j] = temp;
					}
				}
			}
			//for(int t = 0; t<3; t++) {
				//cout << ratios[u][t] << " " << weights[u][t] << " " << profits[u][t]<< endl;
			//}
			double totalWeight = 0;
			int maxProfit = 0;
			int iter = 0;
			while(totalWeight+weights[u][iter] <=knapcaps[u]) {
				totalWeight+=weights[u][iter];
				maxProfit+=profits[u][iter];
				knapsack.push_back(profits[u][iter]);
				iter++;
			}
			cout << knapcaps[u] << " "<< totalWeight<< " " << maxProfit << endl;
		}
		//greedy algorithm 2
		else if(alg==1) {
			for(int i = 0; i<items[u]; i++) {
				for(int j = 1; j<items[u]; j++) {
					if(ratios[u][j] > ratios[u][i]) {
						int temp = ratios[u][i];
						ratios[u][i] = ratios[set][j];
						ratios[u][j] = temp;
						
						temp = weights[u][i];
						weights[u][i] = weights[u][j];
						weights[u][j] = temp;
						
						temp = profits[u][i];
						profits[u][i] = profits[u][j];
						profits[u][j] = temp;
					}
				}
			}
			//for(int t = 0; t<3; t++) {
				//cout << ratios[u][t] << " " << weights[u][t] << " " << profits[u][t]<< endl;
			//}
			double totalWeight = 0;
			int maxProfit = 0;
			int iter = 0;
			while(totalWeight+weights[u][iter] <=knapcaps[u]) {
				totalWeight+=weights[u][iter];
				maxProfit+=profits[u][iter];
				knapsack.push_back(profits[u][iter]);
				iter++;
			}
			int pmax = 0;
			for(int g = 0; g<items[u]; g++) {
				if(profits[u][g] > pmax && weights[u][g] <=knapcaps[u]) {
					pmax = profits[u][g];
				}
			}
			if(pmax>maxProfit){
				cout << knapcaps[u] << " "<< totalWeight<< " " << pmax << endl;
			}
			else {
				cout << knapcaps[u] << " "<< totalWeight<< " " << maxProfit << endl;
			}
		}
		//backtracking
		else {

		}	
	}
	
	//output.close();
}
