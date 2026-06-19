#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
/*
v[i]:初速度 a[i]:加速度
n,m,L,V,分别表示车辆数量、测速仪数量、主干道长度和道路限速
*/
int T,d[N],v[N],a[N];
int pos[N];
bool cd1(int n){for(int i=1;i<=n;++i)if(a[i]!=0)return 0;return 1;}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	for(int i=1;i<=T;++i){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;++j){
			cin>>d[j]>>v[j]>>a[j];	
		}
		for(int j=1;j<=m;++j)
			cin>>pos[j];
		if(a[j]==0){
			
		}
		else if(a[j]>0){
			double g=(V*V-v[j])*1.0/(2*a[j]);
		}
		else{
			
		}
		//[d[j],d[j]+g)
	}
	return 0;
}
