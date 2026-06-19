#include <bits/stdc++.h>
using namespace std;
int a[500005],sum[500005],v[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1]^a[i];
    }
    for(int i = 1; i <= n; i++){
        if(v[i] == 0){
            for(int j = i; j <= n; j++){
                if(sum[j]^sum[i-1] == k){
                    cnt++;
                    for(int x = i; x <= j; x++){
                        v[x] = 1;
                    }
                    break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
