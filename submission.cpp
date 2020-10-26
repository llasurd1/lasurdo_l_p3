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
  int weights[10][1000];
  int profits[10][1000];
  int ratios[10][1000];
  int items[10];
  int knapcaps[10];
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
  
  output.close();
}
