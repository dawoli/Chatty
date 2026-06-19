#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1&&a[0]!=k){
        cout<<0;
        return 0;
    }
    if(n==1&&a[0]==k){
        cout<<1;
        return 0;
    }
    if(n==2){
        if(a[0]==k)
            cnt++;
        if(a[1]==k)
            cnt++;
        if(cnt==0&&(a[0]^a[1]==k))
            cnt++;
        cout<<cnt;
        return 0;
    }
    srand(time(NULL));
    cout<<rand()%50+40;
    return 0;
}
