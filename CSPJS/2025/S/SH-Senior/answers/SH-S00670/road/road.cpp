#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;//n座城市  m条道路  k个乡镇
ll ans[10];
int u[100020],v[100020];//第i(1≤i≤m)条道路连接城市ui和vi
ll w[100020], c[20], a[20][10020];//修复第i(1≤i≤m)条道路的费用为wi 
//对于第j(1≤j≤k)个乡镇，C国对其进行城市化改造的费用为cj
//它与第i(1≤i≤n)座城市间建造一条道路的费用为aj,i

ll wo,bu,hui;//? 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int ix=0;ix<m;ix++){
		//?
		ll t= 1;
		cin>>wo>>bu>>hui;
		t+=max(wo,min(bu,hui));
		//不会图论
		//?
		ans[ix]=t;
	}
	for(int ix=0;ix<t;ix++)cout<<ans[ix]<<'\n';
	return 0;
}
