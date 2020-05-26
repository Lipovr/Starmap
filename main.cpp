#include <SFML/Graphics.hpp>
#include<vector>
#include<memory>
#include<algorithm>

#define RW 1366.0f
#define RH 768.0f
#define UIW 0.2f

#include"Defaults.h"
#include"Attribute_types.h"
#include"FeatureTypes.h"

#include"Feature.h"
    #include"Star.h"
    #include"WSRoute.h"
    #include"Button.h"
        #include"Textbox.h"
        #include"Listbox.h"


//std::vector<std::unique_ptr<Feature*>> get_UI_def(){
//    std::vector<std::unique_ptr<Feature*>> UI_def={
//        std::unique_ptr<Feature*>(new Button(1, 0, 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Add Star")),
//        Button(2, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Add WSRoute"),
//        Button(3, 2*static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Delete"),
//        Button(1, 0, 0, 10, static_cast<unsigned int>(RW*UIW/CONSTANTS::menu_unit), "None")
//    }
//
typedef std::unique_ptr<Feature*> ptr_F;
typedef std::unique_ptr<Button*> ptr_B;
void generate_UI_def(std::vector<ptr_B>& v){
    v.clear();
    v.push_back(std::unique_ptr<Button*>(new Button(1, 0, 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Add Star")));
    v.push_back(std::unique_ptr<Button*>(new Button(2, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Add WSRoute")));
    v.push_back(std::unique_ptr<Button*>(new Button(3, 2*static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Delete")));
    v.push_back(std::unique_ptr<Button*>(new Button(4, 0, 10, 10, static_cast<unsigned int>(RW*UIW/CONSTANTS::menu_unit), "None")));

}

class comp{

public:
    bool operator()(const ptr_F& l, const ptr_F& r){
        return (*l)<(*r);
    }
};

int main()
{

    sf::RenderWindow window(sf::VideoMode(RW, RH), "Starmap");
    sf::FloatRect UIrect(0.0f, 0.0f, UIW, 1.0f);
    sf::FloatRect Fieldrect(UIW, 0.0f, 1.0f, 1.0f);
    sf::View UIview;
    sf::View Fieldview;

    UIview.setViewport(UIrect);
    Fieldview.setViewport(Fieldrect);


    UIview.setCenter(UIview.getSize()*0.5);
    UIview.setSize(UIW*RW, RH);

    Fieldview.setCenter(sf::Vector2f());
    Fieldview.setSize((1-UIW)*RW,RH);


    std::vector<std::unique_ptr<Feature*> > UIdr;
    std::vector<std::unique_ptr<Button*> > Fdr;



    generate_UI_def(UIdr);



//    Feature* selected=nullptr;
    Star* sel_star=nullptr;


    WSRoute* sel_wsr=nullptr;
    bool text_selected=false;
    int text_pos=-1;

    bool UI_height_ch=false;

    TOOLS::TOOLS_T sel_tool=0;

    unsigned long long last_gen_id=0;



    sf::Font font;
    if(!font.loadFromFile())///!!!

    sf::Event event;
    while(window.isOpen()){
        ///события

        while(window.pollEvent(event)){
        switch (event.type){
        case sf::Event.MouseButtonPressed:
            //ввод в текстовое поле отключать по ЛЮБОМУ нажатию
                if(text_selected){

                    if(text_pos==-1||UIdr[text_pos]->get_type()!=FT::TEXTBOX||text_selected>=UIdr.size())
                        ///throw
                    else{
                        UIdr[text_pos]->set_state(false);
                        text_selected=false;
                        text_pos=-1;
                    }

                }

        case sf::Event.MouseButtonReleased:

            sf::Vector2i wcoords=sf::Vector2i(event.MouseButtonEvent.x, event.MouseButtonEvent.y);

            if(wcoords.x<=UIW*window.getSize().x){
                sf::Vector2f coords=window.mapPixelToCoords(wcoords, UIview);
                int i=0;
                Button* p=null;
                for(; i<UIdr.size(); i++){

                    if(UIdr[i]->check()){
                        p=UIdr[i].get();
                        break;
                    }
                }
                if(p){

                    ///выбор инструмента
                    if (i<3){
                        p->set_state(!p->get_state());
                        if(sel_tool){
                            if(sel_tool==static_cast<TOOLS::TOOLS_T>(i+1))
                                sel_tool=TOOLS::NONE;
                            else{
                                UIdr[sel_tool-1]->set_state(false);
                                sel_tool=static_cast<TOOLS::TOOLS_T>(i+1);
                            }
                        }
                        else{
                            sel_tool=static_cast<TOOLS::TOOLS_T>(i+1);
                        }


                    }
                    ///обработка всего остального
                    else{
                        ///чего "остального"?
                        switch (p->get_type()){
                            ///запланировано...непонятно чего
                            case FT::BUTTON:
                                break;
                            ///"перечисляемый атрибут"
                            case FT::LISTBOX:
                                Listbox* l=static_cast<Listbox*>(p);
                                l->change(l->check_side(coords.x, coords.y));
                                if(sel_star){
                                    switch (l->get_repr_attr){
                                    case ATTRIBUTES::ATTRIBUTES_TYPE::STARCLASS:
                                        sel_star->set_starclass(static_cast<ATTRIBUTES::ATTRIBUTES_STAR::STARCLASS::STARCLASS_T>(l->get_sel_entry()));
                                        break;
                                    case ATTRIBUTES::ATTRIBUTES_TYPE::ECONOMY:
                                        sel_star->set_economy(static_cast<ATTRIBUTES::ATTRIBUTES_STAR::ECONOMY::ECONOMY_T>(l->get_sel_entry()));
                                        break;
                                    }

                                }
                                else {
                                    ///throw
                                }
                                break;
                            case FT::TEXTBOX:
                                Textbox* t=static_cast<Textbox*>(p);
                                t->set_state(true);
                                text_selected=true;
                                text_pos=i;
                                break;
                        }
                    }
                }
            }
            else{
                sf::Vector2f coords=window.mapPixelToCoords(wcoords, Fieldview);
                switch (sel_tool){
                case TOOLS::NONE:

                int i=0;
                Feature* f=null;
                for(; i<Fdr.size(); i++){
                    if(Fdr[i]->check()){
                        f=Fdr[i].get();
                        break;
                    }
                }

                if(f){
                    switch (f->get_type()){
                    case FT::STAR:
                        sel_wsr=null;
                        sel_star=static_cast<Star*>(f);
                        generate_UI_def(UIdr);
                        Button* bp=UIdr.rend()->get();
                        bp->set_name(sel_star->get_name());
                        bp->set_repr_attr(ATTRIBUTES::ATTRIBUTES_TYPE::NAME);

                        UIdr.push_back(ptr_B(new Button(5, 0, 20, 10, static_cast<unsigned int>(RW*UIW/CONSTANTS::menu_unit), sel_star->get_description())));
                        UIdr.push_back(ptr_B(new Listbox(6, 0, 30, 10, static_cast<unsigned int>(RW*UIW/CONSTANTS::menu_unit), LISTS::starclass)));
                        UIdr.push_back(ptr_B(new Listbox(7, 0, 40, 10, static_cast<unsigned int>(RW*UIW/CONSTANTS::menu_unit), LISTS::economy)));

                        UI_height_ch=true;
                        break;
                    case FT::WSROUTE:
                        sel_star=null;
                        sel_wsr=static_cast<WSRoute*>(f);
                        generate_UI_def(UIdr);
                        Button* bp=UIdr.rend()->get();
                        bp->set_name(sel_wsr->get_name());
                        bp->set_repr_attr(ATTRIBUTES::ATTRIBUTES_TYPE::NAME);

                        UI_height_ch=true;

                        break;
                    }
                }
                else{
                    sel_star=null;
                    sel_wsr=null;
                    UIdr={
                        std::unique_ptr<Button*>(new Button(1, 0, 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Add Star")),
                        std::unique_ptr<Button*>(new Button(2, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Add WSRoute")),
                        std::unique_ptr<Button*>(new Button(3, 2*static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), 0, 10, static_cast<unsigned int>(RW*UIW/(3*CONSTANTS::menu_unit)), "Delete")),
                        std::unique_ptr<Button*>(new Button(4, 0, 1, 1, static_cast<unsigned int>(RW*UIW/CONSTANTS::menu_unit), "None"))
                    };
                }
                break;
                case TOOLS::ADD_STAR:
                    Fdr.push_back(ptr_F(new Star(++last_gen_id, coords.x, coords.y)));
                    std::sort(Fdr.begin(), Fdr.end());
                    break;
                case TOOLS::ADD_WSR:



                }

            }


            break;

        }






        }










    }
    return 0;
}
