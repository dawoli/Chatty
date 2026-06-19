#include<bits/stdc++.h>
using namespace std;
int a[10010],c,b[10010];
int n,book[100010];
int f(int p,int x,int s){
	int cnt=0;
	//int o=n;
//	for(int i=1;i<o;i++){
//		if(a[i]==a[i-1])
//		{
//			for(int j=i;j<n;j++){
//				a[j-1]=a[j];
////				for(int i=0;i<n;i++){
////					cout<<a[i]<<" ";
////				}	
////				cout<<endl;
//			}
//			a[n-1]=-1;
//			n--;
//		}
//		
//	}
	
	for(int i=0;i<s;i++){
		if(p-a[i]>x&&book[a[i]]==0) {
			cnt++;
			book[i]=1;
			cnt+=f(p-a[i],x,s);	
		}
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int x=1;x<n;x++){
			if(a[x]<a[x-1])
			swap(a[x],a[x-1]);
		}
	}
	
	
	
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<n<<endl;
	b[0]=a[0];
	for(int i=0;i<n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	for(int i=n-1;i>=0;i--){
		int x=2*a[i];
		int p=b[i];
//		if(p>x) c++;
		c+=f(p,x,i);
		int book[100010]={0};
	} 
	cout<<c;
	return 0; 
}

