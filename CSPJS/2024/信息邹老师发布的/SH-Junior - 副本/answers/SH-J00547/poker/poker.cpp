#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin)
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int t=52;
	int a[n];
	for(int i=1;i<=n;i++){
	    cin>>a[i]; 
	    t--;
	}
	cout<<t;
  return 0;
}
