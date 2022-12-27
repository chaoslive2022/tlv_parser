#include <stdio.h>
#include <string.h>

#include "tlv_parser_configuration.h"

typedef struct
{
    unsigned char m_version;
    unsigned char m_mode;

} tOptionsSet;

void parse_running_options(int argc, char **argv, tOptionsSet *options_set)
{
    int i=0;
    
    while(++i < argc)
    {
        if(argv[i][0] = '-')
        {
            if(argv[i][1] == 'v')
            {
                options_set->m_version = 1;
            }
            else if(argv[i][1] == 't')
            {
                options_set->m_mode = 1;
            }
        }
    }
}

void display_options(tOptionsSet *options_set)
{
    if(options_set->m_version)
    {
        printf("*** Version %i.%i.%i.%i ***\n",tlv_parser_VERSION_MAJOR,tlv_parser_VERSION_MINOR,tlv_parser_VERSION_PATCH,tlv_parser_VERSION_TWEAK);
    }
    
    if(options_set->m_mode)
    {
#ifdef USE_GTEST
        printf("*** GTEST ON ***\n");
#else     
        printf("*** GTEST OFF ***\n");
#endif
    }
}

int main(int argc, char **argv)
{
    tOptionsSet options;

    printf("*** running tlv_parser... ***\n");
    
    memset(&options,0x00,sizeof(tOptionsSet));
    parse_running_options(argc,argv,&options);    
    display_options(&options);

    return 0;
}