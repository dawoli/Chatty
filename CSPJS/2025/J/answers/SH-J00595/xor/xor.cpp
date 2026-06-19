#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],trie[N];
vector<int> st(N,N);
ll fxor(ll a,ll b){
	return (~a&b)|(a&~b);
}
int main(){
    freopen("xor4.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
	ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		trie[i]=fxor(trie[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(fxor(trie[i],trie[j-1])==k){
				st[j]=min(st[j],i);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int idx=1,res=0;
		while(idx<=n){
			res++;
			idx=st[idx]+1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

