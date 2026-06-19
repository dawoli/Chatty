#include<bits/stdc++.h>
using namespace std;
int a[100005];
//bool sum[25]={0},ans[25]={0};
int main(){
    int n,m,ans=0,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }

    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum%m==0&&sum!=0){
            ans++;
            sum=0;
        }
    }
    cout<<ans;
    /*int x=1;
    while(m!=0){
        ans[x]=m%2;
        m/=2;
        x++;
    }
    int k=1;
    while(a[1]!=0){
        sum[k]=a[1]%2;
        a[1]/=2;
        k++;
        cout<<sum[k]<<' ';
    }
    for(int i=2;i<=n;i++){
        int k=1;
        if(a[i]==0){
            for(int i=1;i<=x;i++){
                if(sum[k]==0) sum[k]=1;
                cout<<sum[k]<<' ';
            }
        }
        while(a[i]!=0){
            if(sum[k]==a[i]%2) sum[k]=0;
            else sum[k]=1;
            a[i]/=2;
            k++;
            cout<<sum[k]<<' ';
        }
        cout<<endl;
        bool flag=1;
        for(int j=1;j<=x;j++){
            if(ans[j]!=sum[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            for(int j=1;j<=x;j++){
                sum[j]==0;
            }
        }
    }
    cout<<ans1;*/
    return 0;
}
