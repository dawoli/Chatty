#include<bits/stdc++.h>
using namespace std;
int n=0,a=0;
string s;
bool b[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=52;i++)
		b[i]=false;
	for(int i=1;i<=n;i++){
		cin>>s;char h=s[0],l=s[1];
		int t=0;
		switch(h){
			case 'D':break;
			case 'C':t=13;break;
			case 'H':t=26;break;
			case 'S':t=39;break;
		}
		switch(l){
			case 'A':l='1';break;
			case 'T':l='9'+1;break;
			case 'J':l='9'+2;break;
			case 'Q':l='9'+3;break;
			case 'K':l='9'+4;break;
		}
		t+=l-'0';
		b[t]=true;
	}
	for(int i=1;i<=52;i++)
		if(b[i]==false)
			a++;
	cout<<a;
	return 0;
}
