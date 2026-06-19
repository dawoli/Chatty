#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,r[N],a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		a[r[i]]++;
	}
	sort(r+1,r+1+n);
	int f=a[r[1]];
	for(int i=r[1]+1;i<=r[n];i++){
		if(a[i]==0) continue;
		if(a[i]>=f) f=a[i];
	}
	cout<<f<<endl;
	return 0;
}
