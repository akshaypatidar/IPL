// #include "ast.hh"


int Ast::labelCounter;

Ast::Ast(){}
Ast::~Ast(){}


bool Ast::is_value_zero(){};

bool Ast::check_ast(){};
Symbol_Table_Entry & Ast::get_symbol_entry(){};



Data_Type Ast::get_data_type(){
	return node_data_type;
}

void Ast::set_data_type(Data_Type dt){
	node_data_type = dt;
}


Assignment_Ast::Assignment_Ast(Ast * temp_lhs, Ast * temp_rhs, int line){
	lhs = temp_lhs;
	rhs = temp_rhs;
	lineno = line;

}


Assignment_Ast::~Assignment_Ast(){}

bool Assignment_Ast::check_ast(){
	if(rhs->get_data_type() == lhs->get_data_type())return true;
	else return false;
}

void Assignment_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_SPACE<<"Asgn:\n" <<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer << ")";
	file_buffer<<endl<<AST_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer << ")";
	// file_buffer<<endl;
}


Name_Ast::Name_Ast(string & name, Symbol_Table_Entry & var_entry, int line){
	variable_symbol_entry = &var_entry;
	lineno = line;
	// Dont know what to do with name
}

Name_Ast::~Name_Ast(){}

Data_Type Name_Ast::get_data_type(){
	return node_data_type;
}

Symbol_Table_Entry & Name_Ast::get_symbol_entry(){
	return *variable_symbol_entry;
}

void Name_Ast::set_data_type(Data_Type dt){
	node_data_type = dt;
}


void Name_Ast::print(ostream & file_buffer){
	file_buffer<<"Name : "<<variable_symbol_entry->get_variable_name();
}



template <class T>
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line){
	constant = number;
	node_data_type = constant_data_type;
	lineno = line;
}

template Number_Ast<int>::Number_Ast(int number, Data_Type constant_data_type, int line);
template Number_Ast<double>::Number_Ast(double number, Data_Type constant_data_type, int line);

template <class T>
Number_Ast<T>::~Number_Ast(){}

template Number_Ast<int>::~Number_Ast();
template Number_Ast<double>::~Number_Ast();

template <class T>
Data_Type Number_Ast<T>::get_data_type(){
	return node_data_type;
}

template Data_Type Number_Ast<int>::get_data_type();
template Data_Type Number_Ast<double>::get_data_type();

template <class T>
void Number_Ast<T>::set_data_type(Data_Type dt){
	node_data_type=dt;
}

template void Number_Ast<int>::set_data_type(Data_Type dt);
template void Number_Ast<double>::set_data_type(Data_Type dt);

template <class T>
bool Number_Ast<T>::is_value_zero(){
	if(constant==0)return true;
	else return false;
}

template bool Number_Ast<int>::is_value_zero();
template bool Number_Ast<double>::is_value_zero();

template <class T>
void Number_Ast<T>::print(ostream & file_buffer){
	file_buffer<<"Num : "<<constant;
}

template void Number_Ast<int>::print(ostream & file_buffer);
template void Number_Ast<double>::print(ostream & file_buffer);

Data_Type Arithmetic_Expr_Ast::get_data_type(){
	return node_data_type;
}

void Arithmetic_Expr_Ast::set_data_type(Data_Type dt){
	node_data_type=dt;
}

bool Arithmetic_Expr_Ast::check_ast(){
	if(rhs->get_data_type() == lhs->get_data_type())return true;
	else return false;
}


Plus_Ast::Plus_Ast(Ast * l, Ast * r, int line){
	lhs = l;
	rhs = r;
	lineno = line;
}

void Plus_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: PLUS\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")"<<endl<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}



Minus_Ast::Minus_Ast(Ast * l, Ast * r, int line){
	lhs = l;
	rhs = r;
	lineno = line;
}

void Minus_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: MINUS\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")"<<endl<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}




Divide_Ast::Divide_Ast(Ast * l, Ast * r, int line){
	lhs = l;
	rhs = r;
	lineno = line;
}

void Divide_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: DIV\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")"<<endl<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}




Mult_Ast::Mult_Ast(Ast * l, Ast * r, int line){
	lhs = l;
	rhs = r;
	lineno = line;
}

void Mult_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: MULT\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")"<<endl<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

UMinus_Ast::UMinus_Ast(Ast * l, Ast * r, int line){
	lhs = l;
	rhs = r;
	lineno = line;
}

