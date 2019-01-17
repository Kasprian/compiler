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
      int k=0;
      bool write=false;
      string currentTabIndex="-1";

      void loadToRegister(string s, string place);
      void addToOutPut(string s);
      void storeInMemoryFromRegister(string s, string place);
      void storeInMemoryFromRegister(long long index,string place);
   
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
                                    variable var; var.name = $2; var.value = -2; var.index= -2;
                                    variables.push_back(var);
                              } else {
                                    cout << "Błąd, druga deklaracja " << $2 << endl;
                                    exit(1);
                              }
                        } SEM
      | declarations IDE LB NUM COLON NUM RB SEM {
                      
                              if(stoll($4)>stoll($6)){
                              cout << "Błąd, niewłaściwy zakres tablicy " << $2 << endl;
                                    exit(1);
                              }
                              if(myfind(variables, $2) == -1){
                                    for(long long i=stoi($4);i<=stoi($6);i++){
                                    variable var; var.name = $2; var.value = -2;var.index= i;
                                    variables.push_back(var);
                              }
                              } else {
                                    cout << "Błąd, druga deklaracja " << $2 << endl;
                                    exit(1);
                              }
                              
                             
      }

      |
      ; 

commands:
      commands command
      | command
;

command:  identifier ASSIGN {assign=1;} expression SEM {
                                                                        long long i = myfind(variables, $1);
                                                                        if(variables[i].index==-2){
                                                                        storeInMemoryFromRegister(i,"C");
                                                                        variables[i].value = temp;
                                                                        }else{
                                                                        long long index=myfindTable(variables, $1,currentTabIndex);
                                                                        storeInMemoryFromRegister(index,"C");
                                                                        variables[index].value = temp;
                                                                        }                  
                                                                  assign=0;
                                                }
             | IF condition THEN commands ELSE commands ENDIF
             | IF condition THEN commands ENDIF
             | WHILE condition DO commands ENDWHILE
             | DO commands WHILE condition ENDDO
             | FOR IDE FROM value TO value DO commands ENDFOR
             | FOR IDE FROM value DOWNTO value DO commands ENDFOR
             | READ identifier SEM { 
                              cout<<$2<<endl;
                              long long x ;
                              if(isNumber($2)){
                              x=stoll($2);
                              }else{
                              x = myfind(variables, $2);
                              if(x == -1){
                                    cout << "Błąd! Niezadeklarowana zmienna " << $2 << endl;
                                    exit(1);
                              }
                              if(variables[x].index!=-2){
                                                x= myfindTable(variables, $2,currentTabIndex);
                                          }
                              }
                              variables[x].value=-3;
                              output.push_back("SUB B B");
                              output.push_back("GET B");
                              storeInMemoryFromRegister(x,"B");

             }
             | WRITE {assign=1;write=true;} value SEM {
              output.push_back("PUT C");
              assign=0;
              write=false;
             }
             ;

expression:   value{    
                loadToRegister($1,"C");
                temp=getValue(variables,$1,currentTabIndex);}
             | value ADD value{
             loadToRegister($1,"B");
             loadToRegister($3,"C");
             long long a=getValue(variables,$1,currentTabIndex);
             long long b=getValue(variables,$3,currentTabIndex);
             temp=a+b;
             output.push_back("ADD C B");
             }
             | value SUB value{
             loadToRegister($1,"B");
             loadToRegister($3,"C");
             long long a=getValue(variables,$1,currentTabIndex);
             long long b=getValue(variables,$3,currentTabIndex);
             if(a>=b)
             temp=a-b;
             else
             temp=b-a;
             output.push_back("SUB C B");
             }
             | value MUL value{
                    if(getValue(variables,$1,currentTabIndex)>getValue(variables,$3,currentTabIndex)){
                    loadToRegister($1,"C");
                    loadToRegister($1,"B");
                    for(long long i=0;i<getValue(variables,$3,currentTabIndex)-1;i++){
                    output.push_back("ADD C B");
                    }
              }else{
                    loadToRegister($3,"C");
                    loadToRegister($3,"B");
                    for(long long i=0;i<getValue(variables,$1,currentTabIndex)-1;i++){
                        output.push_back("ADD C B");
                    }
                }
                 long long a=getValue(variables,$1,currentTabIndex);
                  long long b=getValue(variables,$3,currentTabIndex);
                temp=a*b;
            }
             | value DIV value{

             }
             | value MOD value
             ;

