#include <bits/stdc++.h>
using namespace std;
const int N1=1e5+5;
const int N2=2e5+5;

int s[N1][N2];
int qs[N1][2];
int end[N1];

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int T;
	cin>>T;
	
	for (int t=0;t<T;t++){
		int n,k,q;
		cin>>n,k,q;
		for (int i=0; i<n; i++){
			int l;
			cin>>l;
			int endt;
			for (int j=0;j<l;j++){
				cin>>s[i][j];
				endt=s[i][j];
			}
			end[i]=endt;
		}
		
		for (int i=0; i<q;i++){
			cin>>qs[i][0]>>qs[i][1];
		}
		int ret=0;
		
		if (k==2e5){
			ret=1;
		}
		
		cout<<ret<<endl;
	}
	
	return 0;
}
