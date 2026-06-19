#include<bits/stdc++.h>
using namespace std;
const int O=1e6+5;
int T,n,a;
long long cnt;
int ranse[O];
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a;
			if(ranse[a]>0)cnt=cnt+a;
			ranse[a]++;
		}
		cout<<cnt;
	}
	return 0;
}
