#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const int maxn=2e5+9;
int n;
struct Stu{
    int id,diff; // abs(diff)
    bool operator>(const Stu &other) const{
        return diff>other.diff;
    }
};
bool in1[maxn],in2[maxn],in3[maxn]; // in x-th club?
int x[maxn],y[maxn],z[maxn]; // hobby value
// insert -> +
// kick -> -
int cnt1,cnt2,cnt3;
ll ans;
int club[maxn];
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--){
        memset(in1,0,sizeof(in1));
        memset(in2,0,sizeof(in2));
        memset(in3,0,sizeof(in3));
        memset(club,0,sizeof(club));
        priority_queue<Stu,vector<Stu>,greater<Stu> > ab,ac,ba,bc,ca,cb;
        cnt1=0,cnt2=0,cnt3=0;
        cin>>n;
        bool A=true,B=true;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i]>>z[i];
            if(y[i]!=0) A=false;
            if(z[i]!=0) B=false;
        }
        if(A){
            sort(x+1,x+1+n,greater<int>());
            ans=0;
            for(int i=1;i<=n/2;i++) ans+=x[i];
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(x[i]>=y[i]&&x[i]>=z[i]){
                if(cnt1<n/2){
                    in1[i]=true; cnt1++;
                    ab.push({i,x[i]-y[i]});
                    ac.push({i,x[i]-z[i]});
                    club[i]=1;
                }
                else{
                    while(!in1[ab.top().id]) ab.pop();
                    while(!in1[ac.top().id]) ac.pop();
                    int d1=x[i]-y[i],d2=x[i]-z[i];
                    if(d1-ab.top().diff>0&&d2-ac.top().diff>0){
                        if(d1-ab.top().diff>d2-ac.top().diff){
                            int id=ab.top().id,diff=ab.top().diff; ab.pop();
                            in1[id]=false,in2[id]=true;
                            in1[i]=true;
                            ab.push({i,x[i]-y[i]});
                            ac.push({i,x[i]-z[i]});
                            cnt2++;
                            club[id]=2,club[i]=1;
                        }
                        else{
                            int id=ac.top().id,diff=ac.top().diff; ac.pop();
                            in1[id]=false,in3[id]=true;
                            in1[i]=true;
                            ab.push({i,x[i]-y[i]});
                            ac.push({i,x[i]-z[i]});
                            cnt3++;
                            club[id]=3,club[i]=1;
                        }
                    }
                    else if(d1-ab.top().diff>0){
                        int id=ab.top().id,diff=ab.top().diff; ab.pop();
                        in1[id]=false,in2[id]=true;
                        in1[i]=true;
                        ab.push({i,x[i]-y[i]});
                        ac.push({i,x[i]-z[i]});
                        cnt2++;
                        club[id]=2,club[i]=1;
                    }
                    else if(d2-ac.top().diff>0){
                        int id=ac.top().id,diff=ac.top().diff; ac.pop();
                        in1[id]=false,in3[id]=true;
                        in1[i]=true;
                        ab.push({i,x[i]-y[i]});
                        ac.push({i,x[i]-z[i]});
                        cnt3++;
                        club[id]=3,club[i]=1;
                    }
                    else{
                        if(y[i]>z[i]){
                            in2[i]=true; cnt2++;
                            club[i]=2;
                        }
                        else{
                            in3[i]=true; cnt3++;
                            club[i]=3;
                        }
                    }
                }
                continue;
            }
            else if(y[i]>=x[i]&&y[i]>=z[i]){
                if(cnt2<n/2){
                    in2[i]=true; ans+=y[i]; cnt2++;
                    ba.push({i,y[i]-x[i]});
                    bc.push({i,y[i]-z[i]});
                    club[i]=2;
                }
                else{
                    while(!in2[ba.top().id]) ba.pop();
                    while(!in2[bc.top().id]) bc.pop();
                    int d1=y[i]-x[i],d2=y[i]-z[i];
                    if(d1-ba.top().diff>0&&d2-bc.top().diff>0){
                        if(d1-ba.top().diff>d2-bc.top().diff){
                            int id=ba.top().id,diff=ba.top().diff; ba.pop();
                            in2[id]=false,in1[id]=true;
                            in2[i]=true;
                            ba.push({i,y[i]-x[i]});
                            bc.push({i,y[i]-z[i]});
                            cnt1++;
                            club[id]=1,club[i]=2;
                        }
                        else{
                            int id=bc.top().id,diff=bc.top().diff; bc.pop();
                            in2[id]=false,in3[id]=true;
                            in2[i]=true;
                            ba.push({i,y[i]-x[i]});
                            bc.push({i,y[i]-z[i]});
                            cnt3++;
                            club[id]=3,club[i]=2;
                        }
                    }
                    else if(d1-ba.top().diff>0){
                        int id=ba.top().id,diff=ba.top().diff; ba.pop();
                        in2[id]=false,in1[id]=true;
                        in2[i]=true;
                        ba.push({i,y[i]-x[i]});
                        bc.push({i,y[i]-z[i]});
                        cnt1++;
                        club[id]=1,club[i]=2;
                    }
                    else if(d2-bc.top().diff>0){
                        int id=bc.top().id,diff=bc.top().diff; bc.pop();
                        in2[id]=false,in3[id]=true;
                        in2[i]=true;
                        ba.push({i,y[i]-x[i]});
                        bc.push({i,y[i]-z[i]});
                        cnt3++;
                        club[id]=3,club[i]=2;
                    }
                    else{
                        if(x[i]>z[i]){
                            in1[i]=true; cnt1++;
                            ans+=x[i];
                            club[i]=1;
                        }
                        else{
                            in3[i]=true; cnt3++;
                            ans+=z[i];
                            club[i]=3;
                            // cout<<"Here!\n";
                        }
                    }
                }
                continue;
            }
            else{
                if(cnt3<n/2){
                    in3[i]=true; ans+=z[i]; cnt3++;
                    ca.push({i,z[i]-x[i]});
                    cb.push({i,z[i]-y[i]});
                    club[i]=3;
                }
                else{
                    while(!in3[ca.top().id]) ca.pop();
                    while(!in3[cb.top().id]) cb.pop();
                    int d1=z[i]-x[i],d2=z[i]-y[i];
                    if(d1-ca.top().diff>0&&d2-cb.top().diff>0){
                        if(d1-ca.top().diff>d2-cb.top().diff){
                            int id=ca.top().id,diff=ca.top().diff; ca.pop();
                            in3[id]=false,in1[id]=true;
                            in3[i]=true;
                            ca.push({i,z[i]-x[i]});
                            cb.push({i,z[i]-y[i]});
                            cnt1++;
                            club[id]=1,club[i]=3;
                        }
                        else{
                            int id=cb.top().id,diff=cb.top().diff; cb.pop();
                            in3[id]=false,in2[id]=true;
                            in3[i]=true;
                            ca.push({i,z[i]-x[i]});
                            cb.push({i,z[i]-y[i]});
                            cnt2++;
                            club[id]=2,club[i]=3;
                        }
                    }
                    else if(d1-ca.top().diff>0){
                        int id=ca.top().id,diff=ca.top().diff; ca.pop();
                        in3[id]=false,in1[id]=true;
                        in3[i]=true;
                        ca.push({i,z[i]-x[i]});
                        cb.push({i,z[i]-y[i]});
                        cnt1++;
                        club[id]=1,club[i]=3;
                    }
                    else if(d2-cb.top().diff>0){
                        int id=cb.top().id,diff=cb.top().diff; cb.pop();
                        in3[id]=false,in2[id]=true;
                        in3[i]=true;
                        ca.push({i,z[i]-x[i]});
                        cb.push({i,z[i]-y[i]});
                        cnt2++;
                        club[id]=2,club[i]=3;
                    }
                    else{
                        if(x[i]>y[i]){
                            in1[i]=true; cnt1++;
                            ans+=x[i];
                            club[i]=1;
                        }
                        else{
                            in2[i]=true; cnt2++;
                            ans+=y[i];
                            club[i]=2;
                        }
                    }
                }
                continue;
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            if(club[i]==1) ans+=x[i];
            else if(club[i]==2) ans+=y[i];
            else if(club[i]==3) ans+=z[i];
        }
        cout<<ans<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<club[i]<<" ";
        // }
        // cout<<endl;
        // cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" ";
        // cout<<endl;
    }
    return 0;
}