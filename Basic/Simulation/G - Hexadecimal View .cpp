// hdu 4054
 
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	char s[5000];
	while(gets(s)){
		int len = strlen (s);
		int line;
		int j = 0, k = 0;
		if(len % 16 == 0) line = len / 16 ;
		else line = len / 16 + 1;
		for (int i = 0; i < line; i++){
			printf("%03x0: ",i);
			for(; j < line * 16; j++){
				if(j < len) printf("%x", s[j]);
				if(j >= len) printf("  ");
				if(j % 2 == 1) printf(" ");
				if((j + 1) % 16 == 0) {j++; break;}
			}
		    for(; k < len; k++){
                if(s[k] >= 'A' && s[k] <= 'Z')
                    printf("%c", s[k] + 32);
                else if (s[k] >= 'a'&& s[k] <= 'z')
                    printf("%c", s[k] - 32);
                else
                    printf("%c", s[k]);
                if(s[k] == '\0')  break;
                if( (k+1) % 16 == 0)
                {
                    k++;
                    break;
                }
            }
            printf("\n");
		}
	}
	return 0;
}