#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][100];
int ans=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int l=0,k=0;
		if(s[0]=='D') l=1;
		else if(s[0]=='S') l=2;
		else if(s[0]=='H') l=3;
		else l=4;
		if(s[1]=='A') k=1;
		else if(s[1]=='T') k=10;
		else if(s[1]=='J') k=11;
		else if(s[1]=='Q') k=12;
		else if(s[1]=='K') k=13;
		else k=s[1]-'0';
		a[l][k]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!a[i][j]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
