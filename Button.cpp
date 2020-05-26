#include"Button.h"

Button::Button(unsigned long long _id, unsigned int _unitsx, unsigned int _unitsy, unsigned int _height, int _width, const std::string& _name="\n", ATTRIBUTES::ATTRIBUTES_TYPE::TYPE _repr_attr=ATTRIBUTES::ATTRIBUTES_TYPE::UNDEFINED, const std::string& _description="\n")
:   Feature(_id, static_cast<float>(_unitsx)*CONSTANTS::menu_unit, static_cast<float>(_unitsy)*CONSTANTS::menu_unit, _name, _description),
    //unitsx(_unitsx),
    //unitsy(_unitsy),
    max_char_size(0),
    line_height(0),
    height(_height),
    width(_width),
    rel_color(CONSTANTS::b_rel),
    pressed_color(CONSTANTS::b_pr),
    outl_color(CONSTANTS::menu_outl),
    outl_thickness(CONSTANTS::menu_element_outline),
    rectangle(sf::RectangleShape(sf::Vector2f(static_cast<double>(width)*CONSTANTS::menu_unit, static_cast<double>(height)*CONSTANTS::menu_unit))),
    is_pressed(false),
    repr_attr(_rep_attr){
    rectangle.setFillColor(rel_color);
    rectangle.setOutlineThickness(outl_thickness);
    rectangle.setOutlineColor(outl_color);
    rectangle.setPosition(posx, posy);
    update_text();
}

virtual void Button::update_pos() override{
    rectangle.setSize(sf::vector2f(static_cast<double>(width)*CONSTANTS::menu_unit, static_cast<double>(height)*CONSTANTS::menu_unit);
    rectangle.setPosition(posx, posy);
}

virtual void Button::update_outl() override{
    rectangle.setOutlineColor(outl_color);
    rectangle.setOutlineThickness(outl_thickness);

}


virtual void Button::update_text(){
    for (int j=0; j<name.size(); j++){
        if(name[j]=='\n')
            name[j]=' ';
    }
    int addh=1;
    int cpos=0;
    while(){
    if(CONSTANTS::max_char_size*(name.size()-cpos)>width*CONSTANTS::menu_unit){//остаток больше
        int p=width*CONSTANTS::menu_unit/CONSTANTS::max_char_size;//начиная с какого не влезло
        int i;
        for(i=p;i>=0;i--){
            if(name[i]==' '){
                name[i]='\n';
                addh++;
                cpos=i+1;
                break;
            }
        }
        if(i==0){
            name[p]='\n';
            addh++;
            cpos=p+1;
        }
    }
    else{

        break;
    }
    }
    set_height(get_height()+addh);
}


    virtual const sf::Drawable& Button::get_drawable() const override{
        const sf::Drawable& r=rectangle;
        return r;
    }


    //float get_posy() const override;
    virtual FT::TYPE Button::get_type() const override{
        return FT::BUTTON;
    }
    virtual int Button::get_rank() const override {
        return get_type();
    }
    virtual bool Button::check(float _x, float _y) const override{
        return rectangle.getGlobalBounds().contains(_x,_y);
    }

//    void set_posx(float _x) override;
//    void set_posy(float _y) override;
//
    virtual void Button::set_height(unsigned int _height){
        height=_height;
        update_pos();
    }
    virtual void Button::set_width(unsigned int _width){
        width=_width;
        update_pos();
    }
    unsigned int Button::get_height() const {
        return height;
    }
    virtual unsigned int Button::get_width() const{
        return width;
    }

    virtual sf::Color Button::get_rel_color() const{
        return rel_color;
    }
    virtual void Button::set_rel_color(sf::Color _color){
        rel_color=_color;
        if(!is_pressed)
            rectangle.setFillColor(rel_color);
    }
    virtual sf::Color Button::get_pressed_color() const{
        return pressed_color;
    }
    virtual void Button::set_pressed_color(sf::Color _color){
        pressed_color=_color;
        if(is_pressed)
            rectangle.setFillColor(pressed_color);
    }

    virtual void Button::set_state(bool _state){
        if(_state==is_pressed){
            return;
        }
        is_pressed=_state;
        if(is_pressed){
            rectangle.setFillColor(pressed_color);
            return;
        }
        rectangle.setFillColor(rel_color);
    }
    virtual bool Button::get_state() const{
        return is_pressed;
    }
    virtual void Button::set_unit_pos(unsigned int _x, unsigned int _y){
        posx=static_cast<double>(_x)*CONSTANTS::menu_unit;
        posy=static_cast<double>(_y)*CONSTANTS::menu_unit;
        update_pos();

    }

    virtual void Button::set_unit_x(unsigned int _x){
        posx=static_cast<double>(_x)*CONSTANTS::menu_unit;
        update_pos();
    }

    virtual void Button::set_unit_y(unsigned int _y){
        posy=static_cast<double>(_y)*CONSTANTS::menu_unit;
        update_pos();
    }

    virtual unsigned int Button::get_unit_x()const{
        if(CONSTANTS::menu_unit==0)
            ///throw
        return static_cast<unsigned int>(posx/CONSTANTS::menu_unit);
    }
    virtual unsigned int Button::get_unit_y()const{
        if(CONSTANTS::menu_unit==0)
            ///throw
        return static_cast<unsigned int>(posy/CONSTANTS::menu_unit);
    }

    virtual ATTRIBUTES::ATTRIBUTES_TYPE::TYPE Button::get_repr_attr() const{
        return repr_attr;
    }

    virtual void Button::set_repr_attr(ATTRIBUTES::ATTRIBUTES_TYPE::TYPE _repr_attr){
        repr_attr=_repr_attr;
    }

    virtual void Button::set_name(std::string _name){
        name=_name;
        update_text();
    }
