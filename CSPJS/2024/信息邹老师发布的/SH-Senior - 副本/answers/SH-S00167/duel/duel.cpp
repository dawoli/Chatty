#include <bits/stdc++.h>
using namespace std;
int n,m,i,p,o,most,ans,eatnum,lst,rmn,jian;
int r[100001];
int sm[100001];
int cntn[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	ans = n;
	for (i=0;i<n;i++)cin >> r[i];
	sort(r,r+n);//small to big
	//smallest
	lst = 2;
	for (i=0;i<n+10;i++)sm[i]=0;
	while (sm[lst] != n){
		//cout << sm[lst-1];
		for (i=sm[lst-1];i<=n;i++){
			if (r[i] != r[sm[lst-1]] or i==n){
				sm[lst] = i;
				cntn[lst] = sm[lst]-sm[lst-1];
				lst++;
				break;
			}
		}
		rmn = cntn[lst-1];
		for (p=lst-1;p>=2;p--){
			jian = min(rmn,cntn[p-1]);
			cntn[p-1]-=jian;
			rmn-=jian;
			if (rmn==0)break;
		}
		eatnum = cntn[lst-1]-rmn;
		//cout << eatnum << endl;
		if (i==n){
			if (sm[lst-2] != 0)ans -= eatnum;
			break;
		}
		//new level
		if (sm[lst-2] != 0)ans -= eatnum;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

