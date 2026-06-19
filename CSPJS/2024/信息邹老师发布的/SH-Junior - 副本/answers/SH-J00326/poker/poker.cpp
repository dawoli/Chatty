#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
char a,b;
bool have[55][55]={0};
int main(){
	freopen("poker.in","r",stdin);freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int l1,l2;
		if(a=='D')l1=1;
		else if(a=='C')l1=2;
		else if(a=='H')l1=3;
		else if(a=='S')l1=4;
		
		if(b=='A')l2=1;
		else if(b=='T')l2=10;
		else if(b=='J')l2=11;
		else if(b=='Q')l2=12;
		else if(b=='K') l2=13;
		else{
			l2=b-'1'+1;
		}
		have[l1][l2]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!have[i][j]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
