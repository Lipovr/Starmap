#ifndef STAR_H_INCLUDED
#define STAR_H_INCLUDED
#include "Feature.h"
#include<vector>
class Star: public Feature {
protected:
    sf::CircleShape circle;
    std::vector<WSRoute*> WSRoutes;
    ATTRIBUTES::ATTRIBUTES_STAR::STARCLASS::STARCLASS_T starclass;
    ATTRIBUTES::ATTRIBUTES_STAR::ECONOMY::ECONOMY_T economy;
    void update_pos() override;
public:
    Star()=delete;
    Star(unsigned long long _id, float _x=0.0f, float _y=0.0f,const std::string& _name="\n",const std::string& _description="\n", ATTRIBUTES::STARCLASS::STARCLASS_T=ATTRIBUTES::STARCLASS::O, ATTRIBUTES::ECONOMY::ECONOMY_T=ATTRIBUTES::ECONOMY::UNDEFINED);
    std::unique_ptr<sf::Drawable*> get_drawable() const override;
    FT::TYPE get_type() const override;
    bool check(float _x, float _y) const override;
    int get_rank() const override;
//    std::string get_name() const override;
//    std::string get_description() const override;
    ATTRIBUTES::ATTRIBUTES_STAR::STARCLASS::STARCLASS_T get_starclass() const;
    ATTRIBUTES::ATTRIBUTES_STAR::ECONOMY::ECONOMY_T get_economy() const;
    void set_starclass(ATTRIBUTES::ATTRIBUTES_STAR::STARCLASS::STARCLASS_T _starclass);
    void set_economy(ATTRIBUTES::ATTRIBUTES_STAR::ECONOMY::ECONOMY_T _economy);
    void add_WSR(WSRoute* _wsr);
    void erase_WSR(WSRoute* _wsr);
    std::vector<WSRoute*> get_WSRs() const;

    void set_pos(float _x, float _y) override;
    void set_posx(float _x) override;
    void set_posy(float _y) override;


};


#endif // STAR_H_INCLUDED
