#include <bits/stdc++.h>
using namespace std;
int a[]={6,2,5,5,4,5,6,3,7,6};
int get_sum(int val){
	char tmp[100000]={};
	int ans=0;
	sprintf(tmp,"%d",val);
	for(int i=0;tmp[i];i++)
		ans+=a[tmp[i]-'0'];
	return ans;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		int j;
		for(j=1;get_sum(j)!=n;j++);
		cout<<j<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
