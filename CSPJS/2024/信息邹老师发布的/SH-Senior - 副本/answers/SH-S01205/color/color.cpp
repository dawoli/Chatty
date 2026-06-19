#include<iostream>
#include<cstring>
using namespace std;
#define N 100005
int T,n,a[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		memset(a,0,sizeof(a));
		int c=0,maxc=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int p=0;p<(1<<n);p++){
			c=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if((p>>j)%2==(p>>i)%2){
						if(a[i]==a[j]){
							c+=a[i];
						}
						break;
					}
				}
			}
			maxc=max(c,maxc);
		}
		cout<<maxc<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
