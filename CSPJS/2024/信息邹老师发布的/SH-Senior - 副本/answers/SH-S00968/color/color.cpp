#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
const int M=1e6+9;
typedef long long ll;
ll f[N][2]; //任务：只要可以把两端中间的部分的唯一情况求解出来，就解决了！ 
int a[N];
int pre[N],cnt[M];
ll ans=0;
int t,n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(pre,0,sizeof(pre));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(cnt[a[i]]){
				pre[i]=cnt[a[i]];
			}
			cnt[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(!pre[i]) continue;
			else{
				f[i][0]=f[i][1]=max(f[pre[i]-1][0],f[pre[i]-1][1])+a[i];
					//考虑包在里面的情况 
					for(int j=pre[i]+1;j<=i-1;j++){
						if(pre[j]<pre[i]&&pre[j]){
							f[i][0]=max(f[i][0],f[pre[i]-1][0]+a[j]+a[i]);
							f[i][1]=max(f[i][1],max(f[pre[i]-1][1],f[pre[j]-1][1])+a[j]+a[i]);
						}
						else if(pre[j]){
							f[i][0]=max(f[i][0],max(f[pre[i]-1][0],f[pre[i]-1][1])+a[i]+a[j]);
							f[i][1]=max(f[i][1],max(f[pre[i]-1][0],f[pre[i]-1][1])+a[i]+a[j]);
						} 
					}
			}
			ans=max(f[i][0],max(ans,f[i][1]));
//			cout<<i<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
