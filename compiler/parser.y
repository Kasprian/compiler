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
        extern FILE *yyin;
        void yyerror(char const *s);
        vector<string> output;
        vector<variable> variables;
        vector<variable> forIterators;
        vector<long long int> whilejumps;
        vector<long long int> ifjumps;
        vector<long long int> forjumps;
        bool assign=true;
        long long int currentIndex=0;
        long long int k=0;
        bool write=false;
        bool table=false;

        void loadToRegister(string s, string place,string tableIndex);
        void addToOutPut(string s);
        void storeInMemoryFromRegister(string s, string place, string tableIndex);

        void storeInMemoryIterator(string s,string place);
        void loadLastIterator();
        void storeInMemoryIterator2(string s,string place);
        void loadLastIterator2();

        string decToBin(long long int n);
        void addToRegisterValue(long long int n,string place);

        string ideName[2] = {"-1", "-1"};
        string ideIndex[2] = {"-1", "-1"};

        string tableAssignIndex = "-1";
        string assignIDE="";
   
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
                                    addToOutPut("HALT");}
      ;

declarations:
      declarations IDE {      
                                if(myfind(variables, $2) == -1){
                                        variable var; 
                                        var.name = $2;
                                        var.initialized=false; 
                                        var.beginIndex= -1;
                                        var.endIndex= -1;
                                        var.table=false;
                                        var.memBeginIndex=currentIndex;
                                        var.memEndIndex=currentIndex;
                                        currentIndex++;
                                        variables.push_back(var);
                                } else {
                                        cout << "Błąd, użyto już" << $2 << "do deklaracji."<<endl;
                                        exit(1);
                                }
                        } SEM
      | declarations IDE LB NUM COLON NUM RB SEM {
                                long long int begin=atoll($4.c_str());
                                long long int end=atoll($6.c_str());
                                if(begin>end){
                                cout << "Błąd, niewłaściwy zakres tablicy " << $2 << endl;
                                    exit(1);
                                }
                                if(myfind(variables, $2) == -1){
                                        variable var; 
                                        var.name = $2;
                                        var.initialized=false;
                                        var.table=true;
                                        var.beginIndex=begin;
                                        var.endIndex=end;
                                        var.memBeginIndex=currentIndex;
                                        currentIndex=currentIndex+(end-begin);
                                        var.memEndIndex=currentIndex;
                                        currentIndex++;
                                        variables.push_back(var);

                                } else {
                                        cout << "Błąd, użyto już" << $2 << "do deklaracji."<<endl;
                                        exit(1);
                                }
      }
      |
      ;

commands:
      commands command
      | command
;

