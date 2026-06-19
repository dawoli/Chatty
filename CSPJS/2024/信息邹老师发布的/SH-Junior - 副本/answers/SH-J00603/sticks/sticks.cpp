#include<bits/stdc++.h>
using namespace std;
int n;
int dbf[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int db[7]={108,188,200,208,288,688,888};
int main(){
	cin.tie(nullptr);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=14){
			cout<<dbf[n];
		}else{
			n-=15;
			cout<<db[n%7];
			n/=7;
			for(int i=1;i<=n;i++){
				cout<<8;
			}
		}
		cout<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
