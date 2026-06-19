#include <fstream>
using namespace std;
ifstream fin("chain.in");
ofstream fout("chain.out");
const int maxn=1e5+5;
int s[maxn];
int have[maxn*2];
int main(){
	int T;
	fin >> T;
	while (T--){
		int n,k,q;
		fin >> n >> k >> q;
		for (int i=0;i<n;i++){
			int l;
			fin >> l;
			for (int j=0;j<l;j++){
				fin >> s[i];
				have[s[i]]=1;
			}
		}
		for (int i=0;i<q;i++){
			int r,c;
			fin >> r >> c;
			if (!have[c])
				fout << 0 << endl;
			else{
				fout << 1 << endl;
			}
		}
	}
	return 0;
}
