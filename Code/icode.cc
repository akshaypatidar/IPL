#include "icode.hh"


///////////////////////// Instruction Descriptor ///////////////////////////////////


Instruction_Descriptor::Instruction_Descriptor(Tgt_Op op, string name, string mnn, string ics, Icode_Format icf, Assembly_Format af){
	this->inst_op = op;
	this->mnemonic = mnn;
	this->name = name;
	this->ic_symbol = ics;    
	this->ic_format = icf;
	this->assem_format = af;

}

Instruction_Descriptor::Instruction_Descriptor(){
	this->inst_op = nop;
	this->mnemonic = "";
	this->name = "";
	this->ic_symbol = "";    
	this->ic_format = i_nsy;
	this->assem_format = a_nsy;
}


Tgt_Op Instruction_Descriptor::get_op(){
	return this->inst_op;
}

string Instruction_Descriptor::get_name(){
	return name;
}

string Instruction_Descriptor::get_mnemonic(){
	return mnemonic;
}

string Instruction_Descriptor::get_ic_symbol(){
	return ic_symbol;
}

Icode_Format Instruction_Descriptor::get_ic_format(){
	return ic_format;
}

Assembly_Format Instruction_Descriptor::get_assembly_format(){
	return assem_format;
}

void Instruction_Descriptor::print_instruction_descriptor(ostream & file_buffer){
	// TODO
}




///////////////////////////// Ics_Opd ///////////////////////////////////

Register_Descriptor * Ics_Opd::get_reg(){
	return NULL;
}


// Mem_Addr_Opd


Mem_Addr_Opd::Mem_Addr_Opd(Symbol_Table_Entry & se){

	symbol_entry = &se;
}

void Mem_Addr_Opd::print_ics_opd(ostream & file_buffer){
	file_buffer<<symbol_entry->get_variable_name();
}

void Mem_Addr_Opd::print_asm_opd(ostream & file_buffer){
	if(symbol_entry->get_symbol_scope() == local || symbol_entry->get_symbol_scope() == formal){
		if(symbol_entry->get_ref_offset() == fp_ref){
			file_buffer<<symbol_entry->get_start_offset()<<"($fp)";
		}
		else{
			file_buffer<<symbol_entry->get_start_offset()<<"($sp)";
		}
		
	}
	else if(symbol_entry->get_symbol_scope() == global){
		file_buffer<<symbol_entry->get_variable_name();
	}
		
}

Mem_Addr_Opd & Mem_Addr_Opd::operator= (const Mem_Addr_Opd & rhs){
	symbol_entry = rhs.symbol_entry;
	return *this;
}


// Register_Addr_Opd

Register_Addr_Opd::Register_Addr_Opd(Register_Descriptor * rd){
	register_description = rd;
}

Register_Descriptor * Register_Addr_Opd::get_reg(){
	return register_description;
}

void Register_Addr_Opd::print_ics_opd(ostream & file_buffer){
	file_buffer<<register_description->get_name();
}
void Register_Addr_Opd::print_asm_opd(ostream & file_buffer){
	file_buffer<<"$"<<register_description->get_name();
}

Register_Addr_Opd & Register_Addr_Opd::operator=(const Register_Addr_Opd & rhs){
	register_description = rhs.register_description;
	return *this;
}

/// Const_Opd

template <class T>
Const_Opd<T>::Const_Opd(T num){
	this->num = num;
}

template Const_Opd<int>::Const_Opd(int num);
template Const_Opd<double>::Const_Opd(double num);

template <class T>
void Const_Opd<T>::print_ics_opd(ostream & file_buffer){
	file_buffer<<num;
}

template void Const_Opd<int>::print_ics_opd(ostream & file_buffer);
template void Const_Opd<double>::print_ics_opd(ostream & file_buffer);

template <class T>
void Const_Opd<T>::print_asm_opd(ostream & file_buffer){
	file_buffer<<num;
}

template void Const_Opd<int>::print_asm_opd(ostream & file_buffer);
template void Const_Opd<double>::print_asm_opd(ostream & file_buffer);

template <class T>
Const_Opd<T> & Const_Opd<T>::operator=(const Const_Opd<T> & rhs){
	this->num = rhs.num;
	return *this;
}

template Const_Opd<int> & Const_Opd<int>::operator=(const Const_Opd<int> & rhs);
template Const_Opd<double> & Const_Opd<double>::operator=(const Const_Opd<double> & rhs);



///////////////////////////////// Icode_Stmt //////////////////////////


Instruction_Descriptor & Icode_Stmt::get_op(){
	return op_desc;
}

Ics_Opd * Icode_Stmt::get_opd1(){

}

Ics_Opd * Icode_Stmt::get_opd2(){

}

Ics_Opd * Icode_Stmt::get_result(){

}

void Icode_Stmt::set_opd1(Ics_Opd * io){

}

void Icode_Stmt::set_opd2(Ics_Opd * io){

}

