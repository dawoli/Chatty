#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,ans,k;
long long my_xor[500010];
int cbe;
int do_xor(int a,int b){
	if(a==b) return 0;
	else return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i!=1) my_xor[i]=do_xor(my_xor[i-1],a[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(do_xor(my_xor[i],my_xor[j])==k&&cbe<=i){
				++ans;
				cbe=j+1;
				break;
			}
		}
	}
	cout<<ans; 
	return 0;
}
