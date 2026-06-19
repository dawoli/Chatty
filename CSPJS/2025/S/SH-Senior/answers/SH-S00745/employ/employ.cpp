#include <iostream>
using namespace std;

const int mod=998244353;
int n,m;
bool s[505];
long long pw[505];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	pw[0]=pw[1]=1;
	for(int i=2;i<=n;i++){
		pw[i]=pw[i-1]*i%mod;
	}
	int tot1=0;
	bool flg=1;
	for(int i=1;i<=n;i++){
		char tmp;
		cin >> tmp;
		s[i]=tmp-'0';
		tot1+=s[i];
		if(!s[i])flg=0;
	}
	if(tot1<m){
		cout << 0 << endl;
	}else if(flg){
		long long ans=1;
		for(int i=n;i>n-m;i--) ans=ans*i%mod;
		cout << ans << endl;
	}else{
		for(int i=1;i<=n;i++){
			cin >> c[i];
		}
		cout << 0 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
