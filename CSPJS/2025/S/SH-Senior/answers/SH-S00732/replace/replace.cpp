#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
pair<string,string>rep[N];
string t1,t2;
int solve(){
	cin>>t1>>t2;
	if(t1.size()!=t2.size())return 0;
	int f=N,b=N;
	for(int i=0;i<t1.size();i++){
		if(t1[i]!=t2[i]){
			f=i;
			break;
		}
	}
	for(int i=t2.size();i>=f;i--){
		if(t1[i]!=t2[i]){
			b=i;
			break;
		}
	}
	int ans=0; 
	for(int i=1;i<=n;i++){
		if(rep[i].first.size()<b-f+1)continue;
		if((~t1.find(rep[i].first))&&(~t2.find(rep[i].second))){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>rep[i].first>>rep[i].second;
	while(m--)cout<<solve()<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
