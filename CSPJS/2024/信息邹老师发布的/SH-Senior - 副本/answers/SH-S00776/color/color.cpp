#include<bits/stdc++.h>
using namespace std;
int c[200001];
vector<int> a;
int sum[200001];
int leftsame1=-1;
int leftsame2=-1;
void check(int b){
	int temp2=b-1;
	while(temp2>0){
		
//	if(a[b]==a[temp2]&&(leftsame1==0)) {
//		leftsame1=b;
//		
//		sum[temp2]=1;
//		sum[b]=1;	
//	}
//	if(a[b]==a[temp2]&&(leftsame2==0)) {
//		leftsame2=b;
//		sum[temp2]=2;
//		sum[b]=2;	
//	}
	if(a[b]==a[temp2]&&temp2>=leftsame2) {
		leftsame2=b;
		c[b]+=a[b];
	}else{
		if(a[b]==a[temp2]&&temp2>=leftsame1) {
		leftsame1=b;
		c[b]+=a[b];
	}
	}
temp2--;
//	cout <<"temp2__"<<temp2;
}	
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		a.clear();
		int sum=0;
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			int temp;
			cin>>temp;
			a.push_back(temp);
		}	
		for(int x=1;x<n;x++){
//			cout <<x;
		check(x);			
	}
	for(int d=0;d<n;d++){
		cout<<c[d]<<"__";
		sum+=c[d];
	}	
	cout <<endl;
	cout <<sum<<endl;	
//		for(int k=0;k<n;k++){
//			cout << a[k]<<" ";
//		}
//		cout <<endl;	
	}
	return 0;
}
