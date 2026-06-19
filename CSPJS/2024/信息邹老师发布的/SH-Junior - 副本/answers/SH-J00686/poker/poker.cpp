#include<bits/stdc++.h>
using namespace std;
int ans[5][14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char x,y;
		cin>>x>>y;
		int c,d;
		if(y=='A')d=1;
		else if(y=='T')d=10;
		else if(y=='J')d=11;
		else if(y=='Q')d=12;
		else if(y=='K')d=13;
		else if(y>='1' and y<='9'){
			d=y-'1'+1;
		}
		if(x=='D')c=1;
		else if(x=='C')c=2;
		else if(x=='H')c=3;
		else if(x=='S')c=4;
		ans[c-1][d-1]++;
	}
	int z=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			
			if(ans[i][j]==0)z++;
		}
	}
	cout<<z;
	return 0;
} 

