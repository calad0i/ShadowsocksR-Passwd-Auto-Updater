#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAXLINE 100000
#define BUFLEN  1024

int main()
{
  //  system("\"C:\\Other Programs\\download.vbs\"");
    FILE *pretest1,*pretest2;
    fdel:
    WinExec( "cmd.exe /c del /q /s Y:\\0", SW_HIDE );
    WinExec( "cmd.exe /c del /q /s Y:\\1", SW_HIDE );
    Sleep(25);
    pretest1=fopen("Y:\\0\\index.html","r");
   // pretest2=fopen("Y:\\1\\index.html","r");
    if (pretest1 ){//|| pretest2){
        fclose(pretest1);
     //   fclose(pretest2);
        goto fdel;
    }
        WinExec( "cmd.exe /c D:\\Schedule\\wget.exe -P Y:\\0  get.freevpnss.me --no-check-certificate", SW_HIDE );
        WinExec( "cmd.exe /c D:\\Schedule\\wget.exe -P Y:\\2  www.h6v6.com --no-check-certificate", SW_HIDE );
       // WinExec( "cmd.exe /c D:\\Schedule\\wget.exe -P Y:\\1  ss.404da.com --no-check-certificate", SW_HIDE );
    Sleep(1500);

//pretest/operation to make sure files are on their positions
//    system("ping 127.168.0.1");
    FILE *src,*dst,*tmp;
    char jp[80] = {'\0'};
    char us[80] = {'\0'};
    char us2[3][80] = {'\0'};
    char jp2[3][80] = {'\0'};
    char sg[3][80] = {'\0'};
    char un[3][80] = {'\0'};
    char mar[3] = "abc";
    int i = 0;
    src = fopen("Y:\\0\\index.html", "r");
    tmp = fopen("Y:\\2\\index.html", "r");
    while(!src || !tmp){// || !tmp){
//        WinExec( "cmd.exe /c D:\\Schedule\\wget.exe -P Y:\\0  get.freevpnss.me/index.html --no-check-certificate", SW_HIDE );
//        WinExec( "cmd.exe /c D:\\Schedule\\wget.exe -P Y:\\1  ss.404da.com/index.html --no-check-certificate", SW_HIDE );
        if(i++>3)return -1;
       Sleep(2000);
        src = fopen("Y:\\0\\index.html", "r");
        tmp = fopen("Y:\\2\\index.html", "r");
    }
    if(!src && !tmp) return -1;
  //  fclose(tmp);
    i=0;
//printf("%d",src);
    while(!feof(src))
    {
        if(fgetc(src) == 'e' && fgetc(src) == '<'&& fgetc(src) == '/'&& fgetc(src) == 's'&& fgetc(src) == 'p'&& fgetc(src) == 'a'&& fgetc(src) == 'n'&& fgetc(src) == '>'){
            while((jp[i++] = fgetc(src)) != '<'&& !feof(src));{
              //  printf("ch(%d)=%s\n",i,ch);
            }
        jp[i-1] = '*';
        }
    }
//    src = fopen("Y:\\index.html", "r");
    fclose(src);
    int a=0;
    src = fopen("Y:\\2\\index.html", "r");
    while(!feof(src))
    {
        if(fgetc(src) == '>'&& fgetc(src) == '-'){
            i=0;
            while((un[a][i++] = fgetc(src)) != '-'&& !feof(src));{
              //  printf("ch(%d)=%s\n",i,ch);
            }
        un[a][i-1] = '\0';
        a++;
        }
    }
    fclose(src);
    printf("%s\n",un[0]);
    printf("%s\n",un[1]);
    printf("%s\n",un[2]);
    /*
    int lp=0;
    while(lp++<3){//src2 operation
        i=0;
        src = fopen("Y:\\1\\index.html", "r");
        while(!feof(src))
        {
            if(fgetc(src) == '"' && fgetc(src) == 'p' && fgetc(src) == 'w' && fgetc(src) == 'u' && fgetc(src) == 's' && fgetc(src) == mar[lp-1] && fgetc(src) == '"' && fgetc(src) == '>'){
                while((us2[lp-1][i++] = fgetc(src)) != '<'&& !feof(src));{
                //  printf("ch(%d)=%s\n",i,ch);
                }
            us2[lp-1][i-1] = '*';
            del_chr(us2[lp-1],'*');
            fclose(src);
            break;
            }
          //  break;
        }

        i=0;
        src = fopen("Y:\\1\\index.html", "r");
        while(!feof(src))
        {
            if(fgetc(src) == '"' && fgetc(src) == 'p' && fgetc(src) == 'w' && fgetc(src) == 'j' && fgetc(src) == 'p' && fgetc(src) == mar[lp-1] && fgetc(src) == '"' && fgetc(src) == '>'){
                while((jp2[lp-1][i++] = fgetc(src)) != '<'&& !feof(src));{
                //  printf("ch(%d)=%s\n",i,ch);
                }
            jp2[lp-1][i-1] = '*';
            del_chr(jp2[lp-1],'*');
            fclose(src);
            break;
            }
            //break;
        }

        i=0;
        src = fopen("Y:\\1\\index.html", "r");
        while(!feof(src))
        {
            if(fgetc(src) == '"' && fgetc(src) == 'p' && fgetc(src) == 'w' && fgetc(src) == 's' && fgetc(src) == 'g' && fgetc(src) == mar[lp-1] && fgetc(src) == '"' && fgetc(src) == '>'){
                while((sg[lp-1][i++] = fgetc(src)) != '<'&& !feof(src));{
                //  printf("ch(%d)=%s\n",i,ch);
                }
            sg[lp-1][i-1] = '*';
            del_chr(sg[lp-1],'*');
            fclose(src);
            break;
            }
        }


        printf("us%d=%s\n",lp-1,us2[lp-1]);
        printf("jp%d=%s\n",lp-1,jp2[lp-1]);
        printf("sg%d=%s\n",lp-1,sg[lp-1]);
    }
    */
    us[0] = jp[0] = '*';
    us[1] = jp[1] = '*';
    us[2] = jp[2] = '*';
    us[3] = jp[3] = '*';
    us[4] = jp[4] = '*';
    us[5] = jp[5] = '*';
    jp[6] = '*';
    jp[8] = '*';
    jp[7] = '*';
    jp[9] = '*';
    del_chr(jp,'*');
    del_chr(us,'*'); //fix bugs with Chinese chars

    WinExec( "cmd.exe /c taskkill /t /im ShadowsocksR-dotnet4.0.exe", SW_HIDE );
        Sleep(50);
    WinExec( "cmd.exe /c taskkill /t /f /im ShadowsocksR-dotnet4.0.exe", SW_HIDE );
    WinExec( "cmd.exe /c taskkill /t /f /im ShadowsocksR-dotnet4.0.exe", SW_HIDE );
    WinExec( "cmd.exe /c taskkill /t /f /im ShadowsocksR-dotnet4.0.exe", SW_HIDE );// make sure terminated

FILE *file;
char buf[BUFLEN];
int len=0;
i=0;
char *array[MAXLINE];

file=fopen("D:\\Program Files\\SSR\\gui-config","r");//open module
if(!file)return -1;
while(fgets(buf,BUFLEN,file))//read module
{
 len=strlen(buf);
 array[i]=(char*)malloc(len+1);
 if(!array[i])break;
 strcpy(array[i++],buf);
}

fclose(file);
i--;
//printf("%s",array);
int x=i;
i=0;
//far *oo=old;
dst=fopen("D:\\Program Files\\SSR\\gui-config.json","w");
printf("%s\n%s",jp,us);
while(i<=x&&array[i])//replace mark with fetched passwd
{
    strrpl(array[i],"[^&Rep.us&^]",us);
    strrpl(array[i],"[^&Rep.jp&^]",jp);
    strrpl(array[i],"[^&Rep.us1&^]",us2[0]);
    strrpl(array[i],"[^&Rep.us2&^]",us2[1]);
    strrpl(array[i],"[^&Rep.us3&^]",us2[2]);
    strrpl(array[i],"[^&Rep.jp1&^]",jp2[0]);
    strrpl(array[i],"[^&Rep.jp2&^]",jp2[1]);
    strrpl(array[i],"[^&Rep.jp3&^]",jp2[2]);
    strrpl(array[i],"[^&Rep.sg1&^]",sg[0]);
    strrpl(array[i],"[^&Rep.sg2&^]",sg[1]);
    strrpl(array[i],"[^&Rep.sg3&^]",sg[2]);
    strrpl(array[i],"[^&Rep.un1&^]",un[0]);
    strrpl(array[i],"[^&Rep.un2&^]",un[1]);
    strrpl(array[i],"[^&Rep.un3&^]",un[2]);
    fprintf(dst,"%s\n",array[i]);//write to gui-config.json
    free(array[i++]);
}
fclose(dst);
Sleep(300);
WinExec( "cmd.exe /c \"D:\\Program Files\\SSR\\ShadowsocksR-dotnet4.0.exe\"",SW_HIDE);
    fdel2:
    fclose(src);
    fclose(tmp);
    WinExec( "cmd.exe /c del /q /s Y:\\0", SW_HIDE );
    WinExec( "cmd.exe /c del /q /s Y:\\1", SW_HIDE );
    WinExec( "cmd.exe /c del /q /s Y:\\2", SW_HIDE );
    WinExec( "cmd.exe /c rd Y:\\0", SW_HIDE );
    WinExec( "cmd.exe /c rd Y:\\1", SW_HIDE );
    WinExec( "cmd.exe /c rd Y:\\2", SW_HIDE );

/*
    Sleep(25);
    pretest1=fopen("Y:\\0\\index.html","r");
    pretest2=fopen("Y:\\1\\index.html","r");
    if (pretest1 || pretest2){
        fclose(pretest1);
        fclose(pretest2);
        goto fdel2;
    }
*/
return 0;
}
void del_chr( char *s, char ch )
{
    char *t=s; //to ori. head
    while( *s != '\0' ) //through s
    {
        if ( *s != ch ) //in not to del, save to tar.
            *t++=*s;
        s++ ; //next
    }
    *t='\0'; //reset tar.
}

void strrpl(char *s, const char *s1, const char *s2)

{

        char *ptr;

while (ptr = strstr(s, s1))     // if s is found in s1

        {

                memmove(ptr + strlen(s2) , ptr + strlen(s1), strlen(ptr) - strlen(s1) + 1);

                memcpy(ptr, &s2[0], strlen(s2));

        }

        return s;

}
