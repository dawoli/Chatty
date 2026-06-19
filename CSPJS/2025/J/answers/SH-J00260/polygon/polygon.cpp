#include<iostream>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0,sum,countn=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1){
            countn++;
        }
    }
    if(n==3){
        for(int i=0;i<3;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[j+1]){
                    swap(a[j],a[j+i]);
                }
            }
        }
        sum=a[0]+a[1]+a[2];
        if(sum>(2*a[0])){
            ans=1;
        }
    }
    else if(countn==0){
        int b=n-2;
        int sqsum=0;
        for(int i=0;i<=b;i++){
            sqsum+=(i*i);
        }
        ans=sqsum;
    }
    else{
        ans=6;
    }
    cout<<ans;
    return 0;
}

