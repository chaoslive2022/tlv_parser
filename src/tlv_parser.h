/**
 *
 *
 */

/**
 * @file tlv_parser.h
 * @brief tlv_parser meant to process a BER TLV data objects stream as per ASN-1 definition
 *
 */

/**
 * @mainpage
 *
 */

#include <stdint.h>

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
 * @brief
 *
 */
typedef struct
{
    uint8_t *m_tag; /** pointer to the TAG */
    uint8_t m_tag_length; /** number of bytes encoding TAG - update to 4 */
    uint32_t m_tag_value; /** TAG's value*/
    uint8_t *m_length; /** pointer to the LENGTH */
    uint8_t m_length_length; /** number of bytes encoding LENGTH - update to 4 */
    uint16_t m_length_value; /* LENGTH's value*/
    uint8_t *m_data; /** VALUE */
} tlv_parser_data_object;

/**
 * @brief intializes BER TLV iterator
 *
 */
typedef struct
{
    uint8_t *m_stream_start; /** */
    uint16_t m_length; /** */
    uint8_t *m_stream_current; /** */
    tlv_parser_data_object m_data_object; /** */
} tlv_parser_iterator;

/**
 * @brief initializes an iterator from a TLV data objects stream
 * @param[in] data stream containing TLV data objects
 * @param[in] lengh length of the stream
 * @param[inout] iterator iterator's address provided by calling module
 * @return error code
 */
uint16_t tlv_parser_initialize(const uint8_t *data, uint16_t length, tlv_parser_iterator *iterator);

/**
 * @brief sets an iterator to enable stream parsing
 * @param[inout] iterator iterator's address provided by calling module
 * * @return error code
 */
uint16_t tlv_parser_first(tlv_parser_iterator *iterator);

/**
 * @brief
 * @param[in] iterator iterator's address provided by calling module
 * @return error code
 */
uint8_t tlv_parser_has_next(const tlv_parser_iterator *iterator);

/**
 * @brief moves iterator to next BER TLV data object
 * @param[inout] iterator iterator's address provided by calling module
 * @return error code
 */
uint16_t tlv_parser_next(tlv_parser_iterator *iterator);

/**
 * @brief sets iterator's data object to current BER TLV data object's value
 * @param[inout] iterator iterator's address provided by calling module
 * @return error code
 */
uint16_t tlv_parser_current(tlv_parser_iterator *iterator);
