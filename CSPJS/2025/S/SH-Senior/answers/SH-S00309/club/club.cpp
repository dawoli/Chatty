#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,cnt[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("ciub.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		multiset <int> s[3];
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=max(b,c)){
				ans+=a;
				cnt[1]++;
				s[0].insert(a-max(b,c));
			}
			else if(b>=max(a,c)){
				ans+=b;
				cnt[2]++;
				s[1].insert(b-max(a,c));
			}
			else{
				ans+=c;
				cnt[3]++;
				s[2].insert(c-max(a,b));
			}
		}
		if(cnt[1]>n/2){
			for(int i=n/2;i<cnt[1];i++){
				auto it=s[0].begin();
				ans-=*it;
				s[0].erase(it);
			}
		}
		else if(cnt[2]>n/2){
			for(int i=n/2;i<cnt[2];i++){
				auto it=s[1].begin();
				ans-=*it;
				s[1].erase(it);
			}
		}
		else if(cnt[3]>n/2){
			for(int i=n/2;i<cnt[3];i++){
				auto it=s[2].begin();
				ans-=*it;
				s[2].erase(it);
			}
		}
		cout<<ans<<endl;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
	}
}
