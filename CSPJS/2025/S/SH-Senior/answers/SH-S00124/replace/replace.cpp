#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	string a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		mp[a]=b;
	}
	int sum=0;
	for(int iu=0;iu<q;iu++){
		cin>>a>>b;
		sum=0;
		int i=0,j=a.size()-1;
		while(a[i]==b[i])i++;
		while(a[j]==b[j])j--;
		int t=0,d=j;
		for(t;t<=i;t++){
			for(d=j;d<=a.size()-1;d++){
				if(mp[a.substr(t,d-t+1)]==b.substr(t,d-t+1)){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
