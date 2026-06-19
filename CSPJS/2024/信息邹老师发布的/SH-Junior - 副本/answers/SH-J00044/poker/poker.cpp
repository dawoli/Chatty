#include<bits/stdc++.h>
using namespace std;
int n,ans;
char a,b;
bool f[100][100];
int main(){
	freopen("poker.in","r",stdin);freopen("poker.out","w",stdout);
	ans=52;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int c;
		if(a=='D') c=1;
		if(a=='C') c=2;
		if(a=='H') c=3;
		if(a=='S') c=4;
		f[c][b-'0']=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=99;j++)
			if(f[i][j]) ans--;
	}
	cout<<ans<<endl;
	return 0;
}
