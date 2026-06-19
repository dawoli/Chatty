#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
long long n,k,a[500050],sum[500050],l,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(a[i]^sum[i-1]);
	}
	l=1;
	for (int i=1;i<=n;i++){
		for (int j=i;j>=l;j--){
			if ((sum[i]^sum[j-1])==k){
				//cout<<(sum[i]^sum[j-1])<<" "<<i<<" "<<j<<endl;
				//cout<<i<<j; 
				l=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
