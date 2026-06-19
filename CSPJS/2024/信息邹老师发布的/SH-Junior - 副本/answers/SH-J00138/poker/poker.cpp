#include<bits/stdc++.h>
using namespace std;
bool pk[5][14]={false};
int n,ina,inb,asw=52;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s[0]=='C') ina=1;
		if(s[0]=='D') ina=2;
		if(s[0]=='H') ina=3;
		if(s[0]=='S') ina=4;
		if(s[1]>='2'&&s[1]<='9') inb=s[1]-'0';
		if(s[1]=='T') inb=10;
		if(s[1]=='J') inb=11;
		if(s[1]=='Q') inb=12;
		if(s[1]=='K') inb=13;
		if(s[1]=='A') inb=1;
		if(!pk[ina][inb]){
			pk[ina][inb]=true;
			asw--;
		}
	}
	cout<<asw;
	return 0;
}
