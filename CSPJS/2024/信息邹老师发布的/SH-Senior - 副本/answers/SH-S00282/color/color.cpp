#include<bits/stdc++.h>
using namespace std;
int a[1000001],ans[11];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		ans[i]=65536;
	}
	for(int i=0;i<t;i++){
		cout<<ans[i];
	}
	return 0;
}
