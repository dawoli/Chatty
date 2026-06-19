#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN],minn=1; 
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]>a[minn]){
			minn++;
		}
	}
	cout<<n-minn+1;
}

