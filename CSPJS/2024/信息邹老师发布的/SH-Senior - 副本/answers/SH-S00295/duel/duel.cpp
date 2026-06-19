#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5+9;
int a,b[N];
map<int,int> q,r,s;
int flg=0;
//期望100 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		//经典桶排 
		q[a]++;
		r[flg]=a;
		if(q[a]==1){
			flg++;
		}
		
	}
	int lst = 0;
	for(int i=1;i<flg;i++){
		//策略，贪心：大的就近打小的，打不掉的往后放 
		int x = r[i-1];
		int y = r[i];
		//特殊处理，把之前没杀掉的权值提升到x 
		//cout<<x<<" "<<y<<" "<<lst<<endl; 
		q[x]+=lst;
		//记得清空 
		lst = 0;
		if(q[x]>q[y]){
			//杀不光
			q[x]-=q[y];
			lst+=q[x];
			//剩下杀不掉的放到lst
		} 
		else{
			q[x]-=q[y];
		}
	}
	//之前杀不掉的和最大的加起来就是答案 
	cout<<lst+q[r[flg-1]]<<endl;
	return 0;
}
