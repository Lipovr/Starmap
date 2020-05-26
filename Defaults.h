#ifndef DEFAULTS_H_INCLUDED
#define DEFAULTS_H_INCLUDED
#include"SFML/Graphics/Color.hpp"
#include<vector>
namespace DEF_DESCRIPTIONS{
    //const std::string
}
namespace CONSTANTS{
    const float menu_unit=20.0f;
    const float menu_element_outline = 10.0f;
    const sf::Color sel_outl();
    const sf::Color menu_outl(161, 161, 161, 1);
    const sf::Color b_rel(64, 64, 64, 1);
    const sf::Color b_pr(161, 161, 161, 1);
    const unsigned int max_char_size=6;
    const unsigned int char_height=6;
}



namespace TOOLS{
    enum TOOLS_T{
        NONE=0,
        ADD_STAR=1,
        ADD_WSR=2,
        DELETE=3

    };
}

namespace

#endif // DEFAULTS_H_INCLUDED
