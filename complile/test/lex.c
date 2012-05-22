#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *lexout;
const char* isreservation(char *start,char *end)
{
    static const char *rs[] = {"if","else","for","while","do","int","read","write"};
    int i,len = (int)(end-start)+1;
    char t = *end;
    *end = 0;
    
    for(i=0;rs[i];i++)
    {
        if(!strncmp(rs[i],start,len))
        {
            *end = t;
            return rs[i];
        }
    }
    
    *end = t;
    return NULL;
}

void printone(char *cur,char *end)
{
    char t = *end;
    *end = 0;
    
    fprintf(lexout,"%s\n",cur);
    
    *end = t;
}

void escape(char **cur)
{
    char *tmp = *cur;
    while(strchr(" \n\t",*tmp) && *tmp) tmp++;
    *cur = tmp;
}

const char *err = NULL;
int parse(char *src)
{
    char *cur = src;
    char *tmp;
    
    while(*cur)
    {
        escape(&cur);
        //printf("%s\n",cur);
        if(isalpha(*cur))
        {
            const char *rt;
            tmp = cur+1;
            while(isalnum(*tmp)) tmp++;
            rt = isreservation(cur,tmp);
            
            if(rt) fprintf(lexout,"%s\t",rt);
            else fprintf(lexout,"ID\t");
            printone(cur,tmp);
            
            cur = tmp;
        }else if(isdigit(*cur))
        {
            tmp = cur+1;
            while(isdigit(*tmp)) tmp++;
            
            fprintf(lexout,"NUM\t");
            printone(cur,tmp);
            
            cur = tmp;
        }else if(*cur=='/' && *(cur+1) == '*')
        {
            tmp = cur+2;
            while(!(*tmp=='*' && *(tmp+1)=='/') && *tmp) tmp++;
            if(!*tmp)
            {
                err = "unclosed comment";
                return -1;
            }
            cur = tmp+2;
        }else if(*cur=='*' && *(cur+1) == '/')
        {
            err = "no start comment";
            return -1;
        }else if(strchr("+-*/=|;,<>!{}()",*cur))
        {
            if(*(cur+1) == '=')
            {
                if(strchr("<>=!",*cur))
                {
                    fprintf(lexout,"%c=\t%c=\n",*cur,*cur);
                    cur += 2;
                }
            }else
            {
                fprintf(lexout,"%c\t%c\n",*cur,*cur);
                cur += 1;
            }
        }else if(*cur == '%')
        {
            fprintf(lexout,"%c\t%c\n",*cur,*cur);
            cur += 1;
        }else{
            err = "unexpected char";
            return -1;
        }
        escape(&cur);
    }
    return 0;
}

int lex(const char *fsource)
{
    FILE *fp = fopen(fsource,"r");
    char *source;
    int length,ret;

    fseek(fp,0,SEEK_END);
    length = ftell(fp);
    fseek(fp,0,SEEK_SET);
    
    source = (char*)malloc(length+1);
    memset(source,0,length+1);
    fread(source,length,1,fp);
	fclose(fp);
    
	lexout = fopen("temp.file","w");
	ret = parse(source);
	fclose(lexout);
    if(ret)
    {
        printf("**词法分析错误 : %s\n",err);
		return -1;
    }else{
		FILE *ftmp = fopen("temp.file","r");
		char buf[100];
		while(!feof(ftmp)){
			if(fgets(buf,90,ftmp) == buf){
				printf("%s",buf);
			}
		}
		fclose(ftmp);
		printf("词法分析成功\n");

		return 0;
	}
}










