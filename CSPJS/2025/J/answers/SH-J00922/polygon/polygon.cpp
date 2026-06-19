#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[23333];
ll c(int x,int y){
	ll an=1,ab=1;
	for(int opo=x;opo>x-y;opo--){
		an*=opo;
	}for(int oe=1;oe<=y;oe++)ab*=oe;
	return an/ab; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int  n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}//a.sort(a,a+n);
	for(int i=3;i<=n;i++){
		ans+=c(n,i);
	}cout<<ans<<endl;
	
	return 0;
}
