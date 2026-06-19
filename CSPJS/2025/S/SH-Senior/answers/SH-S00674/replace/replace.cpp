#include<bits/stdc++.h>
using namespace std;

int n,q;
string a[1010],b[1010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	while(q--){
		string s1,s2;
		cin >> s1 >> s2;
		int ans=0;
		if(s1.size()!=s2.size()){
			cout << ans;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<s1.size();j++){
				if(s1[j]==a[i][0]){
					int flag=0;
					for(int k=j;k<j+a[i].size();k++){
						if(s1[k]!=a[i][k-j]){
							flag=1;
						}
					}
					if(flag==0){
						string s3;
						s3=s1;
						for(int l=j;l<j+a[i].size();l++){
							s3[l]=b[i][l-j];
						}
						if(s3==s2){
							ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
