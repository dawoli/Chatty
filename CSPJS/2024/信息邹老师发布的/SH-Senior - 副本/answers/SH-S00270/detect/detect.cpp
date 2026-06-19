#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int tl,n,m,l,v,a[N];
vector<pair<int,int> > q;
int ans1,ans2;bool vl[N];

bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second||x.second==y.second&&x.first<y.first;
}

void solve(){
    cin>>n>>m>>l>>v;int x,y,z;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        if(z>0){
            if(y>v)q.push_back({x,l});
            else{x+=(v*v-y*y)/(z*2)+1;
                if(x<=l)q.push_back({x,l});
            }
        }else if(z<0){
            if(y>v){
                y=x+(y*y-v*v-1)/(-z*2);
                q.push_back({x,min(y,l)});
            }
        }else if(y>v)q.push_back({x,l});
    }
    sort(q.begin(),q.end(),cmp);a[0]=-1;
    for(int i=1;i<=m;i++)cin>>a[i];x=0;ans2=m;
    for(auto j:q){//cerr<<j.first<<" "<<j.second<<"\n";
        if(x==m+1)break;
        if(a[x]<j.first){
            while(x<m&&a[x+1]<=j.second)x++;
            if(a[x]<j.first)continue;
            if(!vl[x])vl[x]=1,ans2--;ans1++;
        }
        else{ans1++;if(!vl[x])vl[x]=1,ans2--;}
    }cout<<ans1<<" "<<ans2<<"\n";
    ans1=ans2=0;q.clear();memset(vl,0,sizeof(vl));
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin>>tl;
    for(int i=1;i<=tl;i++)solve();
    return 0;
}