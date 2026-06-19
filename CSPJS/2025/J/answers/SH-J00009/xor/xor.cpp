#include<bits/stdc++.h>
using namespace std;
//xor
int n,k;

struct L{
	int x;
	int a,b;
};

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool A=1,B=1,C=1,F=0;
	int cnt1=0,cnt0=0;
	cin>>n>>k;
	
	
	vector<vector<bool>> val(n+1,vector<bool>(n+1,0));
	vector<int> a(n+1,0);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&A){
			A=0;
		}
		if(a[i]!=0&&a[i]!=1&&B){
			B=0;
		}
		if(B){
			if(a[i]==1){
				cnt1++;
			}else cnt0++;
		}
		
		//ÄÃ±©Á¦ 
			for(int k=0;k<=i;k++){
				int t=a[i] xor a[k];
				if(t==k){
					val[i][k]=1;
					//cout<<"FUCK\n";
				}
			}
		
		
	}
	
	if(k==0&&A){
		cout<<n/2;
		return 0;
	}
	
	if(B){
		if(k==1){
			cout<<max(min(cnt1,cnt0),cnt1);
		}else if(k==0){
			cout<<cnt1/2+cnt0;
		}
		return 0;
	}

	vector<vector<int>> ans(n+1,vector<int>(n+1,0);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(val[i][j]||val[j][i]){
				ans[i][j]++;
			}else{
				ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
			}
		}
	}
	
	//cout<<"Fuck!";
	//cout<<"Baka¢á";
	cout<<ans[n][n];
	return 0;
}
