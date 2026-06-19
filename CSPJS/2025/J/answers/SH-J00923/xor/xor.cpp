#include<bits/stdc++.h>
using namespace std;
int n,k,tep,s[500001];//[l,r]的权值是s[r]^s[l-1] 
int sides[500001],dp[500001];
struct node{
	int digit,inde;
}ast[500001];
bool cmp(node n,node m){
	if(n.digit<m.digit)return true;
	else if(n.digit==m.digit&&n.inde<m.inde)return true;
	else return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&tep);
		s[i]=tep^s[i-1];
		node temp;
		temp.digit=s[i];
		temp.inde=i;
		ast[i]=temp;
	}
	sort(ast+1,ast+n+1,cmp);
	for(int i=1;i<=n;i++){
		sides[i]=-1;
		int target=s[i]^k;
		int l=0,r=n,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(ast[mid].digit>target)r=mid-1;
			else if(ast[mid].digit<target)l=mid+1;
			else if(ast[mid].digit==target && ast[mid].inde+1>i)r=mid-1;
			else if(ast[mid].digit==target && ast[mid].inde+1<=i){
				sides[i]=ast[mid].inde+1;
				l=mid+1;
			}
		}
		//if((s[i-1]^s[i])==k)sides[i]=i;
	//	printf("%d ",sides[i]);
	}
	for(int i=1;i<=n;i++){
		if(sides[i]!=-1)dp[i]=max(dp[i-1],dp[sides[i]-1]+1);
		else dp[i]=dp[i-1];
	//	printf("%d ",dp[i]);
	}
	printf("%d",dp[n]);
	return 0;
}
