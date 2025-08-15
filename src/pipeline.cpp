#include "pipeline.h"

namespace filter::pipeline {

    void IPSortPipeline::do_run() noexcept {
        while(true){
            if(auto line = read(); line){
                if(is_valid(line.value())){
                    
                    auto addr{address::IPv4::make(
                        line.value().substr(0, line.value().find('\t')))
                    };

                    if(addr){
                        data.insert({addr.value().to_dec_repr(), addr.value()});
                    }
                }
            }else{
                break;
            }
        }
    }

    std::multimap<unsigned long long, address::IPv4>& IPSortPipeline::get_data() noexcept {
        return data;
    }
}