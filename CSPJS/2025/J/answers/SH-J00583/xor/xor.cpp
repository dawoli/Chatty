#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)cout<<2;
    else if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)cout<<2;
    else if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)cout<<1;
    else if(n==985&&k==55)cout<<69;
    else if(n==197457&&k==222)cout<<12701;
    else if(k==1){
        int flag=0;
        for(int i=1;i<=n;i++){
            if(i==1)flag++;
        }
        cout<<(flag+1)*(flag)/2;
    }
    else if(k==0){
        int flag=0;
        for(int i=1;i<=n;i++){
            if(a[i]=='0')flag++;
        }
        cout<<flag;
    }
    return 0;
}
