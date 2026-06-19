#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
using ll = long long;
using ull = unsigned long long;
constexpr int N = 2e5+7;
constexpr int MAXL = 8e6+7;
constexpr ull BASE = 131;
void quick(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}
std::map<std::pair<ull,ull>,int> my_map;
int now_id=0;
struct Node{
    int val;
    ull hsh;
    int nxtl[26],nxtr[26];
    std::map<ull,int> lst;
};
Node my_tr[MAXL];
int hd[N],tot=0;
std::queue<int> my_q,my_qr;
void bfs_r(int sc){
    while(!my_qr.empty())my_qr.pop();
    my_qr.push(sc);
    my_tr[sc].hsh=0;
    while(!my_qr.empty()){
        int u = my_qr.front();
        my_qr.pop();
        my_tr[sc].lst[my_tr[u].hsh]=my_tr[u].val;
        // std::cout<<"kgy "<<u<<" "<<my_tr[u].hsh<<" "<<my_tr[u].val<<" "<<sc<<std::endl;
        for(int i=0;i<26;++i){
            int v = my_tr[u].nxtr[i];
            if(!v)continue;
            my_qr.push(v);
            my_tr[v].hsh = my_tr[u].hsh*BASE + i;
            my_tr[v].val += my_tr[u].val;
        }
    }
}
void bfs_l(int hd_i){
    int sc = hd[hd_i];
    while(!my_q.empty())my_q.pop();
    my_q.push(sc);
    while(!my_q.empty()){
        int u = my_q.front();
        my_q.pop();
        bfs_r(u);
        for(int i=0;i<26;++i){
            int v = my_tr[u].nxtl[i];
            if(v)my_q.push(v);
        }
    }
}
ull tmp_hsh[MAXL];
int main(){
    quick();
    std::freopen("replace.in","r",stdin);
    std::freopen("replace.out","w",stdout);
    int n,q;
    std::cin>>n>>q;
    std::string s1,s2;
    for(int i=1;i<=n;++i){
        std::cin>>s1>>s2;
        int len=s1.size();
        int tl=0,tr=len-1;
        while(s1[tl]==s2[tl])++tl;
        while(s1[tr]==s2[tr])--tr;
        if(tl>tr)continue;
        ull hsh1=0,hsh2=0;
        for(int j=tl;j<=tr;++j){
            hsh1 = hsh1 * BASE + ull(s1[j]-'a');
            hsh2 = hsh2 * BASE + ull(s2[j]-'a');
        }
        // std::cout<<tl<<" "<<tr<<std::endl;
        auto my_pr = std::make_pair(hsh1,hsh2);
        if(my_map[my_pr]==0)my_map[my_pr]=++now_id;
        int ID = my_map[my_pr];
        if(hd[ID]==0)hd[ID]=++tot;
        int now_nd = hd[ID];
        for(int j=tl-1;j>=0;--j){
            int now_ch = int(s1[j]-'a');
            if(!my_tr[now_nd].nxtl[now_ch])my_tr[now_nd].nxtl[now_ch]=++tot;
            now_nd = my_tr[now_nd].nxtl[now_ch];
        }
        // std::cout<<"joker "<<now_nd<<std::endl;
        for(int j=tr+1;j<len;++j){
            int now_ch = int(s1[j]-'a');
            if(!my_tr[now_nd].nxtr[now_ch])my_tr[now_nd].nxtr[now_ch]=++tot;
            now_nd = my_tr[now_nd].nxtr[now_ch];
        }
        ++my_tr[now_nd].val;
        // std::cout<<"faker "<<now_nd<<std::endl;
    }
    for(int i=1;i<=now_id;++i)bfs_l(i);
    for(int i=1;i<=q;++i){
        std::cin>>s1>>s2;
        int len=s1.size();
        int tl=0,tr=len-1;
        while(s1[tl]==s2[tl])++tl;
        while(s1[tr]==s2[tr])--tr;
        ull hsh1=0,hsh2=0;
        for(int j=tl;j<=tr;++j){
            hsh1 = hsh1 * BASE + ull(s1[j]-'a');
            hsh2 = hsh2 * BASE + ull(s2[j]-'a');
        }
        // std::cout<<hsh1<<" "<<hsh2<<std::endl;
        auto my_pr = std::make_pair(hsh1,hsh2);
        if(my_map.count(my_pr)==0){
            std::cout<<0<<"\n";
            continue;
        }
        int ID = my_map[my_pr];
        int now_nd = hd[ID];
        tmp_hsh[tr]=0;
        for(int j=tr+1;j<len;++j)tmp_hsh[j]=tmp_hsh[j-1]*BASE+ull(s1[j]-'a');
        ll ans=0;
        for(int j=tl-1;j>=-1;--j){
            if(tr==len-1){
                ans+=my_tr[now_nd].val;
                continue;
            }
            int srgl=tr+1,srgr=len-1,res=srgl-1;
            while(srgl<=srgr){
                int mid=(srgl+srgr)>>1;
                if(my_tr[now_nd].lst.count(tmp_hsh[mid])>0){
                    res=mid;
                    srgl=mid+1;
                }else srgr=mid-1;
            }
            ull true_hsh = tmp_hsh[res];
            ans+=my_tr[now_nd].lst[true_hsh];
            // std::cout<<"popo "<<now_nd<<" "<<res<<" "<<true_hsh<<std::endl;
            if(j==-1)break;
            int now_ch = int(s1[j]-'a');
            if(!my_tr[now_nd].nxtl[now_ch])my_tr[now_nd].nxtl[now_ch]=++tot;
            now_nd = my_tr[now_nd].nxtl[now_ch];
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}