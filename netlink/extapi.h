/*
 * extapi.h - external interface of netlink code
 *
 * Declarations needed by non-netlink code (mostly ethtool.c).
 */

#ifndef ETHTOOL_EXTAPI_H__
#define ETHTOOL_EXTAPI_H__

struct cmd_context;
struct nl_context;

#ifdef ETHTOOL_ENABLE_NETLINK

int netlink_init(struct cmd_context *ctx);
void netlink_done(struct cmd_context *ctx);

int nl_gset(struct cmd_context *ctx);
int nl_sset(struct cmd_context *ctx);
int nl_permaddr(struct cmd_context *ctx);
int nl_monitor(struct cmd_context *ctx);

void nl_monitor_usage(void);

#else /* ETHTOOL_ENABLE_NETLINK */

static inline int netlink_init(struct cmd_context *ctx maybe_unused)
{
	return -EOPNOTSUPP;
}

static inline void netlink_done(struct cmd_context *ctx maybe_unused)
{
}

static inline void nl_monitor_usage(void)
{
}

#define nl_gset			NULL
#define nl_sset			NULL
#define nl_permaddr		NULL

#endif /* ETHTOOL_ENABLE_NETLINK */

#endif /* ETHTOOL_EXTAPI_H__ */
