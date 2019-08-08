%{
#include <stdio.h>
extern "C" void yyerror(char *s);
extern int yylex(void);
extern int yylineno;
Symbol_Table * global_symbol_table = new Symbol_Table(), *local_symbol_table = new Symbol_Table();
%}
%token INTEGER_NUMBER
%token ASSIGN
%token INTEGER
%token NAME
%token VOID
%token DOUBLE_NUMBER
%token RETURN
%token FLOAT
%token LESS_THAN
%token LESS_THAN_EQUAL
%token GREATER_THAN
%token GREATER_THAN_EQUAL
%token EQUAL
%token NOT_EQUAL
%token AND
%token OR
%token NOT
%token WHILE
%token DO
%token IF
%token ELSE
%token PRINT

%right ASSIGN
%left '?' ':'
%left OR
%left AND
%left EQUAL NOT_EQUAL
%left GREATER_THAN_EQUAL LESS_THAN_EQUAL LESS_THAN GREATER_THAN
%left '+' '-'
%left '*' '/'
%right NOT

%union{
	int integer_value;
	double double_value;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;
	list<Symbol_Table_Entry *>* symbol_entry_list;
	Data_Type type;
}


%type<ast> E constant variable assignment_statement statement unmatched_stmt matched_stmt logical_expression boolean_expression 
%type<ast_list> statement_list
%type<symbol_entry_list> variable_list
%type<string_value> NAME
%type<symbol_table> local_variable_declaration local_variable_declaration_list local_optional_variable_declaration_list
%type<symbol_table> global_variable_declaration global_variable_declaration_list global_optional_variable_declaration_list
%type<type> data_type
%type<procedure> procedure_definition
%type<integer_value> INTEGER_NUMBER
%type<double_value> DOUBLE_NUMBER
%%

program		:	global_optional_variable_declaration_list
				procedure_definition {program_object.set_procedure($2, yylineno);
									  $1->set_table_scope(global);
									  program_object.set_global_table(*$1);
									 }
			;

// declaration_list	:	procedure_declaration
// 					|	variable_declaration_list 
// 						procedure_declaration
// 					|	procedure_declaration 
// 						variable_declaration_list
// 					;


// procedure_declaration	:	/* empty */	
// 						|	VOID NAME '(' ')' ';'
//     		  			;

procedure_definition	:	VOID NAME '(' ')'
							'{'
							local_optional_variable_declaration_list
							statement_list
							'}'			{$$ = new Procedure(void_data_type,*$2,yylineno);
										 $$->set_ast_list(*$7);
										 $6->set_table_scope(local);
										 $$->set_local_list(*$6);
										 
										}
                        ;

local_optional_variable_declaration_list	:	/* empty */{$$ = new Symbol_Table();}
									|	local_variable_declaration_list {	
																			$$ = $1;
																			// local_symbol_table = new Symbol_Table();
																			// local_symbol_table = $1; 
																		}
									;

local_variable_declaration_list	:	local_variable_declaration {$$ = $1;}
							|	local_variable_declaration_list 
								local_variable_declaration {$1->append_list(*$2,yylineno);$$ = $1;}
							;

local_variable_declaration	:	data_type variable_list ';' {	$$ = new Symbol_Table();
															for (list<Symbol_Table_Entry*>::iterator it=$2->begin(); it != $2->end(); ++it){
																if(local_symbol_table->is_empty()){
																	(*it)->set_data_type($1);
																	$$->push_symbol(*it);
																	local_symbol_table->push_symbol(*it);	
																}
																else{
																	if(local_symbol_table->variable_in_symbol_list_check((*it)->get_variable_name())){
																		printf("cs316: Error : Variable declared twice. Line no. : %d\n",yylineno);
																		exit(0);
																	}
																	else{
																		(*it)->set_data_type($1);
																		$$->push_symbol(*it);
																		local_symbol_table->push_symbol(*it);		
																	}
																}
															}
														}
						;

global_optional_variable_declaration_list	:	/* empty */{$$ = new Symbol_Table();}
									|	global_variable_declaration_list {	
																			$$ = $1;
																			//global_symbol_table = new Symbol_Table();
																			//global_symbol_table = $1;																			
																		}
									;

global_variable_declaration_list	:	global_variable_declaration {$$ = $1;}
							|	global_variable_declaration_list 
								global_variable_declaration {$1->append_list(*$2,yylineno);$$ = $1;
															}
							;

