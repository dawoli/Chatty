#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
int t,n,len,a[10000],tran[10]={0,0,1,7,4,2,0,8},op[10]={0,6,2,5,4,3,7},num,minn;
bool flag;
void dfs(int step,int sum,int prev){
	if(sum>n){
		return;
	}
	if(step>len){
		if(sum==n){
			for(int i=1;i<=len;i++){
				a[i]=tran[a[i]];
			}
			if(a[1]==0){
				flag=false;
				for(int i=1;i<=len;i++){
					if(a[i]!=0){
						swap(a[1],a[i]);
						flag=true;
						break;
					}
				}
				if(!flag){
					a[1]=6;
				}
			}
			num=0;
			for(int i=1;i<=len;i++){
				num=num*10+a[i];
			}
			minn=min(minn,num);
		}
		return;
	}
	for(int i=prev;i<=6;i++){
		a[step]=op[i];
		dfs(step+1,sum+op[i],i);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<2){
			printf("-1\n");
			continue;
		}
		len=ceil(n/7.0);
		minn=INT_MAX;
		dfs(1,0,1);
		printf("%d\n",minn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
