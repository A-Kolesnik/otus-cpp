/**
 * @file Содержит описание классв для построения конвейера обработки
 * @author Kolesnik Andrey
 */
#pragma once

#include <map>
#include "readers.h"
#include "validator.h"

namespace filter::pipeline{
    /**
     * @brief Абстрактный класс. Описывает интерфейс конвейера обработки
     */
    template<typename T>
    class IPipeline{
        private:
            /**
             * @brief Частная реализация работы конвейера
             *  Nothing.
             */
            virtual void do_run() noexcept = 0;

        public:
            /**
             * @brief Конструктор по-умолчанию
             */
            IPipeline() = default;

            /**
             * @brief Деструктор по-умолчанию
             */
            ~IPipeline() = default;

            /**
             * @brief Конструктор копирования по-умолчанию
             */
            IPipeline(IPipeline const&) = default;

            /**
             * @brief Конструктор перемещения по-умолчанию
             */
            IPipeline(IPipeline&&) = default;

            /**
             * @brief Оператор присваивания копированием
             */
            IPipeline& operator=(IPipeline const&) = default;

            /**
             * @brief Оператор присваивания перемещением
             */
            IPipeline& operator=(IPipeline&&) = default;

            /**
             * @brief Выполняет запуск конвейера обработки
             *  Nothing.
             */
            void run() noexcept{
                do_run();
            }

            /**
             * @brief Возвращает ссылку на данные, которые подготовлено в конвейере
             * @return Данные, которые подготовлены в результате работы конвейера
             */
            virtual T const& get_data() noexcept = 0;
    };


    /**
     * @brief Описывает конвейер сортировки ip-адресов
     */
    class IPSortPipeline : 
        public IPipeline<std::multimap<unsigned long long, address::IPv4>>, 
        public readers::StandardInputReader,
        public validator::IPValidator
    {
        private:
            /**
             * @brief Выполняет шаги конвейера для обработки IP-адресов
             *  Nothing.
             */
            virtual void do_run() noexcept override;

            std::multimap<unsigned long long, address::IPv4> data;///< Контейнер с адресами
            
        public:
            
            /**
             * @brief Конструктор по-умолчанию
             */
            IPSortPipeline() = default;

            /**
             * @brief Деструктор по-умолчанию
             */
            ~IPSortPipeline() = default;

            /** 
             * @brief Конструктор копирования по-умолчанию
             */
            IPSortPipeline(IPSortPipeline const&) = default;

            /**
             * @brief Конструктор перемещения по-умолчанию
             */
            IPSortPipeline(IPSortPipeline&&) = default;

            /**
             * @brief Оператор присваивания копированием по-умолчанию
             */
            IPSortPipeline& operator=(IPSortPipeline const&) = default;
            
            /**
             * @brief Оператор присваивания перемещением по-умолчанию
             */
            IPSortPipeline& operator=(IPSortPipeline&&) = default;

            /**
             * @brief Возвращает ссылку на контейнер с отсортированными адресами
             * @return Cсылку на контейнер с отсортированными адресами
             */
            virtual std::multimap<unsigned long long, address::IPv4>&
            get_data() noexcept override;
    };
}
