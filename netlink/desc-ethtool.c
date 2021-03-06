/*
 * desc-ethtool.c - ethtool netlink format descriptions
 *
 * Descriptions of ethtool netlink messages and attributes for pretty print.
 */

#include <linux/ethtool_netlink.h>

#include "../internal.h"
#include "prettymsg.h"

static const struct pretty_nla_desc __header_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_HEADER_UNSPEC),
	NLATTR_DESC_U32(ETHTOOL_A_HEADER_DEV_INDEX),
	NLATTR_DESC_STRING(ETHTOOL_A_HEADER_DEV_NAME),
	NLATTR_DESC_X32(ETHTOOL_A_HEADER_FLAGS),
};

static const struct pretty_nla_desc __bitset_bit_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_BITSET_BIT_UNSPEC),
	NLATTR_DESC_U32(ETHTOOL_A_BITSET_BIT_INDEX),
	NLATTR_DESC_STRING(ETHTOOL_A_BITSET_BIT_NAME),
	NLATTR_DESC_FLAG(ETHTOOL_A_BITSET_BIT_VALUE),
};

static const struct pretty_nla_desc __bitset_bits_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_BITSET_BITS_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_BITSET_BITS_BIT, bitset_bit),
};

static const struct pretty_nla_desc __bitset_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_BITSET_UNSPEC),
	NLATTR_DESC_FLAG(ETHTOOL_A_BITSET_NOMASK),
	NLATTR_DESC_U32(ETHTOOL_A_BITSET_SIZE),
	NLATTR_DESC_NESTED(ETHTOOL_A_BITSET_BITS, bitset_bits),
	NLATTR_DESC_BINARY(ETHTOOL_A_BITSET_VALUE),
	NLATTR_DESC_BINARY(ETHTOOL_A_BITSET_MASK),
};

static const struct pretty_nla_desc __string_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_STRING_UNSPEC),
	NLATTR_DESC_U32(ETHTOOL_A_STRING_INDEX),
	NLATTR_DESC_STRING(ETHTOOL_A_STRING_VALUE),
};

static const struct pretty_nla_desc __strings_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_STRINGS_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_STRINGS_STRING, string),
};

static const struct pretty_nla_desc __stringset_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_STRINGSET_UNSPEC),
	NLATTR_DESC_U32(ETHTOOL_A_STRINGSET_ID),
	NLATTR_DESC_U32(ETHTOOL_A_STRINGSET_COUNT),
	NLATTR_DESC_NESTED(ETHTOOL_A_STRINGSET_STRINGS, strings),
};

static const struct pretty_nla_desc __stringsets_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_STRINGSETS_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_STRINGSETS_STRINGSET, stringset),
};

static const struct pretty_nla_desc __strset_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_STRSET_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_STRSET_HEADER, header),
	NLATTR_DESC_NESTED(ETHTOOL_A_STRSET_STRINGSETS, stringsets),
	NLATTR_DESC_FLAG(ETHTOOL_A_STRSET_COUNTS_ONLY),
};

static const struct pretty_nla_desc __linkinfo_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_LINKINFO_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_LINKINFO_HEADER, header),
	NLATTR_DESC_U8(ETHTOOL_A_LINKINFO_PORT),
	NLATTR_DESC_U8(ETHTOOL_A_LINKINFO_PHYADDR),
	NLATTR_DESC_U8(ETHTOOL_A_LINKINFO_TP_MDIX),
	NLATTR_DESC_U8(ETHTOOL_A_LINKINFO_TP_MDIX_CTRL),
	NLATTR_DESC_U8(ETHTOOL_A_LINKINFO_TRANSCEIVER),
};

static const struct pretty_nla_desc __linkmodes_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_LINKMODES_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_LINKMODES_HEADER, header),
	NLATTR_DESC_BOOL(ETHTOOL_A_LINKMODES_AUTONEG),
	NLATTR_DESC_NESTED(ETHTOOL_A_LINKMODES_OURS, bitset),
	NLATTR_DESC_NESTED(ETHTOOL_A_LINKMODES_PEER, bitset),
	NLATTR_DESC_U32(ETHTOOL_A_LINKMODES_SPEED),
	NLATTR_DESC_U8(ETHTOOL_A_LINKMODES_DUPLEX),
};

static const struct pretty_nla_desc __linkstate_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_LINKSTATE_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_LINKSTATE_HEADER, header),
	NLATTR_DESC_BOOL(ETHTOOL_A_LINKSTATE_LINK),
};

static const struct pretty_nla_desc __debug_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_DEBUG_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_DEBUG_HEADER, header),
	NLATTR_DESC_NESTED(ETHTOOL_A_DEBUG_MSGMASK, bitset),
};

static const struct pretty_nla_desc __wol_desc[] = {
	NLATTR_DESC_INVALID(ETHTOOL_A_WOL_UNSPEC),
	NLATTR_DESC_NESTED(ETHTOOL_A_WOL_HEADER, header),
	NLATTR_DESC_NESTED(ETHTOOL_A_WOL_MODES, bitset),
	NLATTR_DESC_BINARY(ETHTOOL_A_WOL_SOPASS),
};

const struct pretty_nlmsg_desc ethnl_umsg_desc[] = {
	NLMSG_DESC_INVALID(ETHTOOL_MSG_USER_NONE),
	NLMSG_DESC(ETHTOOL_MSG_STRSET_GET, strset),
	NLMSG_DESC(ETHTOOL_MSG_LINKINFO_GET, linkinfo),
	NLMSG_DESC(ETHTOOL_MSG_LINKINFO_SET, linkinfo),
	NLMSG_DESC(ETHTOOL_MSG_LINKMODES_GET, linkmodes),
	NLMSG_DESC(ETHTOOL_MSG_LINKMODES_SET, linkmodes),
	NLMSG_DESC(ETHTOOL_MSG_LINKSTATE_GET, linkstate),
	NLMSG_DESC(ETHTOOL_MSG_DEBUG_GET, debug),
	NLMSG_DESC(ETHTOOL_MSG_DEBUG_SET, debug),
	NLMSG_DESC(ETHTOOL_MSG_WOL_GET, wol),
	NLMSG_DESC(ETHTOOL_MSG_WOL_SET, wol),
};

const unsigned int ethnl_umsg_n_desc = ARRAY_SIZE(ethnl_umsg_desc);

const struct pretty_nlmsg_desc ethnl_kmsg_desc[] = {
	NLMSG_DESC_INVALID(ETHTOOL_MSG_KERNEL_NONE),
	NLMSG_DESC(ETHTOOL_MSG_STRSET_GET_REPLY, strset),
	NLMSG_DESC(ETHTOOL_MSG_LINKINFO_GET_REPLY, linkinfo),
	NLMSG_DESC(ETHTOOL_MSG_LINKINFO_NTF, linkinfo),
	NLMSG_DESC(ETHTOOL_MSG_LINKMODES_GET_REPLY, linkmodes),
	NLMSG_DESC(ETHTOOL_MSG_LINKMODES_NTF, linkmodes),
	NLMSG_DESC(ETHTOOL_MSG_LINKSTATE_GET_REPLY, linkstate),
	NLMSG_DESC(ETHTOOL_MSG_DEBUG_GET_REPLY, debug),
	NLMSG_DESC(ETHTOOL_MSG_DEBUG_NTF, debug),
	NLMSG_DESC(ETHTOOL_MSG_WOL_GET_REPLY, wol),
	NLMSG_DESC(ETHTOOL_MSG_WOL_NTF, wol),
};

const unsigned int ethnl_kmsg_n_desc = ARRAY_SIZE(ethnl_kmsg_desc);
