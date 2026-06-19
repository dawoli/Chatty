#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int t,n;
bool flag1=1,flag2=1;
struct nums{
	int s1,s2,s3;
}a[N];
bool cmp1(const nums&x,const nums&y){
	return x.s1>y.s1;
}
bool cmp2(const nums&x,const nums&y){
	return x.s1-x.s2<y.s1-y.s2;
}
int p[N];
int cnt[9];
int ans=0;
void dfs(int i){
	if(i==n+1){
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			int sum=0;
			for(int i=1;i<=n;i++){
				 if(p[i]==1){
				 	sum+=a[i].s1;
				 }
				 if(p[i]==2){
				 	sum+=a[i].s2;
				 }
				 if(p[i]==3){
				 	sum+=a[i].s3;
				 }
			}
			ans=max(sum,ans);
		}
		return;
	}
	p[i]=1;
	cnt[1]++;
	dfs(i+1);
	p[i]=2;
	cnt[1]--;
	cnt[2]++;
	dfs(i+1);
	p[i]=3;
	cnt[2]--;
	cnt[3]++;
	dfs(i+1);
	p[i]=0;
	cnt[3]--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			if(a[i].s3!=0){
				flag1=0;
				flag2=0;
			}
			if(a[i].s2!=0){
				flag1=0;
			}
		}
		if(flag1){
			sort(a+1,a+n+1,cmp1);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].s1;
			}
			cout<<sum<<endl;
		}else if(flag2){
			sort(a+1,a+n+1,cmp2);
			int sum=0;
			for(int i=1;i<=n;i++){
				if(i<=2){
					sum+=a[i].s2;
				}else{
					sum+=a[i].s1;
				}
			}
			cout<<sum<<endl;
		}else{
			ans=0;
			dfs(1);
			cout<<ans<<endl;
		}
	}
}
