/**
 * @file tlv_parser.h
 * @author olivier chauvineau
 * @brief specfiies tlv_parser API
 * @note tlv_parser is meant to process a BER TLV data objects stream as per ASN-1 definition
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022 Olivier CHAUVINEAU
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of tlv_parser library.
 *
 * Author:          Olivier CHAUVINEAU o.chauvineau@gmail.com
 */

#ifndef TLV_PARSER_H
#define TLV_PARSER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @mainpage
 *
 */

/**
 * \addtogroup Module
 * @{
 * @file tlv_parser.h
 * @brief
 *
 *
 */

#define TLV_PARSER_NO_ERROR                 0
#define TLV_PARSER_INVALID_PARAM_IN         1
#define TLV_PARSER_NOT_INITIALIZED          2
#define TLV_PARSER_INVALID_STREAM           3
#define TLV_PARSER_INVALID_STREAM_LENGTH    4
#define TLV_PARSER_INVALID_CURRENT          5
#define TLV_PARSER_PARSING_ERROR            6

/** \defgroup Structure Data Structure
 * @{
 * @file tlv_parser.h
 * @brief BER TLV data object
 * @note Hypothesis
 *  - 4-byte length tag
 *  -
 *
 */

/**
 * @brief iterator sctructure used to parse a TLV stream
 *
 */
typedef struct {
    const uint8_t* stream_start; /** */
    uint16_t length; /** */
    uint8_t* stream_current; /** */
} tlv_parser_iterator_t;

/**
 * @brief data object parsed by the tlv parser iterator
 *
 */
typedef struct {
    uint8_t* tag; /** pointer to the TAG */
    uint8_t tag_length; /** number of bytes encoding TAG - update to 4 */
    uint32_t tag_value; /** TAG's value*/
    uint8_t* length; /** pointer to the LENGTH */
    uint8_t length_length; /** number of bytes encoding LENGTH - update to 4 */
    uint16_t length_value; /* LENGTH's value*/
    uint8_t* data; /** VALUE */
} tlv_parser_data_object_t;

/**
 * @brief initializes an iterator from a TLV data objects stream
 * @note 
 *  - TLV stream is allocated by calling application so tlv_parser remains stateless
 *  - m_strean_current is kept to 0 as long as iterator->first is not called
 * @param[in] data stream containing TLV data objects
 * @param[in] lengh length of the stream
 * @param[inout] iterator iterator provided by calling module
 * @return error code
 */
uint16_t tlv_parser_initialize(const uint8_t* data, uint16_t length, tlv_parser_iterator_t* iterator);

/**
 * @brief sets an iterator to first data object
 * @param[inout] iterator iterator provided by calling module
 * * @return error code
 */
uint16_t tlv_parser_first(tlv_parser_iterator_t* iterator);

/**
 * @brief
 * @param[in] iterator iterator's address provided by calling module
 * @return error code
 */
uint8_t tlv_parser_has_next(const tlv_parser_iterator_t* iterator);

/**
 * @brief moves iterator to next BER TLV data object
 * @param[inout] iterator iterator's address provided by calling module
 * @return error code
 */
uint8_t* tlv_parser_next(tlv_parser_iterator_t* iterator);

/**
 * @brief gets current BER TLV data object pointer by iterator
 * @note: data object is allocated by calling module so tlv_parser remains stateless
 * @param[in] iterator iterator provided by calling module
 * @param[out] data_object data object provided by calling module and set with appropriate values
 * @return error code
 */
uint16_t tlv_parser_current(const tlv_parser_iterator_t* iterator, tlv_parser_data_object_t* data_object);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TLV_PARSER_H */
