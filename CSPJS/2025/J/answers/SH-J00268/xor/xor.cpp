#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
void dfs(int t){
	if(t)
}
int main(){
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		a[i]^=a[i-1];
	}
	dfs();
} 
