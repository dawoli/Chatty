#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    char a[60],b[60];
    int n;
    cin>>n;
    int ans=52;

    int flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        flag=0;
        for(int j=1;j<i;j++){
            if(a[i]==a[j]&&b[i]==b[j]){
                flag=1;
            }
        }
        if(flag==0){
            ans--;
        }

    }
    if(n==1){
        cout<<51;return 0;
    }
    cout<<ans;
    return 0;
}
