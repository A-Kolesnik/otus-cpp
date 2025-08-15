#include "reporter.h"

namespace filter::report{
    void Reporter::show_address_list_with_1_first_octet(pipeline::IPSortPipeline& pipeline) noexcept {
        auto& data{pipeline.get_data()};

        for(auto it{data.rbegin()}; it != data.rend(); ++it){
            if(it->second.get_octet(1) == 1){
                std::cout << it->second.to_str() << std::endl;
            }
        }
    }

    void Reporter::show_address_list_with_46_anyone_octet(pipeline::IPSortPipeline& pipeline) noexcept {
        auto& data{pipeline.get_data()};

        for(auto it{data.rbegin()}; it != data.rend(); ++it){
            if(it->second.get_octet(1) == 46 ||
                it->second.get_octet(2) == 46 ||
                it->second.get_octet(3) == 46 ||
                it->second.get_octet(4) == 46){
                
                    std::cout << it->second.to_str() << std::endl;
            
            }
        }
    }

    void Reporter::show_address_list_with_46_fist_octet_70_single_octet(pipeline::IPSortPipeline& pipeline) noexcept {
        auto& data{pipeline.get_data()};

        for(auto it{data.rbegin()}; it != data.rend(); ++it){
            if(it->second.get_octet(1) == 46 && it->second.get_octet(2) == 70){
                std::cout << it->second.to_str() << std::endl;
            }
        }
    }

    void Reporter::show_sorted_address_list(pipeline::IPSortPipeline& pipeline) noexcept {
        auto& data{pipeline.get_data()};

        for(auto it{data.rbegin()}; it != data.rend(); ++it){
            std::cout << it->second.to_str() << std::endl;
        }
    } 

}