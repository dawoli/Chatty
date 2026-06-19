#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
}
const int N=100005;
int r[N],n,res;bool ok[N];//ok[i]==1表示该怪兽已攻击过 
int main(){
	file();
	scanf("%d",&n);
	res=n;
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	sort(r+1,r+1+n);
	for(int i=2,j=1;i<=n;i++){
	//	j记录已经退出游戏的怪兽的最大编号+1 
	//	i为当前处理的怪兽的编号 
		if(ok[i])continue;
		if(r[i]==r[j])continue;
		--res,ok[i]=1,j++;
	}
	printf("%d",res);
	return 0;
}
