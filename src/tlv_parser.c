/**
 * @file tlv_parser.c
 * @author olivier chauvineau
 * @brief implements tlv_parser API
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifdef USE_HAL
    #include "hal/hal.h"
#else
    #include <string.h>
#endif

#include "tlv_parser.h"


int parse_tlv()
{
    return 0;
}

int tlv_parser_create(const unsigned char *data, unsigned int length, tlv_parser_iterator *iterator)
{
    if(!iterator)
    {
        return 1;
    }

#ifdef USE_HAL
    hal_memset(iterator,0x00,sizeof(tlv_parser_iterator));
#else
    memset(iterator,0x00,sizeof(tlv_parser_iterator));
#endif

    iterator->m_pStreamStart = (unsigned char *)data;
    iterator->m_length = length;

    return 0;
}

int tlv_parser_first(tlv_parser_iterator *iterator)
{
    if(!iterator)
    {
        return 1;
    }

    iterator->m_pStreamCurrent = iterator->m_pStreamStart;

#ifdef USE_HAL 
    hal_memset(&iterator->m_pDataObject,0x00,sizeof(tlv_parser_data_object));
#else
    memset(&iterator->m_pDataObject,0x00,sizeof(tlv_parser_data_object));
#endif

   return 0;
}

int tlv_parser_has_next(const tlv_parser_iterator *iterator)
{
    if(!iterator)
    {
        return 0; // if iterator not defined then process like end reached
    }

    return iterator->m_pStreamCurrent < (iterator->m_pStreamStart + iterator->m_length);
}

int tlv_parser_next(tlv_parser_iterator *iterator)
{
    if(!iterator)
    {
        return 1;
    }

    return 0;    
}

int tlv_parser_current(tlv_parser_iterator *iterator)
{
    if(!iterator)
    {
        return 1;
    }

    parse_tlv();

    return 0;
}