command:        identifier ASSIGN {assign=false;} expression SEM {   
                                                        long long int index=myfind(variables, $1);
                                                        if(variables[index].table==false){
                                                        variables[index].initialized=true;
                                                        } 
                                                        storeInMemoryFromRegister($1,"D",tableAssignIndex);
                                                       // tableAssignIndex="-1";     
                                                        assign=true;
                                                }
                | IF{assign=false;} condition{assign=true;
                                        ifjumps.push_back(k);
                                        addToOutPut("JZERO D ");
                                        } THEN commands ifend
                | whilecond                     {
                                                whilejumps.push_back(k);
                                                addToOutPut("JZERO D ");
                                                } DO commands ENDWHILE {
                                                output[whilejumps.back()]=output[whilejumps.back()]+toString(k+1);
                                                whilejumps.pop_back();
                                                addToOutPut("JUMP "+toString(whilejumps.back()));
                                                whilejumps.pop_back();
                                                }
                | DO {whilejumps.push_back(k);}commands whilecond{
                                                        whilejumps.pop_back();
                                                        addToOutPut("JZERO D "+toString(k+2));
                                                        addToOutPut("JUMP "+toString(whilejumps.back()));
                                                        }ENDDO{
                                                        whilejumps.pop_back();
                                                        }
                | FOR IDE {
                                long long int x=myfind(variables,$2);
                                //long long int y=myfind(forIterators,$2);
                                if(x==-1){
                                        variable var; 
                                        var.name = $2;
                                        var.initialized=true; 
                                        var.beginIndex= -1;
                                        var.endIndex= -1;
                                        var.table=false;
                                        var.memBeginIndex=currentIndex;
                                        var.memEndIndex=currentIndex;
                                        currentIndex++;
                                        variables.push_back(var);
                                        var.memBeginIndex=currentIndex;
                                        var.memEndIndex=currentIndex;
                                        currentIndex++;
                                        forIterators.push_back(var);
                                }else {
                                        cout << "Błąd, użyto już" << $2 << "do deklaracji."<<endl;
                                        exit(1);
                                }
                                assign=false;
                                assignIDE=$2;
                }  FROM value forend     
                | READ{assign=true;} identifier SEM { 
                                        long long int index=myfind(variables, assignIDE);
                                        if(variables[index].table==false){
                                        variables[index].initialized=true;
                                        } 
                                        addToOutPut("SUB D D");
                                        addToOutPut("GET D");
                                        storeInMemoryFromRegister(assignIDE,"D",tableAssignIndex);
                                        assign=true;
                                        }
                | WRITE {
                        assign=false;
                        write=true;
                        } value SEM {
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        addToOutPut("PUT D");
                                        assign=false;
                                        write=false;
                                        ideName[0] = "-1";
                                        ideIndex[0] = "-1";
                                        assign=true;
                                        write=false;
                                        }
             ;

forend:        TO value DO {    loadToRegister(ideName[0],"D",ideIndex[0]);
                                loadToRegister(ideName[1],"E",ideIndex[1]);
                                storeInMemoryIterator(assignIDE,"D");
                                forjumps.push_back(k);
                                addToOutPut("JZERO D ");
                                ideName[0]="-1";
                                ideIndex[0]="-1";
                                ideName[1]="-1";
                                ideIndex[1]="-1";
                                assign = true;
         } commands ENDFOR {
                                loadLastIterator();
                                addToOutPut("DEC D");
                                addToOutPut("STORE D");
                                addToOutPut("JUMP "+toString(forjumps.back()));
                                output[forjumps.back()]=output[forjumps.back()]+toString(k);
                                forjumps.pop_back();
                                variables.pop_back();
                                forIterators.pop_back();
                                assign=true;
                         }
                |    DOWNTO value DO {
                                loadToRegister(ideName[0],"D",ideIndex[0]);
                                loadToRegister(ideName[1],"E",ideIndex[1]);
                                storeInMemoryIterator2(assignIDE,"D");
                                forjumps.push_back(k);
                                addToOutPut("JZERO D ");
                                ideName[0]="-1";
                                ideIndex[0]="-1";
                                ideName[1]="-1";
                                ideIndex[1]="-1";
                                assign = true; } commands ENDFOR {
                                                loadLastIterator2();
                                                addToOutPut("DEC D");
                                                addToOutPut("STORE D");
                                                addToOutPut("JUMP "+toString(forjumps.back()));
                                                output[forjumps.back()]=output[forjumps.back()]+toString(k);
                                                forjumps.pop_back();
                                                variables.pop_back();
                                                forIterators.pop_back();
                                                assign=true;
                         }
                ;   

whilecond:                  WHILE       {       
                                        assign=false;
                                        whilejumps.push_back(k);
                                        } condition {   
                                                assign=true;
                                        }
        ;

ifend:         ELSE {                  
                                        long long int elsejump=k;
                                        addToOutPut("JUMP ");
                                        output[ifjumps.back()]=output[ifjumps.back()]+toString(k);
                                        ifjumps.pop_back();
                                        ifjumps.push_back(elsejump);
                        }commands ENDIF{
                                        output[ifjumps.back()]=output[ifjumps.back()]+toString(k);
                                        ifjumps.pop_back();
                        }
                |       ENDIF{                  
                                        output[ifjumps.back()]=output[ifjumps.back()]+toString(k);
                                        ifjumps.pop_back();
                        }
                ;

