#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll n , q;
struct node{
	string a , b;
	
} to[200009];
ll nm[29];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(ll i = 1; i <= n; i++){
		//scanf("%s %s",&to[i].a,&to[i].b);
		cin >> to[i].a >> to[i].b;
	}
	while(q--){
		string qa , qb;
		//scanf("%s %s",&qa,&qb);
		cin >> qa >> qb;
		ll sum = 0;
		for(ll i = 1; i <= n; i++){
			ll ok = 0 , flag = 0;
			string a = to[i].a , b = to[i].b;
			if(a.length() > qa.length()) continue;
			for(ll j = 1; j <= qa.length() - a.length() + 1; j++){
				if(qa[j-1] == a[0] && qb[j-1] == b[0] && ok == 0){
					ll cnt = 1;
					while(a[cnt-1] == qa[j - 1 + cnt - 1] && b[cnt-1] == qb[j - 1 + cnt - 1] && cnt <= a.length()){
						if(qa[j - 1 + cnt - 1] != qb[j - 1 + cnt - 1]) flag = 2;
						cnt++;
					}
					if(cnt > a.length()){
						ok = 1;
						j = j - 1 + cnt - 1;
					}
					else{
						if(flag == 2) break;
					}
					flag = 0;
				}
				else if(qa[j-1] != qb[j-1]){
					flag = 1;
					break;
				}
			}
			if(flag == 0 && ok == 1) sum++;
		}
		cout << sum << endl;
	}
	return 0;
} 
