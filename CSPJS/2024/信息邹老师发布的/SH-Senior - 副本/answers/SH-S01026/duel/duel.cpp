#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],ji[N],b[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    int n,mx=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(int i=0;i<n;i++){
        ji[a[i]]++;
    }

    int ma=0,i1=0;
    for(int i=1;i<=mx;i++){
        if(ji[i]>=ma){
            ma=ji[i];
            i1=i;
        }
    }
    int sum=0;
    for(int i=1;i<i1;i++){
        sum+=ji[i];
    }
    cout<<ma+max(0,sum-ma);
    return 0;
}
