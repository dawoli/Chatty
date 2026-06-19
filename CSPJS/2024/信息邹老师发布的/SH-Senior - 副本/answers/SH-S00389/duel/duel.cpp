#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100010],p1,p2,ans;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	ans=n;
	for(;p1<n;p1++){
		if(a[p2]>a[p1]){
			p2++;
			ans--;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
