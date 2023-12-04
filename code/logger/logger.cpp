#include "logger.h"


Logger::Logger()
{
    char input;
    std::string file_path;

    std::cout << "Куда выводит логи?\n1.В терминал\n2.В файл" << std::endl;
    std::cin >> input;

    switch (input - '0')
    {
    case 1:
    {
        outwrite = new TerminalOut;
        if ( outwrite == nullptr )
            std::cout << "Не была выделена память под объект" << std::endl;
        break;
    }
    case 2:
    {
        std::cout << "Введите название файла для вывода в него информации" << std::endl;
        std::cin >> file_path;
        outwrite = new FileOut(file_path);
        if ( outwrite == nullptr )
            std::cout << "Не была выделена память под объект" << std::endl;
        break;
    }
    default:
        std::cout << "Не верный ввод" << std::endl;
        outwrite = nullptr;
        break;
    }
}

Logger::~Logger()
{
    for ( auto it : recentLogs )
        delete it;

    recentLogs.clear(); 

    delete outwrite;
}

void Logger::write_message ( BaseMesg* message )
{
    recentLogs.push_back ( message );
    //outwrite->out( *message );
}

void Logger::print_logs()
{
    for ( auto it : recentLogs )
        outwrite->out ( *it );
}