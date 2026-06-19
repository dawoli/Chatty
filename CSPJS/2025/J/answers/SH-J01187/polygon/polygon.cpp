#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		int l[3];
		cin>>l[0]>>l[1]>>l[2];
		if(l[0]+l[1]>l[2] && l[0]+l[2]>l[1] && l[1]+l[2]>l[0]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(n==4){
		int l[4],ans=0;
		cin>>l[0]>>l[1]>>l[2]>>l[3];
		sort(l,l+4);
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				for(int k=j+1;k<4;k++){
					if(l[i]+l[j]>l[k]){
						//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<"\n";
						ans++;
					}
				}
			}
		}
		if(l[2]+l[1]+l[0]>l[3]){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	else if(n==5){
		int l[5],ans=0;
		cin>>l[0]>>l[1]>>l[2]>>l[3]>>l[4];
		sort(l,l+4);
		for(int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				for(int k=j+1;k<5;k++){
					if(l[i]+l[j]>l[k]){
						//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<"\n";
						ans++;
					}
				}
			}
		}
		for(int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				for(int k=j+1;k<5;k++){
					for(int x=k+1;x<5;x++){
						if(l[i]+l[j]+l[k]>l[x]){
							//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<"\n";
							ans++;
						}
					}
				}
			}
		}
		if(l[0]+l[2]+l[1]+l[3]>l[4]){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	else if(n==6){
		int l[6],ans=0;
		cin>>l[0]>>l[1]>>l[2]>>l[3]>>l[4]>>l[5];
		for(int i=0;i<6;i++){
			for(int j=i+1;j<6;j++){
				for(int k=j+1;k<6;k++){
					if(l[i]+l[j]>l[k]){
						//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<"\n";
						ans++;
					}
				}
			}
		}
		for(int i=0;i<6;i++){
			for(int j=i+1;j<6;j++){
				for(int k=j+1;k<6;k++){
					for(int x=k+1;x<6;x++){
						if(l[i]+l[j]+l[k]>l[x]){
							//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<"\n";
							ans++;
						}
					}
				}
			}
		}
		for(int i=0;i<6;i++){
			for(int j=i+1;j<6;j++){
				for(int k=j+1;k<6;k++){
					for(int x=k+1;x<6;x++){
						for(int y=x+1;y<6;y++){
							if(l[i]+l[j]+l[k]+l[x]>l[y]){
								//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<" "<<l[y]<<"\n";
								ans++;
							}
						}
					}
				}
			}
		}
		if(l[0]+l[1]+l[2]+l[3]+l[4]>l[5]){
			ans++;	
		}
		cout<<ans;
	}
	else if(n==7){
		int l[7],ans=0;
		cin>>l[0]>>l[1]>>l[2]>>l[3]>>l[4]>>l[5]>>l[6];
		for(int i=0;i<7;i++){
			for(int j=i+1;j<7;j++){
				for(int k=j+1;k<7;k++){
					if(l[i]+l[j]>l[k]){
						//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<"\n";
						ans++;
					}
				}
			}
		}
		for(int i=0;i<7;i++){
			for(int j=i+1;j<7;j++){
				for(int k=j+1;k<7;k++){
					for(int x=k+1;x<7;x++){
						if(l[i]+l[j]+l[k]>l[x]){
							//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<"\n";
							ans++;
						}
					}
				}
			}
		}
		for(int i=0;i<7;i++){
			for(int j=i+1;j<7;j++){
				for(int k=j+1;k<7;k++){
					for(int x=k+1;x<7;x++){
						for(int y=x+1;y<7;y++){
							if(l[i]+l[j]+l[k]+l[x]>l[y]){
								//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<" "<<l[y]<<"\n";
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=0;i<7;i++){
			for(int j=i+1;j<7;j++){
				for(int k=j+1;k<7;k++){
					for(int x=k+1;x<7;x++){
						for(int y=x+1;y<7;y++){
							for(int z=y+1;z<7;z++){
								if(l[i]+l[j]+l[k]+l[x]+l[y]>l[z]){
									//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<" "<<l[y]<<"\n";
									ans++;
								}
							}
						}
					}
				}
			}
		}
		if(l[0]+l[1]+l[2]+l[3]+l[4]+l[5]>l[6]){
			ans++;	
		}
		cout<<ans;
	}
	else if(n==8){
		int l[8],ans=0;
		cin>>l[0]>>l[1]>>l[2]>>l[3]>>l[4]>>l[5]>>l[6]>>l[7];
		for(int i=0;i<8;i++){
			for(int j=i+1;j<8;j++){
				for(int k=j+1;k<8;k++){
					if(l[i]+l[j]>l[k]){
						//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<"\n";
						ans++;
					}
				}
			}
		}
		for(int i=0;i<8;i++){
			for(int j=i+1;j<8;j++){
				for(int k=j+1;k<8;k++){
					for(int x=k+1;x<8;x++){
						if(l[i]+l[j]+l[k]>l[x]){
							//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<"\n";
							ans++;
						}
					}
				}
			}
		}
		for(int i=0;i<8;i++){
			for(int j=i+1;j<8;j++){
				for(int k=j+1;k<8;k++){
					for(int x=k+1;x<8;x++){
						for(int y=x+1;y<8;y++){
							if(l[i]+l[j]+l[k]+l[x]>l[y]){
								//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<" "<<l[y]<<"\n";
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=0;i<8;i++){
			for(int j=i+1;j<8;j++){
				for(int k=j+1;k<8;k++){
					for(int x=k+1;x<8;x++){
						for(int y=x+1;y<8;y++){
							for(int z=y+1;z<8;z++){
								if(l[i]+l[j]+l[k]+l[x]+l[y]>l[z]){
									//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<" "<<l[y]<<"\n";
									ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=0;i<8;i++){
			for(int j=i+1;j<8;j++){
				for(int k=j+1;k<8;k++){
					for(int x=k+1;x<8;x++){
						for(int y=x+1;y<8;y++){
							for(int z=y+1;z<8;z++){
								for(int w=y+1;w<8;w++){
									if(l[i]+l[j]+l[k]+l[x]+l[y]+l[z]>l[w]){
										//cout<<l[i]<<" "<<l[j]<<" "<<l[k]<<" "<<l[x]<<" "<<l[y]<<"\n";
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(l[0]+l[1]+l[2]+l[3]+l[4]+l[5]+l[6]>l[7]){
			ans++;	
		}
		cout<<ans;
	}
	cout<<n*(n-1);
	return 0;
} 
