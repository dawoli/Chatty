#include<bits/stdc++.h>
using namespace std;
const int N=20;
int t;
int n;
int a[N];
int ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<ans;
	}
	return 0;
}
