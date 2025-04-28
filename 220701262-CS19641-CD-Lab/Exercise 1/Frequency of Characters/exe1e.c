#include<stdio.h>
#include<string.h>
int main(){
char str[100];
scanf("%s",str);
int a=0;
int b=0,c=0;
for(int i=0;i<strlen(str);i++){
if(str[i]=='a'){
a++;
}
else if(str[i]=='b'){
b++;
}
else{
c++;
}
}
printf("%d\n",a);
printf("%d\n",b);
printf("%d\n",c);
}
