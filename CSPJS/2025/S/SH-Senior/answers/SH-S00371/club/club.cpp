#include<bits/stdc++.h>
using namespace std;
#define int long long
int m[100050],m2[100050],ind[100050];
pair<int,int> loss[100050];
void get(int a,int b,int c,int i){
    m[i]=max(a,max(b,c));
    if(m[i]==a) ind[i]=0;
    if(m[i]==b) ind[i]=1;
    if(m[i]==c) ind[i]=2;
    if(a>=b&&b>=c)m2[i]=b;
    if(a>=c&&c>=b)m2[i]=c;
    if(b>=a&&a>=c)m2[i]=a;
    if(b>=c&&c>=a)m2[i]=c;
    if(c>=a&&a>=b)m2[i]=a;
    if(c>=b&&b>=a)m2[i]=b;
    loss[i]=make_pair(m[i]-m2[i],ind[i]);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n,t;
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
        int ap=0,bp=0,cp=0;
        for(int i=0,a,b,c;i<n;i++){
            cin>>a>>b>>c;
            get(a,b,c,i);
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0) ap++;
            if(ind[i]==1) bp++;
            if(ind[i]==2) cp++;
            ans+=m[i];
        }
        sort(loss,loss+n);
        int l=0;
        if(max(ap,max(bp,cp))>n/2){
            if(ap>n/2) l=0;
            if(bp>n/2) l=1;
            if(cp>n/2) l=2;
            int i=0,j=0;
            while(i<max(ap,max(bp,cp))-n/2){
                if(loss[j].second==l){ans-=loss[j].first;i++;}
                j++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
