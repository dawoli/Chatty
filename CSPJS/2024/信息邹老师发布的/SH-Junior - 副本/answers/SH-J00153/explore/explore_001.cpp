#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
char a[1009][1009];
ll vst[1009][1009];
ll n,m,k,x0,y0,d0;
ll dfs(){
	d0%=4;
	if(d0==0){
		if(a[x0][y0+1]=='.'){
			vst[x0][y0+1]=1; 
			y0++;
		}
		else{
			d0+=1;
			d0%=4;
		}
	}
	else if(d0==1){
		if(a[x0+1][y0]=='.'){
			vst[x0+1][y0]=1; 
			x0++;
		}
		else{
			d0+=1;
			d0%=4;
		}
	}
	else if(d0==2){
		if(a[x0][y0-1]=='.'){
			vst[x0][y0-1]=1; 
			y0--;
		}
		else{
			d0+=1;
			d0%=4;
		}
	}
	else if(d0==3){
		if(a[x0-1][y0]=='.'){
			vst[x0-1][y0]=1; 
			x0--;
		}
		else{
			d0+=1;
			d0%=4;
		}
	}
	return 0;
}
void solve(){
	for(int i=0;i<1009;i++)
		for(int j=0;j<1009;j++)
			a[i][j]=' ',vst[i][j]=0;
	cin>>n>>m>>k>>x0>>y0>>d0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	vst[x0][y0]=1;
	for(int i=1;i<=k;i++){
		d0%=4;
		dfs();
	}	
	ll cnt=0;		
	for(int i=0;i<1009;i++)
		for(int j=0;j<1009;j++)
			if(vst[i][j]==1)cnt++;
	cout<<cnt<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll t;
	cin>>t;
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}
