#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int f[5][14],num=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D'){
			if(s[1]>'0' and s[1]<='9') f[1][s[1]-'0']=1;
			else{
				if(s[1]=='A') f[1][1]=1;
				if(s[1]=='T') f[1][10]=1;
				if(s[1]=='J') f[1][11]=1;
				if(s[1]=='Q') f[1][12]=1;
				if(s[1]=='K') f[1][13]=1;
			}
		}
		if(s[0]=='C'){
			if(s[1]>'0' and s[1]<='9') f[2][s[1]-'0']=1;
			else{
				if(s[1]=='A') f[2][1]=1;
				if(s[1]=='T') f[2][10]=1;
				if(s[1]=='J') f[2][11]=1;
				if(s[1]=='Q') f[2][12]=1;
				if(s[1]=='K') f[2][13]=1;
			}
		}
		if(s[0]=='H'){
			if(s[1]>'0' and s[1]<='9') f[3][s[1]-'0']=1;
			else{
				if(s[1]=='A') f[3][1]=1;
				if(s[1]=='T') f[3][10]=1;
				if(s[1]=='J') f[3][11]=1;
				if(s[1]=='Q') f[3][12]=1;
				if(s[1]=='K') f[3][13]=1;
			}
		}
		if(s[0]=='S'){
			if(s[1]>'0' and s[1]<='9') f[4][s[1]-'0']=1;
			else{
				if(s[1]=='A') f[4][1]=1;
				if(s[1]=='T') f[4][10]=1;
				if(s[1]=='J') f[4][11]=1;
				if(s[1]=='Q') f[4][12]=1;
				if(s[1]=='K') f[4][13]=1;
			}
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(f[i][j]) num++;
		}
	}
	cout<<52-num;
	return 0;
}
