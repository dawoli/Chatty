#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
ll t,n,m,l;
db ma;
struct h{
	db s,v,a;
}e[100005];
ll b[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>ma;
		for(int i=1;i<=n;i++){
			cin>>e[i].s>>e[i].v>>e[i].a;
		}
		for(int i=1;i<=m;i++)cin>>b[i];
		int sum=0;
		for(int i=1;i<=n;i++){
			if(e[i].s>b[m])continue;
			db s=b[m]-e[i].s;
			if(sqrt(e[i].v*e[i].v+2.0*e[i].a*s)>ma)sum++;
		}
		cout<<sum<<" "<<m-1<<endl;
	}
	return 0;
} 
