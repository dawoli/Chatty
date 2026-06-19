#include <iostream>
using namespace std;
int t,n,lasb,lasr,curpos;
int a[200005];
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	cin>>t;
	for(int z=0;z<t;z++){
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<(1<<n);i++){
			while(curpos!=n){
				if(i%2==0){
					if(lasr==a[curpos]){
						ans+=lasr;
					}
					else{
						lasr=a[curpos];
					}
				}
				else(i%2==1){
					if(lasb==a[curpos]){
						ans+=lasb;
					}
					else{
						lasr=a[curpos];
					}
				}
				curpos++;
				i/=2;
			}
			curpos=0;
		}
		cout<<ans<<endl;
		curpos=0;
	}
	return 0;
}
