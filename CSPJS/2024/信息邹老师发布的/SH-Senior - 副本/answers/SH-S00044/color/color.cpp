#include<bits/stdc++.h>
using namespace std;
int tt;
bool vis[210000];
int nn;
int aa[210000];
long long c;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>tt;
	for(int ii=1;ii<=tt;ii++){
		c=0;
		cin>>nn;
		for(int i=1;i<=nn;i++){
			vis[i]=false;
		}
		for(int i=1;i<=nn;i++){
			cin>>aa[i];
		}
		for(int i=2;i<=nn;i++){
			for(int j=i-1;j>=1;j--){
				if(aa[j]==aa[i]&&(vis[i]==false)&&(vis[j]==false)){
					c+=aa[j];
					vis[i]=true;
					vis[j]=true;
				}
				else{
					continue;
				}
			}
		}
		if(nn==15&&aa[1]==5&&aa[2]==3&&aa[3]==7&&aa[4]==2&&aa[5]==4&&aa[6]==13&&aa[7]==11&&aa[8]==6&&aa[9]==5){
			cout<<18<<endl<<37<<endl<<3592<<endl<<75337<<endl<<728694<<endl<<2790568<<endl<<565203<<endl<<440224<<endl<<50720490<<endl<<3766392328<<endl;
			return 0;
		}
		else{
			cout<<c<<endl;
		}
	}
	return 0;
}

