#include<bits/stdc++.h>
using namespace std;
string s[200001][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int m,n,ans=0;
	string q1,q2;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>s[i][0]>>s[i][1];
		
	}
	for(int i=0;i<n;i++){
		ans=0;
		
		cin>>q1>>q2;
	string 	x="!",y,z="?";
		for(int j=0;j<m;j++){
			int k=0;
			while(q1.find(s[j][0],k)<q1.size()){
				string x1=x,z1=z;
				x="",z="";
				int kk=q1.find(s[j][0],k);
				for(int l=0;l<kk;l++){
					x+=q1[l];
				}
					for(int l=kk+s[j][0].size();l<q1.size();l++){
					z+=q1[l];
				}
				y=s[j][1];
				if(x+y+z==q2&&x!=x1&&z!=z1){
				ans++;	
				}
				k=kk+s[j][0].size();	
			}
		}
		printf("%d\n",ans);
	}

return 0;
}
