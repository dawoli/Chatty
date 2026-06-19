#include<bits/stdc++.h>
using namespace std;
#define MAXN 100007
int n,r[MAXN];
void update(int *ind){
	int t=*ind;
	for(int i=t+1;i<=n;i++){
		if(r[i]!=r[t]) {
			*ind=i;
			return;
		}
	}
	*ind=-1;
	return;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",r+i);
	}
	sort(r+1,r+n+1);
//	for(int i=1;i<=n;i++){
//		printf("%d\n",r[i]);
//	}
//	cout<<endl;
	int lst=1,sec=1;
	int ans=n;
	update(&sec); 
	for(int i=lst,j=sec;j<=n;i++,j++){
		if(r[j]<=r[i]){
			update(&j);
			if(j==-1) break;
		}
		ans--;
//		printf("%d defeated %d with %d over %d.\n",j,i,r[j],r[i]);	
	}
	printf("%d",ans);
	return 0;
}
