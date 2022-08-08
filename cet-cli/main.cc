#include "cetcli_pch.h"
#include "cmd.h"


int main(int argc, char *argv[])
{
    std::vector<std::string> args;

    if (argc < 2)
    {
        args = {ARGS_ERROR_STR};
        ExeCommand(args);
        return 0;
    }

    for (int i = 0; i < argc; i++)
    {
        args.push_back(argv[i]);
    }

    ExeCommand(args);

    return 0;
}
