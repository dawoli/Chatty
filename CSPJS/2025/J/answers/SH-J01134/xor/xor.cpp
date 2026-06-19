#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500005];
int b[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    int start=1;
    int i=start;
    for(;i<=n;i++){
        b[i]=a[i];
        for(int j=i;j<=n;j++){
            b[j]=b[j-1]^a[j];
            if(b[j]==k){
                cnt++;
                start=j;
                break;
            }
        }
        for(int j=1;j<=n;j++) b[j]=0;
        i=start;
    }
    cout<<cnt;
    return 0;
}
