//
// Created by derri on 3/12/2022.
//

#include "Parser.h"
#include "Givens.h"

_Bool IP(struct lexics *someLexics){

    int i =3;

    if (someLexics[i].token == LEFT_PARENTHESIS){
        return TRUE;
    }
    if(someLexics[i].token != VARTYPE && someLexics[i+1].token !=IDENTIFIER){
        return FALSE;
    }
    if(someLexics[i+3].token ==COMMA && someLexics[i+4].token != VARTYPE && someLexics[i+5].token !=IDENTIFIER){
        return FALSE;
    }

}

_Bool parser(struct lexics *someLexics, int numberOfLexics) {

  if(someLexics[0].token!=VARTYPE){
      return FALSE;
  }

if(someLexics[1].token!=IDENTIFIER){
    return FALSE;
}


if(someLexics[2].token!=LEFT_PARENTHESIS){
    return FALSE;
}
if (!IP(someLexics)) {
    return FALSE;
}

if(someLexics[numberOfLexics-2].token!=RETURN_KEYWORD){
    return FALSE;
}
    if(someLexics[numberOfLexics-1].token!=IDENTIFIER) {
        return FALSE;
    }
    if(someLexics[numberOfLexics].token!=EOL) {
        return FALSE;
    }
    else
        return TRUE;

}