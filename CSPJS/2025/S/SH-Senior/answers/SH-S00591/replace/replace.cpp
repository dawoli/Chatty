#include<iostream>
#include<cstring>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int k=a.size(),cnt=0;
		for(int i=0;i<k-1;i++){
			for(int j=i+1;j<k;j++){
				string y="",z="",o="",p="";
				for(int x=i;x<=j;x++){
					y+=a[x],z+=b[x];
				}
				for(int x=0;x<i;x++){
					o+=a[x];
				}
				for(int x=j+1;x<k;x++){
					p+=a[x];
				}
				if(o+y+p!=a||o+z+p!=b) continue;
				for(int i=1;i<=n;i++){
					if(s1[i]==y&&s2[i]==z) cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
