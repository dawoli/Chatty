#include<bits/stdc++.h>
using namespace std;
long long l,f[10000],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>l;
	for(int i=1; i<=l; i++){
		cin>>f[i];
	}
	for(int i=0; i<pow(2,l); i++){
		int c=i;
		string aa;
		for(int j=0; j<l; j++){
			aa=aa+to_string(c%2);
			c=c>>1;
		}
		long long leng=0,maxx=-1,p=0;
		for(int j=0;j<aa.size(); j++){
			if(aa[j]=='1'){
				p++;
				leng+=f[j+1];
				maxx=max(maxx,f[j+1]);
				//cout<<f[j+1]<<' ';
			}
		}
		if(p<3){
			continue;
		}else if(leng>maxx*2){
			ans+=1;
		}
		//cout<<leng<<' '<<maxx;
	}
	cout<<ans%998224353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
