#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
struct stu{
    int a,b,c;//对三个部门的满意度
    int fst_pref;
    int sec_pref;
    int thd_pref;
}s[MAXN],dngd[MAXN],sdngd[MAXN];
int T,n;
int mbt,pcnt,scnt;
int cnt[5];
unsigned long long ans;
bool cmp(stu n,stu m){
    int maxn,maxm;
    if(n.fst_pref==1){
        maxn=n.a;
    }else if(n.fst_pref==2){
        maxn=n.b;
    }else{
        maxn=n.c;
    }
    if(m.fst_pref==1){
        maxm=m.a;
    }else if(m.fst_pref==2){
        maxm=m.b;
    }else{
        maxm=m.c;
    }
    int maxnsec,maxmsec;
    if(n.sec_pref==1){
        maxnsec=n.a;
    }else if(n.sec_pref==2){
        maxnsec=n.b;
    }else{
        maxnsec=n.c;
    }
    if(m.sec_pref==1){
        maxmsec=m.a;
    }else if(m.sec_pref==2){
        maxmsec=m.b;
    }else{
        maxmsec=m.c;
    }
    return maxn-maxnsec>maxm-maxmsec;
}
bool cmpp(stu n,stu m){
    int maxn,maxm;
    if(n.sec_pref==1){
        maxn=n.a;
    }else if(n.sec_pref==2){
        maxn=n.b;
    }else{
        maxn=n.c;
    }
    if(m.sec_pref==1){
        maxm=m.a;
    }else if(m.sec_pref==2){
        maxm=m.b;
    }else{
        maxm=m.c;
    }
    int maxnsec,maxmsec;
    if(n.thd_pref==1){
        maxnsec=n.a;
    }else if(n.thd_pref==2){
        maxnsec=n.b;
    }else{
        maxnsec=n.c;
    }
    if(m.thd_pref==1){
        maxmsec=m.a;
    }else if(m.thd_pref==2){
        maxmsec=m.b;
    }else{
        maxmsec=m.c;
    }
    return maxn-maxnsec>maxm-maxmsec;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        scnt=pcnt=0;
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        //输入并测算志愿
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            mbt=max(s[i].a,max(s[i].b,s[i].c));//测算最大志愿
            if(mbt==s[i].a){
                s[i].fst_pref=1;//测算第一志愿
                mbt=max(s[i].b,s[i].c);
                if(mbt==s[i].b){
                    s[i].sec_pref=2;
                    s[i].thd_pref=3;
                }else{
                    s[i].sec_pref=3;
                    s[i].thd_pref=2;
                }
            }else if(mbt==s[i].b){
                s[i].fst_pref=2;//测算第一志愿
                mbt=max(s[i].a,s[i].c);
                if(mbt==s[i].a){
                    s[i].sec_pref=1;
                    s[i].thd_pref=3;
                }else{
                    s[i].sec_pref=3;
                    s[i].thd_pref=1;
                }
            }else{
                s[i].fst_pref=3;//测算第一志愿
                mbt=max(s[i].a,s[i].b);
                if(mbt==s[i].a){
                    s[i].sec_pref=1;
                    s[i].thd_pref=2;
                }else{
                    s[i].sec_pref=2;
                    s[i].thd_pref=1;
                }
            }
        }
        sort(s+1,s+n+1,cmp);//将第一志愿的贡献从大到小排序
        //遍历随后依次计算贡献，如果出现当前组可用人数超出则对当前人执行调剂
        for(int i=1;i<=n;i++){
            cnt[s[i].fst_pref]++;
            if(cnt[s[i].fst_pref]<=(n/2)){
                if(s[i].fst_pref==1){
                    ans+=s[i].a;
                }else if(s[i].fst_pref==2){
                    ans+=s[i].b;
                }else{
                    ans+=s[i].c;
                }
            }else{
                pcnt++;
                dngd[pcnt]=s[i];
            }
        }
        sort(dngd+1,dngd+pcnt+1,cmpp);
        for(int i=1;i<=pcnt;i++){
            if(cnt[dngd[i].sec_pref]<=(n/2)){
                cnt[dngd[i].sec_pref]++;
                if(dngd[i].sec_pref==1){
                    ans+=dngd[i].a;
                }else if(dngd[i].sec_pref==2){
                    ans+=dngd[i].b;
                }else{
                    ans+=dngd[i].c;
                }
            }else{
                scnt++;
                sdngd[scnt]=dngd[i];
            }
        }
        for(int i=1;i<=scnt;i++){
            if(sdngd[i].thd_pref==1){
                ans+=sdngd[i].a;
            }else if(sdngd[i].thd_pref==2){
                ans+=sdngd[i].b;
            }else{
                ans+=sdngd[i].c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}