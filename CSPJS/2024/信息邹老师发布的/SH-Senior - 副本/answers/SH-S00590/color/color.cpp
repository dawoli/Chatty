#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int n,T,cnt;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int g=1;g<=T;g++){
		for(int i=1;i<1000010;i++){
			a[i]=0;
		}
		cnt=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]){
				cnt=cnt+a[i];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
