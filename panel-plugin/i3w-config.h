/*  $Id$
 *
 *  Copyright (C) 2014 Dénes Botond <dns.botond@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef I3W_CONFIG_H
#define I3W_CONFIG_H

#include <libxfce4panel/xfce-panel-plugin.h>

typedef struct
{
    GdkRGBA normal_color;
    GdkRGBA focused_color;
    GdkRGBA visible_color;
    GdkRGBA urgent_color;
    GdkRGBA mode_color;
    gboolean strip_workspace_numbers;
    gboolean auto_detect_outputs;
    gchar *output;
}
i3WorkspacesConfig;

typedef void (*ConfigChangedCallback) (gpointer cb_data);

/* utility functions */
guint32
gdk_rgba_to_int(GdkRGBA *gdkrgba);

/* interface functions */
i3WorkspacesConfig *
i3_workspaces_config_new();
void
i3_workspaces_config_free(i3WorkspacesConfig *config);
gboolean
i3_workspaces_config_load(i3WorkspacesConfig *config, XfcePanelPlugin *plugin);
gboolean
i3_workspaces_config_save(i3WorkspacesConfig *config, XfcePanelPlugin *plugin);
void
i3_workspaces_config_show(i3WorkspacesConfig *config, XfcePanelPlugin *plugin,
        ConfigChangedCallback cb, gpointer cb_data);

#endif /* I3W_CONFIG_H */
