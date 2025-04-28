
#include<stdio.h>
#include<string.h>
int main(){
char str[50];
char str1[50];
char ans[110];
printf("Enter the first string...");
scanf("%s",str);
printf("Enter the second string...");
scanf("%s",str1);
int z=0;
for(int i=0;i<strlen(str);i++){
ans[z]=str[i];
z++;
}
for(int j=0;j<strlen(str1);j++){
ans[z]=str1[j];
z++;
}
printf("%s",ans);
}

