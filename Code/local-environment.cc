#include "local-environment.hh"




int Eval_Result_Value::get_int_value(){}
void Eval_Result_Value::set_value(int number){}
double Eval_Result_Value::get_double_value(){}
void Eval_Result_Value::set_value(double number){}
bool Eval_Result_Value::is_variable_defined(){}
void Eval_Result_Value::set_variable_status(bool def){}

int Eval_Result::get_int_value(){}
void Eval_Result::set_value(int number){}
double Eval_Result::get_double_value(){}
void Eval_Result::set_value(double number){}
bool Eval_Result::is_variable_defined(){}
void Eval_Result::set_variable_status(bool def){}


Eval_Result_Value_Int::Eval_Result_Value_Int(){}
Eval_Result_Value_Int::~Eval_Result_Value_Int(){}


void Eval_Result_Value_Int::set_value(int number){
	value = number;
}
void Eval_Result_Value_Int::set_value(double number){
	value = (int)number;
}
int Eval_Result_Value_Int::get_int_value(){
	return value;
}

void Eval_Result_Value_Int::set_variable_status(bool def){
	defined = def;
}
bool Eval_Result_Value_Int::is_variable_defined(){
	return defined;
}

void Eval_Result_Value_Int::set_result_enum(Result_Enum res){
	result_type = res;
}
Result_Enum Eval_Result_Value_Int::get_result_enum(){
	return result_type;
}


Eval_Result_Value_Double::Eval_Result_Value_Double(){}
Eval_Result_Value_Double::~Eval_Result_Value_Double(){}


void Eval_Result_Value_Double::set_value(int number){
	value = (double)number;
}
void Eval_Result_Value_Double::set_value(double number){
	value = number;
}
double Eval_Result_Value_Double::get_double_value(){
	return value;
}

void Eval_Result_Value_Double::set_variable_status(bool def){
	defined = def;
}
bool Eval_Result_Value_Double::is_variable_defined(){
	return defined;
}

void Eval_Result_Value_Double::set_result_enum(Result_Enum res){
	result_type = res;
}
Result_Enum Eval_Result_Value_Double::get_result_enum(){
	return result_type;
}

Local_Environment::Local_Environment(){}

Local_Environment::~Local_Environment(){}

void Local_Environment::print(ostream & file_buffer){
	for (map<string, Eval_Result *>::iterator itr = variable_table.begin(); itr != variable_table.end(); ++itr){
		if(!itr->second->is_variable_defined()){
			file_buffer<<AST_SPACE<<itr->first<<" : undefined\n";
		}
		else if(itr->second->get_result_enum() == int_result){
			file_buffer<<AST_SPACE<<itr->first<<" : "<<itr->second->get_int_value()<<endl;
		}
		else if(itr->second->get_result_enum() == double_result){
			file_buffer<<AST_SPACE<<itr->first<<" : "<<itr->second->get_double_value()<<endl;
		}
        
    } 
}

bool Local_Environment::is_variable_defined(string name){
	if(variable_table.count(name)>0 && variable_table[name]->is_variable_defined()){
		return true;
	}
	else{
		return false;
	}
}

Eval_Result * Local_Environment::get_variable_value(string name){
	return variable_table[name];
}

void Local_Environment::put_variable_value(Eval_Result & value, string name){
	variable_table[name] = &value;
}

bool Local_Environment::does_variable_exist(string name){
	if(variable_table.count(name)>0){
		return true;
	}
	else{
		return false;
	}
}

void Symbol_Table::create(Local_Environment & local_global_variables_table){

	for (list<Symbol_Table_Entry*>::iterator it=variable_table.begin(); it != variable_table.end(); ++it){
		Eval_Result * var;
		
		if((*it)->get_data_type() == int_data_type) {
			var = new Eval_Result_Value_Int();
			var->set_result_enum(int_result);
			if((*it)->get_symbol_scope() == local){
				var->set_variable_status(false);
			}
			else if((*it)->get_symbol_scope() == global){
				var->set_variable_status(true);
				var->set_value(0);
			}
			
			
		}
		else if((*it)->get_data_type() == double_data_type){
			var = new Eval_Result_Value_Double();
			var->set_result_enum(double_result);
			if((*it)->get_symbol_scope() == local){
				var->set_variable_status(false);
			}
			else if((*it)->get_symbol_scope() == global){
				var->set_variable_status(true);
				var->set_value(0.0);
			}
		} 

		local_global_variables_table.put_variable_value(*var,(*it)->get_variable_name());
	}

}