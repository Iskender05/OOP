#include "file_out.h"

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
