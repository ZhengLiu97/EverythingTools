#include <iostream>

#include "Everything.h"

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

    // unnecessary
    Everything_SetRequestFlags(EVERYTHING_REQUEST_FILE_NAME | EVERYTHING_REQUEST_PATH);
    
    // EVERYTHING_REQUEST_FULL_PATH_AND_FILE_NAME not works, no idea why
    // Everything_SetRequestFlags(EVERYTHING_REQUEST_FULL_PATH_AND_FILE_NAME); 

    char* search_string = argv[1];

    cout << search_string << endl;

    Everything_SetSearch(search_string);

    Everything_Query(TRUE);

    if (!Everything_GetNumFileResults())
    {
        cout << "No file found!" << endl;
        return -1;
    }

    cout << Everything_GetNumFileResults() << " files found!" << endl;

    char full_path[300];
    for (DWORD i = 0; i < Everything_GetNumFileResults(); i++)
    {
        Everything_GetResultFullPathName(i, full_path, 300);
        cout << full_path << endl;
    }

    return 0;
}