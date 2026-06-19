#include<bits/stdc++.h>
using namespace std;
#define N 1001
#define LN 2001
typedef long long LL;
LL n,k,q;	//参与游戏的人数、接龙序列长度上限、任务个数
LL s[N][LN];	//s[i][j]:第i人的词库中的第j位数 s[i][0]储存词库中词的数量 

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T; cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>s[i][0];
			for(int j=1;j<=s[i][0];j++) cin>>s[i][j];	//输入第i人的词库{s[j]} 
		}
		LL r,c;	//恰好r轮接龙，最后的元素为c 
		while(q--){	//每次询问给出答复 
			cin>>r>>c;
			/*关注r=1时的解*/
			bool flag1=false;
			for(int i=1;i<=n;i++){
				bool flag2=false;
				LL pos=-1;	//最右边的1的位置 
				for(int j=1;j<=s[i][0];j++){
					if(s[i][j]==1) pos=j;
					if(s[i][j]==c&&pos!=-1){
						if(j-pos+1<=k&&j-pos+1>=2){
							cout<<1<<endl;
							flag2=true;	//标记已找到 
							break;
						}
					} 
				}
				if(flag2){
					flag1=true;
					break;
				}
			}
			if(!flag1){
				cout<<0<<endl;
				continue;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7
*/
