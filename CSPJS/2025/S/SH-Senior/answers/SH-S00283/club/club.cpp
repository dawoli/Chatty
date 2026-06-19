/*
seems like a not easy Problem 1
but I think that I can get 100 since I've got AC in the samples,
the random duipai, and some special samples.
(17:33)
restart a new round of duipai. Planed to test at least 10 samples.
(17:43)
It's just 10 minutes, but I felt it's so different. Let me read the problems and think again... *shortly leave*
(17:44)
Already progressed. I found that the problem 3 gives 2 GB memory.
(17:48)
Let me try something on Linux...
Not bad. The string problem doesn't make any incorrect things.
(17:55)
Ok, turn back to Windows, and run every test again.
What I wrote in "road.cpp" is just impossible. A problem I cannot solve will never become possible.

This is my first time to take part in the CSP-S, 
rp+=INF;

What I've learnt at the end of my first try in CSP-S
- Sleep when encounter difficulties.   ----DeepSleep
- A 30-minute-sleep can skip to the time when the exam ends.   ----Easily inferred from the current time, 18:00

zip password: Ren5Jie4Di4Ling5%
rp++;
*/

#include<bits/stdc++.h>

using namespace std;

const int NR = 100010;
struct Node{
	int d[5],p;
} a[NR];
int cnt[5];
struct Move{ // let someone go to another club and it's cost
	int p,u,v,cost; // who, from where, to where
	bool operator >(const Move &other) const{
		return cost > other.cost;
	}
};
priority_queue<Move, vector<Move>, greater<Move> > q;

int first(Node x){
	return max(x.d[1],max(x.d[2],x.d[3]));
}
int second(Node x){
	return(max(x.d[1],max(x.d[2],x.d[3])) - min(x.d[1],min(x.d[2],x.d[3])));
}
int last(Node x){
	return min(x.d[1],min(x.d[2],x.d[3]));
}

bool cmp(Node x, Node y){
	return first(x)-second(x) < first(y)-second(y);
}

void solve(){
	memset(a,0,sizeof a);
	while(q.size()) q.pop();
	
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
	// greedy? put all members into the best place.
	// when a club contains too many people, change the worst
	cnt[1]=0, cnt[2]=0, cnt[3]=0;
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		int mx = first(a[i]); // default club
		if(mx == a[i].d[1]){
			cnt[1] ++, ans += a[i].d[1], a[i].p = 1;
			q.push({i,1,2,a[i].d[1]-a[i].d[2]}), q.push({i,1,3,a[i].d[1]-a[i].d[3]});
		}
		else if(mx == a[i].d[2]){
			cnt[2] ++, ans += a[i].d[2], a[i].p = 2;
			q.push({i,2,1,a[i].d[2]-a[i].d[1]}), q.push({i,2,3,a[i].d[2]-a[i].d[3]});
		}
		else{
			cnt[3] ++, ans += a[i].d[3], a[i].p = 3;
			q.push({i,3,1,a[i].d[3]-a[i].d[1]}), q.push({i,3,2,a[i].d[3]-a[i].d[2]});
		}
	}
//	cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3];
	// only when a club has too many members, it needs to move
	while(cnt[1] > n/2 || cnt[2] > n/2 || cnt[3] > n/2){
		Move f = q.top(); q.pop();
		if(f.cost < 0 || cnt[f.u] <= n/2 || a[f.p].p != f.u) continue;
		ans -= f.cost; a[f.p].p = f.v;
		cnt[f.u] --, cnt[f.v] ++;
		for(int i = 1; i <= 3; i ++) if(i != f.v)
			q.push({f.p,f.v,i,a[f.u].d[i]});
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T; cin >> T;
	while(T --) solve();
	
	return 0;
}
