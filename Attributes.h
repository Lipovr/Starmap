#ifndef ATTRIBUTES_H_INCLUDED
#define ATTRIBUTES_H_INCLUDED
#include<string>
#include"Attribute_types.h"
namespace ATTRIBUTES{
    namespace ATTRIBUTES_TYPE{
        enum TYPE{
            ///ALL
            NAME=0,
            DESCRIPTION,
            END_TEXT,
            ///STAR
            STARCLASS,
            ECONOMY,
            //POP,

            END_LIST,
            ///WSROUTE
            //CONNECTED_NAME,

            UNDEFINED
        };
    }
    namespace ATTRIBUTES_STAR{
        namespace ECONOMY {
            enum ECONOMY_T{
                EXTRACTION=0,
                REFINERY,
                INDUSTRIAL,
                TERRAFORMING,
                TOURISM,
                HIGHTECH,
                AGRICULTURE,
                END
            };
        }
        namespace STARCLASS{
            enum STARCLASS_T{
                O=0,
                B,
                A,
                F,
                G,
                K,
                M,

                END
            };
        }
    }
}

namespace LISTS {
    const std::vector<std::string> starclass={
        "O",
        "B",
        "A",
        "F",
        "G",
        "K",
        "M"
    }

    const std::vector<
}



//class Attribute{
//protected:
//    const ATTRIBUTES::ATTRIBUTES_TYPE::TYPE type;
//    unsigned short int id;
//public:
//    Attribute()=0;
//    Attribute(unsigned short int _id);
//    virtual ~Attribute();
//    ATTRIBUTES::ATTRIBUTES_TYPE::TYPE get_type() const;
//    virtual bool is_list() const;
//
//    bool operator < (const Attribute& a) const;
//    bool operator > (const Attribute& a) const;
//    bool operator ==(const Attribute& a) const;
//    bool operator !=(const Attribute& a) const;
//    bool operator <=(const Attribute& a) const;
//    bool operator >=(const Attribute& a) const;
//};
//
//class Name: public Attribute{
//protected:
//    std::string name;
//public:
//    Name()=0;
//    Name(unsigned long long _id);
//    Name(unsigned long long _id, std::string _name);
//    std::string get_name() const;
//    void set_name(std::string _name);
//    virtual bool is_list() const override;
//};
//
//class Description: public Attribute{
//protected:
//    std::string description;
//public:
//    Description()=0;
//    Description(unsigned long long _id);
//    Description(unsigned long long _id, std::string _description);
//    std::string get_description() const;
//
//};

#endif // ATTRIBUTES_H_INCLUDED
