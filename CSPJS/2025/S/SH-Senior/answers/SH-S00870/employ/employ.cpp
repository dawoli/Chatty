#include<bits/stdc++.h>
using namespace std;
int E[505],D[505],n,m;
long long M;
string L;
void e(int em,int ue){
	if(em==n){
		if(ue<=n-m){
			M+=1;
		if(M==998244353)M=0;
		}
		
		return;
	}
	for(int i=0;i<n;i++){
		if(!D[i]){
			D[i]=1;
			if(E[i]<=ue||!(int(L[em])-48))e(em+1,ue+1);
			else e(em+1,ue);
			D[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>L;
	for(int i=0;i<n;i++)cin>>E[i];
	e(0,0);
	cout<<M;
	return 0;
}
