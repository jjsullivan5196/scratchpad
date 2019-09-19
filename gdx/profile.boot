(set-env!
  :resource-paths #{"src" "resources"}
  :dependencies '[[org.clojure/clojure "1.10.1"]
                  [org.clojure/core.async "0.4.500"]
                  [org.clojure/core.match "0.3.0"]
                  [org.clojure/core.incubator "0.1.4"]
                  [environ "1.1.0"]
                  [boot-environ "1.1.0"]
                  [com.badlogicgames.gdx/gdx "1.9.10"]
                  [com.badlogicgames.gdx/gdx-backend-lwjgl "1.9.10"]
                  [com.badlogicgames.gdx/gdx-box2d "1.9.10"]
                  [com.badlogicgames.gdx/gdx-box2d-platform "1.9.10"
                   :classifier "natives-desktop"]
                  [com.badlogicgames.gdx/gdx-bullet "1.9.10"]
                  [com.badlogicgames.gdx/gdx-bullet-platform "1.9.10"
                   :classifier "natives-desktop"]
                  [com.badlogicgames.gdx/gdx-platform "1.9.10"
                   :classifier "natives-desktop"]])

(require '[environ.boot :refer [environ]])

(task-options!
  environ {}
  pom {:project 'gdxtest
       :version "0.1.0-SNAPSHOT"}
  jar {:main 'gdxtest.desktop
       :file "gdxtest.jar"}
  aot {:all true})

(deftask build
  "Build it"
  []
  (comp (aot) 
        (pom) 
        (uber)
        (jar) 
        (target)))

;; vim: set ft=clojure:
