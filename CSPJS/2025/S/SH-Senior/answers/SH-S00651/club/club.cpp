#include<bits/stdc++.h>
using namespace std;
struct stu{
	int q[3];
};
bool cmp(stu a,stu b){
	return max(max(a.q[2],a.q[1]),a.q[0])>max(max(b.q[2],b.q[1]),b.q[0])||(max(max(a.q[2],a.q[1]),a.q[0])==max(max(b.q[2],b.q[1]),b.q[0]))&&(min(min(a.q[2],a.q[1]),a.q[0])<min(min(b.q[2],b.q[1]),b.q[0]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		cin>>n;
		stu a[100005];
		for(int i=1;i<=n;i++){
			cin>>a[i].q[0]>>a[i].q[1]>>a[i].q[2];
			int p;
			if(a[i].q[0]<=max(a[i].q[1],a[i].q[2])&&min(a[i].q[1],a[i].q[2])<=a[i].q[0])p=a[i].q[0];
			else if(a[i].q[1]<=max(a[i].q[0],a[i].q[2])&&min(a[i].q[0],a[i].q[2])<=a[i].q[1])p=a[i].q[1];
			else if(a[i].q[2]<=max(a[i].q[0],a[i].q[1])&&min(a[i].q[0],a[i].q[1])<=a[i].q[2])p=a[i].q[2];
			a[i].q[0]-=p;
			a[i].q[1]-=p;
			a[i].q[2]-=p;
			ans+=p;
		}
		sort(a+1,a+n+1,cmp);
		int cnt[3]={0,0,0};
		for(int i=1;i<=n;i++){
			int p=0;
			for(int j=0;j<3;j++){
				if(a[i].q[j]>a[i].q[p])p=j;
			}
			if(cnt[p]<n/2){
				ans+=a[i].q[p];
				cnt[p]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
