#include<bits/stdc++.h> 
using namespace std;

int main(){
	
	int a[105],b,cnt=0,k=0;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>b;
	for(int i=0;i<=b;i++){
		cin>>a[i];
		k=0;
		for(int j=1;j<=i;j++){
			if(a[i]==a[j]){
				k=1;
			}
			if(k==1)break;
		}
		if(k==0)cnt++;
	}
	cout<<(52-cnt);
	
	for(int i=0;i<=b;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}
