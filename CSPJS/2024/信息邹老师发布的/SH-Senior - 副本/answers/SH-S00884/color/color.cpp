#include<iostream>
#include<cstring>
using namespace std;
int t,n;
int a[200005];
int dfs(int *a,int idx,int score,bool *color){
	if(idx==n)	return score;
	for(int i=idx-1;i>=0;i--)
		if(color[idx]==color[i])
			if(a[idx]==a[i]){
				score+=a[i];
				break;
			}
	int maxn=-1;
	color[idx]=0;
	int A=dfs(a,idx+1,score,color);
	color[idx]=1;
	int B=dfs(a,idx+1,score,color);
	int C=max(A,B);
	maxn=max(C,maxn);
	return maxn;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	bool color[200005];
	while(t--){
		memset(color,0,sizeof(color));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<dfs(a,0,0,color)<<endl;
	}
	return 0;
}
