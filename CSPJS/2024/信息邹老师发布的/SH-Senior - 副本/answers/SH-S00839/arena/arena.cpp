#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
typedef struct node{
	int i;
	bool friend operator<(node p1,node p2){
		return p1.i < p2.i;
	}
}node;
priority_queue <node>Q;
int main(){
//	freopen("arena.in","r",stdin);
//	freopen("arena.out","w",stdout);
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		node xx;
		xx.i = x;
		if(r[x] == 0){
			Q.push(xx);
		}
		r[x] ++;
//		cout << i << " ";
	}
	int mmax = 0;
	int ans = 0;
	node nnode;
	while(!Q.empty()){
		nnode = Q.top();
		Q.pop();
//		cout << nnode.i << endl;
		ans += min(mmax,r[nnode.i]);
		mmax = max(mmax,r[nnode.i]);
	}
	cout << n-ans;
	return 0;
} 
