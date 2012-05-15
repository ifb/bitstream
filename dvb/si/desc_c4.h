/*****************************************************************************
 * desc_c4.h: WBU-ISOG Descriptor 0xc4: Carrier ID
 *****************************************************************************
 * Copyright (C) 2012 Phillip Blucas
 *
 * Authors: Phillip Blucas <pblucas@gmail.com>
  *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *****************************************************************************/

/*
 * Normative references:
 *  - ETSI EN 300 468 V1.12.1 (2011-10) (SI in DVB systems)
 *  - WBU-ISOG Carrier ID - Video (2010-10)
 */

#ifndef __BITSTREAM_DVB_DESC_C4_H__
#define __BITSTREAM_DVB_DESC_C4_H__

#include <bitstream/common.h>
#include <bitstream/mpeg/psi/descriptors.h>
#include <bitstream/dvb/si/strings.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
 * Descriptor 0xc4: Carrier ID
 *****************************************************************************/
#define DESCC4_HEADER_SIZE      DESC_HEADER_SIZE

static inline void descc4_init(uint8_t *p_desc)
{
    int i;
    char *format = "02";
    char *longitude = "+000.0000";
    char *latitude = "+00.0000";

    desc_set_tag(p_desc, 0xc4);

    // padding characters shall use underscore only
    for (i = 0; i < 80; i++)
        p_desc[DESC_HEADER_SIZE + i] = '_';

    // Comma Separator
    p_desc[DESC_HEADER_SIZE +  2] = ',';
    p_desc[DESC_HEADER_SIZE +  8] = ',';
    p_desc[DESC_HEADER_SIZE + 21] = ',';
    p_desc[DESC_HEADER_SIZE + 27] = ',';
    p_desc[DESC_HEADER_SIZE + 45] = ',';
    p_desc[DESC_HEADER_SIZE + 55] = ',';
    p_desc[DESC_HEADER_SIZE + 64] = ',';

    memcpy(p_desc + DESC_HEADER_SIZE +  0, format,    strlen(format));
    memcpy(p_desc + DESC_HEADER_SIZE + 46, longitude, strlen(longitude));
    memcpy(p_desc + DESC_HEADER_SIZE + 56, latitude,  strlen(latitude));
}

// Encoder Manufacturer
static inline void descc4_set_manufacturer(uint8_t *p_desc,
                                           const uint8_t *p_manufacturer,
                                           uint8_t i_length)
{
    uint8_t *p = p_desc + DESCC4_HEADER_SIZE + 3;
    memcpy(p, p_manufacturer, i_length > 5 ? 5 : i_length);
}

static inline const uint8_t *descc4_get_manufacturer(const uint8_t *p_desc,
                                                     uint8_t *pi_length)
{
    *pi_length = 5;
    return p_desc + DESCC4_HEADER_SIZE + 3;
}

// Encoder Serial Number
static inline void descc4_set_serial(uint8_t *p_desc,
                                     const uint8_t *p_serial,
                                     uint8_t i_length)
{
    uint8_t *p = p_desc + DESCC4_HEADER_SIZE + 9;
    memcpy(p, p_serial, i_length > 12 ? 12 : i_length);
}

static inline const uint8_t *descc4_get_serial(const uint8_t *p_desc,
                                               uint8_t *pi_length)
{
    *pi_length = 12;
    return p_desc + DESCC4_HEADER_SIZE + 9;
}

// Carrier Identifier
static inline void descc4_set_carrier(uint8_t *p_desc,
                                     const uint8_t *p_carrier,
                                     uint8_t i_length)
{
    uint8_t *p = p_desc + DESCC4_HEADER_SIZE + 22;
    memcpy(p, p_carrier, i_length > 5 ? 5 : i_length);
}

static inline const uint8_t *descc4_get_carrier(const uint8_t *p_desc,
                                                uint8_t *pi_length)
{
    *pi_length = 5;
    return p_desc + DESCC4_HEADER_SIZE + 22;
}

// Telephone Number
static inline void descc4_set_telephone(uint8_t *p_desc,
                                        const uint8_t *p_telephone,
                                        uint8_t i_length)
{
    uint8_t *p = p_desc + DESCC4_HEADER_SIZE + 28;
    memcpy(p, p_telephone, i_length > 17 ? 17 : i_length);
}

static inline const uint8_t *descc4_get_telephone(const uint8_t *p_desc,
                                                  uint8_t *pi_length)
{
    *pi_length = 17;
    return p_desc + DESCC4_HEADER_SIZE + 28;
}

// Longitude
static inline void descc4_set_longitude(uint8_t *p_desc,
                                        const uint8_t *p_longitude,
                                        uint8_t i_length)
{
    uint8_t *p = p_desc + DESCC4_HEADER_SIZE + 46;
    memcpy(p, p_longitude, i_length > 9 ? 9 : i_length);
}

static inline const uint8_t *descc4_get_longitude(const uint8_t *p_desc,
                                                  uint8_t *pi_length)
{
    *pi_length = 9;
    return p_desc + DESCC4_HEADER_SIZE + 46;
}

// Latitude
static inline void descc4_set_latitude(uint8_t *p_desc,
                                       const uint8_t *p_latitude,
                                       uint8_t i_length)
{
    uint8_t *p = p_desc + DESCC4_HEADER_SIZE + 56;
    memcpy(p, p_latitude, i_length > 8 ? 8 : i_length);
}

