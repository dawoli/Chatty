#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100114
ll a[N][4];
pair<ll,int> d[N][4];
ll cnt[N];
vector<int> vec;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        ll ans=0;
        for(int i=1;i<=n;i++) {
            d[i][0]=make_pair(a[i][0],0);
            d[i][1]=make_pair(a[i][1],1);
            d[i][2]=make_pair(a[i][2],2);
            sort(d[i],d[i]+3);
            cnt[d[i][2].second]++;
            ans+=d[i][2].first;
        }
        int pos=-1;
        for(int i=0;i<=2;i++) {
            if(cnt[i]>n/2) {//if cnt[i]>n/2, other cnt won't >n/2
                pos=i;
                break;
            }
        }
        if(pos!=-1) {
            for(int i=1;i<=n;i++) {
                if(d[i][2].second==pos) {
                    vec.push_back(d[i][2].first-d[i][1].first);
                }
            }
            sort(vec.begin(),vec.end());
            for(int i=0;i<cnt[pos]-n/2;i++) ans-=vec[i];
        }
        cout<<ans<<"\n";
        for(int i=0;i<=2;i++) cnt[i]=0;
        vec.clear();
        for(int i=1;i<=n;i++) d[i][0]=d[i][1]=d[i][2]=make_pair(0,0);
    }
    return 0;
}
