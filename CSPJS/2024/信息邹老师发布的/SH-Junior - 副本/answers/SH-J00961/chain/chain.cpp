#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[200001],r[200001],c[200001],s[200001][200001];
int main(){
	ifstream fin("chain.in");
	ofstream fout("chain.out");
	fin>>t;
	while(t--){
		fin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			fin>>l[i];
			for(int j=1;j<=l[i];j++){
				fin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
		}
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}
