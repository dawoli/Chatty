#include<bits/stdc++.h>
using namespace std;
int n;
string card;
int p[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>card;
		int col,num;
		if(card[1]>='2'&&card[1]<='9'){
			num=card[1]-48;
		}else{
			switch(card[1]){
				case'A':num=1;break;
				case'T':num=10;break;
				case'J':num=11;break;
				case'Q':num=12;break;
				case'K':num=13;break;
			}
		}
		switch(card[0]){
			case'D':col=1;break;
			case'C':col=2;break;
			case'S':col=3;break;
			case'H':col=4;break;
		}
		p[col][num]=1;
	}
	long long cnt=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(p[i][j]==0){
				cnt++;
			}
		}
	}
	cout <<cnt<<endl;
	return 0;
} 
