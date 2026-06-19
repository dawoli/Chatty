#include <bits/stdc++.h>
using namespace std;
int t, n, m, l, vmax;
struct node{
	int d;
	int v;
	int a;
}carx[100010];
struct stut{
	int head;
	int tail;
}exce[100010];

int p[100010];
int vis[100010];
int ad[100010];

double calc(int acc, int dis, int vv0){
	if(acc!=0){
		return sqrt(vv0*vv0+2*acc*dis);
	}else{
		return vv0;
	}
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	cin>>n>>m>>l>>vmax;
	for(int i=1; i<=n; i++){
		int x=0, y=0, z=0;
		cin>>x>>y>>z;
		carx[i].d = x;
		carx[i].v = y;
		carx[i].a = z;
	}
	for(int i=1; i<=n; i++){
		cin>>p[i];
	}
	for(int i=1; i<=n; i++){
		int flag = 0;
		for(int j=1; j<=m; j++){
			if(p[j]-carx[i].d<0){
				continue;
			}
			if(calc(carx[i].a, p[j]-carx[i].d, carx[i].v)>vmax){
				if(flag==0){
					flag=1;
					exce[i].head=j;
					exce[i].tail=j;
				}else{
					exce[i].tail=j;
				}
			}
		}
	}
	int ans = 0, cnt=1;
	for(int i=1; i<=n; i++){
		if(exce[i].head!=0){
			ans++;
			int tmp = 0;
			for(int j=exce[i].head; j<=exce[i].tail; j++){
				vis[j]++;
				if(ad[j]==1){
					tmp=1;
				}
			}
			if(tmp==0){
				cnt++;
			}
		}	
	}
	
	cout<<ans<<" "<<cnt;
	return 0;
}
