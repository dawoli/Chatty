#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt=0;
int a[500010];
vector<int> pos; 
bool v_find(int n){
	for(int i=0;i<pos.size();i++)
		if(n==pos[i]) return true;
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			pos.push_back(i);
		}
	}
	for(int i=0;i<n;i++){
		int sum=a[i];
		if(v_find(i)) continue;
		for(int j=i+1;j<n;j++){
			if(v_find(j)) break;
			sum^=a[j];
			if(sum==k){
				cnt++;
				i=j-1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
