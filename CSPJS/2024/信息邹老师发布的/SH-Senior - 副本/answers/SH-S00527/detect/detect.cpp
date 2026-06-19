//A, B 40pts 
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
const int maxm=1e5+5;

int T;
int d[maxn],v[maxn],a[maxn];
int p[maxm];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		int maxp=-1;
		for(int i=1;i<=m;i++)maxp=max(maxp,p[i]);
		int ans1=0,ans2;
		for(int i=1;i<=n;i++){
			if(d[i]<=maxp){
				if(sqrt(v[i]*v[i]+2*a[i]*(maxp-d[i]))>V)ans1++;
			}
		}
		if(ans1==0)ans2=m;
		else ans2=m-1;
		cout<<ans1<<" "<<ans2<<"\n";
	}
	return 0;
} 
