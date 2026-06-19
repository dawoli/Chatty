#include<iostream>
#include<algorithm>
typedef unsigned long long ull;
using namespace std;
int n,T;int a[10]={6,2,5,-1,4,-1,6,3,7,-1},ans;
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
		for(ull i=n/10+1;;++i){
			s=i,ans=0;
			while(s){
				if(a[s%10]==-1){
					goto e;
				}
				else ans+=a[s%10];
				s/=10;
			}
			if(ans==n){
				cout<<i<<'\n';
				break;
			}
			e:1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
