#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int T,n,a[N][3],b[N],c[3];
vector<int> v;
void solve(){
	v.clear();
	int ans=0;
	c[0]=c[1]=c[2]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x=-1,y=0;
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(a[i][j]>x) x=a[i][j],y=j;
		}
		ans+=x;
		c[y]++;
		b[i]=y;
	}
	int mx=0,mxp=0;
	for(int j=0;j<3;j++)if(c[j]>mx) mx=c[j],mxp=j;
	if(mx*2>n){
		for(int i=1;i<=n;i++)if(b[i]==mxp){
			int mn=1e9;
			for(int j=0;j<3;j++)if(j!=mxp) mn=min(mn,a[i][mxp]-a[i][j]);
			v.push_back(mn);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<mx-n/2;i++) ans-=v[i];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
