#include<stdio.h>

int main(void){
    long int n,m,a;
    long int ans;
    scanf("%ld %ld %ld",&n,&m,&a);
	ans = ((m+a-1)/a)*((n+a-1)/a); 
	printf("%ld",ans);
}
