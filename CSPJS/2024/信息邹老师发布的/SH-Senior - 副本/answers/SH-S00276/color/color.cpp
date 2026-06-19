#include <stdio.h>

int a[200010];
int book[200010];

int main(){
	freopen("color2.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int i=1,j=2;
		while(j<=n){
			if(a[i]==a[j]){
				book[i]=book[j]=1;
				i=j+1,j=j+2;
			}
			else j++;
		}
		int l1=-1,l2=-1;
		for(int i=1;i<=n;i++){
			if(book[i]==0) {
				if(a[i]==l1) ans+=l1;
				l1=a[i];
			}
			if(book[i]==1) {
				if(a[i]==l2) ans+=l2;
				l2=a[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
