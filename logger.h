#ifndef _LOGGER_H_
#define _LOGGER_H_

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstdlib>
#include<stdint.h>

typedef enum log_rank{
    INFO,
    WARNING,
    ERROR,
    FATAL
}log_rank_t;

void initLogDoc(const std::string& info_log_filename,const std::string& iwarn_log_filename,const std::string& info_log_filename);

class logger{
friend void initLogDoc(const std::string& info_log_filename,const std::string& iwarn_log_filename,const std::string& info_log_filename);

public:
    logger(log_rank_t log_rank):m_log_rank(log_rank) {};
    ~logger();

    //参数log_rank表示日志的等级，参数line表示日志发生的行数，function表示日志发生的函数
    static std::ostream start(log_rank_t log_rank,const int line,const std::string & function);

private:
    static std::ostream getStream(log_rank_t log_rank);
    static std::ofstream m_info_log_file;
    static std::ofstream m_warn_log_file;
    static std::ofstream m_error_log_file;
    log_rank_t m_log_rank;
};


#endif
