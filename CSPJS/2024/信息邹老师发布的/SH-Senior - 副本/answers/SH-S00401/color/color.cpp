#include<bits/stdc++.h>
using namespace std;
int T,a[200005],b[200005],c[200005],n;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int p=0;p<T;p++){
		int amt=0,res=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];b[i]=0,c[i]=0;}
		for(int i=0;i<n;i++){
			int ap=1;
			for(int j=0;j<amt;j++){
				if(b[j]==a[i]){
					c[j]++;ap=0;break;}}
			if(ap){
				b[amt]=a[i];
				c[amt++]=1;}}
		for(int i=0;i<amt;i++){
			res+=(c[i]-1)*b[i];}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