void Icode_Stmt::set_result(Ics_Opd * io){

}


// Print_IC_Stmt
Print_IC_Stmt::Print_IC_Stmt(){

}

Print_IC_Stmt::~Print_IC_Stmt(){

}

void Print_IC_Stmt::print_icode(ostream & file_buffer){
	file_buffer<<"\tprint\n";
}

void Print_IC_Stmt::print_assembly(ostream & file_buffer){
	file_buffer<<"\tsyscall\n";
}



//  Move_IC_Stmt
Move_IC_Stmt::Move_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * result){
	this->opd1 = opd1;
	this->result = result;
	this->op_desc = *machine_desc_object.spim_instruction_table[inst_op];
}

Move_IC_Stmt & Move_IC_Stmt::operator=(const Move_IC_Stmt & rhs){
	this->opd1 = rhs.opd1;
	this->result = rhs.result;
	this->op_desc = rhs.op_desc;

	return *this;
}

Instruction_Descriptor & Move_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd * Move_IC_Stmt::get_opd1(){
	return opd1;
}

void Move_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1 = io;
}

Ics_Opd * Move_IC_Stmt::get_result(){
	return result;
}

void Move_IC_Stmt::set_result(Ics_Opd * io){
	result = io;
}

void Move_IC_Stmt::print_icode(ostream & file_buffer){
	file_buffer<<"\t"<<op_desc.get_name()<<":    \t";
	result->print_ics_opd(file_buffer);
	file_buffer<<" <- ";
	opd1->print_ics_opd(file_buffer);
	file_buffer<<endl;
}

void Move_IC_Stmt::print_assembly(ostream & file_buffer){
	if(op_desc.get_assembly_format() == a_op_o1_r){
		file_buffer<<"\t"<<op_desc.get_mnemonic()<<" ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", ";
		result->print_asm_opd(file_buffer);
		file_buffer<<endl;

	}
	else{
		file_buffer<<"\t"<<op_desc.get_mnemonic()<<" ";
		result->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<endl;
	}
	
}



//   Compute_IC_Stmt

Compute_IC_Stmt::Compute_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * opd2, Ics_Opd * result){
	this->opd1 = opd1;
	this->opd2 = opd2;
	this->result = result;
	this->op_desc = *machine_desc_object.spim_instruction_table[inst_op];
}

Compute_IC_Stmt & Compute_IC_Stmt::operator=(const Compute_IC_Stmt & rhs){
	this->opd1 = rhs.opd1;
	this->opd2 = rhs.opd2;
	this->result = rhs.result;
	this->op_desc = rhs.op_desc;

	return *this;
}

Instruction_Descriptor & Compute_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd * Compute_IC_Stmt::get_opd1(){
	return opd1;
}

void Compute_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1 = io;
}

Ics_Opd * Compute_IC_Stmt::get_opd2(){
	return opd2;
}

void Compute_IC_Stmt::set_opd2(Ics_Opd * io){
	opd2 = io;
}

Ics_Opd * Compute_IC_Stmt::get_result(){
	return result;
}

void Compute_IC_Stmt::set_result(Ics_Opd * io){
	result = io;
}

void Compute_IC_Stmt::print_icode(ostream & file_buffer){
	
	if(result == NULL){
		printf("cs316: Error : Result of Compute_IC_Stmt cannot be NULL\n");
		exit(0);
	}
	else{
		file_buffer<<"\t"<<op_desc.get_name()<<":    \t";
		result->print_ics_opd(file_buffer);
		file_buffer<<" <- ";
		opd1->print_ics_opd(file_buffer);
		file_buffer<<" , ";
		opd2->print_ics_opd(file_buffer);
		file_buffer<<endl;
	}
	
		
}

void Compute_IC_Stmt::print_assembly(ostream & file_buffer){
	
	file_buffer<<"\t"<<op_desc.get_mnemonic()<<" ";
	if(result != NULL){
		result->print_asm_opd(file_buffer);
		file_buffer<<", ";
	}
	opd1->print_asm_opd(file_buffer);
	file_buffer<<", ";
	opd2->print_asm_opd(file_buffer);
	file_buffer<<endl;
	
}



//  Control_Flow_IC_Stmt

Control_Flow_IC_Stmt::Control_Flow_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * opd2, string label, int size){
	this->opd1 = opd1;
	this->opd2 = opd2;
	this->offset = label;
	this->op_desc = *machine_desc_object.spim_instruction_table[inst_op];
}

Control_Flow_IC_Stmt & Control_Flow_IC_Stmt::operator=(const Control_Flow_IC_Stmt & rhs){
	this->opd1 = rhs.opd1;
	this->opd2 = rhs.opd2;
	this->offset = rhs.offset;
	this->op_desc = rhs.op_desc;

	return *this;
}

Instruction_Descriptor & Control_Flow_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd * Control_Flow_IC_Stmt::get_opd1(){
	return opd1;
}

