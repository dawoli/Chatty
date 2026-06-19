#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k,x,y,d;
int ans[5];
char ditu[1009][1009];
bool flag=true;
int input(){
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ditu[i][j];	
			if(ditu[i][j]=='x')flag=false;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		input();
		if(k==1){
			if(m==1)ans[i]=1;
			else if(flag){
				if(y==m&&d==2)ans[i]=2;
				else if(y==1&&d==0)ans[i]=2;
				else ans[i]=1;
			}
			else if(!flag)ans[i]=1;
		}
	}
	for(int i=0;i<T;i++)cout<<ans[i]<<endl;
	return 0;
}
