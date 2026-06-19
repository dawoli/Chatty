#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct stu{
	int d,v,a;
}s[N];
int p[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	int n,m,L,V;
	while(t--){
		int cnt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>s[i].d>>s[i].v>>s[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(s[1].v==0){
			for(int i=1;i<=n;i++){
				if(s[i].d<=p[m]&&s[i].v>V) cnt++;
			}
			if(cnt==0) cout<<0<<" "<<m<<"\n";
			else cout<<cnt<<" "<<m-1<<"\n";
		}
		for(int i=1;i<=n;i++){
			long double v0=sqrt(s[i].v*s[i].v+2*s[i].a*(p[m]-s[i].d));
			if(s[i].d<=p[m]&&v0>V) cnt++;
		}
		if(cnt==0) cout<<0<<" "<<m<<"\n";
		else cout<<cnt<<" "<<m-1<<"\n";
	}
	return 0;
}
