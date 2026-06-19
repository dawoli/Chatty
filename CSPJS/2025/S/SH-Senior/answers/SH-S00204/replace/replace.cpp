#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
string s[200005][3];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()) cout<<"0";
		else{
			int len=a.size(),ans=0;
			string qz="",hz="";
			for(int i=0;i<len;i++){
				if(a[i]==b[i]) qz+=a[i];
				else break;
			}
			for(int i=len-1;i>=0;i--){
				if(a[i]==b[i]) hz+=a[i];
				else break;
			}
			reverse(hz.begin(),hz.end());
			if(qz==""&&hz==""){
				for(int j=1;j<=n;j++){
					if(s[j][1]==a&&s[j][2]==b) ans++;
				}
				cout<<ans;
			}
			else{
				for(int j=1;j<=n;j++){
					int lena=s[j][1].size();
					string save=s[j][2];
					for(int k=0;k<=len-lena;k++){
						string sss=a,is="";
						for(int h=k;h<=k+lena-1;h++){
							is+=a[h];
						}
						if(is==s[j][1]){
							for(int h=0;h<=lena-1;h++){
								sss[h+k]=save[h];
							}
						}
						if(sss==b) ans++;
					}
				}
				cout<<ans;
			}
		}
		cout<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
