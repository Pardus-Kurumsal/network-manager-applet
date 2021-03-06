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
 * Copyright 2012 - 2014 Red Hat, Inc.
 */

#ifndef __PAGE_BRIDGE_H__
#define __PAGE_BRIDGE_H__

#include <glib.h>
#include <glib-object.h>

#include "page-master.h"

#define CE_TYPE_PAGE_BRIDGE            (ce_page_bridge_get_type ())
#define CE_PAGE_BRIDGE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), CE_TYPE_PAGE_BRIDGE, CEPageBridge))
#define CE_PAGE_BRIDGE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), CE_TYPE_PAGE_BRIDGE, CEPageBridgeClass))
#define CE_IS_PAGE_BRIDGE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CE_TYPE_PAGE_BRIDGE))
#define CE_IS_PAGE_BRIDGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CE_TYPE_PAGE_BRIDGE))
#define CE_PAGE_BRIDGE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), CE_TYPE_PAGE_BRIDGE, CEPageBridgeClass))

typedef struct {
	CEPageMaster parent;
} CEPageBridge;

typedef struct {
	CEPageMasterClass parent;
} CEPageBridgeClass;

GType ce_page_bridge_get_type (void);

CEPage *ce_page_bridge_new (NMConnectionEditor *editor,
                            NMConnection *connection,
                            GtkWindow *parent,
                            NMClient *client,
                            const char **out_secrets_setting_name,
                            GError **error);

void bridge_connection_new (FUNC_TAG_PAGE_NEW_CONNECTION_IMPL,
                            GtkWindow *parent,
                            const char *detail,
                            gpointer detail_data,
                            NMConnection *connection,
                            NMClient *client,
                            PageNewConnectionResultFunc result_func,
                            gpointer user_data);

#endif  /* __PAGE_BRIDGE_H__ */

