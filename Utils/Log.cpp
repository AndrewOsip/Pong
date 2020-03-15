#include "Log.h"

void Log::printError(const std::string& msg, std::ostream& os)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}

int Log::printErrorAndExit(const std::string& msg)
{
    printError(msg);
    exit(-1);
}
