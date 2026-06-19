#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
}u[200005];
string s1,s2,s3;
bool check(int i,int j){
	if(s1.size()-i<u[j].a.size())return 0;
	for(int k=0;k<u[j].a.size();k++){
		if(s1[i]!=u[j].a[k])return 0;
		i++;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>u[i].a>>u[i].b;
	}
	while(q--){
		int ans=0;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
			s3=s1;
			for(int j=1;j<=n;j++){
				if(check(i,j)){
					int ni=i;
					for(int k=0;k<u[j].b.size();k++){
						s3[ni]=u[j].b[k];
						ni++;
					}
					if(s3==s2){
						ans++;
					}
				}
				s3=s1;
			}
		}
	cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

