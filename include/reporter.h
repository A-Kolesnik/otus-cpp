/**
 * @brief Содержит классы для формирования отчетов
 * @author Kolesnik Andrey
 */
#pragma once
#include "pipeline.h"

namespace filter::report{
    /**
     * @brief Предоставляет интерфейс для отображения результатов работы пайплайна
     */
    class Reporter{
        private:
        public:
            /**
             * @brief Отображает список адресов, отсортированных в обратном порядке
             *  Nothing.
             */
            void show_sorted_address_list(pipeline::IPSortPipeline& pipeline) noexcept;

            /**
             * @brief Отображает список адресов, где первый октет = 1
             *  Nothing.
             */
            void show_address_list_with_1_first_octet(pipeline::IPSortPipeline& pipeline) noexcept;

            /**
             * @brief Отображает список адресов, где первый октет = 46, второй = 70
             *  Nothing.
             */
            void show_address_list_with_46_fist_octet_70_single_octet(pipeline::IPSortPipeline& pipeline) noexcept;

            /**
             * @brief Отображает список адресов, где любой октет = 46
             *  Nothing.
             */
            void show_address_list_with_46_anyone_octet(pipeline::IPSortPipeline& pipeline) noexcept;
    };
}

