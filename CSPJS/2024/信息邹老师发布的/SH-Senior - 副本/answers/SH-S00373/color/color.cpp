#include <bits/stdc++.h>
using namespace std;
stack<int> st1,st2;
bool vis[20][20];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		for(int i=0;i<=19;i++){
			for(int j=0;j<=2;j++){
				vis[i][j]=false;
			}
		}
		int ans=0;
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			int x;
			cin >> x;
			if(vis[x][1]){
				while(st1.top()!=x){
					int k=st1.top();
					st2.push(k);
					st1.pop();
				}
				st1.pop();
				vis[x][1]=0;
				ans+=x;
			}
			
			else if(vis[x][2]){
				while(st2.top()!=x){
					int k=st2.top();
					st2.push(k);
					st2.pop();
				}
				st2.pop();
				vis[x][2]=0;
				ans+=x;
			}
			
			else{
				st1.push(x);
				vis[x][1]=1;
			}
		}
		cout << ans << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
