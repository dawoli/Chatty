#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef long long ll;
int n,k;//<1e3 <pow(2,30) 
int a[N];//<pow(2,30)
int g[N][N];//<pow(2,30)
struct node{
	int l,r;
	bool friend operator<(node a,node b){
		return a.r<b.r;
	}
};
vector<node> e;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	//输入
	 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//遍历所有的区间 
			for(int x=i;x<=j;x++){
				g[i][j]^=a[x];
			}
			//计算权值 
			if(g[i][j]==k){
				e.push_back({i,j});
			}
			//若权值==k 记录下这个区间 
		}
	}
	
	sort(e.begin(),e.end());
	//将所有区间按右端点排序
	 
	int nowr=0;//目前区间最远端（后选的区间的左端点不能超过这个值）<1e3 
	ll cnt=0;//已选区间数量 <1e6
	for(int i=0;i<e.size();i++){//遍历所有区间 
		int l=e[i].l,r=e[i].r;//取出左端点和右端点 <1e3
		if(l>nowr){//若区间与前面的区间不相交 
			nowr=r;//更新区间最远端 
			cnt++;//选择这个区间 
		}
	}
	//选择其中部分区间 
	cout << cnt << endl;
	
	//1~12 复杂度1e9 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
