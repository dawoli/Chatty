#include <cstdio>
#include <algorithm>
using namespace std;

int a[200005];

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",a+i);
		long long aans=0;
		for(int i=0;i<1<<n;i++){
			int red=-1,blue=-1;
			long long ans=0;
			for(int j=0;j<n;j++){
				int color=i&(1<<j);
				if(color==0){
					if(~red&&a[red]==a[j]){
						ans+=a[j];
					}
					red=j;
				}else{
					if(~blue&&a[blue]==a[j]){
						ans+=a[j];
					}
					blue=j;
				}
			}
//			printf("%X %d\n",i,ans);
			aans=max(aans,ans);
		}
		printf("%lld\n",aans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
