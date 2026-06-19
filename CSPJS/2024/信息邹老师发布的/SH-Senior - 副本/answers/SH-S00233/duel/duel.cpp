#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,cnt;
int r[100003];
bool used[100003];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    sort(r,r+n);
    int j=0;
    for(int i=0;i<n;i++){
        j=j+1;
        while((j<n&&r[j]<=r[i])||used[j])j++;
        if(j<n){
            used[j]=1;
            cnt++;
        }
    }
    cout<<n-cnt;
    return 0;
}
