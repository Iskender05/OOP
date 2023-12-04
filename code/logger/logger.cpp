#include "logger.h"

FileOut::FileOut( std::string file_path )
{
    file.open ( file_path );
}
FileOut::~FileOut()
{
    file.close ();
}

void FileOut::out ( BaseMesg& message )
{
    file << message;
}

void TerminalOut::out ( BaseMesg& message )
{
    std::cout << message;
}

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
        break;
    }
}

Logger::~Logger()
{
    if ( outwrite != nullptr )
        delete outwrite;
}

void Logger::write_message ( BaseMesg* message )
{
    outwrite->out( *message );
    delete message;
}