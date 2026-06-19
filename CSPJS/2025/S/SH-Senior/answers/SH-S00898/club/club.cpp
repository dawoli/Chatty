#include<bits/stdc++.h>
#define vec vector
using namespace std;
struct cy{
	int d1,d2,d3;
};
cy arr[100005];
int maxn;
int dfs(int a,int b,int c,int man){//当前分配者,当前满意度 
	if(a>maxn/2||b>maxn/2||c>maxn/2){
		return -2;
	}
	if(a+b+c==maxn){
		return man;
	}
	int aa,bb,cc;
	aa=dfs(a+1,b,c,man+arr[a+b+c].d1);
	bb=dfs(a,b+1,c,man+arr[a+b+c].d2);
	cc=dfs(a,b,c+1,man+arr[a+b+c].d3);
	int dmaxsol=max(max(aa,bb),cc);
	return dmaxsol;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;maxn=n;
		for(int i=0;i<n;i++){
			cin>>arr[i].d1>>arr[i].d2>>arr[i].d3;
		}
		cout<<dfs(0,0,0,0)<<"\n;
	}
	return 0;
}
