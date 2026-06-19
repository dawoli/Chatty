#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 7;
int n, ans;
priority_queue<int, vector<int>, greater<int>> q, b; //small

// CCF RP++ :)
// I think I can AC it :D 

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);

	scanf("%d",&n);

	for(int i = 1, x; i <= n; ++ i){
		scanf("%d",&x);
		q.push(x);
	}
	b = q;
	while(!q.empty()){
		int q_cmp = q.top();
		bool isDuel = false;
		while(!b.empty()){
			int b_cmp = b.top();
			if(q_cmp < b_cmp){
				b.pop();
				isDuel = true;
				break;
			}
			b.pop();
		}
		if(isDuel){
			q.pop();
		}else{
			ans++;
			q.pop();
		}
	}
	
	printf("%d", ans);

	return 0;
}
