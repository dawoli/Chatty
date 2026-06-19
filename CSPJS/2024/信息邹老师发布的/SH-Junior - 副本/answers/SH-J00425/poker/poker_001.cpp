#include<bits/stdc++.h> 
using namespace std;
long long n,p;
string x,s[100];
bool f;
int main(){
	freopen("poker.in","r",stdin); 
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		f=1;
		for(int j=1;j<i;j++){
			if(x==s[j]){
				f=0;
				break;
			}
		}
		if(f){
			p++;
			s[p]=x;
		}
	}
	cout<<52-p;
	return 0;
}
