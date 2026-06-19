#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	cout<<1<<endl;
	for(int i=n-1;i>=0;i--){
		cout<<a[i]<<" ";
	}
	return 0;
}
