#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,sum[200005][2],stk[200005];
string s[200005][2],st1,st2;
int check(int l,int r){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i][0].size()!=r-l+1){
			continue;
		} 
		bool flag=true;
		for(int j=l;j<=r;j++){
			if(st1[j]!=s[i][0][j-l]||st2[j]!=s[i][1][j-l]){
				flag=false;
				break;
			} 
		}
		if(flag) cnt++;
	}
	return cnt;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	int ccnt=0;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
		int len=s[i][0].size();
		ccnt+=len;
		for(int j=0;j<len;j++){
			if(s[i][0][j]=='b'){
				sum[i][0]=j;
			}
			if(s[i][1][j]=='b'){
				sum[i][1]=j;
			}
		}
		stk[i]=len;
	}
	while(q--){
		cin >> st1 >> st2;
		int len=st1.size(),lenn=st2.size();
		if(len!=lenn){
			cout << 0 << endl;
			continue;
		}
		if(ccnt>1000){
			int ress=0;
			int l,r;
			for(int i=0;i<len;i++){
				if(st1[i]=='b'){
					l=i;
					break;
				}
			}
			for(int i=0;i<len;i++){
				if(st2[i]=='b'){
					r=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(l>=sum[i][0]&&n-l-1>=stk[i]-sum[i][0]-1&&r>=sum[i][1]&&n-r-1>=stk[i]-sum[i][1]-1&&l-sum[i][0]+sum[i][1]==r&&n-r-1==n-l-stk[i]+sum[i][0]+stk[i]-sum[i][1]-1){
					ress++;
				}
			}
			cout << ress << endl;
			continue;
		}
		int l,r;
		for(int i=0;i<len;i++){
			if(st1[i]!=st2[i]){
				l=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(st1[i]!=st2[i]){
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=0;i<=l;i++){
			for(int j=r;j<len;j++){
				ans+=check(i,j);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
