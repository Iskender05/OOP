#ifndef FILE_OUT_H
#define FILE_OUT_H

#include "output.h"
#include <fstream>


class FileOut : public Output
{
    std::ofstream file;

public:
    FileOut(std::string file_path);
    virtual ~FileOut();

    void out(BaseMesg& message) override;
};



#endif
