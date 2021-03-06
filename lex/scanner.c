#include <stdio.h>
#include <string.h>
#include "scanner.h"

extern int yylex();
extern void yyset_in(FILE* fp);
extern int yylineno;
extern char* yytext;

char tokens[TOKEN_COUNT][10];


int main( const int argc,const char** argv){
    int k,count=0;

    strcpy(tokens[IDENTIFIER],"ID");
    strcpy(tokens[KEYWORD],"KW");
    strcpy(tokens[OPERATOR],"OP");
    strcpy(tokens[DELIMITER],"DLIM");
    strcpy(tokens[HEX_NUM],"NUMBER");
    strcpy(tokens[DEC_NUM],"NUMBER");
    strcpy(tokens[REAL_NUM],"REAL");
    strcpy(tokens[STRING],"STRING");
    strcpy(tokens[CHAR],"CHAR");

    FILE* f_out,*f_in,*intermidiate_file;

    if(argc < 4){
        printf("Expected arguments [input file] [output file]\n");
        return 1;
    }


    f_in = fopen(argv[1],"r");
    f_out = fopen(argv[2],"w");
    intermidiate_file = fopen(argv[3],"w");

    printf("%s %s %s\n",argv[1],argv[2],argv[3]);

    yyset_in(f_in);


    while(k = yylex()){
        count++;
        fprintf(f_out,"%-3d: %-10s %s\n",count,tokens[k],yytext);
        fprintf(intermidiate_file,"%s",yytext);
    }

    fclose(f_out);
    fclose(f_in);
    fclose(intermidiate_file);
    return 0;
}
