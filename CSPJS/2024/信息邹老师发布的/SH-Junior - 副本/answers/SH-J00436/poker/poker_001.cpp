#include<iostream>
#include<string.h>
using namespace std;
string card[53]={"0"};
int n,ans=0;
bool check(string tmp){
	int i=0;
	for(int i=0; i<=ans+1; i++){
		if(card[i]==tmp){return false;}
	}
	return true;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string temp;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		cin>>temp;
		if(check(temp)){
			card[i]=temp;
			ans++;
		}
	}
	printf("%d",52-ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
