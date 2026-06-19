#include<bits/stdc++.h>
using namespace std;
	
int n,k,a[500005],dp[10005][10005],ans=0;;



struct node{
	int x,y;
};

vector<node> num; 

int cmp(node x, node y){
	if(x.y!=y.y){
		return x.y < y.y;
	}else{
		return x.x < y.x;
	}
}

/*void dfs(int s,int step){
	if(s>n)return;
	if(step>=ans){
		ans=step;
	}
	for(int i=s;i<=n;i++){
		if(dp[s][i]==k){
			cout << s << " " << i << endl;
			dfs(i+1,step+1);
		}else{
			dfs(i+1,step);
		}
	} 
}*/

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		dp[1][i]=a[i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[j][i]=dp[j][i-1];
			dp[j][i] ^=a[i];
			if(dp[j][i]==k){
				num.push_back({j,i});
			}
		}
	}
	sort(num.begin(),num.end(),cmp);
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << dp[i][j] << " (" << i << "," << j << ") " ;
		}
		cout << endl;
	}*/
	/*for(int i=0;i<num.size();i++){
		cout << num[i].x << " " << num[i].y << " | ";
	}*/
	node now={-1,-1};
	//cout << endl;
	
	for(int i=0;i<num.size();i++){
		if(num[i].x > now.y){
			now=num[i];
						//cout << now.x << ' ' << now.y << endl;
			ans++;
		}
	}
	//dfs(1,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

