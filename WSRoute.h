#ifndef WSROUTE_H_INCLUDED
#define WSROUTE_H_INCLUDED
#include"Feature.h"

class WSRoute: public Feature{
protected:
    Star* begin_ptr;
    Star* end_ptr;
    float endx;
    float endy;
    float thickness;
    sf::Color color;
    sf::RectangleShape line;
    void update_pos() override;
    void update_thickness();
public:
    WSRoute()=delete;
    WSRoute(unsigned long long _id, float _x=0.0f, float _y=0.0f, float _endx=0.0f, float _endy=0.0f, std::string _name="\n", std::string _description="\n");

    const sf::Drawable& get_drawable() const override;

    FT::TYPE get_type() const override;
    int get_rank() const override;

    void set_begin_ptr(Star* _begin_ptr);
    void set_end_ptr(Star* _end_ptr);
    Star* get_begin_ptr() const;
    Star* get_end_ptr() const;

    void update_ends();

    void set_pos(float _x, float _y) override;
    void set_posx(float _x) override;
    void set_posy(float _y) override;
    void set_end(float _endx, float _endy);
    void set_endx(float _endx);
    void set_endy(float _endy);
    float get_endx() const;
    float get_endy() const;

    void set_thickness(float _thickness);
    float get_thickness() const;

    void set_color(sf::Color _color);
    sf::Color get_color() const;

    bool check(float _x, float _y)const override;





};


#endif // WSROUTE_H_INCLUDED
