#include "spaghetti/os/Printer.hxx"

namespace spaghetti {

    namespace os {


        spaghetti::Shared<spaghetti::ILogger> Printer::logger = 0; 

        void Printer::log(const char *message, LogLevel level) {
            if ( logger ) {
                logger->log( message, level );
            }
        }
        void Printer::log(const wchar_t *message, LogLevel level) {
            if ( logger ) {
                logger->log( message, level );
            }
        }
        void Printer::log(const char *message, const char hint, LogLevel level) {
            if ( logger ) {
                logger->log( message, hint, level );
            }
        }
        void Printer::log(const wchar_t *message, const wchar_t hint, LogLevel level) {
            if ( logger ) {
                logger->log( message, hint, level );
            }
        }

    }    // end namespace os

}    // end namespace spaghetti
