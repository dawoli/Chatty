#include<bits/stdc++.h>
using namespace std;
string a[52];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		bool bol = true;
		for(int j = 0;j<i;j++){
			if(a[j] == a[i]){
				bol = false;
			}
		}
		if(bol){
			cnt += 1;
		}
		
	}
	cout<<52-cnt;
	return 0;
}
