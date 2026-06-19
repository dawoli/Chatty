#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
bool card[100][4];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=13;i++){
		for(int j=0;j<=3;j++){
			card[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		char x,y;
		int color,num;
		cin>>x>>y;
		if(x=='D')color=0;
		if(x=='C')color=1;
		if(x=='H')color=2;
		if(x=='S')color=3;
		if('2'<=y&&y<='9'){
			num=y-'0';
		}
		else{
			if(y=='A')num=1;
			if(y=='T')num=10;
			if(y=='J')num=11;
			if(y=='Q')num=12;
			if(y=='K')num=13;
		}
		card[num][color]=1;
	}
	for(int i=1;i<=13;i++){
		for(int j=0;j<=3;j++){
			if(card[i][j]==0){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
