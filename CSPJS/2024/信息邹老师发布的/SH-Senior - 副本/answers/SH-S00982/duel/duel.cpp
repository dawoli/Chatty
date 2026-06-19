#include<iostream>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int nx[n]={0};
	for(int i=0;i<n;i++){
		cin>>nx[i];
	}
	//找到最大值 
	int max=nx[0];
	for(int i=0;i<n;i++){
		if(nx[i]>max){
			max=nx[i];
		}
	}
	//建立链表，记录出现次序 
	int a[max+1]={0};
	for(int i=0;i<n;i++){
		a[nx[i]]++;
	}
	//cout<<max<<endl;
	for(int i=0;i<max+1;i++){
		//cout<<a[i]<<" ";
	}
	int b[max+1]={0};
	int c=0;
	for(int i=0;i<max+1;i++){
		if(a[i]!=0){
			b[c]=a[i];
			c++;
		}
	}

	
	for(int i=0;i<max;i++){
		if(b[i]<=b[i+1]){
			b[i]=0;
		}
		else{
			b[i]=b[i]-b[i+1];
		}

	}
	
	
	int ans=0;
	for(int i=0;i<max+1;i++){
		ans+=b[i];
	}

	cout<<ans;
}
