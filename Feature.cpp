#include "Feature.h"

Feature::Feature(unsigned long long int _id, float _x=0.0f, float _y=0.0f, std::string _name="\n", std::string _description="\n"):
    posx(_x),
    posy(_y),
    Type(FT::UNDEFINED),
    is_selected(0),
    id(_id),
    name(_name),
    description(_description)
//    starclass(ATTRIBUTES::STARCLASS::UNDEFINED),
//    economy(ATTRIBUTES::ECONOMY::UNDEFINED)

};

Feature::~Feature() {};

virtual unsigned long int Feature::get_posx() const {
    return posx;
}

virtual unsigned long int Feature::get_posy() const {
    return posy;
}

virtual FT::TYPE Feature::get_type() const{
    return FT::UNDEFINED;
}

virtual void Feature::set_posx(float _x) {
    posx=x;
    update_pos();
}

virtual void Feature::set_posy(float _y) {
    posy=y;
    update_pos();
}

virtual void Feature::set_pos(float _x, float _y){
    posx=_x;
    posy=_y;
    update_pos();
}

virtual short int Feature::get_rank(){
//    if(is_selected)
//        return 0;
    return get_type();
}

virtual void Feature::set_name(std::string _name){
    name=_name;
}

virtual std::string Feature::get_name() const{
    return name;
}

virtual void Feature::set_description(std::string _description){
    description=_description;
}


virtual std::string Feature::get_description() const{
    return description;
}


//void Feature::select(){
//    if(selected)
//        selected->is_selected=false;
//    selected=this;
//    is_selected=true;
//}
//
//void Feature::unselect(){
//    if(is_selected){
//        selected=NULL;
//        is_selected=false;
//    }
//}

unsigned long long int Feature::get_id() const {
    return id;
}

//static unsigned long long Feature::generate_id(){
//    return ++last_id;
//}

bool Feature::operator<(const Feature& f) const {
    if(this->get_rank()==f.get_rank())
        return this->id < f.id;
    return this->get_rank() < f.get_rank();
}

bool Feature::operator>(const Feature& f) const{
    if(this->get_rank()==f.get_rank())
        return this->id > f.id;
    return this->get_rank() > f.get_rank();
}

bool Feature::operator==(const Feature& f) const{
    return this->id==f.id;
}

bool Feature::operator!=(const Feature& f) const{
    return !(*this==f);
}

bool Feature::operator<=(const Feature& f) const{
    return (*this<f)||(*this==f);
}

bool Feature::operator>=(const Feature& f) const{
    return (*this>f)||(*this==f);
}
