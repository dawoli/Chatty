#include <bits/stdc++.h>
using namespace std;
int n,a[10][50];
char x,y;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(x=='D'){
			if(y=='A')
				a[1][1]=1;
			else if(y=='T')
				a[1][10]=1;
			else if(y=='J')
				a[1][11]=1;
			else if(y=='Q')
				a[1][12]=1;
			else if(y=='K')
				a[1][13]=1;
			else
				a[1][y-'0']=1;
		}
		if(x=='C'){
			if(y=='A')
				a[2][1]=1;
			else if(y=='T')
				a[2][10]=1;
			else if(y=='J')
				a[2][11]=1;
			else if(y=='Q')
				a[2][12]=1;
			else if(y=='K')
				a[2][13]=1;
			else
				a[2][y-'0']=1;
		}
		if(x=='H'){
			if(y=='A')
				a[3][1]=1;
			else if(y=='T')
				a[3][10]=1;
			else if(y=='J')
				a[3][11]=1;
			else if(y=='Q')
				a[3][12]=1;
			else if(y=='K')
				a[3][13]=1;
			else
				a[3][y-'0']=1;
		}
		if(x=='S'){
			if(y=='A')
				a[4][1]=1;
			else if(y=='T')
				a[4][10]=1;
			else if(y=='J')
				a[4][11]=1;
			else if(y=='Q')
				a[4][12]=1;
			else if(y=='K')
				a[4][13]=1;
			else
				a[4][y-'0']=1;
		}
	}
	int ans=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(!a[i][j])
				ans++;
	cout<<ans;
	return 0;
} 
