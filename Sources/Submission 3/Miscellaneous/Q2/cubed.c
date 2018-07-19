#include <stdio.h>
int main(){
	long long int c, u, b, e, d;
	for(c=0; c<=9; c++){
		for(u=0; u<=9; u++){
			for(b=0; b<=9; b++){
				for(e=0; e<=9; e++){
					for(d=0; d<=9; d++){
						if((c+u+b+e+d)*(c+u+b+e+d)*(c+u+b+e+d)==(d+e*10+b*100+u*1000+c*10000))
							printf("The solution is c=%lld u=%lld b=%lld e=%lld d=%lld\n",c,u,b,e,d);
					}
				}
			}
		}
	}
	return 0;
}
