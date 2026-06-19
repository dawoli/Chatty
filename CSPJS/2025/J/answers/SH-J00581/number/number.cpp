#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a;
int cnt[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for (int i=0;i<n;i++){
		if (a[i]>='0' && a[i]<='9'){
			cnt[a[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		while (cnt[i]){
			cout<<i;
			cnt[i]--;
		}
	}
}