void UMinus_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: UMINUS\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
}




Conditional_Expression_Ast::Conditional_Expression_Ast(Ast* condition, Ast* l, Ast* r, int line){
	cond = condition;
	lhs = l;
	rhs = r;
	lineno = line;
	this->get_new_label();
}

void Conditional_Expression_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_SPACE<<"Cond:\n"<<AST_NODE_SPACE<<"IF_ELSE";
	cond->print(file_buffer);
	file_buffer<<"\n"<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n"<<AST_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

Relational_Expr_Ast::Relational_Expr_Ast(Ast * lhs, Relational_Op rop, Ast * rhs, int line){
	lhs_condition = lhs;
	rhs_condition = rhs;
	rel_op = rop;
	lineno = line;
	node_data_type = int_data_type;
}


Data_Type Relational_Expr_Ast::get_data_type(){
	return node_data_type;
}

void Relational_Expr_Ast::set_data_type(Data_Type dt){
	node_data_type=dt;
}

bool Relational_Expr_Ast::check_ast(){
	if(rhs_condition->get_data_type() == lhs_condition->get_data_type())return true;
	else return false;
}

void Relational_Expr_Ast::print(ostream & file_buffer){
	string op = "";
	if(rel_op == greater_than) op="GT";
	else if(rel_op == greater_equalto) op="GE";
	else if(rel_op == less_than) op="LT";
	else if(rel_op == less_equalto) op="LE";
	else if(rel_op == equalto) op="EQ";
	else if(rel_op == not_equalto) op="NE";

	file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: "<<op<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs_condition->print(file_buffer);
	file_buffer<<")"<<endl<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs_condition->print(file_buffer);
	file_buffer<<")";
	
}

Logical_Expr_Ast::Logical_Expr_Ast(Ast * lhs, Logical_Op bop, Ast * rhs, int line){
	lhs_op = lhs;
	rhs_op = rhs;
	bool_op = bop;
	lineno = line;
	node_data_type = int_data_type;
}


Data_Type Logical_Expr_Ast::get_data_type(){
	return node_data_type;
}

void Logical_Expr_Ast::set_data_type(Data_Type dt){
	node_data_type=dt;
}

bool Logical_Expr_Ast::check_ast(){
	if(lhs_op != NULL){
		if(lhs_op->get_data_type() == rhs_op->get_data_type())return true;
		else return false;
	}
	else{
		return true;
	}
	
}

void Logical_Expr_Ast::print(ostream & file_buffer){
	string op = "";
	string lhs = "";  
	if(bool_op == _logical_and){
		op="AND";
		lhs = "LHS (";
	} 
	else if(bool_op == _logical_or){
		lhs = "LHS (";
		op="OR";
	} 
	else if(bool_op == _logical_not){
		op="NOT";
		lhs = "RHS (";
	} 

	file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: "<<op<<"\n"<<AST_SUB_NODE_SPACE<<lhs;
	

	if(op != "NOT"){
		lhs_op->print(file_buffer);
		file_buffer<<")\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_op->print(file_buffer);
	}
	else{
		rhs_op->print(file_buffer);
	}
	
	file_buffer<<")";
}


Selection_Statement_Ast::Selection_Statement_Ast(Ast * cond ,Ast* then_part, Ast* else_part, int line){
	this->cond = cond;
	this->then_part = then_part;
	this->else_part = else_part;
	lineno = line;
}


Data_Type Selection_Statement_Ast::get_data_type(){
	return node_data_type;
}

void Selection_Statement_Ast::set_data_type(Data_Type dt){
	node_data_type=dt;
}

bool Selection_Statement_Ast::check_ast(){
	// TODO
}

void Selection_Statement_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_SPACE<<"IF : \n"<<AST_SPACE<<"CONDITION (";
	cond->print(file_buffer);
	file_buffer<<")\n"<<AST_SPACE<<"THEN (";
	then_part->print(file_buffer);
	if(else_part != NULL){
		file_buffer<<")\n"<<AST_SPACE<<"ELSE (";
		else_part->print(file_buffer);
	}
	
	file_buffer<<")";


}

Iteration_Statement_Ast::Iteration_Statement_Ast(Ast * cond, Ast* body, int line, bool do_form){
	this->cond = cond;
	this->body = body;
	this->is_do_form = do_form;
	lineno = line;
}


Data_Type Iteration_Statement_Ast::get_data_type(){
	return node_data_type;
}

