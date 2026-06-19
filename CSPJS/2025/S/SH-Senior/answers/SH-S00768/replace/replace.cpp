#include <bits/stdc++.h>
using namespace std;

string s1[200005],s2[200005],t1,t2;

bool check(int l,int r,string y_1,string y_2){
	string a1,a2;
	for(int i=l;i<=r;i++){
		a1+=y_1[i];
		a2+=y_2[i];
		if(a1==t1&&a2==t2){
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	cin>>t1>>t2;
	if(q==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s1[i]==t1&&s2[i]==t2){
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			string y_1=s1[i],y_2=s2[i];
			for(int j=0;j<y_1.size();j++){
				if(y_1[j]!=y_2[j]){
					for(int k=1;k+j<y_1.size();k++){
						if(check(j,k,y_1,y_2)){
							ans++;
						}
					}
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
