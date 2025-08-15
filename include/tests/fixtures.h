#include "address.h"
#include <optional>
#include "gtest/gtest.h"

class IPv4AddressTests : public testing::Test{
    protected:
        IPv4AddressTests() :
            address_valid{filter::address::IPv4::make("10.8.251.46")}
            ,address_invalid{filter::address::IPv4::make("10.8.251.460")}
        {}

        std::optional<filter::address::IPv4> address_valid;
        std::optional<filter::address::IPv4> address_invalid;
};