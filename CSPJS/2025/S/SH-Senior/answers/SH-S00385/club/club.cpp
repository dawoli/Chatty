#include<bits/stdc++.h>
using namespace std;
int t,n,arr[100009][3],maxn,ans,mint[100009];
vector<int> li[3];

bool cmp(int a,int b){
    return mint[a]<mint[b];
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=0;i<3;i++){
            while(li[i].size()) li[i].pop_back();
        }
        for(int i=1;i<=n;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        for(int i=1;i<=n;i++){
            if(arr[i][0]>=arr[i][1]&&arr[i][0]>=arr[i][2]) li[0].push_back(i),ans+=arr[i][0];
            else if(arr[i][1]>=arr[i][0]&&arr[i][1]>=arr[i][2]) li[1].push_back(i),ans+=arr[i][1];
            else li[2].push_back(i),ans+=arr[i][2];
        }
        if(li[0].size()>n/2) maxn=0;
        else if(li[1].size()>n/2) maxn=1;
        else if(li[2].size()>n/2) maxn=2;
        else {cout<<ans<<endl;continue;}
        int num=li[maxn].size()-n/2;
        for(int i=1;i<=n;i++){
            mint[i]=2e9;
            for(int j=0;j<3;j++){
                if(j==maxn) continue;
                mint[i]=min(mint[i],arr[i][maxn]-arr[i][j]);
            }
        }
        sort(li[maxn].begin(),li[maxn].end(),cmp);
        for(int i=0;i<num;i++) ans-=mint[li[maxn][i]];
        cout<<ans<<endl;       
    } 
}
