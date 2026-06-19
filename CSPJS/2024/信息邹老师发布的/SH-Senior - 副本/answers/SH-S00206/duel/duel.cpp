#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int r[MAXN];
int n;
bool have[MAXN];
bool check(int i,int now){
	return r[now]>r[i]&&!have[now];
}
int find(int pos){
	int le=pos+1,ri=n;
	int ans=0;
	while(le<=ri){
		int mid=(le+ri)>>1;
		if(check(pos,mid)){
			ri=mid-1,ans=mid;
		}else{
			le=mid+1;
		}
	}
	return ans;
}
int solve(){
	int cnt=0;
	for(int i=1;i<=n;i++){
        int j=find(i);
        if(j){
        	++cnt;
            have[j]=1;
		}
	}
	return n-cnt;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    sort(r+1,r+1+n);
    cout<<solve();
	return 0;
}
