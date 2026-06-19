#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,ans,b[100010];
struct node{
	pair<int,int> a[3];
}a[100010];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt[3]={0},ans=0,k=0,idx=0;
		for(int i=0;i<n;i++){
			a[i].a[0].second=0,a[i].a[1].second=1,a[i].a[2].second=2;
			cin>>a[i].a[0].first>>a[i].a[1].first>>a[i].a[2].first;
			sort(a[i].a,a[i].a+3,cmp);
			//cout<<a[i].a[0].first<<" "<<a[i].a[0].second<<" "<<a[i].a[1].first<<" "<<a[i].a[1].second<<" "<<a[i].a[2].first<<" "<<a[i].a[2].second<<endl;
			ans+=a[i].a[0].first;
			cnt[a[i].a[0].second]++;
		}
		//cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
		if(cnt[0]<cnt[1])k=1;
		if(cnt[k]<cnt[2])k=2;
		if(cnt[k]>n/2){
			for(int i=0;i<n;i++){
				if(a[i].a[0].second==k){
					b[idx++]=a[i].a[1].first-a[i].a[0].first;
				}
			}
			sort(b,b+idx,greater<int>());
			for(int i=0;i<cnt[k]-n/2;i++)ans+=b[i];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
