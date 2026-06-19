#include<algorithm>
#include<cstdio>
using namespace std;
const int N=100010;
int n,maxv,res;
int cnt[N],can[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int r;
		scanf("%d",&r);
		cnt[r]++;
		can[r]++;
		maxv=max(maxv,r);
	}
	res=n;
	for(int i=1;i<=maxv;i++){
		if(!cnt[i])
			continue;
		bool flag;
		while(cnt[i]){
			flag=false;
			for(int j=i+1;j<=maxv;j++)
				if(can[j]){
					can[j]--;
					cnt[i]--;
					can[i]--;
					res--;
					flag=true;
					break;
				}
			if(!flag)
				break;
		}
		if(!flag)
			break;
	}
	printf("%d\n",res);
	return 0;
}
