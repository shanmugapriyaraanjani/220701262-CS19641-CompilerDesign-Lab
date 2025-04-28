#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
char str[50];
printf("Enter the string...");
fgets(str,50,stdin);
char a;
printf("Enter the chracter which is to be replace...");
scanf("%c",&a);
char ans[50];
for(int i=0;i<strlen(str);i++){
if(str[i]==a){
ans[i]='7';
}
else{
ans[i]=str[i];
}
}
printf("%s",ans);
}