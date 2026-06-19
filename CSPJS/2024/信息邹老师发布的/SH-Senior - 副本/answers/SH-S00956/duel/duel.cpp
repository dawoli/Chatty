#include<iostream> 
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN],ans=0,cnt=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cnt++;
		if(a[i]!=a[i+1]){
			ans=max(ans-cnt,0);
			ans+=cnt;
			cnt=0;
		}
	}
	printf("%d",ans);
	return 0;
}
