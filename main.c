#include <stdio.h>




int strprint(char* map, const char* string, int x, int y, int ien)
{
        char *a;
	a = (char* )string;
	printf("%s",a);
	return 0;
}

int main()
{
       char a[30];

       int i =0;
       while(i<30)
       {
              a[i] = '0';
	      i = i+1;
       }

       char temp[20] = "United Kingdom is good";

       i =0;
       while(i<20)
       {
	       if(temp[i]=='\0')
	       {
		       i=20;
	       }
	       else
	       {
		       a[i+5] = temp[i];
		       i=i+1;
	       }
	     
       }


       printf("&s",a);
       
       strprint("I hate Fucking chienese.");

       return 0;
