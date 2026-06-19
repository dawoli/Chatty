#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	int ones=0,twos=0;
	int temp;
	scanf("%d",&n);
	int ans = 0;
	int cnt[100000],dam[100000];
	memset(cnt,0,sizeof(cnt));
	int maxx = 0;
	for(int i = 0;i<n;i++){
		scanf("%d",&temp);
		cnt[temp] ++;
		dam[temp] ++;
		maxx = max(maxx,temp);
	}
	for(int i = 1;i<maxx;i++){
		if(cnt[i] > 0){
			for(int j = i+1;j<=maxx;j++){
				if(cnt[i] > 0 and dam[j] > 0){
					if(cnt[i]<=dam[j]){
						dam[j]-=cnt[i];
						cnt[i] = 0;
					}
					else{
						cnt[i] -= dam[j];
						dam[j] = 0;
					}
					if(cnt[i] == 0) break;
				}
			}
			ans+=cnt[i];
		}
	}
	printf("%d",ans+cnt[maxx]);
	return 0;
} 
