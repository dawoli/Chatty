#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+2;
int n,m,ans;
int ord[maxn],a[maxn],t[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		t[i]=c-'0';
		ord[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	do{
		int cnt=0,fail=0;
		for(int i=1;i<=n;i++){
			int now=ord[i];
			if(fail>=a[now]){
				fail++;
				continue;
			}
			if(t[i]) cnt++;
			else fail++;
		}
		if(cnt>=m) ans++;
	}while(next_permutation(ord+1,ord+n+1)); 
	cout<<ans;
	return 0;
}
