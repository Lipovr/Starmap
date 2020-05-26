#include"WSRoute.h"

WSRoute::WSRoute(unsigned long long _id, float _x=0.0f, float _y=0.0f, float _endx=0.0f, float _endy=0.0f, std::string _name="\n", std::string _description="\n")
:   Feature(_id, _x, _y, _name, _description), begin_id(0), end_id(0), endx(_endx), endy(_endy), thickness(1.0f), color(sf::Color(211, 19, 236, 1)), line(sf::RectangleShape()){
    sf::Vector2f dir(endx-posx,endy-posy);
    sf::Vector2f th(0.0f, thickness);
    sf::RectangleShape _line(sf::Vector2f(std::sqrt(std::pow(dir.x,2)+std::pow(dir.y,2)),thickness));
    _line.setOrigin(th/2.0f);
    _line.setPosition(sf::Vector2f(posx, posy));
    if(dir.x>0){
        _line.setRotation(180.0f*std::asin(dir.y/std::sqrt(std::pow(dir.x,2)+std::pow(dir.y,2)))/(4*std::atan(1.0f)));

    }
    else{
        _line.setRotation(180.0f-180.0f*std::asin(dir.y/std::sqrt(std::pow(dir.x,2)+std::pow(dir.y,2)))/(4*std::atan(1.0f)));
    }
    _line.setFillColor(color);
    _line.setOutlineThickness(0.0f);
    line=_line;
}

void WSRoute::update_pos() override{
    sf::Vector2f dir(endx-posx,endy-posy);
    line.setSize(sf::Vector2f(std::sqrt(std::pow(dir.x,2)+std::pow(dir.y,2)),thickness));
    line.setPosition(sf::Vector2f(posx, posy));
    if(dir.x>0){
        line.setRotation(180.0f*std::asin(dir.y/std::sqrt(std::pow(dir.x,2)+std::pow(dir.y,2)))/(4*std::atan(1.0f)));
    }
    else{
        line.setRotation(180.0f-180.0f*std::asin(dir.y/std::sqrt(std::pow(dir.x,2)+std::pow(dir.y,2)))/(4*std::atan(1.0f)));
    }
}

void WSRoute::update_thickness(){
    line.setSize(sf::Vector2f(line.getSize().x, thickness));
    line.setOrigin(0.0, thickness/2);
}

const sf::Drawable& WSRoute::get_drawable() const override{
    const sf::Drawable& r=line;
    return r;
}

FT::TYPE WSRoute::get_type() const override{
    return FT::WSROUTE;
}

int WSRoute::get_rank() const override{
    return get_type();
}

void WSRoute::set_begin_ptr(Star* _begin_ptr){
    begin_ptr=_begin_ptr;
}

void WSRoute::set_end_ptr(Star* _end_ptr){
    end_ptr=_end_ptr;
}

Star* WSRoute::get_begin_ptr() const{
    return begin_ptr;
}

Star* WSRoute::get_end_ptr() const{
    return end_ptr;
}

void WSRoute::update_ends(){
    Feature::set_pos(begin_ptr->get_posx(), begin_ptr->get_posy());
    set_end(end_ptr->get_posx(), end_ptr->get_posy());
}

void WSRoute::set_pos(float _x, float _y) override{
    Feature::set_pos(_x, _y);
    update_pos();
}

void WSRoute::set_posx(float _x) override{
    Feature::set_posx(_x);
    update_pos();
}

void WSRoute::set_posy(float _y) override{
    Feature::set_posy(_y);
    update_pos();
}

void WSRoute::set_end(float _endx, float _endy){
    endx=_endx;
    endy=_endy;
    update_pos();
}

void WSRoute::set_endx(float _endx){
    endx=_endx;
    update_pos();
}

void WSRoute::set_endy(float _endy){
    endy=_endy;
    update_pos();
}

float WSRoute::get_endx() const{
    return endx;
}

float WSRoute::get_endy() const{
    return endy;
}

void WSRoute::set_thickness(float _thickness){
    thickness=_thickness;
    update_thickness();
}

float WSRoute::get_thickness() const{
    return thickness;
}

void WSRoute::set_color(sf::Color _color){
    color=_color;
    line.setFillColor(color);
}

sf::Color WSRoute::get_color() const{
    return color;
}


bool WSRoute::check(float _x, float _y) const {
    return line.getLocalBounds().contains(line.getTransform().getInverse().transformPoint(_x, _y));
}
