#include<iostream>
#include<cstdio>
using namespace std;
bool a[5][15];
int n,x,y,sum;
char p,q;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p>>q;
		if(p=='D')x=1;
		if(p=='C')x=2;
		if(p=='H')x=3;
		if(p=='S')x=4;
		if(q>'0'&&q<='9')y=q-'0';
		if(q=='A')y=1;
		if(q=='T')y=10;
		if(q=='J')y=11;
		if(q=='Q')y=12;
		if(q=='K')y=13;
		a[x][y]=1;
	}
	for(int i=1;i<5;i++){
		for(int j=1;j<14;j++){
			if(!a[i][j])sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
