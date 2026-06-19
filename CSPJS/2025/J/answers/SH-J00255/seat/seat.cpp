#include<bits/stdc++.h>
using namespace std;
int c,r;
int seats[15][15];
int tar;
int numbers[105];
bool cmp(int a,int b){
	return a>b;
}
void fill(){
	int index=1;
	for(int i=1;i<=r;i++){
		int start,end,step;
		if(i%2==1){
			start=1,end=c+1,step=1;
		}else{
			start=c,end=0,step=-1;
		}
		for(int j=start;j!=end;j+=step){
			seats[j][i]=numbers[index];
			index++;
		}
	}
}
void test(){
	for(int i=1;i<=c;i++){
		for(int j=1;j<=r;j++){
			cout<<seats[i][j]<<' ';
		}cout<<endl;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	int n=c*r;
	for(int i=1;i<=n;i++){
		cin>>numbers[i];
	}
	tar=numbers[1];
	sort(numbers+1,numbers+n+1,cmp);
	fill();
//	test();
	for(int i=1;i<=c;i++){
		for(int j=1;j<=r;j++){
			if(seats[i][j]==tar){
				cout<<j<<' '<<i<<endl;
			}
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
