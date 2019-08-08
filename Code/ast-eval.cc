// #include "ast.hh"
// #include "local-environment.hh"



void Ast::print_value(Local_Environment & eval_env, ostream & file_buffer){
	
}

Eval_Result & Ast::get_value_of_evaluation(Local_Environment & eval_env){

}

void Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result){

}


Eval_Result & Assignment_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){

	Eval_Result *res = &rhs->evaluate(eval_env,file_buffer);
	string var_name = (((Name_Ast*)lhs)->get_symbol_entry()).get_variable_name();
	res->set_variable_status(true);
	if(eval_env.does_variable_exist(var_name)){
		eval_env.put_variable_value(*res,var_name);
	}
	else{
		interpreter_global_table.put_variable_value(*res,var_name);
	}
	
	this->print(file_buffer);
	((Name_Ast*)lhs)->print_value(eval_env,file_buffer);
	file_buffer<<endl;
	
	return *res;
	 
}


void Name_Ast::print_value(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result* result;

	if(eval_env.is_variable_defined(variable_symbol_entry->get_variable_name())){
		result = eval_env.get_variable_value(variable_symbol_entry->get_variable_name());

	}
	else if(interpreter_global_table.is_variable_defined(variable_symbol_entry->get_variable_name())){
		result = interpreter_global_table.get_variable_value(variable_symbol_entry->get_variable_name());
	}
	else{
		printf("cs316: Error : Line No. %d Variable should be defined before its use\n",lineno);
		exit(0);
	}
	
	if(variable_symbol_entry->get_data_type()==int_data_type){
		file_buffer<<endl<<AST_SPACE<<variable_symbol_entry->get_variable_name()<<" : "<<result->get_int_value()<<endl;
	}
	else if(variable_symbol_entry->get_data_type()==double_data_type){
		file_buffer<<endl<<AST_SPACE<<variable_symbol_entry->get_variable_name()<<" : "<<result->get_double_value()<<endl;
	}


	
}

Eval_Result & Name_Ast::get_value_of_evaluation(Local_Environment & eval_env){
	if(eval_env.does_variable_exist(variable_symbol_entry->get_variable_name())){
		if(eval_env.is_variable_defined(variable_symbol_entry->get_variable_name())){
			return *eval_env.get_variable_value(variable_symbol_entry->get_variable_name());
		}
		else{
			printf("cs316: Error : Line No. %d Variable should be defined before its use\n",lineno);
			exit(0);
		}
	}
	else if(interpreter_global_table.does_variable_exist(variable_symbol_entry->get_variable_name())){
		if(interpreter_global_table.is_variable_defined(variable_symbol_entry->get_variable_name())){
			return *interpreter_global_table.get_variable_value(variable_symbol_entry->get_variable_name());
		}
		else{
			printf("cs316: Error : Line No. %d Variable should be defined before its use\n",lineno);
			exit(0);
		}
	}
	else{
		printf("cs316: Error : Line No. %d Variable should be defined before its use\n",lineno);
		exit(0);
	}
}

void Name_Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result){
	if(eval_env.does_variable_exist(variable_symbol_entry->get_variable_name())){
		eval_env.put_variable_value(result,variable_symbol_entry->get_variable_name());
	}
	else if(interpreter_global_table.does_variable_exist(variable_symbol_entry->get_variable_name())){
		interpreter_global_table.put_variable_value(result,variable_symbol_entry->get_variable_name());
	}
	else{
		printf("cs316: Error : Line No. %d Variable has not been declared\n",lineno);
		exit(0);
	}


}

