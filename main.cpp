#include <iostream>
#include <vector>

#include "address.h"
#include "pipeline.h"
#include "readers.h"
#include "reporter.h"

int main(int, char **) {
	
	filter::pipeline::IPSortPipeline pipeline;
	
	// Запуск формирвания и сортировки списка адресов
	pipeline.run();

	// Публикация результатов
	filter::report::Reporter reporter;

	reporter.show_sorted_address_list(pipeline);
	reporter.show_address_list_with_1_first_octet(pipeline);
	reporter.show_address_list_with_46_fist_octet_70_single_octet(pipeline);
	reporter.show_address_list_with_46_anyone_octet(pipeline);

	return 0;
}
