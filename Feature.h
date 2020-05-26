#ifndef FEATURE_H_INCLUDED
#define FEATURE_H_INCLUDED
#include"SFML/Graphics.hpp"
#include"Attribute_types.h"
#include "FeatureTypes.h"
#include"Defaults.h"
#include<string>
#include<vector>
//#include<memory>
class Feature {
protected:
    float posx;
    float posy;
    //const FT::TYPE type;
    bool is_selected;//?
    unsigned long long id;
    std::string name;
    std::string description;
//    ATTRIBUTES::STARCLASS::STARCLASS_T starclass;
//    ATTRIBUTES::ECONOMY::ECONOMY_T economy;
    //static unsigned long long last_id=0;
    //std::vector<Attribute> attributes;
    virtual void update_pos(){};
public:
    Feature()=delete;
    Feature(unsigned long long _id, float _x=0.0f, float _y=0.0f, const std::string& _name="\n", const std::string& _description="\n");
    virtual ~Feature();
    virtual const sf::Drawable& get_drawable()=0 const;

    virtual float get_posx() const;
    virtual float get_posy() const;
    virtual FT::TYPE get_type() const;
    virtual void set_name(std::string _name);
    virtual std::string get_name() const;
    virtual void set_description(std::string _description);
    virtual std::string get_description() const;

    virtual void set_posx(float _x);
    virtual void set_posy(float _y);
    virtual void set_pos(float _x, float _y);
    virtual bool check(float _x, float _y)=0 const;
    virtual int get_rank() const;

    //static Feature* selected=NULL;
    //static unsigned long long generate_id();

//    void select();
//    void unselect();
    unsigned long long int get_id() const;
    bool operator < (const Feature& f) const;
    bool operator > (const Feature& f) const;
    bool operator ==(const Feature& f) const;
    bool operator !=(const Feature& f) const;
    bool operator <=(const Feature& f) const;
    bool operator >=(const Feature& f) const;
};


#endif // FEATURE_H_INCLUDED
