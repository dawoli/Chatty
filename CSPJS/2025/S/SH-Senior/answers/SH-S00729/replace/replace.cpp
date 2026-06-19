#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
string s1[200005],s2[200005];
string q1,q2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>q1>>q2;
		if(q1.size()!=q2.size()){
			cout<<"0\n";
			continue;
		}
		int cnt=0;
		for(int k=0;k<n;k++){
			for(int j=0;j+s1[k].size()<=q1.size();j++){
				string x=q1.substr(0,j),y=q1.substr(j,s1[k].size()),z=q1.substr(j+s1[k].size());
				string x1=q2.substr(0,j),y1=q2.substr(j,s1[k].size()),z1=q2.substr(j+s1[k].size());
//				cout<<k<<' '<<x<<' '<<x1<<' '<<y<<' '<<y1<<' '<<'z'<<' '<<z1<<'\n'; 
				if(x==x1&&z==z1&&s1[k]==y&&s2[k]==y1) cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

