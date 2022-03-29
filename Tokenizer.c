//
// Created by derri on 3/7/2022.
//
#include <stdio.h>
#include <string.h>
#include "Tokenizer.h"

_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf) {
    int i;
    int p;
    int LCounter;
    int EL_index;
    char Whole[LEXEME_MAX];
    char WholeLine[LEXEME_MAX];
    char out[LEXEME_MAX];
    char plus[] ="+";
    char minus[] ="-";
    char LB [] ="{";
    char RB [] ="}";
    char LP [] ="(";
    char RP [] =")";
    char whil[] ="while";
    char key[]="return";
    char equal[] ="=";
    char comma[] =",";
    char semi[] =";";
    char n[] ="int";
    char n1[]="void";
    char div[] ="/";
    char multi[] ="*";
    char cannont[]="!=";
    char exact[]="==";
    char mod[]="%";
//gets the chars of the file, and put them in an array.
    while (fgets(Whole, 256, inf) != NULL) {
        for (i = 0; i < 256; i++) {
            if (Whole[i] == '\0' || Whole[i] == '\n') {
                WholeLine[256] = '\0';
                break;
            }
            WholeLine[i] = Whole[i];
            EL_index++;
        }

        for (i = 0; i < EL_index; i++) {

             if (!isalnum(WholeLine[i])) {
                 if(p>0) {
                     if(isalnum(out[p-1])) {
                         out[i] = '\0';
                         strcpy(aLex[LCounter].lexeme, out);
                         LCounter++;
                         p = 0;
                         //makes the array empty, so i can pass in a lexeme one at a time.
                         memset(out, 0, sizeof(out));
                     }
                 }
                 if (isspace(WholeLine[i])) {
                     continue;
                 }
             }
             //checks for the special characters
                if(!isalnum(WholeLine[i])) {
                    if (!isspace(WholeLine[i])) {
                        //checks for the !=, ==.
                        if (WholeLine[i] == '!' || WholeLine[i] == '=') {
                            //checks to see if the next index is =.
                            if (WholeLine[i + 1] == '=') {
                                out[p] = WholeLine[i];
                                p++;
                                out[p] = WholeLine[i + 1];
                                p++;
                                out[p] = '\0';
                                strcpy(aLex[LCounter].lexeme, out);
                                LCounter++;
                                p = 0;
                                memset(out, 0, sizeof(out));
                                continue;
                            } else {
                                out[p] = WholeLine[i];
                                p++;
                                out[p] = '\0';
                                strcpy(aLex[LCounter].lexeme, out);
                                LCounter++;
                                p = 0;
                                memset(out, 0, sizeof(out));
                                continue;
                            }

                        } else {
                            out[p] = WholeLine[i];
                            p++;
                            out[p] = '\0';
                            strcpy(aLex[LCounter].lexeme, out);
                            LCounter++;
                            p = 0;
                            memset(out, 0, sizeof(out));
                            continue;
                        }
                    }
                }
                //if its a number or letter add it to the other array, and wait for a space/symbol to pop up before it makes it a lexeme.
            if (isalnum(WholeLine[i])) {
                out[p] = WholeLine[i];
                p++;
                continue;
            }

        }
//reset line count
EL_index=0;
    }
    *numLex=LCounter;
//macthes  each lexeme with a token.
    for(i=0;i<LCounter;i++){


        if (validNumber(aLex[i].lexeme)){
            aLex[i].token=NUMBER;
            continue;
        }
        if(strcmp(aLex[i].lexeme,key)==0){
            aLex[i].token=RETURN_KEYWORD;
            continue;
        }
        if(strcmp(aLex[i].lexeme,n)==0|| strcmp(aLex[i].lexeme,n1)==0){
            aLex[i].token=VARTYPE;
            continue;
        }
        if(strcmp(aLex[i].lexeme,semi)==0){
            aLex[i].token=EOL;
            continue;
        }
        if(strcmp(aLex[i].lexeme,comma)==0){
            aLex[i].token=COMMA;
            continue;
        }
        if(strcmp(aLex[i].lexeme,equal)==0){
            aLex[i].token=EQUAL;
            continue;
        }
        if(strcmp(aLex[i].lexeme,whil)==0){
            aLex[i].token=WHILE_KEYWORD;
            continue;
        }
        if(strcmp(aLex[i].lexeme,RB)==0){
            aLex[i].token=RIGHT_BRACKET;
            continue;
        }
        if(strcmp(aLex[i].lexeme,LB)==0){
            aLex[i].token=LEFT_BRACKET;
            continue;
        }
        if(strcmp(aLex[i].lexeme,RP)==0){
            aLex[i].token=RIGHT_PARENTHESIS;
            continue;
        }
        if(strcmp(aLex[i].lexeme,LP)==0){
            aLex[i].token=LEFT_PARENTHESIS;
            continue;
        }

       if( strcmp(aLex[i].lexeme,minus)==0||strcmp(aLex[i].lexeme,plus)==0||
       strcmp(aLex[i].lexeme,cannont)==0||strcmp(aLex[i].lexeme,mod)==0||
       strcmp(aLex[i].lexeme,div)==0||strcmp(aLex[i].lexeme,multi)==0||
       strcmp(aLex[i].lexeme,exact)==0){
           aLex[i].token=BINOP;
           continue;
       }
        if ( validIdentifier(aLex[i].lexeme) ){
            aLex[i].token = IDENTIFIER;
            continue;
        }
       return TRUE;
    }
}

























