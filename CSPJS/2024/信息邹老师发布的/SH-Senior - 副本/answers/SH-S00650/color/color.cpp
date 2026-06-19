#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[200005];
bool col[200005];//zero-red one-blue
int fan=0;
void dfs(int id){
	if(id==n+1){
		int lst_r=0,lst_b=0;
		int cs=0;
		for(int i=1;i<=n;i++){
			if(col[i]){
				if(a[i]==a[lst_b])	cs+=a[i];
				lst_b=i;
			}
			else{
				if(a[i]==a[lst_r])	cs+=a[i];
				lst_r=i;
			}
		}
		fan=max(fan,cs);
		return;
	}
	col[id]=1;
	dfs(id+1);
	col[id]=0;
	dfs(id+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		a[0]=-1;
		for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
		fan=0;
		dfs(1);
		printf("%d\n",fan);
	}
	return 0;
}

