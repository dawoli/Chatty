#include<cstdio>
const int N = 200200;
int t,n,a[N],c[N],answer;
void dfs(int index);
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t>0){
		t--;
		answer=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dfs(2);
		printf("%d\n",answer);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
void dfs(int index){
	if(index>n){
		int lastone=0,lastzero=1;
		int sum=0;
		for(int i=2;i<=n;i++){
			if(c[i]==0){
				if(a[i]==a[lastzero])
					sum+=a[i];
				lastzero=i;
			}
			if(c[i]==1){
				if(a[i]==a[lastone])
					sum+=a[i];
				lastone=i;
			}
		}
		if(sum>answer){
			answer=sum;
		}
		return ;
	}
	c[index]=1;
	dfs(index+1);
	c[index]=0;
	dfs(index+1);
}
