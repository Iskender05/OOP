#include "not_enable_key_log.h"

NotEnabelKeyLog::NotEnabelKeyLog(InputReader* reader)
    : reader(reader)
{
    input = reader->input;
}

std::string NotEnabelKeyLog::message()
{
    return "Клавиша '" + std::string(&input, 1) + "' была введена, но ни одна команда не сработала\n";
}
