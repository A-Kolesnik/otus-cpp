/**
 * @file include/readers.h
 * @author Kolesnik Andrey
 * @brief Описывает классы, используемые для чтения данных из различных источников
 */
#pragma once

#include <iostream>
#include <optional>
#include <string>

namespace filter::readers{
    /**
     * @brief Абстрактный класс, который описывает интерфейс для читателей
     */
    class Reader{
        private:
            /**
             * @brief Метод чтения данных из источника для переопределения - интерфейс
             */
            virtual std::optional<std::string> do_read() noexcept = 0;
        public:
            /**
             * @brief Конструктор по-умолчанию
             */
            Reader() = default;

            /**
             * @brief Деструктор по-умолчанию
             */
            ~Reader() = default;

            /**
             * @brief Конструктор копирования по-умолчанию
             */
            Reader(Reader const&) = default;

            /**
             * @brief Конструктор перемещения по-умолчанию
             */
            Reader(Reader&&) = default;

            /**
             * @brief Оператор присваивания копированием по-умолчанию
             */
            Reader& operator=(Reader const&) = default;

            /**
             * @brief Оператор присваивания перемещением по-умолчанию
             */
            Reader& operator=(Reader&&) = default;

            /**
             * @brief Выполняет чтение данных из источника
             *  Nothing.
             */
            std::optional<std::string> read() noexcept;
    };

    /**
     * 
     */
    class StandardInputReader : public Reader {
        private:
            virtual std::optional<std::string> do_read() noexcept override;
    };
    
}