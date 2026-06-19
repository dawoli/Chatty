#include<bits/stdc++.h>
using namespace std;
bool flag[128][128];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(flag,false,sizeof(flag));
	cin>>n;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		if(flag[int(a[0])][int(a[1])]) n--;
		flag[int(a[0])][int(a[1])]=true;
	}
	cout<<52-n;
	return 0;
}
