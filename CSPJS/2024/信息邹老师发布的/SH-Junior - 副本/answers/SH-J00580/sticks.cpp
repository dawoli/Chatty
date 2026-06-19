#include<iostream>
#include<algorithm>
typedef unsigned long long ull;
using namespace std;
int n,T;int a[10]={6,2,5,5,4,5,6,3,7,6},ans;
ull s;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin >> n;ans=0;
		if(n<2){
			cout<<"-1\n";continue;
		}
		for(ull i=0;;++i){
			s=i,ans=0;
			while(s){
				ans+=a[s%10];
				s/=10;
			}
			if(ans==n){
				cout<<i<<'\n';
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
