#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool card[5][14];
int ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string c;
		cin>>c;
		int co,nu;
		if(c[0]=='D'){
			co=1;
		}
		else if(c[0]=='C'){
			co=2;
		}
		else if(c[0]=='S'){
			co=3;
		}
		else if(c[0]=='H'){
			co=4;
		}
		if(c[1]<='9'&&c[1]>='2'){
			nu=c[1]-'0';
		}
		else if(c[1]=='T'){
			nu=10;
		}
		else if(c[1]=='J'){
			nu=11;
		}
		else if(c[1]=='Q'){
			nu=12;
		} 
		else if(c[1]=='K'){
			nu=13;
		}
		else if(c[1]=='A'){
			nu=1;
		}
		if(card[co][nu]==0){
			ans--;
		}
		card[co][nu]=1;
	}
	cout<<ans;
	return 0;
}
