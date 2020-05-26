#include"Attributes.h"

///Attribute
Attribute::Attribute(unsigned short int _id)
    : type(ATTRIBUTES::ATTRIBUTES_TYPE::UNDEFINED),
    id(_id) {

    }

ATTRIBUTES::ATTRIBUTES_TYPE::TYPE Attribute::get_type() const {
    return type;
}

virtual bool Attribute::is_list() const{
    return false;
}

bool Attribute::operator< (const Attribute& a) const{
    if(this->type==a.type)
        return this->id < a.id;
    return this->type < a.type;
}

bool Attribute::operator> (const Attribute& a) const{
    if(this->type==a.type)
        return this->id > a.id;
    return this->type > a.type;
}

bool Attribute::operator== (const Attribute& a) const{
    return (this->type==a.type)&&(this->id == a.id);
}

bool Attribute::operator!= (const Attribute& a) const{
    return !(*this==a);
}

bool Attribute::operator<= (const Attribute& a) const{
    return (*this<a)||(this==a);
}

bool Attribute::operator>= (const Attribute& a) const{
    return (*this>a)||(this==a);
}
///Name
Name::Name(unsigned long long _id): Feature(id), name("\n") {

}

Name::Name(unsigned long long _id, std::string _name): Feature(id), name(_name){

}

std::string get_name() const{
    return name;
}

virtual bool is_list() const override{
    return false;
}

