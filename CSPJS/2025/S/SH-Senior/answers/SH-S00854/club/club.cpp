#include<bits/stdc++.h>
using namespace std;
int m,n,x,a[100005][5],dp[100005][50005],minn,upp;
long long T;
/*
招收了 n 个新,中 n 为偶数。现在小 L 希望将他们分到协会不同的部门。
算法协会共设有三个部门，其中第 i 新成员对第 j (1 ≤ j ≤ 3) 个部门的满意度为 a i,j 。定义一个分配方案的满意度为所有新成员对分配到的部门的满意度
之和，也就是说，若将第 i (1 ≤ i ≤ n) 个新成员分配到了第 d i ∈ {1,2,3} 个部门，则该
分配方案的满意度为
∑ n
i=1 a i,d i 。
他要求在分配方案中，不存一个部门被分配n/2个新成员。
求出，满足他要求的分配方案的满意度的最大值。
*/

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		long long cnt0=0,maxn=0,minn=INT_MAX;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			minn=min(a[i][1],min(a[i][2],a[i][3]));
			maxn=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++) a[i][j]-=minn;
			cnt0+=maxn;
		}
		cout<<cnt0<<endl;
		
	}
	//最后的输出结果要加上upp 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
