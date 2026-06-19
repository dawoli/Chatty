#include<iostream>
using namespace std;
int n,k,ans;
int lst[500004][500];
int bakk(int l,int x){
	int t=x,p=l;
	int as=0;
	int r=0;
	while(t){
		if(t%2){
			as^=lst[p][r];
			p+=1<<r;
		}
		r++;
	}
	return as;
}
void calc(int l,int r,int ky){
	//cout<<l<<" "<<r<<" "<<ky<<endl;
	int t=r,key=ky;
	while(t){
		if(key==0){
			for(int i=1;i<=n;i++){
				if(lst[i][0]==k){
					ans++;
					calc(l,i-1,key);
					calc(i+1,r,key);
					return;
		}
	}
		}else{
		for(int i=1+l,j=1+l;i<=r-key;j++,i++){
			lst[j][key]=lst[j][key-1]^lst[j+key][0]; 
			//cout<<lst[j][key-1]+lst[j+(1<<(key-1))][key-1];
			//cout<<i<<" "<<key<<" "<<i+(1<<key)-1<<endl;
				if(lst[j][key]==k){
					ans++;
					//cout<<j<<key<<endl;
					calc(l,j-1,key);
					calc(j+key+1,r,key);
					return;
				}
			}
		
		key++;
		t--;
		//cout<<t; 
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>lst[i][0];
	}
	
	calc(0,n,1);	
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=3;j++){
//			cout<<lst[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
