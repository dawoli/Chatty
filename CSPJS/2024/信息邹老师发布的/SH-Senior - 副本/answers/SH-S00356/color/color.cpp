#include<iostream>
#include<cstdio>
using namespace std;
struct s{
	int x,y;
};
int t,n,c;
int a[200009];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		c=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>0;j--){
				if(a[i]==a[j])c+=a[i];
			}
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
