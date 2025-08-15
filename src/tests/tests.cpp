#include "tests/fixtures.h"
#include "validator.h"
#include <gtest/gtest.h>

TEST_F(IPv4AddressTests, AddressIsValid){
    EXPECT_EQ(address_valid.has_value(), true);
}

TEST_F(IPv4AddressTests, AddressIsInvalid){
    EXPECT_EQ(address_invalid.has_value(), false);
}

TEST_F(IPv4AddressTests, AddressOctetsValue){
    EXPECT_EQ(address_valid->get_octet(1), 10);
    EXPECT_EQ(address_valid->get_octet(2), 8);
    EXPECT_EQ(address_valid->get_octet(3), 251);
    EXPECT_EQ(address_valid->get_octet(4), 46);
}

TEST_F(IPv4AddressTests, AddressStrReprIsValue){
    EXPECT_EQ(address_valid->to_str(), "10.8.251.46");
}

TEST_F(IPv4AddressTests, LexCompareIsValid){
    auto addr_cmp = filter::address::IPv4::make("10.8.252.46");
    EXPECT_EQ(address_valid.value() < addr_cmp.value(), true);
}

TEST_F(IPv4AddressTests, AddrDecReprIsValid){
    EXPECT_EQ(address_valid->to_dec_repr(), 168360750);
}

TEST(ValidatorTests, TestValidFeaturesTrue){
    filter::validator::IPValidator validator;

    EXPECT_EQ(validator.is_valid("10.10.10.1\ttext1\ttext2"), true);
}

TEST(ValidatorTests, TestValidFeaturesFalse){
    filter::validator::IPValidator validator;

    EXPECT_EQ(validator.is_valid("10.10.10.1    text1"), false);
}