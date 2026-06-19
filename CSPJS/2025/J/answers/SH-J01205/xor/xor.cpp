#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
vector<bool> xxx(int x){
    vector<bool> a(0);
    while(x){
        a.push_back(x%2);
        x/=2;
    }
 //reverse(a.begin(),a.end());
    return a;
}
int zxx(int x,int y){
    vector<bool> a=xxx(x);
    vector<bool> b=xxx(y);
    vector<bool> c(0);
    int l1=a.size();
    int l2=b.size();
    int cnt=0;
    int l=max(l1,l2);
    for(int i=l-1;i>=0;i--){
        if(a[i]==b[i]) c.push_back(0);
        else c.push_back(1);
    }
    reverse(c.begin(),c.end());
    for(int i=0;i<l;i++){
        if(c[i]==1) cnt+=pow(2,i);
    }
    return cnt;
}
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int cnt=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]==k) cnt++;
        int x=cnt;
        for(int j=i+1;j<n;j++){
            if(zxx(x,a[j])==k) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
