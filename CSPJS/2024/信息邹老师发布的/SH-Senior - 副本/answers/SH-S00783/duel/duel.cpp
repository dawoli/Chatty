#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define lowbit(x) (x&(-x))
#define maxn 100002
using namespace std;
typedef long long ll;
typedef __int128 lll;
int n,r[maxn];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>r[i];
	sort(r,r+n);
	int pre=0,nxt=0;
	int ans=n;
	while(nxt<n){
		++nxt;
		if(r[pre]<r[nxt]){
			--ans;
			++pre;
		}
	}
	cout<<ans<<endl;
	return 0;
}
