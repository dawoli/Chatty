#include<bits/stdc++.h>
using namespace std;
int n,r,m=0;
int a[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r;
		a[r]++;
	}
	for(int i=1;i<=100000;i++){
		if(a[i]>=m)
			m=a[i];
	}
	cout<<m;
	return 0;
} 
