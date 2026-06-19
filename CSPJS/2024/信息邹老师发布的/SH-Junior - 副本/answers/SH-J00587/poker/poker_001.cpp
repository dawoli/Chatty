#include<bits/stdc++.h>
using namespace std;
int n,a[5][14],ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int c,v;string s;cin>>s;
		if(s[0]=='D')c=1;
		if(s[0]=='C')c=2;
		if(s[0]=='S')c=3;
		if(s[0]=='H')c=4;
		if(s[1]=='A')v=1;
		if(s[1]=='2')v=2;
		if(s[1]=='3')v=3;
		if(s[1]=='4')v=4;
		if(s[1]=='5')v=5;
		if(s[1]=='6')v=6;
		if(s[1]=='7')v=7;
		if(s[1]=='8')v=8;
		if(s[1]=='9')v=9;
		if(s[1]=='T')v=10;
		if(s[1]=='J')v=11;
		if(s[1]=='Q')v=12;
		if(s[1]=='K')v=13;
		if(a[c][v]==0)a[c][v]=1,ans--;
	}
	cout<<ans;
}
