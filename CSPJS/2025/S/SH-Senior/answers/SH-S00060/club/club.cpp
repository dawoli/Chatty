#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+7;

int n;
struct Num{
	int x,y,z;
}sz[N];
ll ans=0;

void search(int k,ll a,ll b,ll c,int d,int e,int f){
	if(d>n/2 || e>n/2 || f>n/2) return ;
	else if(k==n){
		ans=max(ans,a+b+c);
	}
	k++;
	search(k,a+sz[k].x,b,c,d+1,e,f);
	search(k,a,b+sz[k].y,c,d,e+1,f);
	search(k,a,b,c+sz[k].z,d,e,f+1);
	
}

void solve(){
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>sz[i].x>>sz[i].y>>sz[i].z;
		
	}
	search(0,0,0,0,0,0,0);
	cout<<ans<<"\n";
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t; 
	while(t--) solve();
	return 0;
}
