#include <bits/stdc++.h>
using namespace std;
int n;
bool all_1=true;
int ans;
int maxi;
int sum;
int l[5050];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        if(l[i]!=1){
            all_1=false;
        }
    }
    if(n==3){ //special 1
        for(int i=1;i<=n;i++){
            sum+=l[i];
            if(l[i]>maxi){
                maxi=l[i];
            }
        }
        if(sum>2*maxi){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    if(all_1==true){ //special 2
        for(int i=n;i>=3;i--){
            int part_ans=1;
            for(int j=1;j<=i;j++){
                part_ans=part_ans*(n-j+1);
                part_ans/=j;
                part_ans=part_ans%998;
                part_ans=part_ans%244;
                part_ans=part_ans%353;
            }
            ans+=part_ans;
        }
        ans=ans%998;
        ans=ans%244;
        ans=ans%353;
        cout<<ans;
        return 0;
    }
    for(int i=n;i>=3;i--){
        int part_ans=1;
        for(int j=1;j<=i;j++){
            part_ans=part_ans*(n-j+1);
            part_ans/=j;
            part_ans=part_ans%998;
            part_ans=part_ans%244;
            part_ans=part_ans%353;
        }
        ans+=part_ans;
    }
    ans=ans%998;
    ans=ans%244;
    ans=ans%353;
    cout<<ans/2+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
