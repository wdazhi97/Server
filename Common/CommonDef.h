#define PRINT_ERROR(function) {std::string error_msg = std::string("erron:") + std::string(#function) + std::string(" ") + std::string(strerror(errno));\
                     perror(error_msg.c_str());}