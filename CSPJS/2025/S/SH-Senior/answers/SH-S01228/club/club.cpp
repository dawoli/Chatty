#include <bits/stdc++.h>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
int t,n,ans,a[100005][3];
// things for A
int Aa[100005];
// for check A B
bool A=true,B=true;
// for A
void solveA(){
    sort(Aa,Aa+n);
    for(int i=0;i<n/2;++i){
        ans+=Aa[i];
    }
}
// for n <= 30
void dfs(int depth,int sum,int cnt1,int cnt2,int cnt3){
    if(depth==n){
        if(max(cnt3,max(cnt1,cnt2))<=n/2){
            ans=max(ans,sum);
        }
        return;
    }
    dfs(depth+1,sum+a[depth][0],cnt1+1,cnt2,cnt3);
    dfs(depth+1,sum+a[depth][1],cnt1,cnt2+1,cnt3);
    dfs(depth+1,sum+a[depth][2],cnt1,cnt2,cnt3+1);
}
int main() {
    fin>>t;
    for(int i=1;i<=t;++i){
        fin>>n;
        for(int j=0;j<n;++j){
            fin>>a[j][0]>>a[j][1]>>a[j][2];
            Aa[i]=a[i][0];
            if(a[i][1]>0)A=false;
            if(a[i][2]>0)B=false;
        }
        if(A){
            solveA();
        } else if(n<=30){
            dfs(0,0,0,0,0);
        fout<<ans<<endl;
        ans=0;
    }
    return 0;
}