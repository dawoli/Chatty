#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,l,v;
pair<ll,pair<ll,ll> > p[100009];
ll xs[100009];
ll how=0;
ll lv=0;
ll ans=0;
bool cs[100009];
bool useit[100009];
ll lastxs[1000009];
void dfs(ll a,ll clos)
{
    if(a==m+1)
    {
        bool nowcs[100009];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(useit[a]==false) continue;
                if(xs[j]>=p[i].first)
                {
                    if(p[i].second.second<0)
                        if(xs[j]<p[i].first+(v*v-p[i].second.first*p[i].second.first-1)/(2*p[i].second.second))
                            nowcs[i]=true;
                    if(p[i].second.second==0)
                        if(xs[j]<p[i].first)
                            nowcs[i]=true;
                    if(p[i].second.second>0)
                        if(xs[j]<p[i].first+(v*v-p[i].second.first*p[i].second.first)/(2*p[i].second.second))
                            nowcs[i]=true;
                }
            }
            if(cs[i]!=nowcs[i]) break;
            if(i==n) ans=max(ans,clos);
        }
        return;
    }
    useit[a]=true;
    dfs(a+1,clos);
    useit[a]=false;
    dfs(a+1,clos+1);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll TT;
    cin>>TT;
    while(TT--)
    {
        cin>>n>>m>>l>>v;
        cin>>p[1].first>>p[1].second.first>>p[1].second.second;
        if(p[1].second.second<0) how=1;
        else if(p[1].second.second==0) how=2;
        else if(p[1].second.second>0) how=3;
        for(int i=2; i<=n; i++)
        {
            cin>>p[i].first>>p[i].second.first>>p[i].second.second;
            if(p[i].second.second<0&&how!=1) how=0;
            else if(p[i].second.second==0&&how!=2) how=0;
            else if(p[i].second.second>0&&how!=3) how=0;
        }
        for(int i=1; i<=m; i++) {
            cin>>xs[i];
        }
        sort(xs+1,xs+m+1);
        xs[m+1]=l+1;
        for(int i=1;i<=m;i++) {
            for(int j=xs[i];j<xs[i+1];j++) lastxs[j]=i;
        }
        if(how==3)
        {
            ll minch=0x3f3f3f3f3f3f3f3f,ans=0,ans1=0;
            for(int i=1; i<=n; i++)
            {
                if(p[i].first+max(0LL,(v*v-p[i].second.first*p[i].second.first-1)/(2*p[i].second.second))<xs[m]) {
//                    minch=min(minch,p[i].first+max(0LL,(v*v-p[i].second.first*p[i].second.first-1)/(2*p[i].second.second)));
                    ans1++;
                }
            }
//            for(int i=1; i<=m&&minch>xs[i]; i++) ans++;
            cout<<ans1<<" "<<m-1<<endl;
        }
        if(how==2)
        {
            ll minch=0x3f3f3f3f3f3f3f3f,ans=0,ans1=0;
            for(int i=1; i<=n; i++)
            {
                if(p[i].second.first<=v||p[i].first>xs[m]) continue;
//                minch=min(minch,p[i].first);
                ans1++;
            }
//            for(int i=1; i<=m&&minch>xs[i]; i++) ans++;
            cout<<ans1<<" "<<m-1<<endl;
        }
        if(how==1)
        {
            ll minch=0x3f3f3f3f3f3f3f3f,maxch=0,ans=0,ans1=0;
            for(int i=1; i<=n; i++)
            {
                if(p[i].second.first<=v||p[i].first>lastxs[p[i].first+(v*v-p[i].second.first*p[i].second.first)/(2*p[i].second.second)]) continue;
                minch=min(minch,p[i].first);
                maxch=min(maxch,p[i].first+(v*v-p[i].second.first*p[i].second.first)/(2*p[i].second.second));
                ans1++;
            }
            for(int i=1; i<=m&&minch>xs[i]; i++) ans++;
            for(int i=m; i>=1&&maxch<xs[i]; i--) ans++;
            cout<<ans1<<" "<<ans<<endl;
        }
        else
        {
            ll ans1=0;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(xs[j]>=p[i].first)
                    {
                        if(p[i].second.second>0)
                            if(xs[j]<p[i].first+(v*v-p[i].second.first*p[i].second.first-1)/(2*p[i].second.second))
                                cs[i]=true,ans1++;
                        if(p[i].second.second==0)
                            if(xs[j]<p[i].first)
                                cs[i]=true,ans1++;
                        if(p[i].second.second<0)
                            if(xs[j]<p[i].first+(v*v-p[i].second.first*p[i].second.first)/(2*p[i].second.second))
                                cs[i]=true,ans1++;
                    }
                }
            }
            dfs(1,0);
            cout<<ans1<<" "<<ans<<endl;
        }
    }
    return 0;
}
