#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,ans;
int d[500009];
int s[500009];
void solveBF(){
	int i=0,j=1;
	for(;j<=n;j++){
		while(i<j){
			if((s[i]^k)==s[j]){
				ans++;
				i=j;
				break;
			}
			i++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^d[i];
	}
	if(n<=5000){
		solveBF();
		return 0;
	}
	multiset<int> st;
	st.insert(s[0]);
	for(int i=1;i<=n;i++){
		int u=s[i]^k;
		if(st.count(u)==0){
			st.insert(s[i]);
			continue;
		}
		cnt++;
		st.clear();
		st.insert(s[i]);
	}
	cout<<cnt;
	return 0;
}
