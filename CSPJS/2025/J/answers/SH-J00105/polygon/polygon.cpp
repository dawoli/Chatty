#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=4;i<=n;i++){
			cnt+=n-i+1;
	}
	cout<<cnt;
	return 0;
}
