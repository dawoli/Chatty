#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
struct T{
	int a, b, c;
} k[100005];
bool flagA=true, flagB=true;
bool cmpA(T a1, T a2){
	if(a1.a>a2.a){
		return true;
	}
	else{
		return false;
	}
}
void dfsB(int acnt, int bcnt, int step, int tot){
	if(step==n){
		ans=max(ans, tot);
		return;
	}
	if(acnt>0){
		dfsB(acnt-1, bcnt, step+1, tot+k[step+1].a);
	}
	if(bcnt>0){
		dfsB(acnt, bcnt-1, step+1, tot+=k[step+1].b);
	}
	if(acnt==0&&bcnt==0){
		dfsB(acnt, bcnt, step+1, tot+=k[step+1].c);
	}
}
void dfsC(int acnt, int bcnt, int ccnt, int step, int tot){
	if(step==n){
		ans=max(ans, tot);
		return;
	}
	if(acnt>0){
		dfsC(acnt-1, bcnt, ccnt, step+1, tot+k[step+1].a);
	}
	if(bcnt>0){
		dfsC(acnt, bcnt-1, ccnt, step+1, tot+k[step+1].b);
	}
	if(ccnt>0){
		dfsC(acnt, bcnt, ccnt-1, step+1, tot+k[step+1].c);
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ans=0;
		cin >> n;
		int cnt=n/2;
		flagA=true;
		flagB=true;
		memset(k, 0, sizeof(k));
		for(int i=1; i<=n; i++){
			cin >> k[i].a >> k[i].b >> k[i].c;
			if(k[i].b!=0){
				flagA=false;
			}
			if(k[i].c!=0){
				flagA=false;
				flagB=false;
			}

		}
		if(flagA){
			int idx=1;
			sort(k+1, k+n+1, cmpA);
			while(cnt--){
				ans+=k[idx].a;
				idx++;
			}
		}
		else if(flagB){
			dfsB(cnt, cnt, 0, 0);
		}
		else{
			dfsC(cnt, cnt, cnt, 0, 0);
		}
		cout << ans << "\n";
	}

	return 0;
}
