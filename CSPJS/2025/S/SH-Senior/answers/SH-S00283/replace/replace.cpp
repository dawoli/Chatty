/*
rp+=INF;
I'm not sure how many points I can get in this problem. I cannot calculate the time.
But an ambition is a must to success. I believe that I can pass the 2e5, 5e6 level. (17:58)Obviously nonsence. I cannot even pass sample #3 and sample #4!
*/

#include<bits/stdc++.h>

using namespace std;

int n,q;
vector<pair<string,string> > trans(0);

string tran(string a, string b, int p){
	a = a.substr(0,p) + b + a.substr(p+b.size());
	return a;
}

int Check(string x, string y, int i){
	string tmp = ""; tmp = x;
	int p = tmp.find(trans[i].first);
	int cnt = 0;
	while(p != -1){
		if(tran(x,trans[i].second,p) == y)
			cnt ++;
		tmp = tmp.substr(p+1);
		p = tmp.find(trans[i].first);
	}
	return cnt;
}

void solve(){
	string x="",y=""; cin >> x >> y;
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		if(trans[i].first.size() != trans[i].second.size()) continue;
		ans += Check(x,y,i);
	}
	cout << ans << '\n';
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	trans.resize(n+1);
	for(int i = 1; i <= n; i ++)
		cin >> trans[i].first >> trans[i].second;
		
	while(q --)
		solve();
	
	return 0;
}

/*
There are too few English words in T3's code.
Let me complain about the environment here.
Why it is so COLD!!!!!!!!
There isn't any problem with the Junior level in the morning, it's even a little bit hot. Is the air-conditioner on??? Or the temperature of Shanghai has dropped a lot??? I'm slowly becoming ice!!!
Fortunately, it's not bad at other points.
(17:37) except the one on my left. He's making a little sound, sounds like a song. But it doesn't affect me much. It's not bad news.
(17:40) The temperature is still low. I have to keep moving, or I'll be unable to type with my frozen hands. They don't work as well as before! 
*/
