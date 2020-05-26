#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include"Feature.h"

class Button: public Feature{
protected:
    //unsigned int unitsx;
    //unsigned int unitsy;
    unsigned int height;
    unsigned int width;
rectangle.setOutlineColor(CONSTANTS::men_outl);
    sf::Color rel_color;
    sf::Color pressed_color;
    sf::Color outl_color;
    float outl_thickness;
    sf::RectangleShape rectangle;
    bool is_pressed;
    virtual void update_pos() override;
    virtual void update_outl();
    virtual void update_text();
    ATTRIBUTES::ATTRIBUTES_TYPE::TYPE repr_attr;
public:
    Button()=delete;
    Button(unsigned long long _id, unsigned int _unitsx, unsigned int _unitsy, unsigned int _height, int _width, const std::string& _name="\n", ATTRIBUTES::ATTRIBUTES_TYPE::TYPE _repr_attr=ATTRIBUTES::ATTRIBUTES_TYPE::UNDEFINED, const std::string& _description="\n");
    virtual ~Button(){};
    virtual const sf::Drawable& get_drawable() const override;
//    float get_posx() const override;
//    float get_posy() const override;
    virtual FT::TYPE get_type() const override;
    virtual ATTRIBUTES::ATTRIBUTES_TYPE::TYPE get_repr_attr() const;
    virtual void set_repr_attr(ATTRIBUTES::ATTRIBUTES_TYPE::TYPE _repr_attr);
    virtual int get_rank() const override;
    virtual bool check(float _x, float _y) const override;
//    void set_posx(float _x) override;
//    void set_posy(float _y) override;

    virtual void set_unit_pos(unsigned int _x, unsigned int _y);
    virtual void set_unit_x(unsigned int _x);

    virtual void set_unit_y(unsigned int _y);

    virtual unsigned int get_unit_x()const;
    virtual unsigned int get_unit_y()const;

    virtual void set_height(unsigned int _height);
    virtual void set_width(unsigned int _width);
    virtual unsigned int get_height() const;
    virtual unsigned int get_width() const;

    virtual sf::Color get_rel_color() const;
    virtual void set_rel_color(sf::Color _color);
    virtual sf::Color get_pressed_color() const;
    virtual void set_pressed_color(sf::Color _color);

    virtual void set_state(bool _state);
    virtual bool get_state() const;

    virtual void set_name(std::string _name);
};


#endif // BUTTON_H_INCLUDED
