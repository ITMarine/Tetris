#include "arr_fill.h"

std::vector<std::string>& arr_fill(std::vector<std::string>arr,int figure_type)

{
    switch(figure_type){
    case 0: arr  = {"0","0","0","0",
                    "0","1","1","0",
                    "0","1","1","0",
                    "0","0","0","0"};
            return arr;
    case 1: arr  = {"0","0","0","0",
                    "1","1","1","1",
                    "0","0","0","0",
                    "0","0","0","0"};
            return arr;}
}
