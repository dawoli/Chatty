#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,b=0,d=1e7;
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		a[c]++;
		b=max(b,c);
		d=min(d,c);
	}
	int r=a[b];
	for(int i=b-1;i>=d;i--){
		if(a[i]>0){
			if(a[i]<r) n-=a[i];
			else n-=r;
			r=a[i];
		}
	}
	cout<<n;
	return 0;
}
