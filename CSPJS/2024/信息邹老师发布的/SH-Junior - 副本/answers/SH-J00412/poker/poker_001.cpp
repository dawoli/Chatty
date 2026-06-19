#include<bits/stdc++.h>

using namespace std;
int n;
string p[107];
int ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ans++;
		for(int j=1;j<i;j++){
			if(p[j]==p[i]){
				ans--;
				break;
			}
		}
	}
	cout<<52-ans;
	return 0;
}
