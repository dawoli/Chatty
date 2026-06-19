#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int tt(int a,int b,int c){
    int m=max(max(a,b),c);
    int t;
    if(a==m){
        if(b>=c) t=b;
        else t=c;
    }
    if(b==m){
        if(a>=c) t=a;
        else t=c;
    }
    if(c==m){
        if(a>=b) t=a;
        else t=b;
    }
    return t;
}
int mm(int a,int b,int c){
    return max(max(a,b),c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        deque<ll> a1(n+1),a2(n+1),a3(n+1),m(n+1),t(n+1);
        ll cnt1=0,cnt2=0,cnt3=0,sum=0;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
            ll t = tt(a1[i],a2[i],a3[i]);
            ll m = mm(a1[i],a2[i],a3[i]);
            sum+=m;
            if(a1[i]==mm(a1[i],a2[i],a3[i])){
                a1[i]-=t;a2[i]=0;a3[i]=0;
            }
            else{
                if(a2[i]==mm(a1[i],a2[i],a3[i])){
                    a2[i]-=t;a1[i]=0;a3[i]=0;
                }
                else{
                    a3[i]-=t;a2[i]=0;a1[i]=0;
                }
            }
        }
        vector<ll> d1,d2,d3;
        for(int i=1;i<=n;i++){
            if(a1[i]!=0) d1.push_back(a1[i]);
        }
        for(int i=1;i<=n;i++){
            if(a2[i]!=0) d2.push_back(a2[i]);
        }
        for(int i=1;i<=n;i++){
            if(a3[i]!=0) d3.push_back(a3[i]);
        }
        if(d1.size()>n/2){
            sort(d1.begin(),d1.end());
            for(int i=0;i<d1.size()-n/2;i++){
                sum-=d1[i];
            }
        }
        if(d2.size()>n/2){
            sort(d2.begin(),d2.end());
            for(int i=0;i<d2.size()-n/2;i++){
                sum-=d2[i];
            }
        }
        if(d3.size()>n/2){
            sort(d3.begin(),d3.end());
            for(int i=0;i<d3.size()-n/2;i++){
                sum-=d3[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
