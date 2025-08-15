/**
 * @brief Содержит описание классов для выполнения валидации данных
 * @author Kolesnik Andrey
 */
#pragma once

#include <string>
#include "address.h"

namespace filter::validator{
    /**
     * @brief Абстрактный класс. Описывает интерфейс валидатора
     */
    template <typename _T>
    class IValidator{
        public:

            /**
             * @brief Конструктор по-умолчанию
             */
            IValidator() = default;
            
            /**
             * @brief Деструктор по-умолчанию
             */
            ~IValidator() = default;

            /**
             * @brief Конструктор копирования по-умолчанию
             */
            IValidator(IValidator const&) = default;

            /**
             * @brief Конструктор перемещения по-умолчанию
             */
            IValidator(IValidator&&) = default;

            /**
             * @brief Оператор присваивания копированием по-умолчанию
             */
            IValidator& operator=(IValidator const&) = default;

            /**
             * @brief Оператор присваивания перемещением по-умолчанию
             */
            IValidator& operator=(IValidator&&) = default;

            /**
             * @brief Частная реализация процедуры валидации
             * @param data Данные для валидации
             * @retval true Данные валидны
             * @retval false Данные не валидны
             */
            virtual bool do_valid(_T const& data) noexcept = 0;
        
            /**
             * @brief Выполняет валидацию входных данных
             * @param data Данные для валидации
             * @retval true Данные валидны
             * @retval false Данные не валидны
             */
            bool is_valid(_T const& data) noexcept{
                return do_valid(data);
            }
    };


    /**
     * @brief Описывает валидатор IP-адреса
     * @brief Поддерживаемые группы адресов: IPv4
     */
    class IPValidator : public IValidator<std::string> {
        private:
            /**
             * @brief Выполняет валидацию IP-адреса
             * @retval true Адрес валидный
             * @retval false Адрес не валидный
             */
            virtual bool do_valid(std::string const& addr) noexcept override;
    };
}

