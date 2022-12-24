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

#include "../../hal/src/hal.h"
#include <string.h>

#include "tlv_parser.h"


// Private
uint16_t tlv_parser_parse_tlv(uint8_t *tlv, tlv_parser_data_object *data_object)
{
    return TLV_PARSER_NO_ERROR;
}

uint16_t tlv_parser_catch_error(const tlv_parser_iterator *iterator)
{
    if(!iterator)
    {
        return TLV_PARSER_INVALID_PARAM_IN;
    }

    if(!iterator->m_stream_start || !iterator->m_length)
    {
        return TLV_PARSER_NOT_INITIALIZED;
    }

    if(!iterator->m_stream_current)
    {
        return TLV_PARSER_INVALID_CURRENT;
    }

    return TLV_PARSER_NO_ERROR;
}

// Public
uint16_t tlv_parser_initialize(const uint8_t *data, uint16_t length, tlv_parser_iterator *iterator)
{
    if(!iterator)
    {
        return TLV_PARSER_INVALID_PARAM_IN;
    }

    if(!data)
    {
        return TLV_PARSER_INVALID_STREAM;
    }

    if(!length)
    {
        return TLV_PARSER_INVALID_STREAM_LENGTH;
    }

    hal_memset(iterator,0x00,sizeof(tlv_parser_iterator));

    iterator->m_stream_start = (uint8_t *)data;
    iterator->m_length = length;

    return TLV_PARSER_NO_ERROR;
}

uint16_t tlv_parser_first(tlv_parser_iterator *iterator)
{
    if(!iterator)
    {
        return TLV_PARSER_INVALID_PARAM_IN;
    }

    if(!iterator->m_stream_start || !iterator->m_length)
    {
        return TLV_PARSER_NOT_INITIALIZED;
    }

    iterator->m_stream_current = iterator->m_stream_start;

   return TLV_PARSER_NO_ERROR;
}

uint8_t tlv_parser_has_next(const tlv_parser_iterator *iterator)
{
    uint16_t error=TLV_PARSER_NO_ERROR;

    error = tlv_parser_catch_error(iterator);
    if(error)
    {
        return 0; // Any error leads to false (end of stream)
    }

    return iterator->m_stream_current < (iterator->m_stream_start + iterator->m_length);
}

uint16_t tlv_parser_next(tlv_parser_iterator *iterator)
{
    uint16_t error=TLV_PARSER_NO_ERROR;

    error = tlv_parser_catch_error(iterator);
    if(error)
    {
        return error;
    }

    // To do
    // Set current to next TLV

    return TLV_PARSER_NO_ERROR;
}

uint16_t tlv_parser_current(tlv_parser_iterator *iterator)
{
    uint16_t error=TLV_PARSER_NO_ERROR;
    tlv_parser_data_object data_object;

    error = tlv_parser_catch_error(iterator);
    if(error)
    {
        return error;
    }

    error = tlv_parser_parse_tlv(iterator->m_stream_current, &data_object);

    return error;
}
