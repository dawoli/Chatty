#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
bool c[10][15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	memset(c,false,sizeof(c));
	for(int i=1;i<=n;i++){
		cin>>s;
		int tmp1,tmp2;
		if(s[0]=='D')tmp1=1;
		else if(s[0]=='C')tmp1=2;
		else if(s[0]=='H')tmp1=3;
		else tmp1=4;
		
		if(s[1]=='A')tmp2=1;
		else if(s[1]=='T')tmp2=10;
		else if(s[1]=='J')tmp2=11;
		else if(s[1]=='Q')tmp2=12;
		else if(s[1]=='K')tmp2=13;
		else tmp2=s[1]-'0';
		
		c[tmp1][tmp2]=true;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(c[i][j]==0)ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


