#include <iostream>

#include "cpp_everything_dll.h"

int main(int argc, char** argv)
{
    using std::cout;
    using std::endl;
    using std::string;

    if (argc != 2)
    {
        cout << "Please input the search string!" << endl;
        return -1;
    }

    char* search_string = argv[1];

    char* full_path[300];

    get_full_file_path(search_string, full_path);


    return 0;
}