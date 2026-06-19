#include<iostream>
#include<algorithm> 
using namespace std;
int u[10]={6,2,5,5,4,5,6,3,7,6};
int used[10];
int miused[10];
int mi=1000005;
void c(int all,int len){
	if(all==0){
		if(len<mi) {
			mi=len;
			for(int i=0;i<=9;i++){
				miused[i]=used[i];
			}
			return;
		}
		else if(len==mi){
			bool flag=0;
			for(int i=1;i<=9;i++){
				if(used[i]==miused[i]&&flag==0){
					flag=1;
					if(used[0]>miused[0]){
						for(int j=0;j<=9;j++){
							miused[i]=used[i];
						}
						return;
					}
					else if(used[0]<miused[0]) return;
				}for(int j=0;j<=9;j++){
						miused[i]=used[i];
					}
					return;
				if(used[i]<miused[i]) return;
				else if(used[i]>miused[i]){
					for(int j=0;j<=9;j++){
						miused[i]=used[i];
					}
					return;
				}
			}
		}
	}
	else{
		if(all==1) return;
		else{
			for(int i=0;i<=9;i++){
				used[i]++;
				c(all-u[i],len+1);
				used[i]--;
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;t++){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1;
			continue;
		}
		c(n,0);
		for(int i=1;i<=9;i++){
			if(miused[i]!=0){
				cout<<i;
				miused[i]--;
				break;
			}
		}
		for(int i=0;i<=9;i++){
			while(miused[i]!=0){
				cout<<i;
			}
		}
		for(int i=0;i<=9;i++){
			used[i]=0;
			miused[i]=0;
		}
		cout<<"\n";
	}
} 
