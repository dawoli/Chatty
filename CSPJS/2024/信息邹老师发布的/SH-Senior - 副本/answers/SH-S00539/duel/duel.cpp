#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int rem=0,sum=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    sum=0;
    for(int i=1;i<=n;i++){
        sum++;
        if(i==n||a[i+1]!=a[i]){
            if(rem<=sum) rem=sum;
            else rem=sum+(rem-sum);
            sum=0;
        }
    }
    cout<<rem<<endl;
    return 0;
}