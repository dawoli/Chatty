#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	long long n,m,k,s=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i]>>a[i+1]>>a[i+2];
		s+=min(a[i],a[i+1],a[i+2]);
	}cout<<s;
	return 0; 
}
