#ifndef TEXTBOX_H_INCLUDED
#define TEXTBOX_H_INCLUDED
#include"Button.h"
class Textbox: public Button{
protected:
//  sf::Font font;
//    unsigned int character

//    void update_name();
public:
    Textbox()=delete;
    Textbox(unsigned long long _id, unsigned int _unitsx, unsigned int _unitsy, unsigned int _height, int width, const std::string& _name="\n", const std::string& _description="\n");

    void append(char _char);
    void remove();
    FT::TYPE get_type() const override;
    int get_rank() const override;
};


#endif // TEXTBOX_H_INCLUDED