expression:     value{                
                                loadToRegister(ideName[0],"D",ideIndex[0]);
                                ideName[0]="-1";
                                ideIndex[0]="-1";
                                }
                |value ADD value{
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("ADD D E");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                                }
                |value SUB value{
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("SUB D E");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                                }
                | value MUL value{
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("SUB F F");
                                        long long start=k;
                                        addToOutPut("JZERO E "+toString(start+7));
                                        addToOutPut("JODD E "+toString(start+5));
                                        addToOutPut("ADD D D");
                                        addToOutPut("HALF E");
                                        addToOutPut("JUMP "+toString(start));
                                        addToOutPut("ADD F D");
                                        addToOutPut("JUMP "+toString(start+2));
                                        addToOutPut("COPY D F");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                }
                | value DIV value{
                                        /*loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("JZERO E "+toString(k+10));
                                        addToOutPut("SUB F F");
                                        addToOutPut("COPY G D");
                                        addToOutPut("COPY H G");
                                        addToOutPut("INC H");
                                        addToOutPut("SUB H E");
                                        long long start=k;
                                        addToOutPut("JZERO H "+toString(start+5));
                                        addToOutPut("SUB G E");
                                        addToOutPut("INC F");
                                        addToOutPut("JUMP "+toString(start-1));
                                        addToOutPut("SUB F F");
                                        addToOutPut("COPY D F");*/

                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                        addToOutPut("SUB H H");
                                        addToOutPut("SUB F F");
	                                    addToOutPut("SUB G G");
	                                    addToOutPut("JZERO E "+toString(k+20));
	                                    addToOutPut("INC G");
	                                    addToOutPut("COPY H D");
										addToOutPut("COPY B D");
										addToOutPut("COPY C E");
										addToOutPut("SUB B C");
										addToOutPut("JZERO B "+toString(k+4));
										addToOutPut("ADD E E");
										addToOutPut("ADD G G");
										addToOutPut("JUMP "+toString(k-7));
										addToOutPut("COPY B H");
										addToOutPut("INC B");
										addToOutPut("SUB B E");
										addToOutPut("JZERO B "+toString(k+3));
										addToOutPut("SUB H E");
										addToOutPut("ADD F G");
										addToOutPut("HALF E");
										addToOutPut("HALF G");
										addToOutPut("JZERO G "+toString(k+2));
										addToOutPut("JUMP "+toString(k-9));
										addToOutPut("COPY D F");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                }
                | value MOD value       {
                                        loadToRegister(ideName[0],"D",ideIndex[0]);
                                        loadToRegister(ideName[1],"E",ideIndex[1]);
                                       /* addToOutPut("JZERO E "+toString(k+8));
                                        addToOutPut("COPY G D");
                                        addToOutPut("COPY H G");
                                        addToOutPut("INC H");
                                        addToOutPut("SUB H E");
                                        long long start=k;
                                        addToOutPut("JZERO H "+toString(start+4));
                                        addToOutPut("SUB G E");
                                        addToOutPut("JUMP "+toString(start-1));
                                        addToOutPut("SUB G G");
                                        addToOutPut("COPY D G");*/

                                        addToOutPut("SUB H H");
                                        addToOutPut("SUB F F");
	                                    addToOutPut("SUB G G");
	                                    addToOutPut("JZERO E "+toString(k+20));
	                                    addToOutPut("INC G");
	                                    addToOutPut("COPY H D");
										addToOutPut("COPY B D");
										addToOutPut("COPY C E");
										addToOutPut("SUB B C");
										addToOutPut("JZERO B "+toString(k+4));
										addToOutPut("ADD E E");
										addToOutPut("ADD G G");
										addToOutPut("JUMP "+toString(k-7));
										addToOutPut("COPY B H");
										addToOutPut("INC B");
										addToOutPut("SUB B E");
										addToOutPut("JZERO B "+toString(k+3));
										addToOutPut("SUB H E");
										addToOutPut("ADD F G");
										addToOutPut("HALF E");
										addToOutPut("HALF G");
										addToOutPut("JZERO G "+toString(k+2));
										addToOutPut("JUMP "+toString(k-9));
										addToOutPut("COPY D H");
                                        ideName[0]="-1";
                                        ideIndex[0]="-1";
                                        ideName[1]="-1";
                                        ideIndex[1]="-1";
                }
                ;


