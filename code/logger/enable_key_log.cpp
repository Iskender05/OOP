#include "enable_key_log.h"

EnabelKeyLog::EnabelKeyLog(InputReader* reader)
    : reader ( reader )
{
    input = reader->input;
    action = reader->action;
}

std::string EnabelKeyLog::message()
{
    return "Key = '" + std::string ( &input, 1 ) + "' it is action = '" + StrAction[static_cast<int> (action)] + "'\n";
}