#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "admin.h"
#include "user.h"

int main(int argc,char *argv[]){

    char username[50];
    char password[50];
    char role[10];
    
    FILE *fp = fopen("akun.txt", "r");
    int n=1;
    int i;
    while (fscanf(fp,"%s %s %s",username,password,role)==3)
    {   
        if (argc==3 &&(((strcmp(argv[1],username))==0  && (strcmp(argv[2],password))==0)))
        {  i=1; break; }    
        n++;
    }

    fclose(fp);
    if (n==3)
    { 
        printf("login gagal!\n");
        return 0; }

    else if (i==1)
    {
    printf("login berhasil sebagai %s!\n", argv[1]);

    if (strcmp(role,"admin")==0)
    { menuAdmin(); }
    else if (strcmp(role,"user")==0)
    { menuUser(); }
    }
    return 0;
}