void Control_Flow_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1 = io;
}

Ics_Opd * Control_Flow_IC_Stmt::get_opd2(){
	return opd2;
}

void Control_Flow_IC_Stmt::set_opd2(Ics_Opd * io){
	opd2 = io;
}

string Control_Flow_IC_Stmt::get_Offset(){
	return offset;
}

void Control_Flow_IC_Stmt::set_Offset(string label){
	this->offset = label;
}

void Control_Flow_IC_Stmt::print_icode(ostream & file_buffer){
	// if(op_desc.get_mnemonic() == "sw" || op_desc.get_mnemonic() == "s.d"){
	// 	file_buffer<<"\t"<<op_desc.get_name()<<":    \t";
	// 	file_buffer<<offset;
	// 	file_buffer<<" <- ";
	// 	opd1->print_ics_opd(file_buffer);
	// 	file_buffer<<endl;
	// }
	//beq and bne
	if(opd1 != NULL){
		file_buffer<<"\t"<<op_desc.get_name()<<":    \t";
		opd1->print_ics_opd(file_buffer);
		file_buffer<<" , zero : goto "<<offset<<endl;
	}
	else if(op_desc.get_mnemonic() == "jal"){
		file_buffer<<"\t"<<"call "<<offset<<endl;
	}
	// return
	else if(op_desc.get_name() == "return"){
		file_buffer<<"\treturn\n";
	}
	else{
		
		file_buffer<<"\t"<<"goto "<<offset<<endl;
	}
	
	
}

void Control_Flow_IC_Stmt::print_assembly(ostream & file_buffer){
	if(op_desc.get_mnemonic() == "sw" || op_desc.get_mnemonic() == "s.d"){
		file_buffer<<"\t"<<op_desc.get_mnemonic()<<" ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd2->print_asm_opd(file_buffer);
		file_buffer<<"($sp)"<<endl;
	}
	//beq and bne
	else if(opd1 != NULL){
		file_buffer<<"\t"<<op_desc.get_name()<<" ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", $zero, "<<offset<<" "<<endl;
	}
	else if(op_desc.get_mnemonic() == "jal"){
		// TODO no $sp statements when opd2 = 0
		if(opd2 != NULL){
			file_buffer<<"\tsub $sp, $sp, ";
			opd2->print_asm_opd(file_buffer);
			file_buffer<<endl;
			file_buffer<<"\t"<<op_desc.get_mnemonic()<<" "<<offset<<endl;
			file_buffer<<"\tadd $sp, $sp, ";
			opd2->print_asm_opd(file_buffer);
			file_buffer<<endl;
		}
		else{
			file_buffer<<"\t"<<op_desc.get_mnemonic()<<" "<<offset<<endl;
		}
		

	}
	else if(op_desc.get_name() == "return"){
		file_buffer<<"\t"<<"j"<<" "<<offset<<endl;
	}
	// j,bc1t
	else{
		file_buffer<<"\t"<<op_desc.get_mnemonic()<<" "<<offset<<endl;
	}
}



//  Label_IC_Stmt

Label_IC_Stmt::Label_IC_Stmt(Tgt_Op inst_op, string label){
	this->label = label;
	this->op_desc = *machine_desc_object.spim_instruction_table[inst_op];
}

Label_IC_Stmt & Label_IC_Stmt::operator=(const Label_IC_Stmt & rhs){
	this->label = rhs.label;
	this->op_desc = rhs.op_desc;

	return *this;
}

Instruction_Descriptor & Label_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

string Label_IC_Stmt::get_label(){
	return label;
}

void Label_IC_Stmt::set_label(string label){
	this->label = label;
}

void Label_IC_Stmt::print_icode(ostream & file_buffer){
	file_buffer<<endl<<label<<":    \t\n";
}

void Label_IC_Stmt::print_assembly(ostream & file_buffer){
	file_buffer<<endl<<label<<":    \t\n";
}


//  Code_For_Ast

Code_For_Ast::Code_For_Ast(){
	result_register = NULL;
}

Code_For_Ast::Code_For_Ast(list<Icode_Stmt *> & ic_l, Register_Descriptor * reg){
	ics_list = ic_l;
	result_register = reg;
}


void Code_For_Ast::append_ics(Icode_Stmt & ics){
	ics_list.push_back(&ics);
}

list<Icode_Stmt *> & Code_For_Ast::get_icode_list(){
	return ics_list;
}

Register_Descriptor * Code_For_Ast::get_reg(){
	return result_register;
}

void Code_For_Ast::set_reg(Register_Descriptor * reg){
	result_register = reg;
}

Code_For_Ast & Code_For_Ast::operator=(const Code_For_Ast & rhs){


	// Uncomment to remove segmentation fault in -tokens


	this->result_register = rhs.result_register;
	this->ics_list = rhs.ics_list;

	return *this;
}