void Iteration_Statement_Ast::set_data_type(Data_Type dt){
	node_data_type=dt;
}

bool Iteration_Statement_Ast::check_ast(){
	// TODO
}

void Iteration_Statement_Ast::print(ostream & file_buffer){
	if(is_do_form){
		file_buffer<<"\n"<<AST_SPACE<<"DO (\n";
		body->print(file_buffer);
		file_buffer<<")";
		file_buffer<<"\n"<<AST_SPACE<<"WHILE CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")";
	}
	else{
		file_buffer<<"\n"<<AST_SPACE<<"WHILE : \n"<<AST_SPACE<<"CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")\n"<<AST_SPACE<<"BODY (";
		body->print(file_buffer);
		file_buffer<<")";
	}
	
}

Sequence_Ast::Sequence_Ast(int line){
	lineno = line;
	this->get_new_label();
	// statement_list = new list<Ast*>();
	// sa_icode_list = new list<Icode_Stmt *>();
}


void Sequence_Ast::ast_push_back(Ast * ast){
	statement_list.push_back(ast);
}

void Sequence_Ast::print(ostream & file_buffer){
	file_buffer<<endl<<AST_NODE_SPACE;
	int size = statement_list.size();
	int count = 0;
	for (list<Ast *>::iterator it=statement_list.begin(); it != statement_list.end(); ++it){
		(*it)->print(file_buffer);
		if(count<size-1){
			file_buffer<<endl<<AST_NODE_SPACE;
		}
		count++;
	}
}

Print_Ast::Print_Ast(Ast *v, int line){
	var = v;
	lineno = line;
}

Print_Ast::~Print_Ast(){}


void Print_Ast::print(ostream & file_buffer){
	file_buffer<<endl<<AST_SPACE<<"Print :\n"<<AST_SUB_NODE_SPACE << "(";
	if(var != NULL){
		var->print(file_buffer);
	}
	file_buffer << ")";


	
}



Return_Ast::Return_Ast(Ast * ret_val, string name, int line){
	return_value = ret_val;
	proc_name = name;
	lineno = line;
}

void Return_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_SPACE<<"RETURN ";
	if(return_value != NULL){
		return_value->print(file_buffer);
	}
	else{
		file_buffer<<"<NOTHING>";
	}
	file_buffer << endl;
}

Data_Type Return_Ast::get_data_type(){
	return node_data_type;
}




Call_Ast::Call_Ast(string name, int line){
	procedure_name = name;
	lineno = line;
}

Data_Type Call_Ast::get_data_type(){
	return node_data_type;
}

void Call_Ast::set_register(Register_Descriptor * reg){
	return_value_reg = reg;
}

void Call_Ast::check_actual_formal_param(Symbol_Table & formal_param_list){
	Procedure * p = program_object.get_procedure_prototype(procedure_name);
	list<Symbol_Table_Entry *> formal_params = p->get_formal_param_list().get_table();
	int num_formal_parameter = formal_params.size();

	if(num_formal_parameter != actual_param_list.size()){
		printf("cs316: Error : Line No. %d Actual and formal parameter count do not match\n",lineno);
		exit(0);
	}
	else{
		Data_Type formal_param_type[num_formal_parameter];
		int i=0;
		for (list<Symbol_Table_Entry *>::iterator it=formal_params.begin(); it != formal_params.end(); ++it){
			formal_param_type[i] = (*it)->get_data_type();
			i++;
		}

		i=0;
		for (list<Ast *>::iterator it=actual_param_list.begin(); it != actual_param_list.end(); ++it){
			
			if(formal_param_type[i] != (*it)->get_data_type()){
				printf("cs316: Error : Line No. %d Actual and formal parameter types do not match\n",lineno);
				exit(0);
			}
			i++;
		}
	}
	
	
	

}

void Call_Ast::set_actual_param_list(list<Ast *> & param_list){
	actual_param_list = param_list;
}

void Call_Ast::print(ostream & file_buffer){
	file_buffer<<endl<< AST_SPACE <<"FN CALL: "<< procedure_name << "(";
	int size = actual_param_list.size();
	int count = 0;
	for (list<Ast *>::iterator it=actual_param_list.begin(); it != actual_param_list.end(); ++it){
		if(count<size){
			file_buffer<<endl<<AST_NODE_SPACE;
		}
		(*it)->print(file_buffer);
		count++;
	}
	file_buffer << ")";
	// FN CALL: func1_()
}