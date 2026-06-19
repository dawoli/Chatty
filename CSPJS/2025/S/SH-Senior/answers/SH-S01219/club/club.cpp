#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[3];
struct node{long long a[3],val;int xi,yi,zi,id;}s[100010];
bool cmp(node a,node b){
	return a.val>b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			cin>>s[i].a[0]>>s[i].a[1]>>s[i].a[2];
			s[i].id = i;
			for(int p = 0;p <= 2;p++){
				for(int q = 0;q <= 2;q++){
					if(p==q) continue;
					int r = 3-p-q;
					if(s[i].a[p]>=s[i].a[q]&&s[i].a[q]>=s[i].a[r]){
						s[i].xi = p;
						s[i].yi = q;
						s[i].zi = r;
					}
				}
			}
			s[i].val = s[i].a[s[i].xi]-s[i].a[s[i].yi];
		}
		sort(s+1,s+n+1,cmp);
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1;i <= n;i++){
			if(cnt[s[i].xi]>=n/2){
				cnt[s[i].yi]++;
				ans += s[i].a[s[i].yi];
			}
			else{
				cnt[s[i].xi]++;
				ans += s[i].a[s[i].xi];
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
