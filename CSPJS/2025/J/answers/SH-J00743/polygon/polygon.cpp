#include <iostream>
#include <set>
using namespace std;

const int mod=998244353;
int n;
int a[5005];
set<int> se;
void dfs(int x,int cho,int tot,int mx,int st){
	if(cho>=3&&tot>mx*2){
		se.insert(st);
	}
	if(x>n) return;
	dfs(x+1,cho,tot,mx,st);
	dfs(x+1,cho+1,tot+a[x],max(mx,a[x]),st|(1<<(x-1)));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,0,0,0,0);
	cout << se.size() << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
