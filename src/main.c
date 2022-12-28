#include <stdio.h>
#include <string.h>

#include "tlv_parser_configuration.h"

typedef struct {
    unsigned char help;
    unsigned char version;
    unsigned char tlv_string;
    unsigned char tlv_file;
    unsigned char mode;
} options_set_t;

/* To do */
/* Create a separated library */
unsigned char
hex_nibble_to_value (char c) {

    if ((c >= 48) && (c <= 57)) {
        return (c -48);
    } else if ((c >= 65) && (c <= 70)) {
        return (c -55);
    } else if ((c >= 97) && (c <= 102)) {
        return (c -87);
    } else {
        return 0;
    }    
}

unsigned char
ascii_char_to_value (char c) {
    unsigned char high = 0, low = 0;

    high = c >> 4;
    low = c % 16;

    return (high * 16 + low);
}

unsigned char
byte_string_to_value (char c1, char c2) {
    return (hex_nibble_to_value(c1) * 16 | hex_nibble_to_value(c2));
}

void
parse_running_options(int argc, char **argv, options_set_t *options_set) {
    if (2 == argc) {
        if ((argv[1][0] == '-') && (argv[1][1] == '-')) {
            if (argv[1][2] == 'v') {
                options_set->version = 1;
            } else if (argv[1][2] == 't') {
                options_set->mode = 1;
            } else if (argv[1][2] == 'h') {
                options_set->help = 1;
            }
        }
    } else if (3 == argc) {
        if (argv[1][0] == '-') {
            if (argv[1][1] == 's') {
                options_set->tlv_string = 1;            
            } else if (argv[1][1] == 'f') {
                options_set->tlv_file = 1;
            }
        }
    }
}

int
main(int argc, char **argv) {
    int i = 0;
    options_set_t options;

    memset(&options, 0x00, sizeof(options_set_t));
    parse_running_options(argc, argv, &options);    

    if (options.help) {
        printf("Usage\n\n");
        printf("tlv_parser [options]\n\n");
        printf("Specify a tlv source and parse tlv data objects\n\n");
        printf("Options\n");
        printf("--h:\t\t\tdisplays help\n");
        printf("--v:\t\t\tdisplays version\n");
        printf("-s <tlv-string>:\tprovides tlv string to parse\n");
        printf("-f <path-to-tlv-file>:\tdisplays tlv file to parse\n");
        printf("--t:\t\t\tdisplays test mode status\n");
    } else if (options.version) {
        printf("tlv_parser version %i.%i.%i.%i\n", tlv_parser_VERSION_MAJOR, tlv_parser_VERSION_MINOR, tlv_parser_VERSION_PATCH, tlv_parser_VERSION_TWEAK);
    } else if (options.tlv_string) {
        if (!(strlen(argv[2]) % 2)) {
            printf("tlv string (%i): %s\n", strlen(argv[2]), argv[2]);
            for (i = 0; i < strlen(argv[2]); i+=2) {
                printf("%.2X", byte_string_to_value(argv[2][i],argv[2][i+1]));
            }
            printf("\n");
        }
        else {
            printf("odd tlv length\n");
        }
    } else if (options.tlv_file) {
        printf("file not supported yet\n");
    } else if (options.mode) {
#ifdef USE_GTEST
        printf("google unit test is ON\n");
#else     
        printf("google unit test is OFF\n");
#endif
    }

    return 0;
}