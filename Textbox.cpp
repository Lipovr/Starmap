#include"Textbox.h"

Textbox::Textbox(unsigned long long _id, unsigned int _unitsx, unsigned int _unitsy, unsigned int _height, int width, const std::string& _name="\n", const std::string& _description="\n")
:   Button(_id, _unitsx, _unitsy, _height, _width, _name, _description){

}



//void Textbox()::update_height(){
//
//}


void Textbox::append(char _char){
    name.push_back(_char);
}

void Textbox::remove(){
    name.pop_back();
}

FT::TYPE Textbox::get_type() const override{
    return FT::TEXTBOX;
}

int Textbox::get_rank() const override{
    return get_type();
}
