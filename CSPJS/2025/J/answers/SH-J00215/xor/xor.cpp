#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500007];
	cin>>n>>k;
	a[k]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n/2<<endl;
}
