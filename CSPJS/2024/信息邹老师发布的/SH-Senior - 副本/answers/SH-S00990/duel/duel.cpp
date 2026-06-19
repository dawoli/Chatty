#include<iostream>
#include<cstdio>
using namespace std;
FILE* fin=freopen("duel.in","r",stdin);
FILE* fout=freopen("duel.out","w",stdout);
int bucket[100001];
void guibing(int l,int r,int * power,int * a){
	if (l==r)return;
	int mid=(l+r)>>1;
	int i=l,j=mid+1,k=l;
	guibing(l,mid,power,a);
	guibing(mid+1,r,power,a);
	while(i<=mid&&j<=r){
		if (power[i]<power[j]){
			a[k]=power[i];k++;i++;
		}
		else{
			a[k]=power[j];k++;j++;
		}
	}
	while(i<=mid){
		a[k]=power[i];
		k++;i++;
	}
	while(j<=r){
		a[k]=power[j];
		k++;
		j++;
	}
	for (int ii=l;ii<=r;ii++){
		power[ii]=a[ii];
	}
}
int main(){
	int n;
	cin>>n;
	int *power=new int [n+1];
	for (int i=1;i<=n;i++){
		cin>>power[i];
	}
	int *a=new int [n+1];
	guibing(1,n,power,a);
/*	bool temp2=false;
	int ans=0,ans2=0;
	for (int i=1;i<=n;i++){
		if (power[i]==2||temp2)ans++;
		else ans2++;
		cout<<power[i]<<endl; 
	}
	cout<<ans<<endl<<ans2<<endl;*/
	for (int i=1;i<=n;i++){
		bucket[power[i]]++;
	}
	int left=bucket[1];
	for (int j=2;j<=10000;j++){
		if(left>=bucket[j]){
			continue;
		}
		else{
			left=bucket[j]-left;
		}
	}
	cout<<left;
//	bool *attacked=new bool [n+1];
//	bool *dead=new bool [n+1];
	return 0;
}
