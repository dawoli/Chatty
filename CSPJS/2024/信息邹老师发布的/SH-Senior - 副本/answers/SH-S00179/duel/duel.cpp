#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[100100];
bool c[100100];
int d[100100];
int dnum[100100];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	int old=a[0],cnt=0,tot=0;
	for(int i=0;i<n;i++){
		if(a[i]>old){
			d[tot]=old;
			dnum[tot]=cnt;
			cnt=1;
			tot++;
			old=a[i];
		}
		else{
			cnt++;
		}
	}
	d[tot]=old;
	dnum[tot]=cnt;
	int ans=0;
	for(int i=0;i<=tot;i++){
		ans=(ans>=dnum[i])?ans:dnum[i];
	}
	
	printf("%d",ans);
				
	return 0;
}
