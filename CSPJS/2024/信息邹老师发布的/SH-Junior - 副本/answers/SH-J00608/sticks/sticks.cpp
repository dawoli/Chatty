#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("sticks.in","r",stdin);
	//freopen("sticks.out","w",stdout);
	int n,q;
	cin>>q;
	while(cin>>n){
		int m=n;
		int x,y,z,r,u,o;
    	for(x=0;x<(n/7);x++){
    		m-=7;
		}
		if(m==0){
			for(int i=0;i<x;i++){
			    cout<<8;
			}
			
			
		}
		else if(m==1){
			cout<<-1;
		}
		else{
			for(y=0;y<(m/6);y++){
    		m-=6;
		    }
			if(m==0){
			    cout<<6;
			}
			    for(int i=1;i<y;i++){
			        cout<<0;
				}
			    for(int i=0;i<x;i++){
			    cout<<8;
			    }
			
		    }
		    else if(m==1){
			    cout<<-1;
		    }
		    else{
			    for(z=0;z<(m/5);z++){
			        m-=5;
		    	}
			    if(m==0){
			    	cout<<2;
					for(int i=1;i<y;i++){
			            cout<<0;
				    }
				    cout<<6;
			        for(int i=1;i<z;i++){
			            cout<<2;
			    	}
			        for(int i=0;i<x;i++){
			        cout<<8;
			        }
			    }
			    
			    else if(m==1){
		    	        cout<<-1;
		        }
		        else{
		        	for(r=0;r<(m/4);r++){
			        m-=4;
		    	}
			    if(m==0){
			    	cout<<2;
					for(int i=1;i<y;i++){
			            cout<<0;
				    }
			        for(int i=1;i<z;i++){
			            cout<<2;
			    	}
			    	for(int i=0;i<r;i++){
			            cout<<4;
			    	}
					cout<<6;
			        for(int i=0;i<x;i++){
			        cout<<8;
			        }
			    }
			    
			    else if(m==1){
		    	        cout<<-1;
		        }
		        else{
		        	for(z=0;z<(m/5);z++){
			        m-=5;
		    	}
			    if(m==0){
			    	cout<<2;
					for(int i=1;i<y;i++){
			            cout<<0;
				    }
				    cout<<6;
			        for(int i=1;i<z;i++){
			            cout<<2;
			    	}
			        for(int i=0;i<x;i++){
			        cout<<8;
			        }
			    }
			    
			    else if(m==1){
		    	        cout<<-1;
		        }
		        else{
		        	for(u=0;u<(m/3);u++){
			            m-=3;
		    	    }
			        if(m==0){
			    	    cout<<2;
					    for(int i=1;i<y;i++){
			                cout<<0;
				        }
			            for(int i=1;i<z;i++){
			                cout<<2;
			    	    }
			    	    for(int i=0;i<r;i++){
			                cout<<4;
			        	}
				    	cout<<6;
			    		for(int i=0;i<u;i++){
			                cout<<7;
			            }
			            for(int i=0;i<x;i++){
			                cout<<8;
		    	        }
			    }
			    
			    else if(m==1){
		    	        cout<<-1;
		        }
		        else{
		        	for(o=0;o<(2/3);o++){
			            m-=2;
		    	    }
			        if(m==0){
			        	for(int i=1;i<u;i++){
			                cout<<1;
			            }
			    	    cout<<1;
					    for(int i=1;i<y;i++){
			                cout<<0;
				        }
			            for(int i=0;i<z;i++){
			                cout<<2;
			    	    }
			    	    for(int i=0;i<r;i++){
			                cout<<4;
			        	}
				    	cout<<6;
			    		for(int i=0;i<u;i++){
			                cout<<7;
			            }
			            for(int i=0;i<x;i++){
			                cout<<8;
		    	        }
			    }
			    
			    else if(m==1){
		    	        cout<<-1;
		        }
				}
				}
				}
		    }
		        
		    }
		}
	}
	return 0;
}
