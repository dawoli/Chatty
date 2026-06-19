#include<bits/stdc++.h>
using namespace std;
bool flag[10][20];
char a,b;
int n,cnt;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		if(a=='S'){
			if(b=='T')	flag[1][10]=1;
			else if(b=='A')	flag[1][1]=1;
			else if(b=='J')	flag[1][11]=1;
			else if(b=='Q')	flag[1][12]=1;
			else if(b=='K')	flag[1][13]=1;
			else flag[1][int(b-'0')]=1;
		}
		else if(a=='H'){
			if(b=='T')	flag[2][10]=1;
			else if(b=='A')	flag[2][1]=1;
			else if(b=='J')	flag[2][11]=1;
			else if(b=='Q')	flag[2][12]=1;
			else if(b=='K')	flag[2][13]=1;
			else flag[2][int(b-'0')]=1;
		}
		else if(a=='D'){
			if(b=='T')	flag[3][10]=1;
			else if(b=='A')	flag[3][1]=1;
			else if(b=='J')	flag[3][11]=1;
			else if(b=='Q')	flag[3][12]=1;
			else if(b=='K')	flag[3][13]=1;
			else flag[3][int(b-'0')]=1;
		}
		else if(a=='C'){
			if(b=='T')	flag[4][10]=1;
			else if(b=='A')	flag[4][1]=1;
			else if(b=='J')	flag[4][11]=1;
			else if(b=='Q')	flag[4][12]=1;
			else if(b=='K')	flag[4][13]=1;
			else flag[4][int(b-'0')]=1;
		}
	}
	for(int i=1;i<=4;++i)
		for(int j=1;j<=13;++j)
			if(!flag[i][j]){
				//cerr<<i<<' '<<j<<endl;
				cnt++;
			}
	cout<<cnt<<endl;
	return 0;
}
