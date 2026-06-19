#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1002;
ll n,m,k,ans,step,x_st,y_st,d_st;
char mp[N][N];
int T;
void walk(ll x_now,ll y_now,ll di){
	if(step>k) return;
	mp[x_now][y_now]='1';
	int x_nxt,y_nxt;
	if(di==0){x_nxt=x_now; y_nxt=y_now+1;}
	else if(di==1){x_nxt=x_now+1; y_nxt=y_now;}
	else if(di==2){x_nxt=x_now; y_nxt=y_now-1;}
	else if(di==3){x_nxt=x_now-1; y_nxt=y_now;}
	step++;
	if(mp[x_nxt][y_nxt]=='0' || mp[x_nxt][y_nxt]=='x'){
		di=(di+1)%4;
		walk(x_now,y_now,di);
	}else{
		walk(x_nxt,y_nxt,di);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<1002;i++)
		for(int j=0;j<1002;j++)
			mp[i][j]='0';
	for(int l=1;l<=T;l++){
		cin>>n>>m>>k;
		cin>>x_st>>y_st>>d_st;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		step=0;
		walk(x_st,y_st,d_st);
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(mp[i][j]=='1') ans++;
		cout<<ans<<endl;
	}
	return 0;
} 
