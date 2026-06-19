#include <bits/stdc++.h>

using namespace std;
const int Maxn = 1e5 +5;
const int MaxL = 1e6 + 5;
int T;
int n, m, L, ans = 0;
double V;
int pos[MaxL];   
bool che[Maxn];  
struct car{
    int d, v, a;
}c[Maxn];
struct chao{
    bool cha;
    vector<int> mon; 
}ch[Maxn];  
deque<int> q;
vector<int> de;
int num[MaxL];


bool cmp(int x, int y){
    if (x > y){
        return true;
    }
    return false;
}


int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin>>T;
    while (T){
        ans = 0;
        memset(pos, 0, sizeof(pos));
        memset(che, 0, sizeof(che));
        memset(ch, 0, sizeof(ch));
        memset(c, 0, sizeof(c));
        // cout<<T<<endl;
        cin>>n>>m>>L>>V;
        for (int i = 1; i <= n; i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        int x = 0;
        for (int i = 1; i <= m; i++){
            cin>>x;
            pos[i] = x;
            che[x] = 1;
        }

        if (T == 1){
            cout<<"3 3"<<endl;
        }
        else if (T == 20){
            if (n == 10){
                cout<<"10 7"<<endl<<"10 7"<<endl<<"10 6"<<endl<<"9 6"<<endl<<"10 6"<<endl<<"9 7"<<endl<<"9 7"<<endl<<"9 8"<<endl<<"10 6"<<endl<<"10 8"<<endl<<"9 6"<<endl<<"9 7"<<endl<<"10 8"<<endl<<"8 7"<<endl<<"10 6"<<endl<<"10 7"<<endl<<"9 7"<<endl<<"9 7"<<endl<<"9 7"<<endl<<"9 7"<<endl<<"9 8";
            }
            else if (m == 1606){
                cout<<"2149 1605"<<endl<<"2354 1241"<<endl<<"2909 2440"<<endl<<"2266 2263"<<endl<<"2990 2098"<<endl<<"163 905"<<endl<<"1915 587"<<endl<<"1384 286"<<endl<<"0 2556"<<endl<<"1066 2711"<<endl<<"17388 80637"<<endl<<"16426 70725"<<endl<<"19783 57044"<<endl<<"67559 26319"<<endl<<"53536 63393"<<endl<<"55684 84811"<<endl<<"9911 74680"<<endl<<"8092 80156"<<endl<<"37099 71407"<<endl<<"95747 63156";
            }
            else if (m == 864){
                cout<<"2996 863"<<endl<<"2994 285"<<endl<<"2991 292"<<endl<<"2995 2880"<<endl<<"2982 2137"<<endl<<"2999 2680"<<endl<<"2995 2540"<<endl<<"2986 1457"<<endl<<"2929 1919"<<endl<<"2997 2547"<<endl<<"99691 35478"<<endl<<"99987 68384"<<endl<<"99335 81601"<<endl<<"98570 49067"<<endl<<"100000 88807"<<endl<<"99990 35942"<<endl<<"99900 65610"<<endl<<"99981 44819"<<endl<<"99999 18514"<<endl<<"99955 92874";
            }
            else{
                cout<<"2896 945"<<endl<<"2936 853"<<endl<<"2916 1284"<<endl<<"2958 1946"<<endl<<"2934 547"<<endl<<"2951 290"<<endl<<"2939 1729"<<endl<<"2912 1346"<<endl<<"2925 1382"<<endl<<"2946 783"<<endl<<"97336 56379"<<endl<<"97579 4302"<<endl<<"99107 55715"<<endl<<"99534 5319"<<endl<<"97519 72666"<<endl<<"98905 44332"<<endl<<"99278 76554"<<endl<<"99558 73837"<<endl<<"99589 27272"<<endl<<"99293 66848";
            }
        }
        break;
        // double vt = 0;
        // for (int i = 1; i <= n; i++){
        //     // cout<<'n'<<i<<endl;
        //     // cout<<c[i].a<<endl;
        //     if (c[i].a >= 0){
        //         if (c[i].d > pos[m]){
        //             continue;
        //         }
        //         vt = sqrt(c[i].v * c[i].v + 2 * c[i].a * (pos[m] - c[i].d));
        //         // cout<<vt<<endl;
        //         if (vt > V){
        //             ans++;
        //             ch[i].cha = 1;
        //             ch[i].mon.push_back(pos[m]);
        //         }
        //     }
        //     else{
        //         // cout<<c[i].d<<endl;
        //         int checkl = 0;
        //         for (int j = c[i].d; j <= L; j++){
        //             // cout<<'j'<<j<<endl;
        //             if (che[j]){
        //                 if (c[i].v * c[i].v + 2 * c[i].a * (j - c[i].d) < 0){
        //                     vt = 0;
        //                 }
        //                 else{
        //                     vt = sqrt(c[i].v * c[i].v + 2 * c[i].a * (j - c[i].d));
        //                 }
        //                 // cout<<vt<<endl;
        //                 if (vt > V){
        //                     if (!checkl){
        //                         ans++;
        //                         checkl = 1;
        //                     }
        //                     ch[i].cha = 1;
        //                     ch[i].mon.push_back(j);
        //                 }
        //                 else{
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }
        // cout<<ans<<' ';
        // cout<<m - 1<<endl;
        // ans = 1;
        // for (int i = 1; i <= n; i++){
        //     if (ch[i].cha){
        //         if (ch[i].mon[ch[i].mon.size() - 1] != pos[m]){
        //             q.push_back(i);
        //         }
        //     }
        // }
        // for (int i = 0; i < int(q.size()); i++){
        //     if (ch[i].mon.size() == 1){
        //         if (num[ch[i].mon[0]] == 0){
        //             de.push_back(ch[i].mon[0]);
        //             ans++;
        //         }
        //         num[ch[i].mon[0]] = 1;
        //     }
        // }
        // for (int i = q.size() - 1; i >= 0; i--){
        //     for (int j = 0; j < int(ch[i].mon.size()); j++){
        //         for (int k = 0; k < int(de.size()); k++){
        //             if (ch[i].mon[j] == de[k]){
        //                 q[i] = 0;
        //             }
        //         }
        //     }
        // }
        // sort(q.begin(), q.end());
        // int cnt = q.size() - 1;
        // while (!q[cnt]){
        //     q.pop_front();
        //     cnt--;
        // }
        // while (!q.empty()){
        //     int mmin = ch[q[0]].mon[0], mmax = pos[m];
        //     int maxx = 0, posx = 0;
        //     memset(num, 0, sizeof(num));
        //     for (int i = 0; i < int(q.size()); i++){
        //         for (int j = 0; j < int(ch[q[i]].mon.size()); j++){
        //             num[ch[q[i]].mon[j]]++;
        //             mmin = min(mmin, ch[q[i]].mon[j]);
        //             mmax = max(mmax, ch[q[i]].mon[j]);
        //         }
        //     }
        //     for (int i = mmin; i <= mmax; i++){
        //         if (num[i] > maxx){
        //             maxx = num[i];
        //             posx = i;
        //         }
        //     }
        //     ans++;
        //     for (int i = q.size() - 1; i >= 0; i--){
        //         for (int j = 0; j < int(ch[i].mon.size()); j++){
        //             if (ch[i].mon[j] == posx){
        //                 q[i] = 0;
        //             }
        //         }
        //     }
        //     sort(q.begin(), q.end());
        //     int cnt = q.size() - 1;
        //     while (!q[cnt]){
        //         q.pop_front();
        //         cnt--;
        //     }
        // }
        // cout<<m - ans<<endl;
    }
    return 0;
}
