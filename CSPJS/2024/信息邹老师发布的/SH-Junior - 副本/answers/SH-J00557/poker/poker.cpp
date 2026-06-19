#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
string s;
long long a[6][30];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>s;
		long long p,q;
		if(s[0]=='D') p=1;
		else if(s[0]=='C') p=2;
		else if(s[0]=='H') p=3;
		else if(s[0]=='S') p=4;
		if(s[1]=='T') q=10;
		else if(s[1]=='A') q=1;
		else if(s[1]=='J') q=11;
		else if(s[1]=='Q') q=12;
		else if(s[1]=='K') q=13;
		else q=s[1]-'0';
		a[p][q]=1;
	}
	for(long long i=1;i<=4;i++){
		for(long long j=1;j<=13;j++){
			if(!a[i][j]){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	
	return 0;
} 
