#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct car{
    int ds, de;
}over[100005], dtd[100005];
int T, n, m, L, V, d, v0, a, overCars, dtdCars, numOfUP, usedP[100005], p[100005];
bool carDtd[100005];
bool cmp(car a, car b){
    return a.ds < b.ds;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;	overCars = 0, dtdCars = 0, numOfUP = 0;
        memset(usedP, 0, sizeof(usedP));
        for(int i = 1; i <= n; i++){
            cin>>d>>v0>>a;
            if(a < 0 && v0 > V)    over[++overCars].ds = d, over[overCars].de = min(1ll * L, d + (1ll * v0 * v0 - 1ll * V * V) / (2 * -a));
            else if(a == 0 && v0 > V)    over[++overCars].ds = d, over[overCars].de = L;
            else if(a > 0){
                if(v0 > V)  over[++overCars].ds = d, over[overCars].de = L;
                else{
                    int tmp = ceil((1ll * V * V - 1ll * v0 * v0) / (2 * a));
                    if(d + tmp <= L)    over[++overCars].ds = d + tmp, over[overCars].de = L;
                }
            }
        }
        sort(over + 1, over + overCars + 1, cmp);
        for(int i = 1; i <= m; i++) cin>>p[i];
        for(int i = 1; i <= m; i++){
            bool flag = true;
            for(int j = 1; j <= overCars && over[j].ds <= p[i]; j++)
                if(over[j].de >= p[i]){
                    if(flag)    usedP[++numOfUP] = p[i], flag =false;
                    if(over[j].ds > dtd[dtdCars].ds)  dtd[++dtdCars] = over[j];
                }
        }
        cout<<dtdCars<<" ";
        int rest = dtdCars, ans = 0;    memset(carDtd, 0, sizeof(carDtd));
        while(rest > 0){
            int mostD = 0, mostP = 0, dtdCount = 0;
            for(int i = 1; i <= numOfUP; i++){
                int dtdC = 0;
                for(int j = 1; j <= overCars && over[j].ds <= p[i]; j++)
                    if(over[j].de >= p[i] && !carDtd[j])  dtdC++;
                if(dtdC > mostD)    mostD = dtdC, mostP = i;
            }
            for(int j = 1; j <= overCars && over[j].ds <= p[mostP]; j++)
                if(over[j].de >= p[mostP] && !carDtd[j])  dtdCount++, carDtd[j] = true;
            rest -= dtdCount, ans++;
        }
        cout<<m -ans<<endl;    
    }
}