global_variable_declaration	:	data_type variable_list ';' {	$$ = new Symbol_Table();

															for (list<Symbol_Table_Entry*>::iterator it=$2->begin(); it != $2->end(); ++it){
																if(global_symbol_table->is_empty()){
																	(*it)->set_data_type($1);
																	$$->push_symbol(*it);
																	global_symbol_table->push_symbol(*it);	
																}
																else{
																	if(global_symbol_table->variable_in_symbol_list_check((*it)->get_variable_name())){
																		printf("cs316: Error : Variable declared twice. Line no. : %d\n",yylineno);
																		exit(0);
																	}
																	else{
																		(*it)->set_data_type($1);
																		$$->push_symbol(*it);
																		global_symbol_table->push_symbol(*it);		
																	}
																}
															}
																
															
														}
						;

variable_list   :	NAME {$$ = new list<Symbol_Table_Entry*>();
						  //printf("Variable = %s\n",*$1);
						  string s = *$1;
						  s = s + "_";
						  $$->push_back(new Symbol_Table_Entry(s,void_data_type,yylineno));	
						 }
                |	variable_list ',' NAME {
                							string s = *$3;
						  					s = s + "_";
                							$1->push_back(new Symbol_Table_Entry(s,void_data_type,yylineno));
                							$$=$1;
                						}
				;


statement_list	:	/* empty */ {$$ = new list<Ast *>();}
				|	statement_list
					// assignment_statement {$1->push_back($2); $$=$1;}
					statement {$1->push_back($2); $$=$1;}
				;

assignment_statement	:	variable ASSIGN E ';' {$$ = new Assignment_Ast($1,$3,yylineno);
													if ($1->get_data_type() != $3->get_data_type()){
														printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
														exit(0);
													}	
												  }
						;	


statement 	:	matched_stmt {$$ = $1;}
			|	unmatched_stmt {$$ = $1;}
			;

matched_stmt	:	IF '(' logical_expression ')' matched_stmt ELSE matched_stmt {$$ = new Selection_Statement_Ast($3,$5,$7,yylineno);
																				}
				|	assignment_statement {$$ = $1;$$->set_data_type($1->get_data_type());}
				|	WHILE '(' logical_expression ')' matched_stmt {$$ = new Iteration_Statement_Ast($3,$5,yylineno,false);}
				|	DO matched_stmt WHILE '(' logical_expression ')' ';' {$$ = new Iteration_Statement_Ast($5,$2,yylineno,true);}
				|	'{' statement_list '}' {
														Sequence_Ast* temp = new Sequence_Ast(yylineno);
														if($2 == NULL || $2->size() == 0){
																printf("cs316: Error : Line No. %d Block of statements cannot be empty\n",yylineno);
																exit(0);	
														}
														else{
															for(list<Ast*>::iterator it=$2->begin(); it != $2->end(); ++it){
																temp->ast_push_back(*it);
															}
															$$ = temp;
														}
													}
				|	PRINT variable ';' {
											$$ = new Print_Ast($2,yylineno);

									   }
				;

unmatched_stmt	:	IF '(' logical_expression ')' statement {$$ = new Selection_Statement_Ast($3,$5,NULL,yylineno);
															}	
				|	IF '(' logical_expression ')' matched_stmt ELSE unmatched_stmt {$$ = new Selection_Statement_Ast($3,$5,$7,yylineno);
																					}
				|	WHILE '(' logical_expression ')' unmatched_stmt {$$ = new Iteration_Statement_Ast($3,$5,yylineno,false);}
				|	DO unmatched_stmt WHILE '(' logical_expression ')' ';' {$$ = new Iteration_Statement_Ast($5,$2,yylineno,true);}
				;

boolean_expression : 	E LESS_THAN E 	{Ast *temp = new Relational_Expr_Ast($1,less_than,$3,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for LESS_THAN\n",yylineno);
																			exit(0);
																		}
																	}
					| 	E GREATER_THAN E 	{Ast *temp = new Relational_Expr_Ast($1,greater_than,$3,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for GREATER_THAN\n",yylineno);
																			exit(0);
																		}
																	}
					|	E LESS_THAN_EQUAL E 	{Ast *temp = new Relational_Expr_Ast($1,less_equalto,$3,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for LESS_THAN_EQUAL\n",yylineno);
																			exit(0);
																		}
																	}
					|	E GREATER_THAN_EQUAL E 	{Ast *temp = new Relational_Expr_Ast($1,greater_equalto,$3,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for GREATER_THAN_EQUAL\n",yylineno);
																			exit(0);
																		}
																	}
					|	E EQUAL E 	{Ast *temp = new Relational_Expr_Ast($1,equalto,$3,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for EQUAL\n",yylineno);
																			exit(0);
																		}
																	}
					|	E NOT_EQUAL E 	{Ast *temp = new Relational_Expr_Ast($1,not_equalto,$3,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for NOT_EQUAL\n",yylineno);
																			exit(0);
																		}
																	}
					;

