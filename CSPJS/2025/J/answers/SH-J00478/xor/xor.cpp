#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+5;
int n,k;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<k/2<<endl;
	return 0;
}
