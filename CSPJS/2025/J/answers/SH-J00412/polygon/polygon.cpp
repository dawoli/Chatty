#include<bits/stdc++.h>
using namespace std;
const int N=5009;
int n,a[N],b[N],ans;
int maxd(){
	int maxx=0;
	for(int i=0;i<n;i++){
		maxx=max(a[i],maxx);
	}
	return maxx;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(n==3){
			if(a[0]+a[1]+a[2]>2*(max(a[0],max(a[1],a[0])))){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
	}
	if(maxd()<=1){
		ans=1; 
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
