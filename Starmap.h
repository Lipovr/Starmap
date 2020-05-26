#ifndef STARMAP_H_INCLUDED
#define STARMAP_H_INCLUDED
#include<string>
class UI;
class Field;
class Feature;
class Star;
class WSRoute;
//class Region;
//class Label;
class Starmap {
public:
    ~Starmap() {
    //
    };
    static Starmap* get_instance(unsigned long int X, unsigned long int Y, unsigned float scale);//новый
    static void clear_instance();

private:
    Starmap();
    void process_event();
    Feature& get_selected();
    void close();
    void save(std::string name);
    Feature selected;
    UI UI;
    Field Field;
    void draw();
    sf::RenderWindow window;
};


#endif // STARMAP_H_INCLUDED
