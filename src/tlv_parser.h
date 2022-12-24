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


#define TLV_PARSER_NO_ERROR             0
#define TLV_PARSER_INVALID_PARAM_IN     1

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
    uint8_t *m_pTag;         /** pointer to the TAG */
    uint8_t m_tag_length;    /** number of bytes encoding TAG - update to 4 */
    uint32_t m_tag_value;      /** TAG's value*/
    uint8_t *m_pLength;      /** pointer to the LENGTH */
    uint8_t m_length_length; /** number of bytes encoding LENGTH - update to 4 */
    uint16_t m_length_value; /* LENGTH's value*/
    uint8_t *m_pData;        /** VALUE */
} tlv_parser_data_object;

/**
 * @brief intializes BER TLV iterator
 *
 */
typedef struct
{
    uint8_t *m_pStreamStart;        /** */
    uint8_t *m_pStreamCurrent;      /** */
    uint16_t m_length;                /** */
    tlv_parser_data_object m_pDataObject; /** */
} tlv_parser_iterator;

/**
 * @brief creates and initializes an iterator from a TLV data objects stream
 * @param[in] data stream containing TLV data objects
 * @param[in] lengh length of the stream
 * @param[inout] iterator iterator's address provided by calling module
 * @return error code
 */
int tlv_parser_create(const uint8_t *data, uint16_t length, tlv_parser_iterator *iterator);

/**
 * @brief
 * @param[inout] iterator iterator's address provided by calling module
 * * @return error code
 */
int tlv_parser_first(tlv_parser_iterator *iterator);

/**
 * @brief
 * @param[in] iterator iterator's address provided by calling module
 * @return error code
 */
int tlv_parser_has_next(const tlv_parser_iterator *iterator);

/**
 * @brief moves iterator to next BER TLV data object
 * @param[inout] iterator iterator's address provided by calling module
 * @return error code
 */
int tlv_parser_next(tlv_parser_iterator *iterator);

/**
 * @brief sets iterator's data object to current BER TLV data object's value
 * @param[inout] iterator iterator's address provided by calling module
 * @return error code
 */
int tlv_parser_current(tlv_parser_iterator *iterator);
