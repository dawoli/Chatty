#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,n,m,l,liv,mp[100010],d[100010],v[100010],a[100010],ans;
ll ifopen[100010];
ll start_s[100010],end_s[100010],ov[100010];
void dfs(int step, ll target){
	if (step==m+1){
		ll overspeed=0,limitspeed=liv*liv;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (ifopen[j]==1 and mp[j]>=d[i] and v[i]*v[i]+2*a[i]*(mp[j]-d[i])>limitspeed){
					overspeed++;
					break;
				}
		if (target==overspeed){
			ll cnt=0;
			for (int i=1;i<=m;i++) cnt+=(1-ifopen[i]);
			ans=max(ans,cnt);
		}
		return;
	}
	ifopen[step]=0;
	dfs(step+1,target);
	ifopen[step]=1;
	dfs(step+1,target);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--){
		int special_a=0,special_b=0;
		ans=0;
		cin>>n>>m>>l>>liv;
		for (int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if (a[i]==0) special_a++;
			else if (a[i]>0) special_b++;
		}
		for (int i=1;i<=m;i++) cin>>mp[i];
		sort (mp+1,mp+m+1);//mp[m]--fastest
		
		if (special_a==n){//A
			ll overspeed=0;
			for (int i=1;i<=n;i++)
				if (mp[m]>=d[i] and v[i]>liv) overspeed++;
			if (overspeed!=0) cout<<overspeed<<" "<<m-1<<endl;
			else cout<<0<<" "<<m<<endl;
		}else if (special_b==n){//B
			ll overspeed=0,limitspeed=liv*liv;
			for (int i=1;i<=n;i++){
				if (mp[m]>=d[i] and v[i]*v[i]+2*a[i]*(mp[m]-d[i])>limitspeed) overspeed++;
			}
			if (overspeed!=0) cout<<overspeed<<" "<<m-1<<endl;
			else cout<<0<<" "<<m<<endl;
		}else {
			memset(start_s,0,sizeof(start_s));
			memset(end_s,0,sizeof(end_s));
			memset(ov,0,sizeof(ov));
			for (int i=1;i<=n;i++){
				if (a[i]>0){
					if (v[i]>liv){
						start_s[i]=d[i];
						end_s[i]=l;
					}else {
						start_s[i]=min(l+1,d[i]+(liv*liv-v[i]*v[i])/(2*a[i]));
						end_s[i]=l+1;
					}
				}else if (a[i]==0) {
					if (liv<v[i]){
						start_s[i]=d[i];
						end_s[i]=l+1;
					}
				}else{
					if (v[i]>liv){
						start_s[i]=d[i];
						end_s[i]=min(l+1,d[i]+(v[i]*v[i]-liv*liv)/(2*(-a[i])));
					}
				}
			}
			for (int i=1;i<=n;i++){
				int be=1,fi=m,flag=0;
				if ((mp[be]>=start_s[i] and mp[be]<=end_s[i]) or (mp[fi]>=start_s[i] and mp[fi]<=end_s[i])) flag=1;
				while (be<=fi and flag==0){
					int mid=(be+fi)/2;//mp[mid]
					if (mp[mid]<start_s[i]){
						be=mid+1;
					}else if (mp[mid]>end_s[i]){
						fi=mid-1;
					}else {
						flag=1;
						break;
					}
				}
				if (flag){
					ov[i]++;
					ov[0]++;
				}
			}
			dfs(1,ov[0]);
			cout<<ov[0]<<" "<<ans<<endl;
		}
		
	}
	return 0;
}
