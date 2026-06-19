#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s[0]=='D') s[0]='0';
		else if(s[0]=='C') s[0]='1';
		else if(s[0]=='H') s[0]='2';
		else if(s[0]=='S') s[0]='3';
		if(s[0]=='A') s[0]='1';
		else if(s[0]=='T') s[0]='9'+1;
		else if(s[0]=='J') s[0]='9'+2;
		else if(s[0]=='Q') s[0]='9'+3;
		else if(s[0]=='K') s[0]='9'+4;
		a[s[0]-'0'][(int)s[1]-'1']=1;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			ans+=1-a[i][j];
		}
	}
	cout<<ans;
	return 0;
} 
