#include<bits/stdc++.h> 
using namespace std;
int t,ans[6];
int n,k,q,s[1001][10001],len[20001],r[1001],c[10005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	for(int qq=0;qq<t;qq++){
		cin >> n >> k >> q;
		
		for(int i=0;i<n;i++){
			cin >> len[i];
			for(int j=0;j<len[i];j++)cin>>s[i][j];
		}
		for(int i=0;i<q;i++)cin >> r[i] >> c[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				if(s[i][j]==c[i])ans[qq] = 1;
			}
		}
	}
	for(int i=0;i<t;i++){
		cout << ans[i] << endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