static inline const uint8_t *descc4_get_latitude(const uint8_t *p_desc,
                                                 uint8_t *pi_length)
{
    *pi_length = 8;
    return p_desc + DESCC4_HEADER_SIZE + 56;
}

// User Information
static inline void descc4_set_userinfo(uint8_t *p_desc,
                                       const uint8_t *p_userinfo,
                                       uint8_t i_length)
{
    uint8_t *p = p_desc + DESCC4_HEADER_SIZE + 65;
    memcpy(p, p_userinfo, i_length > 15 ? 15 : i_length);
}

static inline const uint8_t *descc4_get_userinfo(const uint8_t *p_desc,
                                                 uint8_t *pi_length)
{
    *pi_length = 15;
    return p_desc + DESCC4_HEADER_SIZE + 65;
}

static inline void descc4_set_length(uint8_t *p_desc)
{
    desc_set_length(p_desc, 80);
}

static inline bool descc4_validate(const uint8_t *p_desc)
{
    int i;
    uint8_t i_length = desc_get_length(p_desc);
    const uint8_t *p = p_desc + DESCC4_HEADER_SIZE;

    if (i_length != 80)
        return false;

    // check for ASCII characters and no spaces
    for (i = 0; i < 80; i++)
        if (p[i] == ' ' || p[i] < 32 || p[i] > 126)
            return false;

    // telephone is numeric only and '+', '(', ')'
    for (i = 0; i < 17; i++)
        if (p[28 + i] != '+' && p[28 + i] != '(' && p[28 + i] != ')' &&
            p[28 + i] != '_' && (p[28 + i] < '0' || p[28 + i] > '9'))
            return false;

    // longitude/latitude is numeric only and '+', '-', '.'
    if (p[46] != '+' && p[46] != '-' && p[56] != '+' && p[56] != '-')
        return false;
    if (p[46 + 4] != '.' && p[56 + 3] != '.')
        return false;

    return true;
}

static inline void descc4_print(const uint8_t *p_desc,
                                f_print pf_print, void *print_opaque,
                                f_iconv pf_iconv, void *iconv_opaque,
                                print_type_t i_print_type)
{
    uint8_t i_manufacturer_length, i_serial_length, i_carrier_length, i_telephone_length,
            i_longitude_length, i_latitude_length, i_userinfo_length;
    const uint8_t *p_manufacturer = descc4_get_manufacturer(p_desc, &i_manufacturer_length);
    const uint8_t *p_serial = descc4_get_serial(p_desc, &i_serial_length);
    const uint8_t *p_carrier = descc4_get_carrier(p_desc, &i_carrier_length);
    const uint8_t *p_telephone = descc4_get_telephone(p_desc, &i_telephone_length);
    const uint8_t *p_longitude = descc4_get_longitude(p_desc, &i_longitude_length);
    const uint8_t *p_latitude = descc4_get_latitude(p_desc, &i_latitude_length);
    const uint8_t *p_userinfo = descc4_get_userinfo(p_desc, &i_userinfo_length);
    char *psz_manufacturer = dvb_string_get(p_manufacturer, i_manufacturer_length,
                                            pf_iconv, iconv_opaque);
    char *psz_serial = dvb_string_get(p_serial, i_serial_length,
                                      pf_iconv, iconv_opaque);
    char *psz_carrier = dvb_string_get(p_carrier, i_carrier_length,
                                       pf_iconv, iconv_opaque);
    char *psz_telephone = dvb_string_get(p_telephone, i_telephone_length,
                                         pf_iconv, iconv_opaque);
    char *psz_longitude = dvb_string_get(p_longitude, i_longitude_length,
                                         pf_iconv, iconv_opaque);
    char *psz_latitude = dvb_string_get(p_latitude, i_latitude_length,
                                        pf_iconv, iconv_opaque);
    char *psz_userinfo = dvb_string_get(p_userinfo, i_userinfo_length,
                                        pf_iconv, iconv_opaque);
    switch (i_print_type) {
    case PRINT_XML:
        psz_manufacturer = dvb_string_xml_escape(psz_manufacturer);
        psz_serial = dvb_string_xml_escape(psz_serial);
        psz_carrier = dvb_string_xml_escape(psz_carrier);
        psz_telephone = dvb_string_xml_escape(psz_telephone);
        psz_longitude = dvb_string_xml_escape(psz_longitude);
        psz_latitude = dvb_string_xml_escape(psz_latitude);
        psz_userinfo = dvb_string_xml_escape(psz_userinfo);
        pf_print(print_opaque,
                 "<CARRIERID_DESC manufacturer=\"%s\" serial=\"%s\" carrier=\"%s\" telephone=\"%s\" longitude=\"%s\" latitude=\"%s\" userinfo=\"%s\" />",
                 psz_manufacturer, psz_serial, psz_carrier, psz_telephone, psz_longitude, psz_latitude, psz_userinfo);
        break;
    default:
        pf_print(print_opaque,
                 "    - desc c4 carrier_id manufacturer=\"%s\" serial=\"%s\" carrier=\"%s\" telephone=\"%s\" longitude=\"%s\" latitude=\"%s\" userinfo=\"%s\"",
                 psz_manufacturer, psz_serial, psz_carrier, psz_telephone, psz_longitude, psz_latitude, psz_userinfo);
    }
    free(psz_manufacturer);
    free(psz_serial);
    free(psz_carrier);
    free(psz_telephone);
    free(psz_longitude);
    free(psz_latitude);
    free(psz_userinfo);
}

#ifdef __cplusplus
}
#endif

#endif
