#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,a[N][3],mx[N];
int cnt[3],res;
vector<int> del;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		res=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1; i<=n; i++){
			int a0,a1,a2;
			scanf("%d%d%d",&a0,&a1,&a2);
			a[i][0]=a0,a[i][1]=a1,a[i][2]=a2;
			if(a0>=a1&&a0>=a2) mx[i]=0;
			else if(a1>=a0&&a1>=a2) mx[i]=1;
			else mx[i]=2;
			res+=a[i][mx[i]],cnt[mx[i]]++;
		}
		int o=-1;
		for(int i=0; i<3; i++)
			if(cnt[i]>n/2) o=i;
		if(o!=-1){
			del.clear();
			for(int i=1; i<=n; i++){
				if(mx[i]!=o) continue;
				int mindel=N;
				for(int j=0; j<3; j++)
					if(j!=o) mindel=min(mindel,a[i][o]-a[i][j]);
				del.push_back(mindel);
				
			}
			sort(del.begin(),del.end());
			for(int i=0; i<cnt[o]-n/2; i++) res-=del[i];
		}
		printf("%d\n",res);
	}
	return 0;
}
