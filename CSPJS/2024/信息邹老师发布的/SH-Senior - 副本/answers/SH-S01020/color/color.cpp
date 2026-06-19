#include<bits/stdc++.h>
using namespace std;
enum COLOR{
	RED,
	BLUE
};
const int N=2e5+10;
int T;
int n;
int a[N];
COLOR color[N];

int ans=0;
void check(){
	int *lred=NULL,*lblue=NULL;
	int C=0;
	//左侧最近的红色/蓝色
	for(int i=1;i<=n;i++){
		if(color[i]==RED && lred==NULL){}
		else if(color[i]==BLUE && lblue==NULL){}
		else{
			if(color[i]==BLUE){
				if(a[i]==*lblue)C+=a[i];
			}
			if(color[i]==RED){
				if(a[i]==*lred)C+=a[i];
			}
		}
		if(color[i]==BLUE)lblue=a+i;
		if(color[i]==RED)lred=a+i;
	} 
	if(C>ans)ans=C;
}
void dfs(int index){
	if(index==n+1){
//		for(int i=1;i<=n;i++){
//			if(color[i]==RED)printf("R");
//			else printf("B");
//		}
//		printf("\n");
//		return;
		
		check();
		return;
	}
	color[index]=RED;
	dfs(index+1);
	color[index]=BLUE;
	dfs(index+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
calcloop:
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
//	for(int i=1;i<=n;i++){
//		printf("%d%c",a[i],i==n?'\n':' ');
//	}
	ans=0;
	dfs(1);
	printf("%d\n",ans);
	
	
	if(--T!=0)goto calcloop;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
