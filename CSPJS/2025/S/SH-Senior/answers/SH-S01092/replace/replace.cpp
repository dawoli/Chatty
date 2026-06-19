#include <bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    while(q--){
        int cnt = 0;
        string x,y;
        cin >> x >> y;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < x.size(); j++){
                int t = j,k = 0,flag = 1;
                while(a[i][k] == x[j] && j < x.size() && k < a[i].size()){
                    k++;
                    j++;
                }
                if(k == a[i].size()){
                    int p = t;
                    for(int z = 0; z < t; z++){
                        if(x[z] != y[z]){
                            flag = 0;
                            break;
                        }
                    }
                    for(int z = 0; z < b[i].size(); z++){
                        if(y[p] != b[i][z]){
                            flag = 0;
                            break;
                        }
                        p++;
                    }
                    for(int z = p+1; z < y.size(); z++){
                        if(x[z] != y[z]){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                        cnt++;
                        break;
                    }
                }
                k = 0;
                j = t;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
