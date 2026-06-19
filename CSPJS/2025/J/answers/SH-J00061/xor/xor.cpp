#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum=0;
    cin>>n>>k;
    vector<int> a(n+1),diff(n+1);
    for(int i=1;i<=n;i++)    cin>>a[i];
    diff[0]=0;
    for(int i=1;i<=n;i++){
        diff[i]=diff[i-1]^a[i];
     //   cout<<diff[i]<<"  ";
    }
    int left=INT_MAX,right=-1;
 //   cout<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i>=left && i<=right)    continue;
            if(j<=right && j>=left)    continue;
            if((diff[i-1]^diff[j])==k){
            //    cout<<"right: "<<right<<"left: "<<left<<"\n";
            //    cout<<(diff[i-1]^diff[j])<<"   "<<k<<"\n";
             //   cout<<diff[i-1]<<"   "<<diff[j]<<"   i: "<<i<<"    j: "<<j<<"\n";
                sum++;
                left=min(i,left);
                right=max(j,right);
                if(j==n){
                    break;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
