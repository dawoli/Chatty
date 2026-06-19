#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int sat[114514][3];

struct P{
    int nb, out_cost;
    bool operator< (const P o) const {
		return out_cost > o.out_cost;
	}
};
priority_queue<P> q1, q2, q3;


int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    
    P p;
    int ans;

    while (t--){
    	ans=0;
    	q1 = priority_queue<P>();
    	q2 = priority_queue<P>();
    	q3 = priority_queue<P>();
        cin >> n;
		for (int i=1;i<=n;i++){
			cin >> sat[i][0] >> sat[i][1] >> sat[i][2];
		}
			
		if (n == 2){
			for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
			if (i != j)
				ans = max(ans, sat[1][i] + sat[2][j]);
			cout << ans << endl;
			continue;
		}
		for (int i=1;i<=n;i++){
			if (sat[i][0] >= sat[i][1] && sat[i][0] >= sat[i][2]){
				p = (P){i, sat[i][0] - max(sat[i][1], sat[i][2])};
				q1.push(p);
				ans += sat[i][0];
			}
			else if (sat[i][1] >= sat[i][0] && sat[i][1] >= sat[i][2]){
				p = (P){i, sat[i][1] - max(sat[i][0], sat[i][2])};
				q2.push(p);
				ans += sat[i][1];
			}
			else {
				p = (P){i, sat[i][2] - max(sat[i][0], sat[i][1])};
				q3.push(p);
				ans += sat[i][2];
			}
		}
		while (q1.size() > (n >> 1)){
			p = q1.top();
			q1.pop();
			ans -= p.out_cost;
		}
		while (q2.size() > (n >> 1)){
			p = q2.top();
			q2.pop();
			ans -= p.out_cost;
		}
		while (q3.size() > (n >> 1)){
			p = q3.top();
			q3.pop();
			ans -= p.out_cost;
		}
		cout << ans << endl;
	}
    return 0;
}
