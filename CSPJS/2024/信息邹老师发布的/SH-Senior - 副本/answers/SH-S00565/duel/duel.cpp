#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> r;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	for (int i=0,ri; i<n; i++) {
		cin>>ri;
		r.push_back(ri);
	}
	sort(r.begin(),r.end());
	int i=0,j=1,cnt=n;
	while (j<n){
		while (j<n and r[j]==r[i]) j++;
		if (j<n) cnt--;
		i++;
		j++;
	}
	
	cout<<cnt<<'\n';
}
