#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[16][6],x,y;
char huase,dis;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>huase>>dis;
		if(huase=='D')x=1;
		else if(huase=='C')x=2;
		else if(huase=='H')x=3;
		else if(huase=='S')x=4;
		if(dis>=50 && dis<=57)y=dis-48;
		else if(dis=='A')y=1;
		else if(dis=='T')y=10;
		else if(dis=='J')y=11;
		else if(dis=='Q')y=12;
		else if(dis=='K')y=13;
		a[y][x]++;
	}
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(a[i][j]==0)cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
