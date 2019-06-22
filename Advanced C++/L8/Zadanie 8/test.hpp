#ifndef TEST_HPP
#define TEST_HPP

#include <string>
#include <vector>

using line_t = std::vector<std::pair<int, std::string>>;

line_t load_file(std::string file_name);
void test_manipulators(std::string file_name);
void test_io(std::string file_in, std::string file_out);

#endif