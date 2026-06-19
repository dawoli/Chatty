#include<bits/stdc++.h>
using namespace std;
bool mat[5][14];
int ans=52;
int n;
char buf[3];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>buf;
		int tmpa,tmpb;
		switch(buf[0]){
			case 'D':
				tmpa=1;
				break;
			case 'C':
				tmpa=2;
				break;
			case 'H':
				tmpa=3;
				break;
			case 'S':
				tmpa=4;
				break;
		}
		switch(buf[1]){
			case 'A':
				tmpb=1;
				break;
			case 'T':
				tmpb=10;
				break;
			case 'J':
				tmpb=11;
				break;
			case 'Q':
				tmpb=12;
				break;
			case 'K':
				tmpb=13;
				break;
			default:
				tmpb=buf[1]-'0';
				break;
		}
		mat[tmpa][tmpb]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			ans-=mat[i][j];
		}
	}
	cout<<ans;
	return 0;
}

