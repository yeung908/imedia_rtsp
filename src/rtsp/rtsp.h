#ifndef __RTSP_H__
#define __RTSP_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <base_app.h>
#include "stream_descriptor.h"

#define IPCAM_TYPE_RTSP (ipcam_rtsp_get_type())
#define IPCAM_RTSP(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), IPCAM_TYPE_RTSP, IpcamRtsp))
#define IPCAM_RTSP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), IPCAM_TYPE_RTSP, IpcamRtspClass))
#define IPCAM_IS_RTSP(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), IPCAM_TYPE_RTSP))
#define IPCAM_IS_RTSP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), IPCAM_TYPE_RTSP))
#define IPCAM_RTSP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), IPCAM_TYPE_RTSP, IpcamRtspClass))

typedef struct _IpcamRtsp IpcamRtsp;
typedef struct _IpcamRtspClass IpcamRtspClass;

struct _IpcamRtsp
{
    GObject parent;
};

struct _IpcamRtspClass
{
    GObjectClass parent_class;
};

GType ipcam_rtsp_get_type(void);
void ipcam_rtsp_set_port(IpcamRtsp *rtsp, guint port);
void ipcam_rtsp_insert_user(IpcamRtsp *rtsp, const gchar *username, const gchar *password);
void ipcam_rtsp_delete_user(IpcamRtsp *rtsp, const gchar *username);
void ipcam_rtsp_set_auth(IpcamRtsp *rtsp, gboolean auth);
void ipcam_rtsp_set_stream_desc(IpcamRtsp *rtsp, StreamChannel chn, StreamDescriptor *desc);
void ipcam_rtsp_set_user_data(IpcamRtsp *rtsp, gpointer user_data);
void ipcam_rtsp_start_server(IpcamRtsp *rtsp);
void ipcam_rtsp_stop_server(IpcamRtsp *rtsp);

#ifdef __cplusplus
}
#endif

#endif /* __RTSP_H__ */
