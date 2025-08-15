/**
 * @brief Описывает форматы адресов
 * @author Kolesnik Andrey
 */
#pragma once

#include <charconv>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <optional>


namespace filter::address{
    /**
     * @brief Описывает адрес IPv4 в формате a.b.c.d
     */
    struct IPv4{
        public:
            /**
             * @brief Конструктор по-умолчанию. Удален
             */
            IPv4() = delete;

            /**
             * @brief Деструктор по-умолчанию
             */
            ~IPv4() = default;

            /**
             * @brief Конструктор копирования по-умолчанию
             */
            IPv4(IPv4 const&) = default;

            /**
             * @brief Конструктор перемещения по-умолчанию
             */
            IPv4(IPv4&&) = default;

            /**
             * @brief Оператор присваивания копированием по-умолчанию
             */
            IPv4& operator=(IPv4 const&) = default;

            /**
             * @brief Оператор присваивания перемещением по-умолчанию
             */
            IPv4& operator=(IPv4&&) = default;

            /**
             * @brief Оператор <
             * @param other Правый операнд
             * @retval true Объект, к которому применяется оператор меньше правого операнда
             * @retval false Объект, к которому применяется опрератор больше правого операнда
             */
            bool operator < (IPv4 const& other) noexcept{
                return this->dec_repr < other.dec_repr;
            }

            /**
             * @brief Выполняет создание объекта адреса IPv4
             * @return Адрес IPv4
             */
            static std::optional<IPv4> make(std::string const& addr_str_repr) noexcept {
                if(IPv4 addr{IPv4(addr_str_repr)}; addr.is_valid()){
                    return addr;
                }

                return std::nullopt;
            }

            /**
             * @brief Возвращает состояние объекта
             * @retval true Объект создан успешно и валидный
             * @retval false Объект не создан, не прошел валидацию
             */
            bool is_valid() noexcept {
                return is_created;
            }
            
            /**
             * @brief Выполняет преобразование адреса к строковому представлению
             * @return Строковое представление адреса
             */
            std::string to_str() const noexcept {

                std::stringstream addr_stream;

                addr_stream << static_cast<int>(octet1)
                            << "."
                            << static_cast<int>(octet2)
                            << "."
                            << static_cast<int>(octet3)
                            << "."
                            << static_cast<int>(octet4);
                
                return addr_stream.str();
            }
            
            /**
             * @brief Возвращает десятичное представление адреса
             * @return Десятичное представление адреса
             */
            unsigned long long to_dec_repr() noexcept {
                return dec_repr;
            }
            
            /**
             * @brief Возвращает значение октета
             * @param octet_num Номер октета
             * @return Значение октета
             */
            unsigned char get_octet(int octet_num) noexcept {
                switch(octet_num){
                    case 1:
                        return octet1;
                    case 2:
                        return octet2;
                    case 3:
                        return octet3;
                    case 4:
                        return octet4;
                    default:
                        return 0;
                }

            }

            friend std::ostream& operator<<(std::ostream& stream, filter::address::IPv4 const& addr) noexcept {
                stream << addr.to_str();
                return stream;
            }
        private:
            /**
             * @brief Конструктор
             * @param addr Адрес в строковом представлении
             */
            IPv4(std::string const& addr) noexcept :
                octet1{0}
                ,octet2{0}
                ,octet3{0}
                ,octet4{0}
                ,is_created{false}
            {
                std::vector<int> octets;
                std::string token;
                std::stringstream addr_stream(addr);

                while(std::getline(addr_stream, token, '.')){
                    int token_dec{0};
                    auto [ptr, err] = std::from_chars(token.c_str(), 
                                                        token.c_str() + token.size(), 
                                                        token_dec);
                    
                    if(err == std::errc{} && 
                       ptr == (token.c_str() + token.size()) && 
                       (token_dec >= 0 && token_dec <= 255)){
                        octets.emplace_back(token_dec);
                    }else{
                        return;
                    }
                }

                if(octets.size() == 4){
                    octet1 = static_cast<char>(octets[0]);
                    octet2 = static_cast<char>(octets[1]);
                    octet3 = static_cast<char>(octets[2]);
                    octet4 = static_cast<char>(octets[3]);
                    dec_repr = (octet1*std::pow(256,3)) 
                               + (octet2*std::pow(256,2))
                               + (octet3*std::pow(256,1))
                               + octet4;

                    is_created = true;
                }
            }

            unsigned char octet1;///< 1 Октет адреса
            unsigned char octet2;///< 2 Октет адреса
            unsigned char octet3;///< 3 Октет адреса
            unsigned char octet4;///< 4 Октет адреса
            unsigned long long dec_repr;///< Десятичное представление адреса
            bool is_created;///< Флаг состояния объекта
    };
}
