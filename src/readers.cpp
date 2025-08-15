#include "readers.h"

namespace filter::readers {
    
    std::optional<std::string> Reader::read() noexcept {
        return do_read();
    }

    std::optional<std::string> StandardInputReader::do_read() noexcept {
        static std::string line;
        std::getline(std::cin, line);

        if(line.empty()){
            return std::nullopt;
        }

        return line;
    }
}