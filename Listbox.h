#ifndef LISTBOX_H_INCLUDED
#define LISTBOX_H_INCLUDED
#include"Button.h"
class Listbox: public Button{
protected:
    const std::vector<std::string>& list;
    unsigned int sel_list_entry;
    unsigned int total_entries;
public:
    Listbox()=delete;
    Listbox(unsigned long long _id, unsigned int _unitsx, unsigned int _unitsy, unsigned int _height, int _width, const std::vector<std::string>& _list, const std::string& _name="\n", const std::string& _description="\n");

    const std::string& get_sel() const;
    unsigned int get_sel_entry() const;
    void set_sel_entry(unsigned int _entry);
    void advance();
    void go_back();
    bool check_side(float _x, float _y) const;
    void change(bool _b);
};


#endif // LISTBOX_H_INCLUDED
