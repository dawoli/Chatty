#include <bits/stdc++.h>
using namespace std;
int n=0,a[100005]={0};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int x=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	int atk=0;
	for(int i=1;i<=100000;i++){
		if(a[i]){
			atk=max(atk-a[i],0);
			atk+=a[i];
		}
	}
	cout<<atk<<endl;
	return 0;
} 