Eval_Result & Name_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){

	if(eval_env.does_variable_exist(variable_symbol_entry->get_variable_name())){
		if(eval_env.is_variable_defined(variable_symbol_entry->get_variable_name())){
			return *eval_env.get_variable_value(variable_symbol_entry->get_variable_name());
		}
		else{
			printf("cs316: Error : Line No. %d Variable should be defined before its use\n",lineno);
			exit(0);
		}
	}
	else if(interpreter_global_table.does_variable_exist(variable_symbol_entry->get_variable_name())){
		if(interpreter_global_table.is_variable_defined(variable_symbol_entry->get_variable_name())){
			return *interpreter_global_table.get_variable_value(variable_symbol_entry->get_variable_name());
		}
		else{
			printf("cs316: Error : Line No. %d Variable should be defined before its use\n",lineno);
			exit(0);
		}
	}
	else{
		printf("cs316: Error : Line No. %d Variable should be defined before its use\n",lineno);
		exit(0);
	}

	

}

template <class T>
Eval_Result & Number_Ast<T>::evaluate(Local_Environment & eval_env, ostream & file_buffer){

}
template <>
Eval_Result & Number_Ast<int>::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result * res = new Eval_Result_Value_Int();
	res->set_value(constant);
	res->set_variable_status(true);
	res->set_result_enum(int_result);

	return *res;
}
template<>
Eval_Result & Number_Ast<double>::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result * res = new Eval_Result_Value_Double();
	res->set_value(constant);
	res->set_variable_status(true);
	res->set_result_enum(double_result);

	return *res;
}

