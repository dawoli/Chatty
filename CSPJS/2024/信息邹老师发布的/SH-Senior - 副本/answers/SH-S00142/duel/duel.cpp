#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],vis[100010],alive[100010];
map<int,int> mp;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long onenum=0,twonum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) vis[i]=1,alive[i]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) onenum++;
		else if(a[i]==2) twonum++;
		b[i]=a[i];
		mp[a[i]]+=1;
	}
	if(onenum+twonum==n){
//		cerr<<"all ones or twos"<<endl;
		if(onenum>twonum){
			printf("%lld",onenum);
//			cerr<<onenum<<endl;
			return 0;
		}
		else if(onenum<=twonum){
			printf("%lld",twonum);
//			cerr<<twonum<<endl;
			return 0;
		}
	}
	sort(b+1,b+n+1);
//	for(int i=1;i<=n;i++) cerr<<b[i]<<" ";
//	cerr<<endl; 
	int j=2;
	for(int i=1;i<=n;i++){
		if(vis[i]==0||alive[i]==0) continue;
//		cerr<<j<<" "<<b[j]<<" "<<vis[j]<<" "<<alive[j]<<endl;
		while(b[j]<=b[i]||vis[j]==0||alive[j]==0){
			j++;
			if(j>n){
//				cerr<<i<<" "<<j<<" j is out of range"<<endl;
				break;
			}
		}
		if(b[i]<b[j]&&vis[i]==1&&vis[j]==1&&alive[i]==1&&alive[j]==1){
//			cerr<<i<<"was killed by"<<j<<endl;
			vis[i]=0,alive[i]=0;
			vis[j]=0;
		}
	}
	
//	j=2;
//	for(int i=1;i<=n;i++){
//		if(vis[i]==0||alive[i]==0) continue;
////		cerr<<j<<" "<<b[j]<<" "<<vis[j]<<" "<<alive[j]<<endl;
//		while(b[j]<=b[i]||vis[j]==0||alive[j]==0){
//			j++;
//			if(j>n){
////				cerr<<i<<" "<<j<<" j is out of range"<<endl;
//				break;
//			}
//		}
//		if(b[i]<b[j]&&vis[i]==1&&vis[j]==1&&alive[i]==1&&alive[j]==1){
////			cerr<<i<<"was killed by"<<j<<endl;
//			vis[i]=0,alive[i]=0;
//			vis[j]=0;
//		}
//	}

//try another time to remove all that is not counted
//this park can't work!!!!!!!!!!

	for(int i=1;i<=n;i++){
		if(alive[i]==1&&alive[n]==1&&vis[n]==1){
			alive[i]=0;
//			cerr<<i<<"was killed by"<<n<<endl;
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(alive[i]==1)
			ans++;
//	cerr<<ans<<endl;
	printf("%d",ans);
	return 0;
}
