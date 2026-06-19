#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int main(){
	ifstream fin("detect.in");
	ofstream fout("detect.out");
	int T,n,m,L,V,a[100001][4],ce[100001],chao[100001][100001],qu[100001],fchao = 0;
	fin >> T;
	for(int i = 1;i <= T;i++){
		fin >> n >> m >> L >> V;
		fchao = 0;
		for(int j = 1;j <= n;j++){
			fin >> a[j][1] >> a[j][2] >> a[j][3];
		}
		for(int j = 1;j <= m;j++){
			fin >> ce[j];
		}
		for(int j = 1;j <= n;j++){
			int v0 = a[j][2],d = a[j][1],ai = a[j][3],f = 0;
			int c = 1;
			double vt;
			while(d > ce[c]){
				c++;
			}
			for(int k = c;k <= m;k++){
				if((v0 * v0) + (2 * ai * (ce[k] - d)) >= 0){
					vt = sqrt((v0 * v0) + (2 * ai * (ce[k] - d)));
				}else{
					continue;
				}
				if(vt > V){
					f = 1;
					chao[j][k] = 1;
				}
			}
			if(f == 1){
				fchao++;
			}
		}
		fout << fchao << " ";
		int f_ = 0,fc = 0;
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= n;k++){
				for(int lll = 1;lll <= m;lll++){
					if(lll == j){
						continue;
					}
					if(chao[k][lll] == 1){
						f_++;
						break;
					}
				}
			}
			if(fchao == f_){
				fc++;
				for(int k = 1;k <= n;k++){
					chao[k][j] = 0;
				}
			}
		}
		fout << fc << endl;
	}
	return 0;
}
