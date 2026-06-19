#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,m,a[109],x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int now=1;
	for(int i=1;i<=n;){
		for(int j=1;j<=m;j++){
			if(a[now]==x){
				cout<<i<<' '<<j<<endl;
				return 0;
			}
			now++;
		}
		i++;
		if(i>n) break;
		for(int j=m;j>0;j--){
			if(a[now]==x){
				cout<<i<<' '<<j<<endl;
				return 0;
			}
			now++;
		}
		i++;
	}
	return 0;
}
