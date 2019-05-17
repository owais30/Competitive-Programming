#include <iostream>

using namespace std;
 
int main(void) {
	int i,j,n,sum,ans,t;
	scanf("%d",&t);
	while(t-->0){
		scanf("%d",&n);
		int coins[n];
		for(i=0;i<n;i++){scanf("%d",coins+i);}
 
		sum=coins[0];ans=1;		
 
		for(i=1;i<n-1;i++){
			if(coins[i]+sum<coins[i+1])
      {
        sum+=coins[i];
        ans++;
      }
		}
 
	printf("%d\n",ans+1);	
 
	}
	return 0;
}
