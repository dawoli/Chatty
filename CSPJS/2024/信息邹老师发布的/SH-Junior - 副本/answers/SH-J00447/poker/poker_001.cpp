#include<bits/stdc++.h>
using namespace std;
long long a=52,n;
int main(){
	freopen("poker.in","r", stdin);
	freopen("poker.out","w", stdout);

	string mq[1000000],x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		for(int j=0;j<n;j++){
			if(x!=mq[j]){
				mq[i]=x;
				a-=1;
				break;
			}
			else{
				break;
			}

	}
	}
	cout<<a;
	return 0;
}

