#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[100009]={},r[100009]={},b[100009]={},maxn=-1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		r[a[i]]++;
		if(a[i]>maxn) maxn=a[i];
	}
	for(int i=1;i<=maxn;i++){
		if(b[i-1]>r[i]) b[i]=b[i-1];
		else b[i]=r[i];
	}
	if(r[maxn]>b[maxn-1]) cout<<r[maxn];
	else cout<<b[maxn-1];
	return 0;
} 
