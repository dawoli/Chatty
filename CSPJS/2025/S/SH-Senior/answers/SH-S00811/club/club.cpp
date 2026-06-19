#include<bits/stdc++.h>
using namespace std;
int t,n,maxn=-0x3f3f3f3f,s1,s2,s3;
struct c{
	int x,y,z;
}a[100005];
void dfs(int t,int sum){
	if(t>n){
		maxn=max(sum,maxn);
		return ;
	}
	if(s1<n/2){
		s1++;
		dfs(t+1,sum+a[t].x);
		s1--;
	}
	if(s2<n/2){
		s2++;
		dfs(t+1,sum+a[t].y);
		s2--;
	}
	if(s3<n/2){
		s3++;
		dfs(t+1,sum+a[t].z);
		s3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		maxn=-0x3f3f3f3f;
		dfs(1,0);
		printf("%d\n",maxn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
