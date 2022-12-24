#include <stdio.h>

#include "tlv_parser_configuration.h"


int main(int argc, char** argv)
{
    printf("*** TLV Parser Tester ***\n");
    printf("*** Version %i.%i.%i.%i ***\n",tlv_parser_VERSION_MAJOR, tlv_parser_VERSION_MINOR, tlv_parser_VERSION_PATCH, tlv_parser_VERSION_TWEAK);

#ifndef USE_GTEST
    printf("*** GTEST OFF ***\n");
#else
    printf("*** GTEST ON ***\n");
#endif    

#ifndef USE_HAL
    printf("*** HAL OFF ***\n");
#else
    printf("*** HAL ON ***\n");
#endif    

    return 0;
}