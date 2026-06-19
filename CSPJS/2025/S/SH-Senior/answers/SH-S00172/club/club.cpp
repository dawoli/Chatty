#include<bits/stdc++.h>
using namespace std;
int a[100001][4]={};
int choice[100001]={};
int lst[100001]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		long long ans=0ll;
		scanf("%d",&n);
		memset(lst,0,sizeof(lst));
		memset(choice,0,sizeof(choice));
		int lim=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int cnt[4]={};
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[1]++;
				ans+=a[i][1];
				choice[i]=1;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt[2]++;
				ans+=a[i][2];
				choice[i]=2;
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				cnt[3]++;
				ans+=a[i][3];
				choice[i]=3;
			}
		}
		if(cnt[1]<=lim&&cnt[2]<=lim&&cnt[3]<=lim){
			printf("%lld\n",ans);
			continue;
		}
		int p;
		if(cnt[1]>lim){
			p=1;
		}else if(cnt[2]>lim){
			p=2;
		}else{
			p=3;
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(choice[i]==p){
				lst[++tot]=a[i][p];
				if(p==1){
					lst[tot]-=max(a[i][2],a[i][3]);
				}else if(p==2){
					lst[tot]-=max(a[i][1],a[i][3]);
				}else if(p==3){
					lst[tot]-=max(a[i][1],a[i][2]);
				}
			}
		}
		sort(lst+1,lst+tot+1);
		for(int i=1;i<=cnt[p]-lim;i++){
			ans-=lst[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
