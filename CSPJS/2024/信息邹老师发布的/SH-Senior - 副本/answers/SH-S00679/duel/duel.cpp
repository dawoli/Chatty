#include<bits/stdc++.h>
using namespace std;
int n,flag,ret,cnt1,cnt2,a[100010],vis[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>2){
			flag=1;
		}
	}if(flag==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt1++;
			}else if(a[i]==2){
				cnt2++;
			}
		}if(cnt2>=cnt1){
			printf("%d",cnt2);
		}else if(cnt2<cnt1){
			printf("%d",cnt1-cnt2);
		}return 0;
	}for(int i=1;i<=n;i++){
		int mx=0,mxi=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&i!=j&&a[i]>a[j]){
				if(mx<a[j]){
					mx=a[j];
					mxi=j;
				}
			}
		}vis[mxi]=1;
	}for(int i=1;i<=n;i++){
		if(vis[i]==0){
			ret++;
		}
	}printf("%d\n",ret);
	return 0;
}
