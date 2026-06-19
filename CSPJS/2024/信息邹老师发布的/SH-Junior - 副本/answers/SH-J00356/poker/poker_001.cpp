#include<bits/stdc++.h>
using namespace std;
bool d['Z'+1]['Z'+1];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		if(!d[a][b]){
			d[a][b]=1;
			cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
}
