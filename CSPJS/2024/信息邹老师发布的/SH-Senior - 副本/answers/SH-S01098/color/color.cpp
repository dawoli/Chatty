#include<iostream>
#include<algorithm>
using namespace std;

inline int read(){
	int xnum=0,fuhao=1;
	char c = getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c = getchar();
	if (c=='-'){
		fuhao = -1;
		c = getchar();
	}
	while (c>='0'&&c<='9'){
		xnum = xnum*10+c-'0';
		c = getchar();
	}
	return xnum*fuhao;
}


const int MAXN = 1000050;
int T,n;
int dp[MAXN];
int a[MAXN];

int main(){
	
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	
	T = read();
	while (T--){
		
		n = read();
		for (int i=1;i<=n;i++){
			a[i] = read();
		}
		
		dp[0] = 0;
		dp[1] = 0;
		
		for (int i=1;i<=n;i++){
			
			
			int maxred=0;
			for (int j=0;j<i;j++){
				if (a[j]==a[i]){
					maxred = max(maxred,dp[j]+a[i]);
					
				}else{
					maxred = max(maxred,dp[j]);
				}
				dp[i] = maxred;
				if (a[i]==a[i-1]&&j!=i-1){
					dp[j]+=a[i];
				}
			}
			
		}
		cout<<dp[n]<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}



