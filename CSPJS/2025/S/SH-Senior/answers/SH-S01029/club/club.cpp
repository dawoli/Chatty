#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
int n;
int a[MAXN][3];
int chos[MAXN];
int cnt[3];
vector<int> vc;
long long ans=0;
void solve(){
    vc.clear();
    ans=0;
    cnt[0]=cnt[1]=cnt[2]=0;
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
        if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
            chos[i]=0;
            cnt[0]++;
            ans+=a[i][0];
        }else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
            chos[i]=1;
            cnt[1]++;
            ans+=a[i][1];
        }else{
            chos[i]=2;
            cnt[2]++;
            ans+=a[i][2];
        }
    }
    int bi=-1;
    if(cnt[0]>n/2){
        bi=0;
    }else if(cnt[1]>n/2){
        bi=1;
    }else{
        bi=2;
    }
    if(bi==-1){
        printf("%lld\n",ans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(chos[i]==bi){
            if(bi==0){
                vc.push_back(a[i][0]-max(a[i][1],a[i][2]));
            }else if(bi==1){
                vc.push_back(a[i][1]-max(a[i][0],a[i][2]));
            }else{
                vc.push_back(a[i][2]-max(a[i][0],a[i][1]));
            }
        }
    }
    sort(vc.begin(),vc.end());
    for(int i=0;i<(cnt[bi]-(n/2));i++){
        ans-=vc[i];
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
