#include<bits/stdc++.h>
using namespace std;
int n,ans;
char s[2];
bool poker[5][15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		int x,y;
		if(s[0]=='D')x=1;
		else if(s[0]=='C')x=2;
		else if(s[0]=='H')x=3;
		else
			x=4;
		if(s[1]>='2'&&s[1]<='9')y=s[1]-'0';
		else if(s[1]=='A')y=1;
		else if(s[1]=='T')y=10;
		else if(s[1]=='J')y=11;
		else if(s[1]=='Q')y=12;
		else
			y=13;
		poker[x][y]=1;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(!poker[i][j])ans++;
	cout<<ans;
	return 0;
}
