#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int d[N],v[N],a[N],p[N];
vector<pair<int,int>> intervals;
int cnt;
int n,m,L,V;
void add_after(int x){
    int idx = lower_bound(p+1,p+1+m,x)-p;
    if(idx <= m){
        cnt ++;
        intervals.push_back({idx,m});
    }
}
void add_between(int l,int r){
    int ll = lower_bound(p+1,p+1+m, l) - p;
    int rr = upper_bound(p+1,p+1+m, r) - p -1;
    if(ll<=rr){
        cnt ++;
        intervals.push_back({ll,rr});
    }
}

bool cmp(const pair<int,int>& lhs, const pair<int,int>& rhs){
    return lhs.second < rhs.second;
}

// 检查两个
// 1. 各种取整开闭是否正确
// 2. 这个区间的贪心策略是否正确

void solve(){
    cnt = 0;
    intervals.clear();
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>v[i]>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(v[i]<=V)continue;
            add_after(d[i]);
        }
        else if(a[i]>0){
            if(v[i]>V) add_after(d[i]);
            else{
                // v>V
                int dd = (V*V - v[i]*v[i])/(a[i]*2);
                add_after(d[i]+dd+1);
            }
        }
        else{
            if(v[i]<=V)continue;
            int dd = (v[i]*v[i] - V*V -a[i]*2 -1)/(a[i]*-2);
            add_between(d[i], d[i]+dd-1);
        }
    }

    int need = 0;
    int now = 0;
    sort(intervals.begin(),intervals.end(), cmp);
    for(int i=0;i<intervals.size();i++){
        int l=intervals[i].first, r=intervals[i].second;
        if(now<l){
            need ++;
            now = r;
        }
    }

    cout << cnt << ' ' << m - need <<'\n';
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);

    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
