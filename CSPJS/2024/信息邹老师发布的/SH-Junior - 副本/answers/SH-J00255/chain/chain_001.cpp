#include<bits/stdc++.h>

using namespace std;

bool dp[110][200010];
int dp2[110][200010];
int s[200010], sl[100010];

struct Node{
	int r,c;
} task[100010]; 
// 降维存储，s[i]存储所有人的序列，l[i]表示第 i 个人序列的长度 
// 第 i 个人的第 j 个数：s[sl[i-1]+j] 

int n,k,q; 

// 表示能否从 st 传到 c，不接受人 p ，如果没有不接受的p，输入-1即可 
int connect(int st, int c, int p){ 
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		if(i == p) continue;
		for(int j = 1; j <= sl[i]-sl[i-1]; j ++){
			// 从这个人的第一个开始遍历到最后一位 
			if(s[sl[i-1]+j] == st){
				for(int l = 1; l < k; l ++){
					if(sl[i-1]+j+l > sl[i]) break;
					if(s[sl[i-1]+j+l] == c){
						if(ans) return -1;
						ans = i;
					}
				}
			}
		}
	}
	return ans;
} 
/*
如果不可以：返回0 
如果只有1个人可以：返回这个人的编号
如果超过1个人可以：返回-1 
*/ 

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	int t; scanf("%d",&t);
	
	while(t--){
		for(int i = 1; i <= 100; i ++) for(int j = 1; j <= 200000; j ++){
			dp[i][j] = 0;
			dp2[i][j] = 0;
		}
		
		scanf("%d%d%d",&n,&k,&q);
		
		int mx_r = -1, mx_c = -1; 
		// 存储最大轮数和最大序列值，决定dp算多少 
		for(int i = 1; i <= n; i ++){
			int lll; scanf("%d",&lll);
			sl[i] = lll + sl[i-1];
			for(int j = 1; j <= lll; j ++){
				scanf("%d",&s[sl[i-1]+j]);
				mx_c = max(mx_c,s[sl[i-1]+j]);
			}
		} 
		for(int i = 1; i <= q; i ++){
			scanf("%d%d",&task[i].r,&task[i].c);
			
//			printf("%d %d",task[i].r,task[i].c);
//			printf("%d ",connect(task[i].r,task[i].c,-1));
			
			mx_r = max(mx_r,task[i].r);
		}
		// 读入 
		
		
		
		for(int i = 1; i <= mx_r; i ++){
			if(i == 1){
				for(int j = 1; j <= mx_c; j ++){
					dp2[1][j] = connect(1,j,-1);
					dp[1][j] = dp2[1][j];
					
//					printf("%d ",dp[1][j]);
				}
			}
			else{
				for(int l = 1; l <= mx_c; l ++){
					if(!dp[i-1][l]) continue;
					for(int j = 1; j <= mx_c; j ++){
						if(!dp2[i][j]) dp2[i][j] = connect(l,j,dp2[i-1][l]);
						dp[i][j] |= dp2[i][j];
					}
				}
			}
		}
		
		for(int i = 1; i <= q; i ++){
//			printf("%d %d",task[i].r,task[i].c);
			printf("%d\n",dp[task[i].r][task[i].c]);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
