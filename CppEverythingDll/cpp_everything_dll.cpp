#include <iostream>
#include < vector>

#include "Everything.h"

#include "cpp_everything_dll.h"

//using std::string;

int get_full_file_path(char* search_string, char* full_path[])
{
    using std::cout;
    using std::endl;

    Everything_SetRequestFlags(EVERYTHING_REQUEST_FILE_NAME | EVERYTHING_REQUEST_PATH);

    cout << search_string << endl;

    Everything_SetSearch(search_string);

    Everything_Query(TRUE);

    if (!Everything_GetNumFileResults())
    {
        cout << "No file found!" << endl;
        return -1;
    }

    cout << Everything_GetNumFileResults() << " files found!" << endl;

    for (DWORD i = 0; i < Everything_GetNumFileResults(); i++)
    {
        Everything_GetResultFullPathName(i, *full_path, 300);
        cout << full_path << endl;
    }

    return 0;
}