#include "enable_key_log.h"

EnabelKeyLog::EnabelKeyLog(InputReader *reader)
    : reader ( reader )
{}

std::string EnabelKeyLog::message()
{
    return "Key = '" + std::string ( &reader->input, 1 ) + "' it is action = '" + StrAction[(int)reader->action] + "'\n";
}