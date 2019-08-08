


Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Code_For_Ast & Assignment_Ast::compile(){

	/// Compile RHS and store in LHS
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	
	if(lhs != NULL && rhs != NULL){
		Code_For_Ast compiled_rhs = rhs->compile();
		Code_For_Ast store_lhs = ((Name_Ast*)lhs)->create_store_stmt(compiled_rhs.get_reg());
		i_stmts->splice(i_stmts->begin(),store_lhs.get_icode_list());
		i_stmts->splice(i_stmts->begin(),compiled_rhs.get_icode_list());
		return *new Code_For_Ast(*i_stmts,NULL);
	}
	else{
		printf("cs316: Error : Line No. %d Operands of assignement cannot be Null\n",lineno);
	}
}	

Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Name_Ast::compile(){
	// load variable in a register
	string var_name = variable_symbol_entry->get_variable_name();
	Data_Type type = variable_symbol_entry->get_data_type();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;

	// allocate a register for result
	Register_Descriptor* reg;

	if(type == int_data_type){
		reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Move_IC_Stmt(load,new Mem_Addr_Opd(*variable_symbol_entry),new Register_Addr_Opd(reg)));
	}
	else if(type == double_data_type){
		reg = machine_desc_object.get_new_register<float_reg>();
		i_stmts->push_back(new Move_IC_Stmt(load_d,new Mem_Addr_Opd(*variable_symbol_entry),new Register_Addr_Opd(reg)));
	}
	reg->set_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);

}

Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}

Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register){

	// Store value of register
	string var_name = variable_symbol_entry->get_variable_name();
	Data_Type type = variable_symbol_entry->get_data_type();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;

	if(type == int_data_type){
		i_stmts->push_back(new Move_IC_Stmt(store,new Register_Addr_Opd(store_register),new Mem_Addr_Opd(*variable_symbol_entry)));
	}
	else if(type == double_data_type){
		i_stmts->push_back(new Move_IC_Stmt(store_d,new Register_Addr_Opd(store_register),new Mem_Addr_Opd(*variable_symbol_entry)));
	}
	store_register->reset_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,store_register);



}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
Code_For_Ast & Number_Ast<T>::compile(){

}

template<> 
Code_For_Ast & Number_Ast<int>::compile(){
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg = machine_desc_object.get_new_register<int_reg>();
	i_stmts->push_back(new Move_IC_Stmt(imm_load,new Const_Opd<int>(constant),new Register_Addr_Opd(reg)));
	reg->set_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);
}

template<>
Code_For_Ast & Number_Ast<double>::compile(){
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg = machine_desc_object.get_new_register<float_reg>();
	i_stmts->push_back(new Move_IC_Stmt(imm_load_d,new Const_Opd<double>(constant),new Register_Addr_Opd(reg)));
	reg->set_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);
}

template<class T>
Code_For_Ast & Number_Ast<T>::compile_and_optimize_ast(Lra_Outcome & lra){

}

