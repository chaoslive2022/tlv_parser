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

#include "tlv_parser.h"
#include <string.h>

typedef enum {
    tlv_parser_NO_STATE,
    tlv_parser_TAG,
    tlv_parser_LENGTH,
    tlv_parser_VALUE
} tlv_parser_state_t;

/* Private functions */
tlv_parser_state_t
parse_tag(uint8_t byte) {
    
}

tlv_parser_state_t
parse_length(uint8_t byte) {
    
}

tlv_parser_state_t
parse_value(uint8_t byte) {
    
}

uint16_t
tlv_parser_parse_tlv(const tlv_parser_iterator_t* iterator) {
    uint8_t *end = iterator->stream_start + iterator->length, *working = iterator->stream_current;
    tlv_parser_state_t next_state = tlv_parser_TAG;
    
    while (working < end) {
        switch (next_state) {
            case tlv_parser_TAG:
                next_state = parse_tag(*working);
                break;
            case tlv_parser_LENGTH:
                next_state = parse_length(*working);
                break;
            case tlv_parser_VALUE:
                next_state = parse_value(*working);
                break;
            default:
                return TLV_PARSER_PARSING_ERROR;
        }

        if (next_state != tlv_parser_NO_STATE) {
            ++working;
        }
    }

    return TLV_PARSER_NO_ERROR;
}

uint16_t
tlv_parser_catch_init_error(const tlv_parser_iterator_t* iterator) {
    if (!iterator) {
        return TLV_PARSER_INVALID_PARAM_IN;
    }

    if (!iterator->stream_start || !iterator->length) {
        return TLV_PARSER_NOT_INITIALIZED;
    }

    if (!iterator->stream_current) {
        return TLV_PARSER_INVALID_CURRENT;
    }

    return TLV_PARSER_NO_ERROR;
}

/* Public functions */
uint16_t
tlv_parser_initialize(const uint8_t* data, uint16_t length, tlv_parser_iterator_t* iterator) {
    if (!iterator) {
        return TLV_PARSER_INVALID_PARAM_IN;
    }

    if (!data) {
        return TLV_PARSER_INVALID_STREAM;
    }

    if (!length) {
        return TLV_PARSER_INVALID_STREAM_LENGTH;
    }

    memset(iterator, 0x00, sizeof(tlv_parser_iterator_t));

    iterator->stream_start = data;
    iterator->length = length;

    return TLV_PARSER_NO_ERROR;
}

uint16_t
tlv_parser_first(tlv_parser_iterator_t* iterator) {
    if (!iterator) {
        return TLV_PARSER_INVALID_PARAM_IN;
    }

    if (!iterator->stream_start || !iterator->length) {
        return TLV_PARSER_NOT_INITIALIZED;
    }

    iterator->stream_current = iterator->stream_start;

    return TLV_PARSER_NO_ERROR;
}

uint8_t
tlv_parser_has_next(const tlv_parser_iterator_t* iterator) {
    uint16_t error = TLV_PARSER_NO_ERROR;

    error = tlv_parser_catch_init_error(iterator);
    if (error) {
        return 0; /* Any error leads to false (end of stream) */
    }

    return iterator->stream_current < (iterator->stream_start + iterator->length);
}

uint8_t*
tlv_parser_next(tlv_parser_iterator_t* iterator) {
    uint16_t error = TLV_PARSER_NO_ERROR;

    error = tlv_parser_catch_init_error(iterator);
    if (error) {
        return error;
    }

    /* To do */
    /* Set current to next TLV */

    return iterator->stream_current;
}

uint16_t
tlv_parser_current(const tlv_parser_iterator_t* iterator, tlv_parser_data_object_t* data_object) {
    uint16_t error = TLV_PARSER_NO_ERROR;

    error = tlv_parser_catch_init_error(iterator);
    if (error) {
        return error;
    }

    if (!data_object) {
        return TLV_PARSER_INVALID_PARAM_IN;
    }

    error = tlv_parser_parse_tlv(iterator);
    if (error) {
        memset(data_object, 0x00, sizeof(tlv_parser_data_object_t));
        return error;
    }

    /* To do */
    /* Set data_object */

    return TLV_PARSER_NO_ERROR;
}
