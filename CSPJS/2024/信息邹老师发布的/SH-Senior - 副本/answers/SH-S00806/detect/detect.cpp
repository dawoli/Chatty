#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define N 100005
#define M 100005 
int T;
int n,m,L,V;
int d[N],v[N],a[N];
int p[M];
bool vis1[N]={};
int ans1=0,ans2=0;

void init() {
	memset(vis1,0,sizeof(vis1));
	ans1=0;
}

int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		init();
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) {
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++) {
			cin>>p[i];
			for(int j=1;j<=n;j++) {
				if(d[j]>p[i]) continue;
				int tv=sqrt(v[j]*v[j]+2*a[j]*(p[i]-d[j]));
				if(tv>V) {
					if(!vis1[j]) {
						vis1[j]=true;
						ans1++;
					}
				}
			}
		}
		cout<<ans1<<' '<<(ans1?m-1:m)<<endl;
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
