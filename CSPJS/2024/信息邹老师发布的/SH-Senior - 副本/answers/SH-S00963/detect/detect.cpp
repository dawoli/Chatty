#include <bits/stdc++.h>
using namespace std;

int T,n,m,L,V;
int d[100005],v[100005],a[100005];
int tec[100005];
int vis[100005];
int over;

void whover(){
	for(int i=1;i<=n;i++){
		double st=0,ed=0;
		if(a[i]==0){
			if(v[i]<=V) continue;
			for(int j=1;j<=m;j++){
				if(d[i]<=tec[j]){
					vis[j]=1;
					over++;
					break;
				}
			}
		}else if(a[i]>0){
			if(v[i]<V) st=d[i]+(pow(V,2)-pow(v[i],2))/double(2*a[i]);
			else st=d[i];
			for(int j=1;j<=m;j++){
				if(st<=tec[j]){
					vis[j]=1;
					over++;
					break;
				}
			}
		}else if(a[i]<0){
			if(v[i]<=V) continue;
			ed=d[i]+(pow(V,2)-pow(v[i],2))/double(2*a[i]);
			for(int j=m;j>=1;j--){
				if(ed>=tec[j] && d[i]<=tec[j]){
					vis[j]=1;
					over++;
					break;
				}
			}
		}
	}
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int aa=1;aa<=T;aa++){
		over=0;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(tec,0,sizeof(tec));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>tec[i];
		whover();
		cout<<over<<" ";
		int num=0;
		for(int i=1;i<=m;i++){
			if(vis[i]) num++;
		}
		cout<<n-num<<endl;
	}
	return 0;
}
