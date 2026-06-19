#include<bits/stdc++.h>
using namespace std;
int n,a[5][15],d,e,ans;
char b,c;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		if(b=='D')d=1;
		else if(b=='C')d=2;
		else if(b=='H')d=3;
		else d=4;
		if(c=='A')e=1;
		else if(c=='T')e=10;
		else if(c=='J')e=11;
		else if(c=='Q')e=12;
		else if(c=='K')e=13;
		else e=c-'0';
		a[d][e]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!a[i][j])ans++;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
