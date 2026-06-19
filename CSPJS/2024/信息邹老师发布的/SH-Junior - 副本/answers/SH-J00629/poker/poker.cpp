#include <bits/stdc++.h>
using namespace std;
bool book[52];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0,x=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		int a,b;
		switch(s[0]){
			case 'D':a=1;break;
			case 'C':a=2;break;
			case 'H':a=3;break;
			case 'S':a=4;break;
		}
		switch(s[1]){
			case 'A':b=1;break;
			case 'T':b=10;break;
			case 'J':b=11;break;
			case 'Q':b=12;break;
			case 'K':b=13;break;
			default: b=s[1]-'0';break;
		}
		x=a*b-1;
		if(book[x]==0){
			cnt++;
			book[x]=1; 
		}
	}
	cout<<(52-cnt);
}
