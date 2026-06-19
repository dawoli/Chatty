#include <bits/stdc++.h>
using namespace std;
inline long long red(){
    long long s=0;
    long long pu=0;
    char ch=getchar();
    while(ch<'0'||'9'<ch){
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    pu=s;
    return  pu;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n=0;
    long long r[100005];
    long long ans=0;
    vector<long long> hp;
    n=red();
    for (long long i=1;i<=n;i++){
        r[i]=red();
        hp.push_back(r[i]);
    }
    sort(hp.begin(),hp.end());
    vector<long long>::iterator fir=hp.begin();
    vector<long long>::iterator sec=hp.begin();
    sec++;
    while(sec!=hp.end()){
        if((*sec)>(*fir)){
            fir++;
            ans++;
        }
        sec++;
    }
    long long give=n-ans;
    cout<<give;
    return 0;
}
