#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
bool f[N];
int n,cnt1,cnt2;
bool flag=true;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){
			cnt1++;
		}else if(a[i]==2){
			cnt2++;
		}
		if(a[i]>2) flag=false;
	}
	if(flag){
		if(cnt2>=cnt1){
			printf("%d",cnt2);
		}else{
			printf("%d",cnt1-cnt2+1);
		}
		return 0;
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		printf("%d",a[i]);
//	}
	int i=1,j=2,ans=n;
	while(i<=n&&j<=n){
		if(!f[j]&&a[j]>a[i]){
			ans--;
			f[i]=f[j]=true;
//			printf("%d %d %d\n",a[i],a[j],ans);
			i++,j++;
			continue;
		}
		if(f[i]){
			i++;
			if(i==j) j++;
		}
		if(a[i]==a[j]){
			j++;
		}
	}
	printf("%d",ans);
	return 0;
}
