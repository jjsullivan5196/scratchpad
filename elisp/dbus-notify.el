(require 'dbus)
(setq dbus-notify/global-notification-id 0)

(defun dbus-notify/register-method (name handler)
  (dbus-register-method
   :session
   "org.freedesktop.Notifications"
   "org/freedesktop/Notifications"
   "org.freedesktop.Notifications"
   name
   handler
   t))

(defun dbus-notify/register-signal (name handler)
  (dbus-register-signal
   :session
   "org.freedesktop.Notifications"
   "org/freedesktop/Notifications"
   "org.freedesktop.Notifications"
   name
   handler))

(defun dbus-notify/register-service ()
  (let ((handle-notify (lambda (app-name
                                notification-id
                                icon
                                summary
                                body
                                actions
                                hints
                                timeout)
                         (message summary)
                         (if notification-id notification-id (setq dbus-notify/global-notification-id (+1 dbus-notify/global-notification-id)))))
        (handle-get-capabilities (lambda () "body"))
        (signal-notification-closed (lambda (id reason) :ignore))
        (handle-close-notification (lambda (id) :ignore))
        (handle-get-server-informatin (lambda () '("spacemacs" "http://spacemacs.org" "0.0.1" "1"))))
    (dbus-notify/register-method "Notify" handle-notify)
    (dbus-notify/register-method "GetCapanilities" handle-get-capabilities)
    (dbus-notify/register-signal "NotificationClosed" signal-notification-closed)
    (dbus-notify/register-method "CloseNotification" handle-close-notification)
    (dbus-notify/register-method "GetServerInformation" handle-get-server-informatin)
    (dbus-register-service :session "org.freedesktop.Notifications")))

(dbus-notify/register-service)