template Code_For_Ast & Number_Ast<int>::compile_and_optimize_ast(Lra_Outcome & lra);
template Code_For_Ast & Number_Ast<double>::compile_and_optimize_ast(Lra_Outcome & lra);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Plus_Ast::compile(){
	Code_For_Ast lhs_compiled = lhs->compile();
	Code_For_Ast rhs_compiled = rhs->compile();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg;

	if(lhs->get_data_type() == int_data_type){
		reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(add,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}
	else if(lhs->get_data_type() == double_data_type){
		reg = machine_desc_object.get_new_register<float_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(add_d,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}

	i_stmts->splice(i_stmts->begin(),rhs_compiled.get_icode_list());
	i_stmts->splice(i_stmts->begin(),lhs_compiled.get_icode_list());

	reg->set_use_for_expr_result();
	rhs_compiled.get_reg()->reset_use_for_expr_result();
	lhs_compiled.get_reg()->reset_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);

}

Code_For_Ast & Plus_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Minus_Ast::compile(){
	Code_For_Ast lhs_compiled = lhs->compile();
	Code_For_Ast rhs_compiled = rhs->compile();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg;

	if(lhs->get_data_type() == int_data_type){
		reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(sub,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}
	else if(lhs->get_data_type() == double_data_type){
		reg = machine_desc_object.get_new_register<float_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(sub_d,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}

	i_stmts->splice(i_stmts->begin(),rhs_compiled.get_icode_list());
	i_stmts->splice(i_stmts->begin(),lhs_compiled.get_icode_list());

	rhs_compiled.get_reg()->reset_use_for_expr_result();
	lhs_compiled.get_reg()->reset_use_for_expr_result();
	reg->set_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);
}

Code_For_Ast & Minus_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Mult_Ast::compile(){
	Code_For_Ast lhs_compiled = lhs->compile();
	Code_For_Ast rhs_compiled = rhs->compile();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg;

	if(lhs->get_data_type() == int_data_type){
		reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(mult,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}
	else if(lhs->get_data_type() == double_data_type){
		reg = machine_desc_object.get_new_register<float_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(mult_d,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}

	i_stmts->splice(i_stmts->begin(),rhs_compiled.get_icode_list());
	i_stmts->splice(i_stmts->begin(),lhs_compiled.get_icode_list());

	rhs_compiled.get_reg()->reset_use_for_expr_result();
	lhs_compiled.get_reg()->reset_use_for_expr_result();
	reg->set_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);
}

Code_For_Ast & Mult_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Divide_Ast::compile(){
	Code_For_Ast lhs_compiled = lhs->compile();
	Code_For_Ast rhs_compiled = rhs->compile();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg;

	if(lhs->get_data_type() == int_data_type){
		reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(divd,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}
	else if(lhs->get_data_type() == double_data_type){
		reg = machine_desc_object.get_new_register<float_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(div_d,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}

	i_stmts->splice(i_stmts->begin(),rhs_compiled.get_icode_list());
	i_stmts->splice(i_stmts->begin(),lhs_compiled.get_icode_list());

	rhs_compiled.get_reg()->reset_use_for_expr_result();
	lhs_compiled.get_reg()->reset_use_for_expr_result();
	reg->set_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);
}

Code_For_Ast & Divide_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



Code_For_Ast & UMinus_Ast::compile(){
	Code_For_Ast lhs_compiled = lhs->compile();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg;

	if(lhs->get_data_type() == int_data_type){
		reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Move_IC_Stmt(uminus,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}
	else if(lhs->get_data_type() == double_data_type){
		reg = machine_desc_object.get_new_register<float_reg>();
		i_stmts->push_back(new Move_IC_Stmt(uminus_d,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
	}

	i_stmts->splice(i_stmts->begin(),lhs_compiled.get_icode_list());

	lhs_compiled.get_reg()->reset_use_for_expr_result();
	reg->set_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);
}

Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Conditional_Expression_Ast::compile(){
	Code_For_Ast cond_compiled = cond->compile();
	Code_For_Ast lhs_compiled = lhs->compile();
	Code_For_Ast rhs_compiled = rhs->compile();

	Tgt_Op op = cond_compiled.get_icode_list().back()->get_op().get_op();
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;

	Register_Descriptor *reg;
	if(lhs->get_data_type() == int_data_type && rhs->get_data_type() == int_data_type){
		reg = machine_desc_object.get_new_register<int_reg>();
	}
	else if(lhs->get_data_type() == double_data_type && rhs->get_data_type() == double_data_type){
		reg = machine_desc_object.get_new_register<float_reg>();
	}
	
	string jump_label = this->get_new_label();
	string next_label = this->get_new_label();
	i_stmts->splice(i_stmts->begin(),cond_compiled.get_icode_list());
	
	if(cond_compiled.get_reg() != NULL){
		i_stmts->push_back(new Control_Flow_IC_Stmt(beq,new Register_Addr_Opd(cond_compiled.get_reg()),NULL,jump_label));
		cond_compiled.get_reg()->reset_use_for_expr_result();
	}
	else{
		if(op == sle_d || op == slt_d || op == seq_d){
			i_stmts->push_back(new Control_Flow_IC_Stmt(bc1f,NULL,NULL,jump_label));
		}
		else{
			i_stmts->push_back(new Control_Flow_IC_Stmt(bc1t,NULL,NULL,jump_label));
		}
	}

	if(lhs->get_data_type() == int_data_type && rhs->get_data_type() == int_data_type){
		
		i_stmts->splice(i_stmts->end(),lhs_compiled.get_icode_list());
		i_stmts->push_back(new Compute_IC_Stmt(or_t,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]),new Register_Addr_Opd(reg)));
		i_stmts->push_back(new Control_Flow_IC_Stmt(j,NULL,NULL,next_label));
		i_stmts->push_back(new Label_IC_Stmt(label,jump_label));
		i_stmts->splice(i_stmts->end(),rhs_compiled.get_icode_list());
		i_stmts->push_back(new Compute_IC_Stmt(or_t,new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]),new Register_Addr_Opd(reg)));
		i_stmts->push_back(new Label_IC_Stmt(label,next_label));
	}
	else if(lhs->get_data_type() == double_data_type && rhs->get_data_type() == double_data_type){
		i_stmts->splice(i_stmts->end(),lhs_compiled.get_icode_list());
		i_stmts->push_back(new Move_IC_Stmt(move_d,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
		i_stmts->push_back(new Control_Flow_IC_Stmt(j,NULL,NULL,next_label));
		i_stmts->push_back(new Label_IC_Stmt(label,jump_label));
		i_stmts->splice(i_stmts->end(),rhs_compiled.get_icode_list());
		i_stmts->push_back(new Move_IC_Stmt(move_d,new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
		i_stmts->push_back(new Label_IC_Stmt(label,next_label));
	
	}

	rhs_compiled.get_reg()->reset_use_for_expr_result();
	lhs_compiled.get_reg()->reset_use_for_expr_result();
	reg->set_use_for_expr_result();

	return *new Code_For_Ast(*i_stmts,reg);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Relational_Expr_Ast::compile(){
	Code_For_Ast lhs_compiled = lhs_condition->compile();
	Code_For_Ast rhs_compiled = rhs_condition->compile();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg;

	if(lhs_condition->get_data_type() == int_data_type){
		reg = machine_desc_object.get_new_register<int_reg>();
		Tgt_Op op;

		if(rel_op == less_than) op = slt;
		else if(rel_op == less_equalto) op = sle;
		else if(rel_op == greater_than) op = sgt;
		else if(rel_op == greater_equalto) op = sge;
		else if(rel_op == equalto) op = seq;
		else if(rel_op == not_equalto) op = sne;
		else op = nop;

		i_stmts->push_back(new Compute_IC_Stmt(op,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
		i_stmts->splice(i_stmts->begin(),rhs_compiled.get_icode_list());
		i_stmts->splice(i_stmts->begin(),lhs_compiled.get_icode_list());

		rhs_compiled.get_reg()->reset_use_for_expr_result();
		lhs_compiled.get_reg()->reset_use_for_expr_result();
		reg->set_use_for_expr_result();
		return *new Code_For_Ast(*i_stmts,reg);
	}
	else if(lhs_condition->get_data_type() == double_data_type){
		Tgt_Op op;

		if(rel_op == less_than) op = slt_d;
		else if(rel_op == less_equalto) op = sle_d;
		else if(rel_op == greater_than) op = sgt_d;
		else if(rel_op == greater_equalto) op = sge_d;
		else if(rel_op == equalto) op = seq_d;
		else if(rel_op == not_equalto) op = sne_d;
		else op = nop;

		i_stmts->push_back(new Compute_IC_Stmt(op,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),NULL));
		i_stmts->splice(i_stmts->begin(),rhs_compiled.get_icode_list());
		i_stmts->splice(i_stmts->begin(),lhs_compiled.get_icode_list());

		rhs_compiled.get_reg()->reset_use_for_expr_result();
		lhs_compiled.get_reg()->reset_use_for_expr_result();
		return *new Code_For_Ast(*i_stmts,NULL);
	}

	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Logical_Expr_Ast::compile(){
	
	Code_For_Ast rhs_compiled;
	Code_For_Ast lhs_compiled;
	if(lhs_op != NULL){
		lhs_compiled = lhs_op->compile();
	}
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Register_Descriptor *reg;


	
	Tgt_Op op;

	if(bool_op == _logical_and) op = and_t;
	else if(bool_op == _logical_or) op = or_t;
	else if(bool_op == _logical_not) op = not_t;
	else op = nop;
	if(op == not_t){
		Register_Descriptor* reg_new = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Move_IC_Stmt(imm_load,new Const_Opd<int>(1),new Register_Addr_Opd(reg_new)));
		reg_new->set_use_for_expr_result();
		rhs_compiled = rhs_op->compile();
		reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->splice(i_stmts->end(),rhs_compiled.get_icode_list());
		i_stmts->push_back(new Compute_IC_Stmt(op,new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg_new),new Register_Addr_Opd(reg)));
		reg_new->reset_use_for_expr_result();
	}
	else{
		rhs_compiled = rhs_op->compile();
		reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Compute_IC_Stmt(op,new Register_Addr_Opd(lhs_compiled.get_reg()),new Register_Addr_Opd(rhs_compiled.get_reg()),new Register_Addr_Opd(reg)));
		i_stmts->splice(i_stmts->begin(),rhs_compiled.get_icode_list());
		i_stmts->splice(i_stmts->begin(),lhs_compiled.get_icode_list());
	}

	
	rhs_compiled.get_reg()->reset_use_for_expr_result();
	if(lhs_op != NULL){
		lhs_compiled.get_reg()->reset_use_for_expr_result();
	}

	reg->set_use_for_expr_result();
	return *new Code_For_Ast(*i_stmts,reg);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Selection_Statement_Ast::compile(){
	Code_For_Ast & cond_compiled = cond->compile();
	Code_For_Ast & then_compiled = then_part->compile();
	Code_For_Ast else_compiled;
	if(else_part != NULL){
		else_compiled = else_part->compile();
	} 
	Tgt_Op op = cond_compiled.get_icode_list().back()->get_op().get_op();
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	string jump_label = this->get_new_label();
	i_stmts->splice(i_stmts->begin(),cond_compiled.get_icode_list());

	if(cond_compiled.get_reg() != NULL){

		i_stmts->push_back(new Control_Flow_IC_Stmt(beq,new Register_Addr_Opd(cond_compiled.get_reg()),NULL,jump_label));
		cond_compiled.get_reg()->reset_use_for_expr_result();
		
	}
	else{
		if(op == sle_d || op == slt_d || op == seq_d){
			i_stmts->push_back(new Control_Flow_IC_Stmt(bc1f,NULL,NULL,jump_label));
		}
		else{
			i_stmts->push_back(new Control_Flow_IC_Stmt(bc1t,NULL,NULL,jump_label));
		}
	}

	i_stmts->splice(i_stmts->end(),then_compiled.get_icode_list());
		
	if(else_part != NULL){
		string next_label = this->get_new_label();
		i_stmts->push_back(new Control_Flow_IC_Stmt(j,NULL,NULL,next_label));
		i_stmts->push_back(new Label_IC_Stmt(label,jump_label));
		i_stmts->splice(i_stmts->end(),else_compiled.get_icode_list());
		i_stmts->push_back(new Label_IC_Stmt(label,next_label));
		if(else_compiled.get_reg()!=NULL){
			else_compiled.get_reg()->reset_use_for_expr_result();
		}
	}
	else{
		i_stmts->push_back(new Label_IC_Stmt(label,jump_label));
	}
	
	if(then_compiled.get_reg()!=NULL){
		then_compiled.get_reg()->reset_use_for_expr_result();
	}
	
	return *new Code_For_Ast(*i_stmts,NULL);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Code_For_Ast & Iteration_Statement_Ast::compile(){
	Code_For_Ast cond_compiled = cond->compile();
	Code_For_Ast body_compiled = body->compile();
	Tgt_Op op = cond_compiled.get_icode_list().back()->get_op().get_op();

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;

	string next_label = this->get_new_label();
	string next_to_next_label = this->get_new_label();

	if(!is_do_form){
		i_stmts->push_back(new Control_Flow_IC_Stmt(j,NULL,NULL,next_to_next_label));
	}
	
	i_stmts->push_back(new Label_IC_Stmt(label,next_label));
	i_stmts->splice(i_stmts->end(),body_compiled.get_icode_list());
	i_stmts->push_back(new Label_IC_Stmt(label,next_to_next_label));
	i_stmts->splice(i_stmts->end(),cond_compiled.get_icode_list());

	if(cond_compiled.get_reg() != NULL){
		i_stmts->push_back(new Control_Flow_IC_Stmt(bne,new Register_Addr_Opd(cond_compiled.get_reg()),NULL,next_label));
		cond_compiled.get_reg()->reset_use_for_expr_result();
	}
	else{
		if(op == sle_d || op == slt_d || op == seq_d){
			i_stmts->push_back(new Control_Flow_IC_Stmt(bc1t,NULL,NULL,next_label));
		}
		else{
			i_stmts->push_back(new Control_Flow_IC_Stmt(bc1f,NULL,NULL,next_label));
		}
	}

	if(body_compiled.get_reg()!=NULL){
		body_compiled.get_reg()->reset_use_for_expr_result();
	}

	return *new Code_For_Ast(*i_stmts,NULL);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Sequence_Ast::print_assembly(ostream & file_buffer){

}

void Sequence_Ast::print_icode(ostream & file_buffer){
	
}


Code_For_Ast & Sequence_Ast::compile(){

	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Code_For_Ast cfa;
	for(list<Ast*>::iterator it=statement_list.begin(); it != statement_list.end(); ++it){
		cfa = (*it)->compile();
		i_stmts->splice(i_stmts->end(),cfa.get_icode_list());
	}

	return *new Code_For_Ast(*i_stmts,NULL);
}



Code_For_Ast & Print_Ast::compile(){
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	
	if(var->get_data_type() == int_data_type){
		i_stmts->push_back(new Move_IC_Stmt(imm_load,new Const_Opd<int>(1),new Register_Addr_Opd(machine_desc_object.spim_register_table[v0])));
		i_stmts->push_back(new Move_IC_Stmt(load,new Mem_Addr_Opd(((Name_Ast*)var)->get_symbol_entry()),new Register_Addr_Opd(machine_desc_object.spim_register_table[a0])));
		i_stmts->push_back(new Print_IC_Stmt());

	}
	else if(var->get_data_type() == double_data_type){
		i_stmts->push_back(new Move_IC_Stmt(imm_load,new Const_Opd<int>(3),new Register_Addr_Opd(machine_desc_object.spim_register_table[v0])));
		i_stmts->push_back(new Move_IC_Stmt(load_d,new Mem_Addr_Opd(((Name_Ast*)var)->get_symbol_entry()),new Register_Addr_Opd(machine_desc_object.spim_register_table[f12])));
		i_stmts->push_back(new Print_IC_Stmt());
	}
	
	return *new Code_For_Ast(*i_stmts,NULL);
}



Code_For_Ast & Call_Ast::compile(){
	check_actual_formal_param(program_object.get_procedure_prototype(procedure_name)->get_formal_param_list());
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	Code_For_Ast cfa;
	int offset = 0;
	int count = program_object.get_procedure_prototype(procedure_name)->get_formal_param_list().get_table().size();

	string param_names[count];

	for (list<Symbol_Table_Entry*>::iterator it=program_object.get_procedure_prototype(procedure_name)->get_formal_param_list().get_table().begin(); it != program_object.get_procedure_prototype(procedure_name)->get_formal_param_list().get_table().end(); ++it){
		count--;
		// In reverse order
		param_names[count] = (*it)->get_variable_name(); 
	}
	count = 0;
	for (list<Ast*>::reverse_iterator rit=actual_param_list.rbegin(); rit != actual_param_list.rend(); ++rit){
		cfa = (*rit)->compile();
		i_stmts->splice(i_stmts->end(),cfa.get_icode_list());
		if((*rit)->get_data_type() == int_data_type){
			Symbol_Table_Entry *param = new Symbol_Table_Entry(param_names[count],int_data_type,lineno,sp_ref);
			param->set_start_offset(offset);
			param->set_symbol_scope(formal);
			// i_stmts->push_back(new Control_Flow_IC_Stmt(store,new Register_Addr_Opd(cfa.get_reg()),new Const_Opd<int>(offset),param_names[count]));
			i_stmts->push_back(new Move_IC_Stmt(store,new Register_Addr_Opd(cfa.get_reg()),new Mem_Addr_Opd(*param)));
			cfa.get_reg()->reset_use_for_expr_result();
			offset = offset - 4;
			count++;
		}
		else if((*rit)->get_data_type() == double_data_type){
			Symbol_Table_Entry *param = new Symbol_Table_Entry(param_names[count],double_data_type,lineno,sp_ref);
			param->set_start_offset(offset);
			param->set_symbol_scope(formal);

			// i_stmts->push_back(new Control_Flow_IC_Stmt(store_d,new Register_Addr_Opd(cfa.get_reg()),new Const_Opd<int>(offset),param_names[count]));
			i_stmts->push_back(new Move_IC_Stmt(store_d,new Register_Addr_Opd(cfa.get_reg()),new Mem_Addr_Opd(*param)));
			cfa.get_reg()->reset_use_for_expr_result();
			offset = offset - 8;
			count++;
		}
		
	}
	if(offset != 0){
		i_stmts->push_back(new Control_Flow_IC_Stmt(jal,NULL,new Const_Opd<int>(-offset),procedure_name));
	}
	else{
		i_stmts->push_back(new Control_Flow_IC_Stmt(jal,NULL,NULL,procedure_name));
	}
	
	if(program_object.get_procedure_prototype(procedure_name)->get_return_type() == int_data_type){
		Register_Descriptor* reg = machine_desc_object.get_new_register<int_reg>();
		i_stmts->push_back(new Move_IC_Stmt(mov,new Register_Addr_Opd(machine_desc_object.spim_register_table[v1]),new Register_Addr_Opd(reg)));
		reg->reset_use_for_expr_result();
		return *new Code_For_Ast(*i_stmts,reg);
	}
	else if(program_object.get_procedure_prototype(procedure_name)->get_return_type() == double_data_type){
		Register_Descriptor* reg = machine_desc_object.get_new_register<float_reg>();
		i_stmts->push_back(new Move_IC_Stmt(move_d,new Register_Addr_Opd(machine_desc_object.spim_register_table[f0]),new Register_Addr_Opd(reg)));
		reg->reset_use_for_expr_result();
		return *new Code_For_Ast(*i_stmts,reg);
	}
	else{
		return *new Code_For_Ast(*i_stmts,NULL);
	}

	
}

Code_For_Ast & Call_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}



Code_For_Ast & Return_Ast::compile(){
	list<Icode_Stmt *>* i_stmts = new list<Icode_Stmt *>;
	if(return_value != NULL){
		Code_For_Ast return_compiled = return_value->compile();
		i_stmts->splice(i_stmts->begin(),return_compiled.get_icode_list());
		if(return_value->get_data_type() == int_data_type){
			i_stmts->push_back(new Move_IC_Stmt(mov,new Register_Addr_Opd(return_compiled.get_reg()),new Register_Addr_Opd(machine_desc_object.spim_register_table[v1])));
		}
		else if(return_value->get_data_type() == double_data_type){
			i_stmts->push_back(new Move_IC_Stmt(move_d,new Register_Addr_Opd(return_compiled.get_reg()),new Register_Addr_Opd(machine_desc_object.spim_register_table[f0])));
		}
		return_compiled.get_reg()->reset_use_for_expr_result();
		
	}
	i_stmts->push_back(new Control_Flow_IC_Stmt(ret_inst,NULL,NULL,"epilogue_"+proc_name));
	return *new Code_For_Ast(*i_stmts,NULL);
	
}

Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra){

}