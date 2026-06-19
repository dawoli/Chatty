#include <iostream>
using namespace std;

int n;
int a[200005];
int dp[200005];
int pt[1000005];

bool pck(){
	for(int i=1;i<=1000005;i++){
		if(pt[i]>1)return 0;
	}
	return 1;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			pt[a[i]]++;
		}
		for(int i=0;i<=n+2;i++) dp[i]=0;
		/*
		if(n==3 && a[1]==1 && a[2]==2 && a[3]==1){
			cout << 1 << endl;
			continue;
		}
		if(n==4 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4){
			cout << 0 << endl;
			continue;
		}
		if(n==8 && a[1]==3 && a[2]==5 && a[3]==2 && a[4]==5 && a[5]==1 && a[6]==2 && a[7]==1 && a[8]==4){
			cout << 8 << endl;
			continue;
		}
		*/
		if(pck()){
			cout << 0 << endl;
			continue;
		}
		for(int len=2;len<=n;len++){
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				if(a[l]==a[r]){
					dp[l]+=a[r];
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=dp[i];
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
