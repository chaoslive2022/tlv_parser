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

/**
 * \addtogroup Module
 * @{
 * @file tlv_parser.h
 * @brief
 * 
 * 
 */

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
    unsigned char* m_pTag; /** pointer to the TAG */
    unsigned char m_tag_length; /** number of bytes encoding TAG - update to 4 */
    unsigned int m_tag_value; /** TAG's value*/
    unsigned char* m_pLength; /** pointer to the LENGTH */
    unsigned char m_length_length; /** number of bytes encoding LENGTH - update to 4 */
    unsigned short m_length_value; /* LENGTH's value*/
    unsigned char* m_pData; /** VALUE */
} tlv_parser_data_object;

/**
 * @brief intializes BER TLV iterator
 * 
 */
typedef struct
{
    unsigned char* m_pStreamStart; /** */
    unsigned char* m_pStreamCurrent; /** */
    unsigned int m_length; /** */
    tlv_parser_data_object m_pDataObject; /** */
} tlv_parser_iterator;

/** 
 * @brief creates and initializes an iterator from a TLV data objects stream
 * @param[in] data stream containing TLV data objects
 * @param[in] lengh length of the stream
 * @param[inout] iterator iterator's address provided by calling module
 * @return error code
*/
int tlv_parser_create(const unsigned char *data, unsigned int length, tlv_parser_iterator *iterator);

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