logical_expression	:	logical_expression AND logical_expression {Ast* temp = new Logical_Expr_Ast($1,_logical_and,$3,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for AND\n",yylineno);
																			exit(0);
																		}
																	}
					|	logical_expression OR logical_expression {Ast* temp = new Logical_Expr_Ast($1,_logical_or,$3,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for OR\n",yylineno);
																			exit(0);
																		}
																	}
					|	NOT logical_expression {Ast *temp = new Logical_Expr_Ast(NULL,_logical_not,$2,yylineno);
																		if(temp->check_ast()){
																			$$ = temp;
																		}
																		else{
																			printf("cs316: Error : Line No. %d Expressions not compatible for NOT\n",yylineno);
																			exit(0);
																		}
																	}
					|	boolean_expression {$$ = $1;$$->set_data_type($1->get_data_type());}
					|	'('logical_expression')' {$$ = $2;$$->set_data_type($2->get_data_type());}
					;

E	:	E '+' E {if ($1->get_data_type() == $3->get_data_type()){
					 $$ = new Plus_Ast($1,$3,yylineno);
					 $$->set_data_type($1->get_data_type());
					}
				else {
					printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
					exit(0);
					}
				}
	|	E '-' E {if ($1->get_data_type() == $3->get_data_type()){
					 $$ = new Minus_Ast($1,$3,yylineno);
					 $$->set_data_type($1->get_data_type());
					}
				else{
					printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
					exit(0);	
					}
				}


	|	E '*' E {if($1->get_data_type() == $3->get_data_type()){
					$$ = new Mult_Ast($1,$3,yylineno);
				 	$$->set_data_type($1->get_data_type());
				 }
				 else{
				 	printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
				 	}
				}
	|	E '/' E {if ($1->get_data_type() == $3->get_data_type()){
					$$ = new Divide_Ast($1,$3,yylineno);
					$$->set_data_type($1->get_data_type());
				}
				else{
					printf("cs316: Error : Line No. %d Data Type not compatible\n",yylineno);
					exit(0);	
					}
				}

 	|	variable {$$ = $1;$$->set_data_type($1->get_data_type());}
	|	constant {$$ = $1;$$->set_data_type($1->get_data_type());}

	| 	'('E')'	{$$ = $2; $$->set_data_type($2->get_data_type());}
	|	'-' E 	%prec '*' {$$ = new UMinus_Ast($2,NULL,yylineno);$$->set_data_type($2->get_data_type());}
	|	logical_expression '?' E ':' E {
										if ($3->get_data_type() == $5->get_data_type()){
											 $$ = new Conditional_Expression_Ast($1,$3,$5,yylineno);
											 $$->set_data_type($3->get_data_type());
											}
										else{
											printf("cs316: Error : Line No. %d Arithmetic statement data type not compatible\n",yylineno);
											exit(0);	
											}
										}
	;


variable	:	NAME {	string s = *$1;
						s = s+"_";
						bool present_local = local_symbol_table->variable_in_symbol_list_check(s);
						bool present_global = global_symbol_table->variable_in_symbol_list_check(s);
						if(present_local){

							$$ = new Name_Ast(s,local_symbol_table->get_symbol_table_entry(s),yylineno);
							$$->set_data_type(local_symbol_table->get_symbol_table_entry(s).get_data_type());
						}
						else if(present_global){
							$$ = new Name_Ast(s,global_symbol_table->get_symbol_table_entry(s),yylineno);
							$$->set_data_type(global_symbol_table->get_symbol_table_entry(s).get_data_type());
						}
						else{
							printf("cs316: Error : Line no : %d Variable not declared\n", yylineno);
							exit(0);
						}
						
					 }
			;
 
constant	:	INTEGER_NUMBER {$$ = new Number_Ast<int>($1,int_data_type,yylineno);}
			|	DOUBLE_NUMBER {$$ = new Number_Ast<double>($1,double_data_type,yylineno);}			  
			;

data_type	:	INTEGER {$$ = int_data_type;}
			|	FLOAT	{$$ = double_data_type;}




