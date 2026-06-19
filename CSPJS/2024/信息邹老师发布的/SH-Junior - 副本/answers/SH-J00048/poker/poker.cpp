#include<bits/stdc++.h>

using namespace std;

int n,cnt=52;
string s[55],t;
bool b;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		b=1;
		for(int j=0;j<i;j++){
			if(s[j]==t) {
				b=0;
				break;
			}
		}
		if(b){
			s[i]=t;
			cnt--;
		} 
	}
	cout<<cnt; 
	return 0;
}

