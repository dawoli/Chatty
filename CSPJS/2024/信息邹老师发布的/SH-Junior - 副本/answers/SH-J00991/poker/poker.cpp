#include <fstream>
using namespace std;
ifstream fin("poker.in");
ofstream fout("poker.out");
bool have[10][20];
int main(){
	int n,num=0;
	fin >> n;
	for (int i=0;i<n;i++){
		char a,b;
		fin >> a >> b;
		int x,y;
		if (a=='D')
			x=0;
		else if (a=='C')
			x=1;
		else if (a=='H')
			x=2;
		else if (a=='S')
			x=3;
		if (b=='T')
			y=10;
		else if (b=='J')
			y=11;
		else if (b=='Q')
			y=12;
		else if (b=='K')
			y=13;
		else
			y=b-'0';
		if (!have[x][y]){
			have[x][y]=1;
			num++;
		}
	}
	fout << 52-num << endl;
	return 0;
}
