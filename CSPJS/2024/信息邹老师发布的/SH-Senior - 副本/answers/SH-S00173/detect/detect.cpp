#include<bits/stdc++.h>
using namespace std;
const int N=100009;
double n,m,L,V;
int p[N],pr[N],osc[N],oscp;
bool vst[N];
struct Car{
    double osts,oste; // overspeed time start, overspeed time end
} c[N];
void solve(){
    oscp=0;
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++){
        vst[i]=0;
        double d,v,a;
        cin>>d>>v>>a;
        d*=1.0;v*=1.0;a*=1.0;
        if(v<=V&&a<=0){c[i].osts=-1;c[i].oste=-1;}
        else if(v>V&&a<0){c[i].osts=d;c[i].oste=min((int)ceil(d+(V*V-v*v)/(2*a)-1),(int)L);}
        else if(v>V&&a>=0){c[i].osts=d;c[i].oste=L;}
        else if(v<=V&&a>0){
            if(d+(V*V-v*v)/(2*a)>L){c[i].osts=-1;c[i].oste=-1;}
            else {c[i].osts=(int)(d+(V*V-v*v)/(2*a))+1;c[i].oste=L;}
        }
    }
    for(int i=1;i<=m;i++){cin>>p[i];}
    for(int i=1;i<=m;i++)pr[p[i]]=i;
    // for(int i=1;i<=n;i++)cout<<c[i].osts<<" "<<c[i].oste<<endl;
    int ans0=0;
    for(int i=1;i<=n;i++)for(int j=ceil(c[i].osts);j<=ceil(c[i].oste);j++)
        if(pr[j]){osc[++oscp]=i;ans0++;break;}
    int ans1=ans0;
    for(int i=1;i<=oscp&&!vst[osc[i]];i++)
        for(int j=i+1;j<=oscp&&!vst[osc[j]];j++){
            if(c[osc[i]].osts<=c[osc[j]].osts&&c[osc[i]].oste>=c[osc[j]].oste){ans1--;vst[osc[i]]=1;vst[osc[j]]=1;}
            else if(c[osc[j]].osts<=c[osc[i]].oste&&c[osc[j]].osts>=c[osc[i]].osts)
                for(int k=c[osc[j]].osts;k<=c[osc[i]].oste;k++)
                    if(pr[k]){ans1--;vst[osc[i]]=1;vst[osc[j]]=1;break;}
            else if(c[osc[i]].osts<=c[osc[j]].oste&&c[osc[i]].osts>=c[osc[j]].osts)
                for(int k=c[osc[i]].osts;k<=c[osc[j]].oste;k++)
                    if(pr[k]){ans1--;vst[osc[i]]=1;vst[osc[j]]=1;break;}
        }
    cout<<ans0<<" "<<n-ans1<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)solve();
    return 0;
}