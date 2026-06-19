#include<bits/stdc++.h>
using namespace std;
int n,r[1000010],mn,p,ans,alive[1000010],num[1000010],k,can_use[1000010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	sort(r+1,r+n+1);
/*	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(r[i]==1){
			cnt1++;
		}
		else if(r[i]==2){
			cnt2++;
		}
	}
	printf("%d %d",cnt1,cnt2);*/
	for(int i=1;i<=n;i++){
		if(i==1){
			num[++k]=r[i];
		}
		else if(r[i]!=r[i-1]){
			num[++k]=r[i];
		}
		alive[r[i]]++;
		can_use[r[i]]++;
	}
	int ntk=1;//need_to_kill
	for(int i=2;i<=k;i++){
		if(i==ntk){
			continue;
		}
		if(can_use[num[i]]>=alive[ntk]){
			can_use[num[i]]-=alive[ntk];
			alive[ntk]=0;
			while(1){
				if(alive[ntk]==0){
					ntk++;
				}
				else{
					break;
				}
			}
		}
		else if(can_use[num[i]]<alive[ntk]){
			can_use[num[i]]=0;
			alive[ntk]-=can_use[num[i]];
		}
	}
	for(int i=1;i<=k;i++){
		ans+=alive[num[i]];
	}
	printf("%d",ans);
	return 0;
}