condition: value EQ value{
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("COPY F D");
                        addToOutPut("COPY H E");
                        addToOutPut("SUB D H");
                        addToOutPut("SUB E F");
                        addToOutPut("ADD D E");
                        addToOutPut("JZERO D "+toString(k+3));
                        addToOutPut("SUB D D");
                        addToOutPut("JUMP "+toString(k+2));
                        addToOutPut("INC D");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                        assign=true;
}
                | value NE value{
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("COPY F D");
                        addToOutPut("COPY H E");
                        addToOutPut("SUB D H");
                        addToOutPut("SUB E F");
                        addToOutPut("ADD D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
                |  value LT value{
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("SUB E D");
                        addToOutPut("COPY D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
                | value GT value{
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("SUB D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
                |  value LE value{
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("INC E");
                        addToOutPut("SUB E D");
                        addToOutPut("COPY D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
                | value GE value{
                        loadToRegister(ideName[0],"D",ideIndex[0]);
                        loadToRegister(ideName[1],"E",ideIndex[1]);
                        addToOutPut("INC D");
                        addToOutPut("SUB D E");
                        ideName[0]="-1";
                        ideIndex[0]="-1";
                        ideName[1]="-1";
                        ideIndex[1]="-1";
                }
                ;

value:          NUM             {
                                if (ideName[0] == "-1"){
                                        ideName[0] = $1;
                                }
                                else{
                                        ideName[1] = $1;
                                }
               }               
                | identifier   
                ;

identifier:     IDE     { 
                                long long int x = myfind(variables, $1);
                                if(x == -1){
                                        cout << "Błąd! Niezadeklarowana zmienna " << $1 << endl;
                                        exit(1);
                                }else if(variables[x].table==true){
                                        cout << "Błąd! Zmienna" << $1 << "jest tablicą."<<endl;
                                        exit(1);
                                }else if(!assign){
                                        if(variables[x].initialized == false){                                                            
                                        cout << "Błąd! Użycie niezainicjowanej zmiennej " << $1 << endl;
                                        exit(1);
                                        }
                                }
                                if(!assign){
                                        if (ideName[0] == "-1"){
                                                ideName[0] = $1;
                                        }
                                        else{
                                                ideName[1] = $1;
                                        }       
                                }else{
                                assignIDE=$1;
                                }
                        }
                  | IDE LB IDE RB{ 
                                long long int x = myfind(variables, $3);
                               
                                if(x == -1){
                                        cout << "Błąd! Niezadeklarowana zmienna" << $3 << endl;
                                        exit(1);
                                } else if(variables[x].table==true){
                                        cout << "Błąd! Zmienna" << $3 << "jest tablicą."<<endl;
                                        exit(1);
                                }else {
                                        if(variables[x].initialized == false){                                                            
                                                cout << "Błąd! Użycie niezainicjowanej zmiennej " << $3 << endl;
                                                exit(1);
                                        }
                                }
                                long long int y = myfind(variables, $1);
                                if(y == -1){
                                        cout << "Błąd! Niezadeklarowana tablica" << $1 << endl;
                                        exit(1);
                                }  else if(variables[y].table==false){
                                        cout << "Błąd! Zmienna" << $1 << "nie jest tablicą."<<endl;
                                        exit(1);
                                }

                                if(!assign){
                                        if (ideName[0] == "-1"){
                                                ideName[0] = $1;
                                                ideIndex[0] = $3;
                                        }
                                        else{
                                                ideName[1] = $1;
                                                ideIndex[1] = $3;
                                        }
                                }else{
                                        assignIDE=$1;
                                        tableAssignIndex=$3;
                                }

                        }
                  | IDE LB NUM RB { 
                                long long int  x = myfind(variables, $1);
                                long long int number= atoll($3.c_str());
                                if(x == -1){
                                        cout << "Błąd! Niezadeklarowana tablica " << $1 << endl;
                                        exit(1);
                                } else if(variables[x].table==false){
                                        cout << "Błąd! Zmienna" << $1 << "nie jest tablicą."<<endl;
                                        exit(1);
                                }
                                else if(number < variables[x].beginIndex || number > variables[x].endIndex){                                                          
                                        cout << "Błąd! Odwołanie się do niestniejącego elementu tablicy" << $1 << "("<<$3<<")"<<endl;
                                        exit(1);
                                }
                                if(!assign){
                                        if (ideName[0] == "-1"){
                                                ideName[0] = $1;
                                                ideIndex[0] = $3;
                                        }
                                        else{
                                                ideName[1] = $1;
                                                ideIndex[1] = $3;
                                        }
                                }else{
                                        assignIDE=$1;
                                      tableAssignIndex=$3;          
                                }
                        }
                  ;
%%



void loadToRegister(string s, string place, string tableIndex){ 
                                if(isNumber(s)){ 
                                        long long int n = stoll(s);
                                        /*string bin = decToBin(n);
                                        long long int limit = bin.size();
                                        addToOutPut("SUB "+place+" "+place);
                                        for(long long int i = 0; i < limit; ++i){
                                                if(bin[i] == '1'){
                                                        addToOutPut("INC "+place);
                                                }
                                                if(i < (limit - 1)){
                                                        addToOutPut("ADD "+place+" "+place);
                                                }
                                        }*/
                                        addToRegisterValue(n,place);
                                        
                                }else {      
                                        long long int x=myfind(variables,s);
                                        if(variables[x].table==true){
                                                if(!isNumber(tableIndex)){
                                                        long long int y=myfind(variables,tableIndex);
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[y].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[y].memBeginIndex,"A");
                                                        addToOutPut("LOAD B");
                                                        /*addToOutPut("SUB C C");
                                                        for(long long int i=0;i<variables[x].beginIndex;i++){
                                                                addToOutPut("INC C");
                                                        }*/
                                                        addToRegisterValue(variables[x].beginIndex,"C");
                                                        addToOutPut("SUB B C");
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[x].memBeginIndex,"A");
                                                        addToOutPut("ADD A B");
                                                        addToOutPut("LOAD "+place);
                                                }else{
                                                        long long targetTableIndex=atoll(tableIndex.c_str());
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[x].memBeginIndex,"A");
                                                        addToRegisterValue(targetTableIndex-variables[x].beginIndex,"B");
                                                        addToOutPut("ADD A B");
                                                        /*for(long long int i=0;i<targetTableIndex-variables[x].beginIndex;i++){
                                                                addToOutPut("INC A");  
                                                        }*/
                                                        addToOutPut("LOAD "+place);
                                                }
                                        }else{
                                                /*addToOutPut("SUB A A");
                                                for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                addToOutPut("INC A");
                                                }*/
                                                addToRegisterValue(variables[x].memBeginIndex,"A");
                                                addToOutPut("LOAD "+place);
                                        }
                                }
                              
}
void storeInMemoryIterator(string s,string place){
                long long int x=myfind(variables,s);
                addToRegisterValue(variables[x].memBeginIndex,"A");
                addToOutPut("STORE D");
                addToOutPut("SUB E D");
                addToOutPut("COPY D E");
                addToOutPut("INC D");
                long long int y=myfind(forIterators,s);
                addToRegisterValue(forIterators[y].memBeginIndex,"A");
                addToOutPut("STORE D");
}
void storeInMemoryIterator2(string s,string place){
                long long int x=myfind(variables,s);
                addToRegisterValue(variables[x].memBeginIndex,"A");
                addToOutPut("STORE D");
                addToOutPut("SUB D E");
                addToOutPut("INC D");
                long long int y=myfind(forIterators,s);
                addToRegisterValue(forIterators[y].memBeginIndex,"A");
                addToOutPut("STORE D");
}
void loadLastIterator(){
        long long int x=myfind(variables,variables.back().name);
        addToRegisterValue(variables[x].memBeginIndex,"A");
        addToOutPut("LOAD D");
        addToOutPut("INC D");
        addToOutPut("STORE D");
        addToOutPut("INC A");
        addToOutPut("LOAD D");
                                
}

void loadLastIterator2(){
        long long int x=myfind(variables,variables.back().name);
        addToRegisterValue(variables[x].memBeginIndex,"A");
        addToOutPut("LOAD D");
        addToOutPut("DEC D");
        addToOutPut("STORE D");
        addToOutPut("INC A");
        addToOutPut("LOAD D");
                                
}

void storeInMemoryFromRegister(string s, string place, string tableIndex){
                                        long long int x=myfind(variables,s);
                                        if(variables[x].table==true){
                                                if(!isNumber(tableIndex)){
                                                        long long int y=myfind(variables,tableIndex);
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[y].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[y].memBeginIndex,"A");
                                                        addToOutPut("LOAD B"); //  uzyskanie wartości a, w B wartość a
                                                        /*addToOutPut("SUB C C");
                                                        for(long long int i=0;i<variables[x].beginIndex;i++){
                                                                addToOutPut("INC C"); // wpisanie początku tablicy
                                                        }*/
                                                        addToRegisterValue(variables[x].beginIndex,"C");
                                                        addToOutPut("SUB B C"); // wartość a - początek tablicy, ile mamy skoczyć
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }*/
                                                        addToRegisterValue(variables[x].memBeginIndex,"A");
                                                        addToOutPut("ADD A B"); // dodanie do A 
                                                        addToOutPut("STORE "+place);
                                                }else{
                                                        long long targetTableIndex=atoll(tableIndex.c_str());
                                                        /*addToOutPut("SUB A A");
                                                        for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                                addToOutPut("INC A");
                                                        }
                                                        for(long long int i=0;i<targetTableIndex-variables[x].beginIndex;i++){
                                                                addToOutPut("INC A");  
                                                        }*/
                                                        addToRegisterValue(variables[x].memBeginIndex,"A");
                                                        addToRegisterValue(targetTableIndex-variables[x].beginIndex,"B");
                                                        addToOutPut("ADD A B");
                                                        addToOutPut("STORE "+place);
                                                }
                                        }else{
                                                /*addToOutPut("SUB A A");
                                                for(long long int i=0;i<variables[x].memBeginIndex;i++){
                                                addToOutPut("INC A");
                                                }*/
                                                addToRegisterValue(variables[x].memBeginIndex,"A");
                                                addToOutPut("STORE "+place);
                                        }
}

void addToRegisterValue(long long int n,string place){
                                        string bin = decToBin(n);
                                        long long int leng = bin.size();
                                        addToOutPut("SUB "+place+" "+place);
                                        for(long long int i = 0; i < leng; ++i){
                                                if(bin[i] == '1'){
                                                        addToOutPut("INC "+place);
                                                }
                                                if(i < (leng - 1)){
                                                        addToOutPut("ADD "+place+" "+place);
                                                }
                                        }

}
void addToOutPut(string s){
      output.push_back(s);
    //cout << s << endl;
      k++;                   
}


string decToBin(long long int n) {
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}



void yyerror (char const *s){
        cout << "Błąd składni w pobliżu linii " << yylineno << ": " << s << endl;
        exit(1);
}

void wypisz(char* argv){
        ofstream myfile;
        myfile.open (argv);
        for (long long int  i = 0; i < output.size(); i++){
                myfile << output[i]+"\n";
        }
        myfile.close();
}

int main(int argc, char* argv[]){
        yyin = fopen(argv[1],"r");
        yyparse();
        wypisz(argv[2]);
        fclose(yyin);
        return 0;
}