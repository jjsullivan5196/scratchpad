#!/usr/bin/emacs --script
(require 'server)

(defun batch-readlines ()
  "Read all lines from stdin in batch mode. Returns lines as a list."
  (let ((lines ())
        (next-element nil))
    (while (setq next-element (ignore-errors (read-from-minibuffer "")))
      (setq lines (cons next-element lines)))
    (reverse lines)))

(defun run-menu (&optional prompt)
  "Takes dmenu choices from stdin and prints the chosen option."
  (let ((lines (batch-readlines)))
    (princ
     (server-eval-at "server"
      `(helm-dmenu (eval-string ,(format "'%s" lines)) ,prompt)))))

(print argv)
(run-menu)

