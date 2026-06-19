#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int num=1;
string q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	int l=q.length();
	for(int i=0;i<l;i++){
		if(q[i]>='0' && q[i]<='9'){
			a[num]=int(q[i]-'0');
			num++;
		}
		
	}
//	for(int i=1;i<num;i++){
//		cout<<a[i];
//		
//	}
//	cout<<endl;
	sort(a+1,a+num);
	for(int i=num-1;i>0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
