#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	int Letters[13][4][3];
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			Letters[i-1][j-1][0]=j;
			Letters[i-1][j-1][1]=i;
			Letters[i-1][j-1][2]=0;
		}
	}
	scanf("%d",&n);
	string a;
	int huase,dianshu;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a[0]=='D') huase=1;
		else if(a[0]=='C') huase=2;
		else if(a[0]=='H') huase=3;
		else huase=4;
		if(a[1]=='A') dianshu=1;
		else if(a[1]=='T') dianshu=10;
		else if(a[1]=='J') dianshu=11;
		else if(a[1]=='Q') dianshu=12;
		else if(a[1]=='K') dianshu=13;
		Letters[dianshu-1][huase-1][2]=1;
	}
	int cnt=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(Letters[j-1][i-1][2]==0) cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
/*
//第一个花色，第二个点数，第三个是否有了 
		{1,1,0},{2,1,0},{3,1,0},{4,1,0},
		{1,2,0},{2,2,0},{3,2,0},{4,2,0},
		{1,3,0},{2,3,0},{3,3,0},{4,3,0},
		{1,4,0},{2,4,0},{3,4,0},{4,4,0},
		{1,5,0},{2,5,0},{3,5,0},{4,5,0},
		{1,6,0},{2,6,0},{3,6,0},{4,6,0},
		{1,7,0},{2,7,0},{3,7,0},{4,7,0},
		{1,8,0},{2,8,0},{3,8,0},{4,8,0},
		{1,9,0},{2,9,0},{3,9,0},{4,9,0},
		{1,10,0},{2,10,0},{3,10,0},{4,10,0},
		{1,11,0},{2,11,0},{3,11,0},{4,11,0},
		{1,12,0},{2,12,0},{3,12,0},{4,12,0},
		{1,13,0},{2,13,0},{3,13,0},{4,13,0}
		*/
