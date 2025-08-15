#include "validator.h"
#include <iostream>

namespace filter::validator{
    bool IPValidator::do_valid(std::string const& data) noexcept {

        std::stringstream line_stream(data);
        int substr_cnt{0};
        
        for(std::string part; std::getline(line_stream, part, '\t');){
            ++substr_cnt;
        }

        if(substr_cnt == 3){
            return true;
        }

        return false;
    }
}