#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 
void main()
{
    int check_1, check_2;

    // Declaring Pointers for a File
    FILE *base;
    FILE *index;

    char* dirname_1 = "templates";
    char* dirname_2 = "static";

    check_1 = mkdir(dirname_1);
    check_2 = mkdir(dirname_2);

    
 
    // check if directory is created or not
    if (!check_1 && !check_2)    
    {
        // Creating the Data
        const char base_data[] = "<html>\n</head>\n</head>\n<body>\n<h3> Hello World This is a base File</h3>\n</body> \n</html>";

        const char index_data[] = "{ extends 'base.html' }";

        // Create a file
        base = fopen("templates/base.html", "w");
        index = fopen("templates/index.html", "w");
        
        // Write inside the File;
        fprintf(base, base_data);
        fprintf(index, index_data);
    
        // Close the file
        fclose(base);
        fclose(index);

        printf("Django Project Initialized. \n");
    
    }
    else {    
        printf("Some Error Occured: Unable to Initialize Django Project.\n");
        exit(1);
    }

    system("dir");
}