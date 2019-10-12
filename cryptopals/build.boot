(set-env!
  :resource-paths #{"src" "resources"}
  :dependencies '[[org.clojure/clojure "1.10.1"]
                  [org.clojure/core.async "0.4.500"]
                  [environ "1.1.0"]
                  [boot-environ "1.1.0"]])

(require '[environ.boot :refer [environ]])

(task-options!
  environ {})

;; vim: set ft=clojure:
