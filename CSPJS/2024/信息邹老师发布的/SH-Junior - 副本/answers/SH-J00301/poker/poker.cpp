#include<iostream>
using namespace std;
int main(){
	fopen("poker.in","r");
	fopen("poker.out","w");
	int n;
	int a[20][20];
	cin>>n;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			a[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		char x,y;
		int b,c;
		cin>>x>>y;
		if(x=='D')b=1;
		if(x=='C')b=2;
		if(x=='H')b=3;
		if(x=='S')b=4;
		if(y=='A')c=1;
		if(y>='2'&&y<='9')c=int(y)-'0';
		if(y=='T')c=10;
		if(y=='J')c=11;
		if(y=='Q')c=12;
		if(y=='K')c=13;
		a[b][c]=1;
	}
	int ans=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==1)ans++;
		}
	}
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
