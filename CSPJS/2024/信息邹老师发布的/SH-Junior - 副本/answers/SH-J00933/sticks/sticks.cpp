#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009,SIZE=10009,INF=1e12+7;
ll T,n,f[N],i=22;
//ll getl(ll a){
//	ll ans=0;
//	do{
//		ans++;
//		a/=10;
//	}while(a);
//	return ans;
//}
//ll p10(ll p){
//	ll ans=1;
//	for(ll q=1;q<=p;q++) ans*=10;
//	return ans;
//}
//0 6
//1 2
//2 5
//4 4
//7 3
//8 7

//6 6

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	f[0]=0;
	f[1]=-1;
	f[2]=1;
	f[3]=7;
	f[4]=4;
	f[5]=2;
	f[6]=6;
	f[7]=8;
	f[8]=10;
	f[9]=67;
	f[10]=22;
	f[11]=20;
	f[12]=28;
	f[13]=68;
	f[14]=88;
	f[15]=108;
	f[16]=188;
	f[17]=200;
	f[18]=208;
	f[19]=288;
	f[20]=688;
	f[21]=888;
	f[22]=1088;
//	for(ll p=1;p<=9;p++) g[p]=getl(f[p]);
	cin>>T;
	while(T--){
		cin>>n;
		if(n%7==0){
			for(ll i=1;i*7<=n;i++) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==1){
			cout<<10;
			for(ll i=1;i*7<=n-8;i++) cout<<8;
			cout<<endl;
			continue;
		}
		if(n<=40){
			for(;i<=n;i++){
				f[i]=INF;
				f[i]=min(f[i],f[i-6]*10+0);
				f[i]=min(f[i],f[i-2]*10+1);
				f[i]=min(f[i],f[i-5]*10+2);
				f[i]=min(f[i],f[i-3]*10+7);
				f[i]=min(f[i],f[i-4]*10+4);
				f[i]=min(f[i],f[i-7]*10+8);
			}
			if(f[n]==INF) cout<<"-1"<<endl;
			else cout<<f[n]<<endl; 
		}
		else{
			ll k=n/7-2;
			ll v=n%7+14;
			cout<<f[v];
			for(ll p=1;p<=k;p++) cout<<8;
			cout<<endl;
		}
	}
//	for(ll i=1;i<=50;i++) cout<<i<<":"<<f[i]<<endl;
	return 0;
}
