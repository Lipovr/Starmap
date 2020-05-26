#include"Listbox.h"
Listbox::Listbox(unsigned long long _id, unsigned int _unitsx, unsigned int _unitsy, unsigned int _height, int _width, const std::vector<std::string>& _list, const std::string& _name="\n", const std::string& _description="\n")
:   Button(_id, _unitsx, _unitsy, _height, _width, _name, _description),
    list(_list),
    sel_list_entry(0),
    total_entries(list.size()){

    }

const std::string& Listbox::get_sel() const{
    if(sel_list_entry>=total_entries)
        ///throw
    const std::string& r=list[sel_list_entry];
    return r;
}

unsigned int Listbox::get_sel_entry() const{
    return sel_list_entry;
}

void Listbox::set_sel_entry(unsigned int _entry){
    if(_entry>=total_entries)
        ///throw
    sel_list_entry=_entry;
}

void Listbox::advance(){
    if(++sel_list_entry>=total_entries)
        sel_list_entry=0;
}

void Listbox::go_back(){
    if(sel_list_entry==0)
        sel_list_entry=(total_entries-1);
    else
        --sel_list_entry;
}

bool Listbox::check_side(float _x, float _y) const{
    sf::Vector2f v(rectangle.getSize().x/2.0f, rectangle.getScale().y);
    sf::FloatRect right_bounds(sf::Vector2f(posx+v.x,posy), v);
    return right_bounds.contains(_x, _y);
}

bool Listbox::change(bool _b){
    if(b)
        advance();
    else
        go_back();
}
