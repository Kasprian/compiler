%option noyywrap
%option yylineno
%{
#define YYSTYPE std::string
#include <stdio.h>
#include <string>
#include <iostream>
#include "parser.tab.h"

%}

%x COMMENT
%%

"["             { BEGIN(COMMENT);       }
<COMMENT>"]"    { BEGIN(INITIAL);   }
<COMMENT>(\n|.)
<COMMENT><<EOF>>    { printf("Błąd: niezakończony komentarz.\n"); yyterminate(); }

"DECLARE"       { return DECLARE;      }
"IN"         	{ return IN;      }
"END"           { return END;      }

"+"             { return ADD;      }
"-"             { return SUB;      }
"*"             { return MUL;      }
"/"             { return DIV;      }
"%"             { return MOD;      }
"("             { return LB;       }
")"             { return RB;       }

"="             { return EQ;       }
"<"             { return LT;       }
">"             { return GT;       }
"<="            { return LE;       }
">="            { return GE;       }
"!="            { return NE;       }

":="            { return ASSIGN;   }
"IF"            { return IF;       }
"THEN"          { return THEN;     }
"ELSE"          { return ELSE;     }
"ENDIF"         { return ENDIF;    }
"WHILE"         { return WHILE;    }
"DO"            { return DO;       }
"ENDWHILE"      { return ENDWHILE; }
"ENDDO"			{ return ENDDO;	}
"FOR"           { return FOR;      }
"FROM"          { return FROM;     }
"TO"            { return TO;       }
"DOWNTO"        { return DOWNTO;   }
"ENDFOR"        { return ENDFOR;   }
"READ"          { return READ;     }
"WRITE"         { return WRITE;    }


[0-9]+          { yylval = (char *)strdup(yytext);
                    return NUM;    }
[_a-z]+         { yylval = (char *)strdup(yytext);
                    return IDE;    }

";"             { return SEM;      }
":"             { return COLON;      }
[ \t\r\n]+
.

%%