condition:  value EQ value
             | value NE value
             | value LT value
             | value GT value
             | value LE value
             | value GE value
             ;

value:       NUM   {if(write)
                        loadToRegister($1,"C");}               
             | identifier {if(write)
                        loadToRegister($1,"C");}    
             ;

identifier:       IDE   { 
                              long long x = myfind(variables, $1);
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
                  | IDE LB IDE RB{ 

                              long long x = myfind(variables, $3);
                               
                              if(x == -1){
                                    cout << "Błąd! Niezadeklarowana zmienna " << $3 << endl;
                                    exit(1);
                              } else {
                                    if(variables[x].value == -2){                                                            
                                    cout << "Błąd! Użycie niezainicjowanej zmiennej " << $3 << endl;
                                    exit(1);
                                    }
                              }
                              long long y = myfindTable(variables, $1,to_string(variables[x].value));
                              if(y == -1){
                                    cout << "Błąd! Niezadeklarowany element tablicy " << $1 << "("<<$3<<")"<< endl;
                                    exit(1);
                              } else if(assign==1){
                                    if(variables[y].value == -2){                                                            
                                    cout << "Błąd! Użycie niezainicjowanej zmiennej " << $1 << endl;
                                    exit(1);
                                    }
                              }

                              currentTabIndex=to_string(variables[x].value);

                        }
                  | IDE LB NUM RB { 
                              long long x = myfindTable(variables, $1,$3);
                              if(x == -1){
                                   cout << "Błąd! Niezadeklarowany element tablicy " << $1 << "("<<$3<<")"<< endl;
                                    exit(1);
                              } else if(assign==1){
                                    if(variables[x].value == -2){                                                            
                                    cout << "Błąd! Użycie niezainicjowanego elementy tablicy " << $1 << "("<<$3<<")"<< endl;
                                    exit(1);
                                    }
                              }
                              currentTabIndex=$3;
                        }
                  ;
%%

void wypisz(){
      for (long long i = 0; i < output.size(); i++){
            cout << output[i] << endl;
      }

}


void loadToRegister(string s, string place){ 
                                          if(isNumber(s)){ 
                                          output.push_back("SUB "+place+" "+place);
                                          //temp=getValue(variables,s,currentTabIndex);
                                          for(long long i=0;i<getValue(variables,s,currentTabIndex);i++){
                                          output.push_back("INC "+place);
                                          }
                              }else {      
                                          long long x = myfind(variables,s);
                                          if(variables[x].index!=-2){
                                                x= myfindTable(variables, s,currentTabIndex);
                                          }
                                          //temp=variables[x].value;
                                          output.push_back("SUB A A");
                                          for(long long i=0;i<x;i++){
                                          output.push_back("INC A");
                                          }
                                          output.push_back("LOAD "+place);
                                          }
                              
}

void storeInMemoryFromRegister(string s, string place){ 
                          long long index=myfind(variables,s);
                          output.push_back("SUB A A");
                          for(long long i=0;i<index;i++){
                          output.push_back("INC A");
                          }
                          output.push_back("STORE "+place);
}
void storeInMemoryFromRegister(long long index,string place){
                        output.push_back("SUB A A");
                          for(long long i=0;i<index;i++){
                          output.push_back("INC A");
                          }
                          output.push_back("STORE "+place);
}
void addToOutPut(string s){
      output.push_back(s);
      k++;                   
}



void yyerror (char const *s){
  cout << "Błąd składni [okolice linii " << yylineno << "]: " << s << endl;
  exit(1);
}
int main(void) {
    yyparse();
    wypisz();
   
    return 0;
}