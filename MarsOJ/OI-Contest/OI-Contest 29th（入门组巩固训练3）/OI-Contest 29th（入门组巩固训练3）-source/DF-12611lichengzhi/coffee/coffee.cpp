#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
long long t,n,m;
string str;
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin >> t;
	while(t--){
		long long sum=0;
		int cnt[6]={0};
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				cin >> str;
				if(str=="math"){
					cnt[i]++;
					cnt[0]++;
				}
			}
		}
		cin >> n >> m;
		for(int i=m;i<=7;i++)if(i<=5)sum+=cnt[i];
		n-=(7-m+1);
		sum+=n/7*cnt[0];
		n%=7;
		for(int i=1;i<=n;i++)if(i<=5)sum+=cnt[i];
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
