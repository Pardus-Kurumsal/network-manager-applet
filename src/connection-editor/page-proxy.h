/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/* NetworkManager Connection editor -- Connection editor for NetworkManager
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * (C) Copyright 2016 Atul Anand <atulhjp@gmail.com>.
 */

#ifndef __PAGE_PROXY_H__
#define __PAGE_PROXY_H__

#include "ce-page.h"

#if NM_LIBNM_COMPAT_PROXY_SUPPORTED

#define CE_TYPE_PAGE_PROXY            (ce_page_proxy_get_type ())
#define CE_PAGE_PROXY(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), CE_TYPE_PAGE_PROXY, CEPageProxy))
#define CE_PAGE_PROXY_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), CE_TYPE_PAGE_PROXY, CEPageProxyClass))
#define CE_IS_PAGE_PROXY(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CE_TYPE_PAGE_PROXY))
#define CE_IS_PAGE_PROXY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CE_TYPE_PAGE_PROXY))
#define CE_PAGE_PROXY_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), CE_TYPE_PAGE_PROXY, CEPageProxyClass))

typedef struct {
	CEPage parent;
} CEPageProxy;

typedef struct {
	CEPageClass parent;
} CEPageProxyClass;

GType ce_page_proxy_get_type (void);

CEPage *ce_page_proxy_new (NMConnectionEditor *editor,
                           NMConnection *connection,
                           GtkWindow *parent,
                           NMClient *client,
                           const char **out_secrets_setting_name,
                           GError **error);

#endif /* NM_LIBNM_COMPAT_PROXY_SUPPORTED */

#endif  /* __PAGE_PROXY_H__ */
