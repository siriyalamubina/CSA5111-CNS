#include<stdio.h>
#include<string.h>
#include<ctype.h>
char m[5][5];
void make(char k[]){
 int u[26]={0},r=0,c=0,i; char ch;
 for(i=0;k[i];i++){
  ch=toupper(k[i]); if(ch=='J')ch='I';
  if(ch>='A'&&ch<='Z'&&!u[ch-'A']){
   m[r][c++]=ch;u[ch-'A']=1;
   if(c==5)c=0,r++;
  }
 }
 for(ch='A';ch<='Z';ch++){
  if(ch=='J')continue;
  if(!u[ch-'A']){
   m[r][c++]=ch;u[ch-'A']=1;
   if(c==5)c=0,r++;
  }
 }
}
void pos(char ch,int*r,int*c){
 int i,j;if(ch=='J')ch='I';
 for(i=0;i<5;i++)for(j=0;j<5;j++)
  if(m[i][j]==ch){*r=i;*c=j;return;}
}
int main(){
 char key[50],t[100],p[200],e[200];int i,n=0,x=0,r1,c1,r2,c2;
 printf("Enter keyword: ");scanf("%s",key);
 printf("Enter plaintext: ");scanf("%s",t);
 make(key);
 printf("\nPlayfair Matrix:\n");
 for(i=0;i<5;i++)printf("%c %c %c %c %c\n",m[i][0],m[i][1],m[i][2],m[i][3],m[i][4]);
 for(i=0;t[i];i++){char ch=toupper(t[i]);if(ch=='J')ch='I';if(ch>='A'&&ch<='Z')p[n++]=ch;}
 p[n]='\0';
 for(i=0;i<n-1;i+=2)
  if(p[i]==p[i+1]){
   for(x=n;x>i+1;x--)p[x]=p[x-1];
   p[i+1]='X';n++;
  }
 if(n%2)p[n++]='X';p[n]='\0';
 for(i=0;i<n;i+=2){
  pos(p[i],&r1,&c1);pos(p[i+1],&r2,&c2);
  if(r1==r2)e[x++]=m[r1][(c1+1)%5],e[x++]=m[r2][(c2+1)%5];
  else if(c1==c2)e[x++]=m[(r1+1)%5][c1],e[x++]=m[(r2+1)%5][c2];
  else e[x++]=m[r1][c2],e[x++]=m[r2][c1];
 }
 e[x]='\0';
 printf("\nPrepared plaintext: %s",p);
 printf("\nEncrypted text: %s\n",e);
 return 0;
}
