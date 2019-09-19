(require 'dbus)
(setq dbus-notify/global-notification-id 0)
(setq dbus-notify/interface-definition-path "~/.dbus/interfaces/org.freedesktop.Notifications.xml")
(setq dbus-notify/interface-definition (with-temp-buffer
                                         (insert-file-contents dbus-notify/interface-definition-path)
                                         (buffer-string)))
(defun dbus-notify/introspect () dbus-notify/interface-definition)

(defun dbus-notify/handle-notify (app-name
                                  notification-id
                                  icon
                                  summary
                                  body
                                  actions
                                  hints
                                  timeout)
  (message summary)
  (if notification-id
      notification-id
      (list :uint32 (setq dbus-notify/global-notification-id (+1 dbus-notify/global-notification-id)))))
(defun dbus-notify/handle-get-capabilities () (list :string "body"))
(defun dbus-notify/signal-notification-closed (id reason) :ignore)
(defun dbus-notify/handle-close-notification (id) :ignore)
(defun dbus-notify/handle-get-server-information () (list :string "spacemacs" :string "http://spacemacs.org" :string "0.0.1" :string "1"))

(defun dbus-notify/register-service ()
  (dbus-register-method :session "org.freedesktop.Notifications" "/org/freedesktop/Notifications" "org.freedesktop.Notifications" "Notify" 'dbus-notify/handle-notify t)
  (dbus-register-method :session "org.freedesktop.Notifications" "/org/freedesktop/Notifications" "org.freedesktop.Notifications" "Notify" 'dbus-notify/handle-notify t)
  (dbus-register-method :session "org.freedesktop.Notifications" "/org/freedesktop/Notifications" "org.freedesktop.Notifications" "GetCapabilities" 'dbus-notify/handle-get-capabilities t)
  (dbus-register-signal :session "org.freedesktop.Notifications" "/org/freedesktop/Notifications" "org.freedesktop.Notifications" "NotificationClosed" 'dbus-notify/signal-notification-closed)
  (dbus-register-method :session "org.freedesktop.Notifications" "/org/freedesktop/Notifications" "org.freedesktop.Notifications" "CloseNotification" 'dbus-notify/handle-close-notification t)
  (dbus-register-method :session "org.freedesktop.Notifications" "/org/freedesktop/Notifications" "org.freedesktop.Notifications" "GetServerInformation" 'dbus-notify/handle-get-server-information t)
  (dbus-register-service :session "org.freedesktop.Notifications"))

;; register
(dbus-notify/register-service)

;; unregister
(dbus-unregister-service :session "org.freedesktop.Notifications")

;; test?
(require 'notify)
(dbus-ping :session "org.freedesktop.Notifications")
(dbus-introspect :session "org.freedesktop.Notifications" "/org/freedesktop/Notifications")
