#include <bits/stdc++.h>
using namespace std;
int a[5][20],n,b_1,c_1,num=0;
char b,c;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i=1;i<=13;i++){
		for (int j=1;j<=4;j++){
			a[i][j]=0;
		}
	}
	for (int i=1;i<=n;i++){
		cin >> b >> c;
		if (b=='D') b_1=1;
		else if (b=='C') b_1=2;
		else if (b=='H') b_1=3;
		else b_1=4;
		if (c=='A') c_1=1;
		else if (c=='T') c_1=10;
		else if (c=='J') c_1=11;
		else if (c=='Q') c_1=12;
		else if (c=='K') c_1=13;
		else c_1=c-48;
		a[b_1][c_1]=1;
	}
	for (int i=1;i<=4;i++){
		for (int j=1;j<=13;j++){
			if (a[i][j]!=1) num++;
		}
	}
	cout << num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
