#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt=52;
map<string,bool> m;
string s;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(m[s]==0){
			cnt--;
			m[s]=1;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
//ÎÒÓÀÔ¶Ï²»¶çæ¶äÀò
/*
2024-PJ-T1 
Ã»É¶ºÃËµµÄ	
*/
