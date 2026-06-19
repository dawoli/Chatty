#include<bits/stdc++.h>
using namespace std;
int T[4][14],N,Cnt=52;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>s;
		int u,v;
		if(s[0]=='D') u=0;
		else if(s[0]=='C') u=1;
		else if(s[0]=='H') u=2;
		else u=3;
		if(s[1]=='A') v=1;
		else if(s[1]=='T') v=10;
		else if(s[1]=='J') v=11;
		else if(s[1]=='Q') v=12;
		else if(s[1]=='K') v=13;
		else v=s[1]-'0';
		if(T[u][v]==0){
			T[u][v]=1;
			Cnt--;
		}
	}
	cout<<Cnt<<endl;
	return 0;
}
