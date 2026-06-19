#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int r[N];
int used[N];
int used_tot;
int ans;
//问r[1..n]中最少有多少个上升子序列
//每个序列中只有最大的予以保留 

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",r+i);
	}
	sort(r+1,r+1+n);
	//for(int i=1;i<=n;i++){
	//	printf("%d ",r[i]);
	//}
	for(;;){
		int last=0;
		for(int i=1;i<=n;i++){
			if(!used[i] && r[i]>last){
				last=r[i];
				used[i]=1;used_tot++;
				//printf("%d ",r[i]);
			}
		}
		ans++;
		if(used_tot==n)break;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
