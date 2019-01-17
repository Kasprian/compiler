%{
      #define YYSTYPE std::string
      #include <algorithm>
      #include <cstdio>
      #include <stdio.h>
      #include <iostream>
      #include <fstream>
      #include <string>
      #include <deque>
      #include <stack>
      #include <vector>
      #include "functions.h"

      int yylex();
      extern int yylineno;
      void yyerror(char const *s);
      vector<string> output;
      vector<variable> variables;
      vector<variable> memory;
      int assign=0;
      long long int temp;
   
%}
%start program
%token NUM
%token IDE
%token DECLARE IN END 
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE ENDDO
%token FOR FROM ENDFOR
%token WRITE READ SEM TO DOWNTO
%token LB RB ASSIGN EQ LT GT LE GE NE ADD SUB MUL DIV MOD COLON


%%
program:
      DECLARE declarations IN commands END {
                                    output.push_back("HALT");}
      ;

declarations:
      declarations IDE {      
                              if(myfind(variables, $2) == -1){
                                    variable var; var.name = $2; var.value = -2;
                                    variables.push_back(var);
                              } else {
                                    cout << "Błąd, druga deklaracja " << $2 << endl;
                                    exit(1);
                              }
                        } SEM
      | declarations IDE LB NUM COLON NUM RB SEM {
                              if($4>$6){
                              cout << "Błąd, druga deklaracja " << $2 << endl;
                                    return 0;
                              }
      }

      |
      ; 

commands:
      commands command
      | command
;

command:  identifier ASSIGN {assign=1;} expression SEM {
                                                                        if(myfind(variables, $1) == -1){
                                                                        cout << "Błąd! Niezadeklarowana zmienna." << endl;
                                                                        return 0;
                                                                  } else {
                                                                        int index=myfind(variables,$1);
                                                                        output.push_back("SUB A A");
                                                                        for(int i=0;i<index;i++){
                                                                        output.push_back("INC A");
                                                                        }
                                                                        output.push_back("STORE C");
                                                                        int i = myfind((variables), $1);
                                                                        (variables)[i].value = temp;                     
                                                                  }
                                                                  assign=0;
                                                }
             | IF condition THEN commands ELSE commands ENDIF
             | IF condition THEN commands ENDIF
             | WHILE condition DO commands ENDWHILE
             | DO commands WHILE condition ENDDO
             | FOR IDE FROM value TO value DO commands ENDFOR
             | FOR IDE FROM value DOWNTO value DO commands ENDFOR
             | READ IDE SEM { 
                              int x = myfind(variables, $2);
                              if(x == -1){
                                    cout << "Błąd! Niezadeklarowana zmienna " << $2 << endl;
                                    exit(1);
                              }
                              variables[x].value=-1;
                              output.push_back("SUB B B");
                              output.push_back("GET B");
                              output.push_back("SUB A A");
                              for(int i=0;i<x;i++){
                              output.push_back("INC A");
                              }
                              output.push_back("STORE B");

             }
             | WRITE value SEM {
                                          int x = myfind(variables,$2);
                                          output.push_back("SUB A A");
                                          for(int i=0;i<x;i++){
                                          output.push_back("INC A");
                                          }
                                          output.push_back("LOAD C");
                                          output.push_back("PUT C");
             }
             ;

expression:       value{      if(isNumber($1)){ 
                                          output.push_back("SUB C C");
                                          temp=getValue(variables,$1);
                                          for(int i=0;i<getValue(variables,$1);i++){
                                          output.push_back("INC C");
                                          }
                              }else {
                                          int x = myfind(variables,$1);
                                          output.push_back("SUB C C");
                                          for(int i=0;i<variables[x].value;i++){
                                          output.push_back("INC C");
                                          }
                              }
                        }
             | value ADD value{
                        
             }
             | value SUB value
             | value MUL value
             | value DIV value
             | value MOD value
             ;

condition:  value EQ value
             | value NE value
             | value LT value
             | value GT value
             | value LE value
             | value GE value
             ;

value:       NUM                    /*{     output.push_back("SUB C C");
                                          temp=getValue(variables,$1);
                                          for(int i=0;i<getValue(variables,$1);i++){
                                          output.push_back("INC C");
                                          }

                                    }*/
             | identifier     /*{           int x = myfind(variables,$1);
                                          output.push_back("SUB A A");
                                          for(int i=0;i<x;i++){
                                          output.push_back("INC A");
                                          }
                                          output.push_back("LOAD C");
                              }*/
             ;

identifier:       IDE   { 
                              int x = myfind(variables, $1);
                              if(x == -1){
                                    cout << "Błąd! Niezadeklarowana zmienna " << $1 << endl;
                                    exit(1);
                              } else if(assign==1){
                                    if(variables[x].value == -2){                                                            
                                    cout << "Błąd! Użycie niezainicjowanej zmiennej " << $1 << endl;
                                    exit(1);
                                    }
                              }
                        }
                  | IDE LB IDE RB
                  | IDE LB NUM RB
                  ;
%%

void wypisz(){
      for (int i = 0; i < output.size(); i++){
            cout << output[i] << endl;
      }

}



void yyerror (char const *s){
  cout << "Błąd [okolice linii " << yylineno << "]: " << s << endl;
}
int main(void) {
    yyparse();
    wypisz();
   
    return 0;
}