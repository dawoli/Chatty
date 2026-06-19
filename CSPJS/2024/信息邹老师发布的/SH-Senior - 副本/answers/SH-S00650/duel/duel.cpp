#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
map<int,int> cnt;
int rd[100005];
int l=1;
int ans=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		if(cnt[r[i]]==0){
			rd[++l]=r[i];
		}
		cnt[r[i]]++;
	}
	int pt=1;
	for(int i=1;i<=n;i++){
		if(r[i]!=r[1]&&pt==1)	++pt;
		if(r[i]!=r[i-1]&&i!=1)	++pt;
		if(pt==1)	continue;
		for(int i=1;i<=pt-1;i++){
			if(cnt[rd[i]]>0){
				cnt[rd[i]]--;
				break;
			}
		}
	}
	for(int i=1;i<=l;i++){
		ans+=cnt[rd[i]];
	}
	printf("%d\n",ans);
	return 0;
}

