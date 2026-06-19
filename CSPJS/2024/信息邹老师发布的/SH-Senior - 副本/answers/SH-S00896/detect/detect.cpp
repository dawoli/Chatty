#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],v[100010],d[100010];
bool book[100010];
int ca(int v0,int a,int s){
	if(a!=0)return v0*v0+2*a*s;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
	int n,m,L,V,cnt=0;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0&&v[i]>V&&d[i]<b[m])cnt++;
		else if(a[i]>0&&d[i]<b[m]&&ca(v[i],a[i],b[m]-d[i])>V*V)cnt++;
		else if(a[i]<0){
			int h=0;
			for(int j=1;j<=m;j++){
				if(b[j]>=d[i]){
				h=j;
				break;
			}
		}
			if(d[i]<b[m]&&ca(v[i],a[i],b[h]-d[i])>V*V)cnt++;
		}
	}
	if(cnt!=0)cout<<cnt<<" "<<m-1<<"\n";
	else cout<<cnt<<" "<<m<<"\n";
	}
	return 0;
}
