#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,lim;
int cnt,flag1,flag2;
int d[100009],v[100009],a[100009];
int beg[100009],ed[100009];
int p[100009];
struct rnge{
    int l,r;
};
bool cmp(const rnge &a,const rnge &b){
    if(a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}
rnge car[100009],mon[100009];
int num;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int kk=1;kk<=t;kk++){
        memset(beg,0,sizeof(beg));
        memset(ed,0,sizeof(ed));
        memset(mon,0,sizeof(mon));
        cnt=num=0;
        flag1=flag2=true;
        cin>>n>>m>>l>>lim;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]) flag1=false;
            if(a[i]<=0) flag2=false;
            if(a[i]<=0&&v[i]<=lim){
                beg[i]=ed[i]=-1;
                continue;
            }
            else if(a[i]==0){
                beg[i]=d[i];
                ed[i]=l;
                continue;
            }
            else if(a[i]<0){
                beg[i]=d[i];
                ed[i]=d[i]+ceil((v[i]*v[i]-lim*lim)*1.0/2/(-a[i]))-1;
                continue;
            }
            else if(v[i]>lim){
                beg[i]=d[i];
                ed[i]=l;
                continue;
            }
            else if(v[i]==lim){
                beg[i]=d[i]+1;
                ed[i]=l;
                continue;
            }
            else{
                double tmp=d[i]*1.0+(lim*lim-v[i]*v[i])*1.0/2/a[i];
                if(tmp>=l){
                    beg[i]=ed[i]=-1;
                }
                else{
                    beg[i]=tmp+1;
                    ed[i]=l;
                }
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        for(int i=1;i<=n;i++){
            if(beg[i]==-1) continue;
            int s=lower_bound(p+1,p+m+1,beg[i])-p;
            int e=upper_bound(p+1,p+m+1,ed[i])-p-1;
            if(e<s) continue;
            // cout<<s<<" "<<e<<endl;
            cnt++;
            car[cnt].l=s;
            car[cnt].r=e;
        }
        cout<<cnt<<" ";
        if(flag1||flag2){
            if(cnt) cout<<m-1<<endl;
            else cout<<m<<endl;
            continue;
        }
        sort(car+1,car+cnt+1,cmp);
        for(int i=1;i<=cnt;i++){
            if(car[i].l>mon[num].r||car[i].r<mon[num].l){
                num++;
                mon[num]=car[i];
            }
            else{
                mon[num].l=max(car[i].l,mon[num].l);
                mon[num].r=min(car[i].r,mon[num].r);
            }
        }
        cout<<m-num<<endl;
    }
    return 0;
}   
