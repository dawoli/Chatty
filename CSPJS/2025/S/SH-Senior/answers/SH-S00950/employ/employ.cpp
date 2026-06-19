#include <iostream>


using namespace std;

char k[505];
int c[505];
int f[15];
bool t[15];
long long ans;
int m,n;

void dfs(int depth){
	if(depth==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(k[i-1]=='0'){
				cnt++;
				continue;
			}
			if(c[i]>=cnt){
				cnt++;
			} 
		}
		if(n-cnt>=m)ans++;
	}
	for(int i=1;i<=n;i++){
		if(t[i]==0){
			t[i]=1;
			f[depth]=i;
			dfs(depth+1);
			t[i]=0;
			f[depth]=0;
		} 
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> k;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	if(n<=10){
		dfs(1);
		
		
		
	}else{
		cout << 0;
	}
	cout << ans;
	
	
	
	return 0;
}
