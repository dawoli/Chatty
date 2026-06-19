#include<bits/stdc++.h>
using namespace std;
int n,ans=52;string s;
map<string,bool> m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(m[s]) continue;
		m[s]=true;
		ans--;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
