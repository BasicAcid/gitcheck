#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// TODO
// Default behavior should be:
// ./gitchek   --> descent from current dir.
// ./gitchek /some/path  --> descent from path.

int
process_dir(const char *path)
{
    DIR *dir = opendir(path);

    char command[128];

    if(dir == NULL)
    {
        perror("Error opening directory");
        return 1;
    }

    struct dirent *entry;

    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            if(entry->d_type == DT_DIR)
            {
                char newPath[PATH_MAX];

                snprintf(newPath, sizeof(newPath), "%s/%s", path, entry->d_name);

                if(strcmp(entry->d_name, ".git") == 0)
                {
                    printf("===== %s =====\n", path);
                    snprintf(command, sizeof(command), "git -C \"%s\" status -s", path);

                    if (system(command) != 0)
                    {
                        perror("Error executing git status");
                        return 1;
                    }
                }
                else
                {
                    process_dir(newPath);
                }
            }
        }
    }
    closedir(dir);
    return 0;
}

int
main()
{
    const char *base_path = "/home/david/Workspace/programming";
    process_dir(base_path);
    return 0;
}
