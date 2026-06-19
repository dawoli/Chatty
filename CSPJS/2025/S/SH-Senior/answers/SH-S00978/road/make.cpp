#include<bits/stdc++.h>

using namespace std;

mt19937 rng(4649);
ofstream fout("data.in");
#define endl '\n'

signed main(){
	int n=1e4,m=1e6,k=10,v=1e9;

	fout<<n<<' '<<m<<' '<<k<<endl;
	for(int i=1;i<=m;i++){
		fout<<rng()%n+1<<' '<<rng()%n+1<<' '<<rng()%v+1<<endl;
	}
	for(int i=1;i<=k;i++){
		fout<<rng()%v+1<<' ';
		for(int j=1;j<=n;j++) fout<<rng()%v+1<<' ';fout<<endl;
	}

	return 0;
}