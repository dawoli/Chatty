#include<bits/stdc++.h>
using namespace std;
int a[500010];
vector<int> alh;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            int p=a[i];
            vector<int> h;
            h.push_back(i);
            for (int l=i+1;l<=j;l++){
                p^=a[l];
                h.push_back(l);
            }
            if (p==k){
                bool flag=false;
                for(int x:alh){
                    for(int y:h){
                        if (x==y){
                            flag=true;
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                if(!flag){
                    cnt++;
                    for(int y:h){
                        alh.push_back(y);
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
