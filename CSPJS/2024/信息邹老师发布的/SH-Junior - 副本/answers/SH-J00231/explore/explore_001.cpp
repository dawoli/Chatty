#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	int T;
	cin>>T;
	int ans[10];
	for(int p=0;p<T;p++){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		char a[1009][1009]={};
		bool b[1009][1009]={};
		b[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<k;i++){
			if(d==0) y++;
			if(d==1) x++;
			if(d==2) y--;
			if(d==3) x--;
			if(a[x][y]!='.'){
				if(d==0) y--;
				if(d==1) x--;			
				if(d==2) y++;
				if(d==3) x++;
				d=(d+1)%4;
			}
			else{
				b[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]==1) ans[p]++;
			}
		}
	}
	for(int i=0;i<T;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
