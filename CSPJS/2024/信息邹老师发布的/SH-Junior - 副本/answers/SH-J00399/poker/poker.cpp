#include<bits/stdc++.h>
using namespace std;
bool p[14][5];
int cnt=0;
int main(){
	freopen(poker.in,"r",stdin);
	freopen(poker.out,"w",stdout);
	int n;
	string poker;
	int x,y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>poker;
		switch(poker[0]){
			case('D'):
				y=1;
				break;
			case('C'):
				y=2;
				break;
			case('H'):
				y=3;
				break;
			case('S'):
				y=4;
				break;
			default:
				y=0;
				break;
		}
		switch(poker[1]){
			case('A'):
				x=1;
				break;
			case('2'):
				x=2;
				break;
			case('3'):
				x=3;
				break;
			case('4'):
				x=4;
				break;
			case('5'):
				x=5;
				break;
			case('6'):
				x=6;
				break;
			case('7'):
				x=7;
				break;
			case('8'):
				x=8;
				break;
			case('9'):
				x=9;
				break;
			case('T'):
				x=10;
				break;
			case('J'):
				x=11;
				break;
			case('Q'):
				x=12;
				break;
			case('K'):
				x=13;
				break;
			default:
				x=0;
				break;
		}
		p[x][y]=true;
	}
	for(int i=1;i<14;i++){
		for(int j=1;j<5;j++){
			if(p[i][j]==false){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
