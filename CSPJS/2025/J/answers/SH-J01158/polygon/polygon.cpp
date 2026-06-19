






#include <bits/stdc++.h>
using namespace std;
int n;
int maxn=-1,sum;
int a[500005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum>maxn*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
