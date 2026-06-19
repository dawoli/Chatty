#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1019;
ll T,n,m,k,x0,y0,d0,cnt;
bool mp[N][N],vst[N][N];
void solve1(){
	ll x=x0,y=y0,d=d0;
	vst[x][y]=1;
	cnt=1;
	ll nx=0,ny=0;
	while(k>0){
		if(d==0){
			nx=0;
			ny=1;
		}
		else if(d==1){
			nx=1;
			ny=0;
		}
		else if(d==2){
			nx=0;
			ny=-1;
		}
		else if(d==3){
			nx=-1;
			ny=0;
		}
		if(mp[x+nx][y+ny]){
			x+=nx;
			y+=ny;
			if(!vst[x][y]){
				vst[x][y]=1;
				cnt++;
			}
			k--;
		}
		else{
			d=(d+1)%4;
			k--;
		}
	}
	cout<<cnt<<endl;
}
string ss;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(ll tt=1;tt<=T;++tt){
		for(ll i=0;i<=1002;++i){
			for(ll j=0;j<=1002;++j){
				mp[i][j]=0;
				vst[i][j]=0;
			}
		}
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(ll i=1;i<=n;++i){
			cin>>ss;
			ss=" "+ss;
			for(ll j=1;j<=m;++j){
				if(ss[j]=='.'){
					mp[i][j]=1;
				}
				else{
					mp[i][j]=0;
				}
			}
		}
		solve1();
	}
	return 0;
}
