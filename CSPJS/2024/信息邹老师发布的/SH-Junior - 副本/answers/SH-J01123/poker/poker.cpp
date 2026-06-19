#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
bool a[105][105];
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int x,y;
		if(s[0]=='D')x=1;
		if(s[0]=='C')x=2;
		if(s[0]=='H')x=3;
		if(s[0]=='S')x=4;
		if(s[1]=='A')y=1;
		if(s[1]=='2')y=2;
		if(s[1]=='3')y=3;
		if(s[1]=='4')y=4;
		if(s[1]=='5')y=5;
		if(s[1]=='6')y=6;
		if(s[1]=='7')y=7;
		if(s[1]=='8')y=8;
		if(s[1]=='9')y=9;
		if(s[1]=='T')y=10;
		if(s[1]=='J')y=11;
		if(s[1]=='Q')y=12;
		if(s[1]=='K')y=13;
		a[x][y]=true;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(a[i][j])ans--;
	cout<<ans;
	return 0;
}
