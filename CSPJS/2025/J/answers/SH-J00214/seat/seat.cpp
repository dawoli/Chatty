#include<bits/stdc++.h>
using namespace std;
int a[110],xiao_R,pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	cin >> xiao_R;
	for(int i=2;i<=n*m;i++){
		int sc;
		cin >> sc;
		a[sc]++;
	} 
	for(int i=100;i>=1;i--){
		if(a[i]!=0 && xiao_R<i) pm++;
		if(xiao_R==i) break;
	}
	int num=pm/n;
	pm-=num*n;
	cout << num+1 << " ";
	if((num+1)%2==0){
		cout << n+1-pm;
	}else{
		cout << pm;
	}
	return 0;
}
