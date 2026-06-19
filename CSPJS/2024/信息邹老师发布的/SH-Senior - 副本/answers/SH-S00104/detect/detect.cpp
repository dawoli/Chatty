#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int d[N],v[N],a[N];
int p[N];
int p1[N]={};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		int ans1=n;
		int ans2=0;
		for(int i=1;i<=n;i++){
			int cnt1=L-d[i];
			for(int j=d[i];j<=cnt1;j++){
				int vshun=sqrt(v[i]*v[i]+2*a[i]*j);
				if(vshun>V){
					for(int k=1;k<=L;k++){
						if(p[k]==j){
							p1[k]++;
						}
					}
				}
				else{
					ans1--;
				}
			}
			//I 	che
			
		}
		cout<<ans1<<' ';
		for(int i=1;i<=m;i++){
			if(p1[i]==m)ans2++;
		}
		cout<<ans2;
	}
	return 0;
}
/*
n车辆数量	m测速仪数量	L主干道长度	V道路限速
d	weizhi	v	sudu	a	jiasudu
*/
