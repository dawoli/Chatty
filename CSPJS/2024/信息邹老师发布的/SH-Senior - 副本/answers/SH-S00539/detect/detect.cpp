#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
int pos[100005],d[100005],v[100005],a[100005];
vector<pair<int,int>> plis;
set<pair<int,int> > ps2,ps3;
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return (a.first<b.first)||(a.first==b.first&&a.second>b.second);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>pos[i];
        for(int i=1;i<=n;i++) {
            if(v[i]<=V&&a[i]<=0) continue;
            if(a[i]==0||(a[i]>0&&v[i]>V)){
                if(d[i]>pos[m]) continue;
                int ids=lower_bound(pos+1,pos+m+1,d[i])-pos;
                plis.push_back(make_pair(ids,m));
                continue;
            }
            int vp=0;
            if((V*V-v[i]*v[i])%(2*a[i])==0) vp=(V*V-v[i]*v[i])/(2*a[i])+d[i];
            else vp=(V*V-v[i]*v[i])/(2*a[i])+d[i]+1;
            if(a[i]>0) {
                if((V*V-v[i]*v[i])%(2*a[i])==0) vp+=1;
                if(vp>pos[m]) continue;
                int ids=lower_bound(pos+1,pos+m+1,vp)-pos;
                plis.push_back(make_pair(ids,m));
            }
            else {
                // if((V*V-v[i]*v[i])%(2*a[i])==0) vp-=1;
                int ids=lower_bound(pos+1,pos+m+1,d[i])-pos,ide=lower_bound(pos+1,pos+m+1,vp)-pos;
                if(ids==ide) continue;
                plis.push_back(make_pair(ids,ide-1));
            }
            // cout<<i<<' '<<vp<<endl;
        }
        sort(plis.begin(),plis.end(),cmp);
        for(auto i:plis){
            while((!ps2.empty())&&i.second<=(ps2.begin()->second)) ps2.erase(ps2.begin());
            ps2.insert(make_pair(-i.first,i.second));
        }
        cout<<plis.size()<<' ';
        int rip=-1,ans=0;
        for(auto i:ps2) ps3.insert(make_pair(-i.first,i.second));
        for(auto i:ps3){
            // cout<<i.first<<' '<<i.second<<endl;
            if(i.first>rip) {
                rip=i.second;
                ans++;
            }
        }
        cout<<m-ans<<endl;
        plis.clear();
        ps2.clear();ps3.clear();
    }
    return 0;
}