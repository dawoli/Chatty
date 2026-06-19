#include<bits/stdc++.h>
using namespace std;
int r[100010];
int ans=0;
int n;
bool at[100010]={0};
bool lv[100010]={0};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	sort(r+1,r+n+1);
	bool flag=1;
	while(flag){
		flag=0;
		int a=0,b=0;
		for(int i=1;i<=n;i++){
			if(!at[i]&&!lv[i]&&!a)a=i;
			else if(!at[i]&&!lv[i]&&a!=0){
				b=i;
				break;
			}
		}
		for( ;b<=n;b++){
			if(!at[b]&&!lv[b]&&r[b]>r[a]){
				ans++;
				at[b]=1;
				lv[a]=1;
				a=b;
				flag=1;
			}
		}
	}
	printf("%d",n-ans);
	return 0;
}
