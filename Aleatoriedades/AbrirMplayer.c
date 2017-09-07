	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>
	
	int main(){
	
		char a[500],b[500],c[1050];
		char mp[10] = "mplayer ";
		char sub[6] = "-sub ";

		printf("\nVideo:");
		gets(a);
		__fpurge(stdin);
		printf("\nLegenda:");
		gets(b);
			
		strcpy(c,mp);
		strcat(c,a);
		strcat(c,sub);
		strcat(c,b);
				
		system(c);
	
		return 0;
	}
