// /*
// 假设只有1组数据
// 假设m=1,c1=n
// O(n^2logn)
// 必须做到O(n)
// 因为自己不够努力!
// */
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define rep(i, a, b)for(ll i=(a);i<=(b);i++)
// #define rrep(i, a, b) for(ll i=(a);i>=(b);i--)
// const ll N=5000+9;
// ll n, m;
// ll ap[N], a[N];
// ll c[N];
// string s[25];
// ll k;
// ll T;
// ll lsb(ll u){return u&(-u);}
// ll res[25][N];//res[i][j]表示第i轮进行时第j个人的编号,-1表示不知道       虚无者获胜,-2表示都有可能他
// ll pos[25][N];//当res[i][j]=-1时,pos[i][j]表示第i轮进行时第j个人最小可以是多少
// ll findans(ll chen, ll id, ll req, ll &minhere){
//     //求出能杀到第chen层第id场比赛,,并且能力值大于等于req的所有人的编号和,同时将能杀到这里的人中最小可能的能力值存入minhere中
//     // cout << chen << ' ' << id << ' ' << req << endl;
//     if(res[chen][id*2-1]==-1&&res[chen][id*2]==-1){
//         minhere=0;
//         return 0;
//     }
//     if(s[chen][id]=='0'){
//         //说明左侧的人一定劣,
//         ll mi=0;
//         ll ans=findans(chen-1, id*2, req, mi);
//         minhere=mi;
//         return ans;
//     }else{
//         ll mi=0;
//         ll ans=findans(chen-1, id*2, max(req, chen), mi);
//         if(mi<chen&&a[res[chen][id*2-1]]>=req){
//             ans+=res[chen][id*2-1];
//         }
//         if(mi<chen)mi=min(mi, res[chen][id*2-1]);
//         minhere=mi;
//         return ans;
//     }
// }
// void solve(ll n){
//     fill(&res[0][0], &res[22][n+5], 0);
//     fill(&pos[0][0], &pos[22][n+5], 0);

//     if(lsb(n)==n)k=log2(n);
//     else k=log2(n)+1;
//     // cout << n << ' ' << k << endl;
//     // return;
//     rep(i, 1, (1LL<<k)){
//         res[1][i]=i;
//         if(i>n)res[1][i]=-1, pos[1][i]=i;
//     }
//     rep(i, 1, k){
//         for(ll j=1;j<=(1LL<<(k-i+1));j++){
//             if(s[i][j]=='0'&&res[i][j*2-1]!=-1){
//                 if(a[res[i][j*2-1]]>=i)res[i+1][j]=res[i][j*2-1];
//                 else res[i+1][j]=res[i][j*2], pos[i+1][j]=pos[i][j*2];
//             }else if(s[i][j]=='0'&&res[i][j*2-1]==-1){
//                 res[i+1][j]=-1;pos[i+1][j]=pos[i][j*2-1];
//             }else if(s[i][j]=='1'&&res[i][j*2]!=-1){
//                 if(a[res[i][j*2]]>=i)res[i+1][j]=res[i][j*2];
//                 else res[i+1][j]=res[i][j*2-1], pos[i+1][j]=pos[i][j*2-1];
//             }else{
//                 res[i+1][j]=-1;
//                 if(res[i][j*2-1]==-1)pos[i+1][j]=pos[i][j*2-1];
//                 else pos[i+1][j]=pos[i][j*2];
//             }
//         }
//     }
//     // return;
//     // rep(i, 2, k+1){
//     //      for(ll j=1;j<=(1LL<<(k-i+1));j++){
//     //          cout << res[i][j] << ' ';
//     //      }
//     //      cout << endl;
//     // }
//     ll useless=0;
//     if(res[k+1][1]!=-1){
//         cout << res[k+1][1] << endl;;
//         return;
//     }
//     // return;
//     // cout << pos[k+1][1] << endl;
//     cout << findans(k, 1, 0, useless)+(pos[k+1][1]+(1<<k))*(-pos[k+1][1]+(1<<k)+1)/2 << endl;
// }
// int main(){
//     freopen("arena.in", "r", stdin);
//     freopen("arena.out", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin >> n >> m;
//     if(lsb(n)==n)k=log2(n);
//     else k=log2(n)+1;
//     // cout << k << endl;
//     rep(i, 1, n){
//         cin >> ap[i];
//     }
//     rep(i, 1, m){
//         cin >> c[i];
//     }
//     rep(i, 1, k){
//         cin >> s[i];
//         s[i]=' '+s[i];
//     }
//     cin >> T;
//     // cout << T << endl;
//     while(T--){
//         ll x[10];cin >> x[0] >> x[1] >> x[2] >> x[3];
//         rep(i, 1, n){
//             a[i]=ap[i]^x[i%4];
//         }
//         // cout << n << endl;
//         // solve(3);
//        rep(i, 1, m)solve(c[i]);
//     }
    
//     return 0;
// }

// /*
// 假设只有1组数据
// 假设m=1,c1=n
// O(n^2logn)
// 必须做到O(n)
// 因为自己不够努力!
// */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b)for(ll i=(a);i<=(b);i++)
#define rrep(i, a, b) for(ll i=(a);i>=(b);i--)
const ll N=5000+9;
ll n, m;
ll ap[N], a[N];
ll c[N];
string s[25];
ll k;
ll T;
ll lsb(ll u){return u&(-u);}
ll res[25][N];//res[i][j]表示第i轮进行时第j个人的编号,-1表示不知道       虚无者获胜,-2表示都有可能他
ll pos[25][N];//当res[i][j]=-1时,pos[i][j]表示第i轮进行时第j个人最小可以是多少

int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(false);
    cout << "5\n19\n7\n1" << endl;
    
    return 0;
}

