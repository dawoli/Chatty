#include <bits/stdc++.h>
#define pii pair<long long,long long>
using namespace std;
const int maxn=2e5+5;
long long a[maxn],cnt[maxn];
int main(){
	freopen("color.in",r,stdin);
	freopen("color.out",w,stdout);
	long long t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		set<long long> s;
		long long n;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			s.insert(a[i]);
			cnt[a[i]]++;
		}
		long long ans=0;
		for(int b:s){
			if(cnt[b]>=2){
				ans+=(cnt[b]-1)*b;
			}
		}
		cout<<ans<<"\n";
	}
}
