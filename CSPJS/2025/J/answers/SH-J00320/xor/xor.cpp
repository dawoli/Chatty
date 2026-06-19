#include <bits/stdc++.h>

using namespace std;

int a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool toku=1;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(toku)
            sum+=a[i];
        if(a[i]!=1&&a[i]!=0)
            toku=0;
    }
    if(toku){
        if(n==1&&k==0){
            cout<<0;
        }else if(sum==n&&k==0){
            cout<<n/2;
        }else if(k==1){
            cout<<sum;
        }else if(k==0){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0)
                    cnt++;
                else if(a[i]==1&&a[i+1]==1){
                    cnt++;
                    i++;
                }
            }
            cout<<cnt;
        }
    }
    cout<<endl;
    return 0;
}
