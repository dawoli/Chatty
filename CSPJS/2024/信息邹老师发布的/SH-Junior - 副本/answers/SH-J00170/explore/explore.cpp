#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,x,y,T,d;
long long ans,k;
int r;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	d=0;
	cin>>T;
	for(int w=1;w<=T;w++){
		cin>>n>>m>>k>>x>>y>>d;
		string mp[n+5];
		for(int i=1;i<=n;i++){
			cin>>mp[i];
		}				
		for(int i=1;i<=k;i++){
			if(d==0) y+=1;
			else if(d==1) x+=1;
			else if(d==2) y-=1;
			else if(d==3) x-=1;
			if(1<=x&&x<=n&&1<=y&&y<=m&&mp[x][y-1]!='x'){
				ans++;
			}
			else{
				if(d==0) y-=1;
				else if(d==1) x-=1;
				else if(d==2) y+=1;
				else if(d==3) x+=1;
				d=(d+1)%4;
			}
		
		}
		if(r==0) {
			cout<<ans+1;
			r++;
		}
		
		else cout<<endl<<ans;
		ans=1;
	}
	return 0;
}	

