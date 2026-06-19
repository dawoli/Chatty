#include<bits/stdc++.h>
using namespace std;
char a[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char l[4]={'D','C','H','S'};
int b[52];
char x,y;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    int n,m,ans=0;
    cin>>n;
    m=n;
    while(m--){
    	cin>>x>>y;
    	for(int i=0;i<13;i++){
    		for(int j=0;j<4;j++){
    			if(x==l[j]&&y==a[i]&&b[j*13+i]==0){
    				ans++;
    				b[j*13+i]=1;
				}
			}
		}
	}
	cout<<52-ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
