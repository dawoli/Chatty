#include<bits/stdc++.h>
using namespace std;
#define int long long
struct A{
	int a,b,c;
	bool operator > (const A x) const {
		if(a - max(b,c) != x.a - max(x.b,x.c))return a - max(b,c) > x.a - max(x.b,x.c);
		else return a - min(b,c) > x.a - min(x.b,x.c);
	}
};struct B{
	int a,b,c;
	bool operator > (const B x) const {
		if(b - max(a,c) != x.b - max(x.a,x.c))return b - max(a,c) > x.b - max(x.a,x.c);
		else return b - min(a,c) > x.b - min(x.a,x.c);
	}
};struct C{
	int a,b,c;
	bool operator > (const C x) const {
		if(c - max(b,a) != x.c - max(x.b,x.a))return c - max(b,a) > x.c - max(x.b,x.a);
		else return c - min(b,a) > x.c - min(x.b,x.a);
	}
};
const int N = 2e5+5;
int t,n,ans;
int a[N][5];
bool flagB=1,flagC=1;
//priority_queue<A,vector<A>,greater<A>> clubA;
//priority_queue<B,vector<B>,greater<B>> clubB;
//priority_queue<C,vector<C>,greater<C>> clubC;
void taskBC(){
	priority_queue<A,vector<A>,greater<A>> clubA;
	for(int i = 1;i <= n;i++){
		clubA.push({a[i][1],a[i][2],a[i][3]});
		ans += a[i][1];
		if((int)clubA.size()>n/2){
			ans -= clubA.top().a;
			clubA.pop();
		}
	}
	cout << ans << "\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);//Don't forget freopen(stdin)!
	freopen("club.out","w",stdout);//Don't forget freopen(stdout)!
	cin >> t;
	while(t--){
		ans = 0;
		priority_queue<A,vector<A>,greater<A>> clubA;
		priority_queue<B,vector<B>,greater<B>> clubB;
		priority_queue<C,vector<C>,greater<C>> clubC;
		cin >> n;
		flagB = 1;flagC = 1;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int lka = a[i][1],lkb = a[i][2],lkc = a[i][3];
			if(lkb) flagB = 0;
			if(lkc) flagC = 0;
		}
		if(flagB && flagC){
			taskBC();
			continue;
		}
		for(int i = 1;i <= n;i++){
			int lka = a[i][1],lkb = a[i][2],lkc = a[i][3];
			if(lka >= lkb && lka >= lkc){
				clubA.push({lka,lkb,lkc});
				ans += lka;
//				cout << "ain";
//				if((int)clubA.size() > (n>>1)){
//					auto ccb = clubA.top();clubA.pop();
//					ans -= ccb.a;
//					if(ccb.b > ccb.c){
//						clubB.push({ccb.a,ccb.b,ccb.c});
//						ans += ccb.b;
//					}else{
//						clubC.push({ccb.a,ccb.b,ccb.c});
//						ans += ccb.c;
//					}
//				}
			}else if(lkb >= lkc && lkb >= lka){
				clubB.push({lka,lkb,lkc});
//				cout << "B in\n";
				ans += lkb;
//				if((int)clubB.size() > (n>>1)){
//					auto ccb = clubB.top();clubB.pop();
//					ans -= ccb.b;
////					cout << "B out " << ccb.a << ccb.b << ccb.c << "\n"; 
//					if(ccb.a > ccb.c){
//						clubA.push({ccb.a,ccb.b,ccb.c});
//						ans += ccb.a;
//					}else{
//						clubC.push({ccb.a,ccb.b,ccb.c});
//						ans += ccb.c;
//					}
//				}
			}else{
				clubC.push({lka,lkb,lkc});
				ans += lkc;
//				if((int)clubC.size() > (n>>1)){
//					auto ccb = clubC.top();clubC.pop();
//					ans -= ccb.c;
//					if(ccb.a > ccb.b){
//						clubA.push({ccb.a,ccb.b,ccb.c});
//						ans += ccb.a;
//					}else{
//						clubB.push({ccb.a,ccb.b,ccb.c});
//						ans += ccb.b;
//					}
//				}
			}
		}
		while((int)clubA.size() > (n>>1)){
			auto ccb = clubA.top();
			clubA.pop();
			ans -= ccb.a;
			if(ccb.b > ccb.c){
				ans += ccb.b;
			}else{
				ans += ccb.c;
			}
		}while((int)clubB.size() > (n>>1)){
			auto ccb = clubB.top();
			clubB.pop();
			ans -= ccb.b;
			if(ccb.a > ccb.c){
				ans += ccb.a;
			}else{
				ans += ccb.c;
			}
		}while((int)clubC.size() > (n>>1)){
			auto ccb = clubC.top();
			clubC.pop();
			ans -= ccb.c;
			if(ccb.a > ccb.b){
				ans += ccb.a;
			}else{
				ans += ccb.b;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

