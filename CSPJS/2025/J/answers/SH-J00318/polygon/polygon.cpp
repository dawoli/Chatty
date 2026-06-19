#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100001];
int sum=0;
int maxx=-1;
signed main(){
	freopen("polygen.in","r",stdin);
	freopen("polygen.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]); 
	}
	if(n==3){
		if(sum>(2*maxx)){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
}
