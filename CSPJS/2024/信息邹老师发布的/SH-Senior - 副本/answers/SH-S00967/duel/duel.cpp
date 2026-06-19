#include<bits/stdc++.h>
#define long long ll
#define unsigned long long ull
using namespace std;
int a[100005];
int flag[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int a1=0,a2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			a1++;
		}
		else{
			a2++;
		}
	}
	if(a1>a2){
		cout<<a1-a2+a2;
	}
	else if(a1==a2){
		cout<<a2;
	}
	else{
		cout<<a2;
	}
	return 0;
}
