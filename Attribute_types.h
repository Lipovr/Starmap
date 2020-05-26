#ifndef ATTRIBUTE_TYPES_H_INCLUDED
#define ATTRIBUTE_TYPES_H_INCLUDED
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
    };

    const std::vector<std::string> economy={
        "Extraction",
        "Refinery",
        "Industrial",
        "Terraforming",
        "Tourism",
        "Hightech",
        "Agriculture"
    };
}


#endif // ATTRIBUTE_TYPES_H_INCLUDED
