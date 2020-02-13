#include"logger.h"
#include<cstdlib>
#include<ctime>

void initLogDoc(const std::string& info_log_filename,const std::string& warn_log_filename,const std::string& error_log_filename)
{
    logger::m_info_log_file.open(info_log_filename.c_str());
    logger::m_warn_log_file.open(warn_log_filename.c_str());
    logger::m_error_log_file.open(error_log_filename.c_str());
}

logger::~logger()
{
    getStream(m_log_rank)<<std::endl<<std::flush;
    if(m_log_rank == FATAL)
    {
        m_info_log_file.close();
        m_warn_log_file.close();
        m_error_log_file.close();
    }
}

std::ostream logger::getStream(log_rank_t log_rank)
{
    if(log_rank == INFO && m_info_log_file.is_open())
        return m_info_log_file;
    else if(log_rank == ERROR && m_error_log_file.is_open())
        return m_error_log_file;
    else if(log_rank == WARNING && m_warn_log_file.is_open())
    {
        return m_warn_log_file;
    }
    else
    {
        return std::cerr;
    }
    
    
}


std::ostream logger::start(log_rank_t log_rank,const int line,const std::string & function))
{
    time_t tm;
    time(&tm);
    char time_string[128];
    ctime_r(&tm,time_string);
    return getStream(log_rank)<<time_string<<" function ("<<function<<" )"<<" line "<<line<< std::flush;
}