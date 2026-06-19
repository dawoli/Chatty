#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[4],ans,p,num,b[100005],a[100005][4],c[100005],mx;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		ans=0;
		for(int i=1;i<=n;i++){
			mx=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>mx){
					mx=a[i][j];
					c[i]=j;
				}
			}
			sort(a[i]+1,a[i]+4);
			ans+=a[i][3];
			cnt[c[i]]++;
		}
		p=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				p=i;
		    }
		}
		if(p){
			num=0;
			for(int i=1;i<=n;i++){
				if(c[i]==p){
					b[++num]=a[i][3]-a[i][2];
				}
			}
			sort(b+1,b+num+1);
			for(int i=1;i<=cnt[p]-n/2;i++){
				ans-=b[i];
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
