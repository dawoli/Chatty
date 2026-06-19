#include<bits/stdc++.h>
using namespace std;
int a[5][14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.ans","w",stdout);
	int n,ans;
	cin>>n;
	for(int i=0;i<n;++i){
		string p;
		cin>>p;
		int h,v;
		if(p[0]=='D') h=1;
		else if(p[0]=='C') h=2;
		else if(p[0]=='H') h=3;
		else if(p[0]=='S') h=4;
		
		if(p[1]=='A') v=1;
		else if(p[1]=='T') v=10;
		else if(p[1]=='J') v=11;
		else if(p[1]=='Q') v=12;
		else if(p[1]=='K') v=13;
		else v=p[1]-'0';
		
		a[h][v]=1;
	}
	for(int i=1;i<5;++i)
		for(int j=1;j<14;++j)
			if(!a[i][j])
				++ans;
	cout<<ans;
	return 0;
}
