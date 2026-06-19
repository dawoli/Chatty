#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
long long ans;
bool s[1005][1005];
bool check[1005][1005];
void doit(){
	for(int i=1;i<=k;++i){
		int x0=x,y0=y;
		if(d==0)
			y0++;
		if(d==1)
			x0++;
		if(d==2)
			y0--;
		if(d==3)
			x0--;
		
		
		if(x0<1||x0>n||y0<1||y0>m){
			d=(d+1)%4;
		}else{
			if(s[x0][y0]==false){
				d=(d+1)%4;
			}else{
				if(check[x0][y0]==false){
					ans++;
				}
				check[x0][y0]=true;
				x=x0;
				y=y0;
				
			}
		}
	}
}
void scan(){
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	ans=1;
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			check[i][j]=false;
			char x;
			cin>>x;
			if(x=='.'){
				s[i][j]=true;
			}else{
				s[i][j]=false;
			}
		}
	}
	check[x][y]=true;
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	for(int w=1;w<=T;++w){
		scan();
		doit();
		cout<<ans<<endl;
	}
	return 0;
}
