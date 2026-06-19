#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
int cont[15]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
struct op{
	string s;
}ls[100005];
int fin(int k){
	for(int i=1;i<=14;i++){
		if(cont[i]>=k) return i;
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(int j=1;j<=m;j++){
		cin>>c[i];
	}
	int K=fin(n);
	for(int i=1;i<=K;i++){
		cin>>ls[i].s;
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int j=1;j<=n;j++){
			a[j]=aa[j]^x[j%4];
		}
	}
	return 0;
}
