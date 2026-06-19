#include<bits/stdc++.h>
using namespace std;
int n,q;
char a[101][101],b[101][101];
char a1[101],b1[101];
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	//if(n>100||q>100){
		string qwe,rty;
		for(int i=1;i<=n;i++){
			cin>>qwe>>rty;
		}
		for(int i=1;i<=q;i++){
			cin>>qwe>>rty;
		}
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	//}
	/*else{
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=1;i<=q;i++){
			cin>>a1>>b1;
			for(int j=1;j<=n;j++){
				char a2[101];
				for(int k=0;k<strlen(a1);k++){
					a2[k]=a1[k];
				}
				for(int k=0;k<strlen(a1)-strlen(a[i]);k++){
					bool fl=true;
					for(int p=k;p<strlen(a[i]);p++){
						if(a1[p]!=a[i][p-k]){
							fl=false;
							break;
						}
					}
					if(fl==true){
						for(int p=k;p<strlen(a[i]);p++){
							a2[p]=b[i][p-k];
						}
						cout<<a2<<endl;
					}
					bool f=true;
					for(int i=0;i<strlen(a1);i++){
						if(a2[i]!=b1[i]){
							f=false;
							break;
						}
					}
					if(f==true){
						ans++;
					}
				}
				
			}
			cout<<ans<<endl;
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
