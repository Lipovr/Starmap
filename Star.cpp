#include"Star.h"
#include<algorithm>
Star::Star(unsigned long long _id, float _x=0.0f, float _y=0.0f, const std::string& _name="\n", const std::string& _description="\n", ATTRIBUTES::STARCLASS::STARCLASS_T _starclass=ATTRIBUTES::STARCLASS::O, ATTRIBUTES::ECONOMY::ECONOMY_T _economy=ATTRIBUTES::ECONOMY::UNDEFINED)
:   Feature(_id, _x, _y, _name, _description),
    starclass(_starclass),
    economy(_economy),
    circle(sf::CircleShape(10.0f)){
        circle.setFillColor(sf::Color::White);
        circle.setOutlineThickness(0.0f);
        circle.setOrigin(10.0f,10.0f);
    }

const sf::Drawable& Star::get_drawable() const override{
    const sf::Drawable& r=circle;
    return r;
}

bool Star::check(float _x, float _y) const override{
    sf::FloatRect< bounds=circle.getGlobalBounds();
    return bounds.contains(_x, _y);
}

FT::TYPE Star::get_type() const override{
    return FT::STAR;
}

int Star::get_rank() const override{
    return get_type();
}

//std::string get_name() const override{
//    return
//}

ATTRIBUTES::ATTRIBUTES_STAR::STARCLASS::STARCLASS_T Star::get_starclass() const{
    return starclass;
}

ATTRIBUTES::ATTRIBUTES_STAR::ECONOMY::ECONOMY_T Star::get_economy() const{
    return economy;
}

void Star::set_starclass(ATTRIBUTES::ATTRIBUTES_STAR::STARCLASS::STARCLASS_T _starclass){
    starclass=_starclass;
}
void Star::set_economy(ATTRIBUTES::ATTRIBUTES_STAR::ECONOMY::ECONOMY_T _economy){
    economy=_economy;
}


void Star::add_WSR(WSRoute* _wsr){
    WSRoutes.push_back(_wsr);

    //std::sort(WSRoutes.begin(), WSRoutes.end(), std::is_greater());
}


void Star::erase_WSR(WSRoute* _wsr){
    auto found=std::find(WSRoutes.begin(), WSRoutes.end(), _wsr);
    if(found==WSRoutes.end()){
        ///throw
    }
    else{
        WSRoutes.erase(found);
    }
}

std::vector<unsigned long long> Star::get_WSRs() const{
    return WSRoutes;
}

void Star::set_pos(float _x, float _y) override{
    Feature::set_pos(_x, _y);
    update_pos();
}

void Star::set_posx(float _x) override{
    Feature::set_posx(_x);
    update_pos();
}

void Star::set_posy(float _y) override{
    Feature::set_posy(_y);
    update_pos();
}