Eval_Result & Plus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result *lhs_result = &lhs->evaluate(eval_env,file_buffer);
	Eval_Result *rhs_result = &rhs->evaluate(eval_env,file_buffer);
	Eval_Result *result;
	if(lhs_result->get_result_enum() == int_result && rhs_result->get_result_enum() == int_result){
		Eval_Result_Value_Int * res = new Eval_Result_Value_Int();
		res->set_value(lhs_result->get_int_value()+rhs_result->get_int_value());
		res->set_variable_status(true);
		res->set_result_enum(int_result);
		result = res;
	}
	else if(lhs_result->get_result_enum() == double_result && rhs_result->get_result_enum() == double_result){
		Eval_Result_Value_Double * res = new Eval_Result_Value_Double();
		res->set_value(lhs_result->get_double_value()+rhs_result->get_double_value());
		res->set_variable_status(true);
		res->set_result_enum(double_result);
		result = res;

	}
	return *result;
	
}


Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result *lhs_result = &lhs->evaluate(eval_env,file_buffer);
	Eval_Result *rhs_result = &rhs->evaluate(eval_env,file_buffer);
	Eval_Result *result;
	if(lhs_result->get_result_enum() == int_result && rhs_result->get_result_enum() == int_result){
		Eval_Result_Value_Int * res = new Eval_Result_Value_Int();
		res->set_value(lhs_result->get_int_value()-rhs_result->get_int_value());
		res->set_variable_status(true);
		res->set_result_enum(int_result);
		result = res;
	}
	else if(lhs_result->get_result_enum() == double_result && rhs_result->get_result_enum() == double_result){
		Eval_Result_Value_Double * res = new Eval_Result_Value_Double();
		res->set_value(lhs_result->get_double_value()-rhs_result->get_double_value());
		res->set_variable_status(true);
		res->set_result_enum(double_result);
		result = res;

	}
	return *result;
}


Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result *lhs_result = &lhs->evaluate(eval_env,file_buffer);
	Eval_Result *rhs_result = &rhs->evaluate(eval_env,file_buffer);
	Eval_Result *result;
	if(lhs_result->get_result_enum() == int_result && rhs_result->get_result_enum() == int_result){
		if(rhs_result->get_int_value() == 0){
			printf("cs316: Error : Line No. %d Divide by 0\n",lineno);
			exit(0);
		}
		Eval_Result_Value_Int * res = new Eval_Result_Value_Int();
		res->set_value(lhs_result->get_int_value()/rhs_result->get_int_value());
		res->set_variable_status(true);
		res->set_result_enum(int_result);
		result = res;
	}
	else if(lhs_result->get_result_enum() == double_result && rhs_result->get_result_enum() == double_result){
		if(rhs_result->get_double_value() == 0.0){
			printf("cs316: Error : Line No. %d Divide by 0",lineno);
			exit(0);
		}
		Eval_Result_Value_Double * res = new Eval_Result_Value_Double();
		res->set_value(lhs_result->get_double_value()/rhs_result->get_double_value());
		res->set_variable_status(true);
		res->set_result_enum(double_result);
		result = res;

	}
	return *result;
}

Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result *lhs_result = &lhs->evaluate(eval_env,file_buffer);
	Eval_Result *rhs_result = &rhs->evaluate(eval_env,file_buffer);
	Eval_Result *result;
	if(lhs_result->get_result_enum() == int_result && rhs_result->get_result_enum() == int_result){
		Eval_Result_Value_Int * res = new Eval_Result_Value_Int();
		res->set_value(lhs_result->get_int_value()*rhs_result->get_int_value());
		res->set_variable_status(true);
		res->set_result_enum(int_result);
		result = res;
	}
	else if(lhs_result->get_result_enum() == double_result && rhs_result->get_result_enum() == double_result){
		Eval_Result_Value_Double * res = new Eval_Result_Value_Double();
		res->set_value(lhs_result->get_double_value()*rhs_result->get_double_value());
		res->set_variable_status(true);
		res->set_result_enum(double_result);
		result = res;

	}
	return *result;
}


Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result *lhs_result = &lhs->evaluate(eval_env,file_buffer);
	Eval_Result *result;
	if(lhs_result->get_result_enum() == int_result){
		Eval_Result_Value_Int * res = new Eval_Result_Value_Int();
		res->set_value(-1 * lhs_result->get_int_value());
		res->set_variable_status(true);
		res->set_result_enum(int_result);
		result = res;
	}
	else if(lhs_result->get_result_enum() == double_result){
		Eval_Result_Value_Double * res = new Eval_Result_Value_Double();
		res->set_value(-1.0 * lhs_result->get_double_value());
		res->set_variable_status(true);
		res->set_result_enum(double_result);
		result = res;

	}

	return *result;
}


Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	int cond_result = cond->evaluate(eval_env,file_buffer).get_int_value();
	Eval_Result *lhs_result = &lhs->evaluate(eval_env,file_buffer);
	Eval_Result *rhs_result = &rhs->evaluate(eval_env,file_buffer);
	Eval_Result *result;

	if(lhs_result->get_result_enum() == int_result && rhs_result->get_result_enum() == int_result){
		Eval_Result_Value_Int * res = new Eval_Result_Value_Int();
		if(cond_result==1){
			res->set_value(lhs_result->get_int_value());
		}
		else{
			res->set_value(rhs_result->get_int_value());
		}
		res->set_variable_status(true);
		res->set_result_enum(int_result);
		result = res;
		
	}
	else if(lhs_result->get_result_enum() == double_result && rhs_result->get_result_enum() == double_result){
		Eval_Result_Value_Double * res = new Eval_Result_Value_Double();
		if(cond_result==1){
			res->set_value(lhs_result->get_double_value());
		}
		else{
			res->set_value(rhs_result->get_double_value());
		}
		res->set_variable_status(true);
		res->set_result_enum(double_result);
		result = res;

	}

	return *result;

}



Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result *lhs_result = &lhs_condition->evaluate(eval_env,file_buffer);
	Eval_Result *rhs_result = &rhs_condition->evaluate(eval_env,file_buffer);
	Eval_Result * result = new Eval_Result_Value_Int();

	if(lhs_result->get_result_enum() == int_result && rhs_result->get_result_enum() == int_result){
		int lhs_value = lhs_result->get_int_value();
		int rhs_value = rhs_result->get_int_value();
		if(rel_op == less_than){
			if(lhs_value < rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == less_equalto){
			if(lhs_value <= rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == greater_than){
			if(lhs_value > rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == greater_equalto){
			if(lhs_value > rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == equalto){
			if(lhs_value == rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == not_equalto){
			if(lhs_value != rhs_value)result->set_value(1);
			else result->set_value(0);
		}

		result->set_variable_status(true);
		result->set_result_enum(int_result);
		
	}
	else if(lhs_result->get_result_enum() == double_result && rhs_result->get_result_enum() == double_result){
		double lhs_value = lhs_result->get_double_value();
		double rhs_value = rhs_result->get_double_value();
		if(rel_op == less_than){
			if(lhs_value < rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == less_equalto){
			if(lhs_value <= rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == greater_than){
			if(lhs_value > rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == greater_equalto){
			if(lhs_value > rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == equalto){
			if(lhs_value == rhs_value)result->set_value(1);
			else result->set_value(0);
		}
		else if(rel_op == not_equalto){
			if(lhs_value != rhs_value)result->set_value(1);
			else result->set_value(0);
		}

		result->set_variable_status(true);
		result->set_result_enum(double_result);
	}

	return *result;

}

Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result* rhs_result = &rhs_op->evaluate(eval_env,file_buffer);
	int rhs_value = rhs_result->get_int_value();
	Eval_Result *lhs_result;
	int lhs_value;
	if(lhs_op != NULL){
	 	lhs_result= &lhs_op->evaluate(eval_env,file_buffer);
	 	lhs_value = lhs_result->get_int_value();
	}
	Eval_Result * result = new Eval_Result_Value_Int();


	if(bool_op == _logical_and){
		if(rhs_value == 1 && lhs_value == 1){
			result->set_value(1);
		}
		else{
			result->set_value(0);
		}
	}
	else if(bool_op == _logical_or){
		if(rhs_value == 1 || lhs_value == 1){
			result->set_value(1);
		}
		else{
			result->set_value(0);
		}
	}
	else if(bool_op == _logical_not){
		if(rhs_value == 1){
			result->set_value(0);
		}
		else{
			result->set_value(1);
		}
	}

	result->set_variable_status(true);
	result->set_result_enum(int_result);
	return *result;
}

Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result * cond_result = &cond->evaluate(eval_env,file_buffer);
	Eval_Result * result;
	if(cond_result->get_int_value()==1){
		result = &then_part->evaluate(eval_env,file_buffer);
	}
	else{
		if(else_part != NULL){
			result = &else_part->evaluate(eval_env,file_buffer);
		}
	}

	return *result;
}

Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result * result;
	if(is_do_form){
		do{
			result = &body->evaluate(eval_env,file_buffer);
		}while(cond->evaluate(eval_env,file_buffer).get_int_value()==1);
	}
	else{
		while(cond->evaluate(eval_env,file_buffer).get_int_value()==1){
			result = &body->evaluate(eval_env,file_buffer);
		}
	}
	return *result;
}

Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result * result;
	for(list<Ast*>::iterator it=statement_list.begin(); it != statement_list.end(); ++it){
		result = &((*it)->evaluate(eval_env,file_buffer));
	}
	return *result;
}


Eval_Result & Call_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){

	for (list<Ast*>::iterator it=actual_param_list.begin(); it != actual_param_list.end(); ++it){
		Eval_Result* r = &(*it)->evaluate(eval_env,file_buffer);
				
	}
	Procedure * p = program_object.get_procedure_prototype(procedure_name);

	// Debugging
	list<Symbol_Table_Entry *> local = p->get_local_list().get_table();	
	list<Symbol_Table_Entry *> formal = p->get_formal_param_list().get_table();	
	file_buffer<<p->get_local_list().is_empty()<<endl;
	for (list<Symbol_Table_Entry *>::iterator it=local.begin(); it != local.end(); ++it){
		file_buffer<<(*it)->get_variable_name()<<endl;
	}
	file_buffer<<p->get_formal_param_list().is_empty()<<endl;

	for (list<Symbol_Table_Entry *>::iterator it=formal.begin(); it != formal.end(); ++it){
		file_buffer<<(*it)->get_variable_name()<<endl;
	}
	return p->evaluate(eval_env,file_buffer);



}

Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result * result;
	if(return_value != NULL){
		result = &return_value->evaluate(eval_env,file_buffer);
		file_buffer<<AST_SPACE<<"RETURN ";
		return_value->print(file_buffer);
		
	}
	return *result;
}

