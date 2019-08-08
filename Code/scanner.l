%{
#include "parser.tab.h"
%}

digit [0-9]
letter [a-zA-Z]
metachar [{}();,?:]
operator [-+*/]
comment "//"[^\n]*$?
whitespace [ \t]+

%%

{comment}	;

{whitespace} 	;
 
({digit}+)   {
				store_token_name("NUM",yytext,yylineno);
				yylval.integer_value = atoi(yytext);
				return INTEGER_NUMBER;
			}

({digit}*"."{digit}+|{digit}+".") {
						store_token_name("FNUM",yytext,yylineno);
						yylval.double_value = atof(yytext);
						return DOUBLE_NUMBER;
					}

"="	{
		store_token_name("ASSIGN_OP",yytext,yylineno);
		yylval.string_value = new std::string;
		*(yylval.string_value) = yytext;
		return ASSIGN;
	}


"<"	{
		store_token_name("LESS_THAN",yytext,yylineno);
		yylval.string_value = new std::string;
		*(yylval.string_value) = yytext;
		return LESS_THAN;
	}

">"	{
		store_token_name("GREATER_THAN",yytext,yylineno);
		yylval.string_value = new std::string;
		*(yylval.string_value) = yytext;
		return GREATER_THAN;
	}

"<="	{
		store_token_name("LESS_THAN_EQUAL",yytext,yylineno);
		yylval.string_value = new std::string;
		*(yylval.string_value) = yytext;
		return LESS_THAN_EQUAL;
	}


">="	{
		store_token_name("GREATER_THAN_EQUAL",yytext,yylineno);
		yylval.string_value = new std::string;
		*(yylval.string_value) = yytext;
		return GREATER_THAN_EQUAL;
	}

"=="	{
		store_token_name("EQUAL",yytext,yylineno);
		yylval.string_value = new std::string;
		*(yylval.string_value) = yytext;
		return EQUAL;
	}

"!="	{
		store_token_name("NOT_EQUAL",yytext,yylineno);
		yylval.string_value = new std::string;
		*(yylval.string_value) = yytext;
		return NOT_EQUAL;
	}

"!"	{
		store_token_name("NOT",yytext,yylineno);
		yylval.string_value = new std::string;
		*(yylval.string_value) = yytext;
		return NOT;
	}

"||"	{
			store_token_name("OR",yytext,yylineno);
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext;
			return OR;
		}

"&&"	{
			store_token_name("AND",yytext,yylineno);
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext;
			return AND;
		}

"while" {
			store_token_name("WHILE",yytext,yylineno); 
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext;
			return WHILE;
		}

"do" 	{
			store_token_name("DO",yytext,yylineno); 
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext;
			return DO;
		}

"if" 	{
			store_token_name("IF",yytext,yylineno); 
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext;
			return IF;
		}

"else" 	{
			store_token_name("ELSE",yytext,yylineno); 
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext;
			return ELSE;
		}

"int"	{
			store_token_name("INTEGER",yytext,yylineno); 
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext;
			return INTEGER;
		}

"float"	{
			store_token_name("FLOAT",yytext,yylineno);
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext; 
			return FLOAT;
		}

"return"	{
				store_token_name("RETURN",yytext,yylineno);
				yylval.string_value = new std::string;
				*(yylval.string_value) = yytext; 
				return RETURN;
			}

"void"	{
			store_token_name("VOID",yytext,yylineno);
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext; 
			return VOID;
		}

"print"	{
			store_token_name("PRINT",yytext,yylineno);
			yylval.string_value = new std::string;
			*(yylval.string_value) = yytext; 
			return PRINT;
		}

({letter}|"_")({letter}|{digit}|"_")* {
								store_token_name("NAME",yytext,yylineno);
								yylval.string_value = new std::string;
								std::string s = yytext;
								if(s == "main"){
									*(yylval.string_value) = s;
								}
								else{
									*(yylval.string_value) = s + "_";
								}
								
								return NAME;
							}

{metachar} 	{
				store_token_name("META CHAR",yytext,yylineno);
				yylval.string_value = new std::string;
				*(yylval.string_value) = yytext;
				return yytext[0];
			}

{operator} 	{
				store_token_name("ARITHOP",yytext,yylineno);
				yylval.string_value = new std::string;
				*(yylval.string_value) = yytext;
				return yytext[0];
			}

"\n" 	{	
			//yylineno++;
		}

.       {
			printf("cs316: Error : Line no: %d --scanner internal Error\n", yylineno);
			exit(0);
		}


%%
