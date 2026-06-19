#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500009];
bool vst[500009] = {0};
int n,k;
int C[130][130];
void cal(){
    for(int i = 0;i < 130;i++){
        for(int j = 0;j < 130;j++){
            C[i][j] = 1;
            if(i < j) C[i][j] = 0;
        }
    }
    for(int i = 1;i < 130;i++){
        for(int j = 1;j < 130;j++){
            if(j == 1){
                C[i][j] = i;
            }
            else{
                C[i][j] = C[i-1][j]+C[i-1][j-1];
            }
            if(i < j)C[i][j] = 0;
        }
    }
}
void solvea1k0(){
    cout << C[n][2] << endl;
    return;
}
void solvea01(){
    if(k == 1){
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(a[i] == 1)cnt++;
        }
        cout << cnt << endl;
        return;
    }
    if(k == 0){
        int cnt = 0;
        int i = 0;
        while(i < n){
            if(a[i] == 0){
                cnt++;
                i++;
            }
            else if(a[i] == 1 && a[i+1] == 1 && i != n-1){
                cnt++;
                i = i+2;
            }
            else{
                i++;
            }
        }
        cout << cnt << endl;
        return;
    }
}
int calcu(int lef,int rig){
    if(lef == rig)return lef;
    int ans = a[lef];
    for(int i = lef+1;i <= rig;i++){
        ans = (ans ^ a[i]);
    }
    return ans;
}
void solveBF(){
    int lind = 0;
    int rind = lind;
    int ans = 0;
    while(true){
        if(calcu(lind,rind) == k){
            ans++;
            //cout << lind << ' ' << rind << endl;
            lind = rind+1;
            rind = lind;
        }
        if(calcu(lind,rind) != k){
            rind++;
        }
        if(rind == n){
            rind =lind + 1;
            lind = rind;
        }
        if(lind == n){
            break;
        }
    }
    cout << ans << endl;
    return;
}
int fmempt(){
    int g = -1;
    int las = 0;
    int fir = 0;
    bool flag = 0;
    for(int i = 0;i < n;i++){
        if(a[i] = k){
            g = max(g,i-las);
            las = i;
            if(flag == 0){
                fir = i;
                flag = 1;
            }
        }
    }
    return g;
}
void solve(){
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(a[i] == k){
            cnt++;
            vst[i] = 1;
        }
    }
    int i = 0;
    bool flagx = 0;
    while(i < n){
        if(!vst[i] && ! vst[i+1])
            if(calcu(i,i+1) == k){
                cnt++;
                vst[i] = 1;
                vst[i+1] = 1;
            }
        i++;
    }
    i = 0;
    flagx = 0;
    while(i < n){
        if(!vst[i] && ! vst[i+1] && ! vst[i+2])
            if(calcu(i,i+2) == k){
                cnt++;
                vst[i] = 1;
                vst[i+1] = 1;
                vst[i+2] = 1;
            }
        i++;
    }
    i = 0;
    flagx = 0;
    while(i < n){
        if(!vst[i] && ! vst[i+1] && ! vst[i+2] && !vst[i+3])
            if(calcu(i,i+3) == k){
                cnt++;
                vst[i] = 1;
                vst[i+1] = 1;
                vst[i+2] = 1;
                vst[i+3] = 1;
            }
        i++;
    }
    i = 0;
    flagx = 0;
    while(i < n){
        if(!vst[i] && ! vst[i+1] && ! vst[i+2] && !vst[i+3] && !vst[i+4])
            if(calcu(i,i+3) == k){
                cnt++;
                vst[i] = 1;
                vst[i+1] = 1;
                vst[i+2] = 1;
                vst[i+3] = 1;
                vst[i+4] = 1;
            }
        i++;
    }
    i = 0;
    flagx = 0;
    while(i < n){
        if(!vst[i] && ! vst[i+1] && ! vst[i+2] && !vst[i+3] && !vst[i+4] && !vst[i+5])
            if(calcu(i,i+3) == k){
                cnt++;
                vst[i] = 1;
                vst[i+1] = 1;
                vst[i+2] = 1;
                vst[i+3] = 1;
                vst[i+4] = 1;
                vst[i+5] = 1;
            }
        i++;
    }
    cout <<cnt << endl;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cal();
    cin >> n >> k;
    bool flaga1 = 1;
    bool flaga01 = 1;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] != 1)flaga1 = 0;
        if(a[i]>1||a[i]<0)flaga01 = 0;
    }
    if(k == 0 && flaga1 == 1){
        solvea1k0();
    }
    if(k <= 1 && flaga01 == 1){
        solvea01();
    }
    else{
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
