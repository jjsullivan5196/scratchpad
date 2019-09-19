(ns gdxtest.core
  (:import [com.badlogic.gdx ApplicationListener]))

(defn create
  []
  (println "New game!"))

(defn resize
  [width height]
  (println "New size is actually" width "x" height))

(defn make-game
  []
  (reify ApplicationListener
    (create [self]
      (create))
    (resize [self w h]
      (resize w h))
    (render [self])
    (pause [self])
    (resume [self])
    (dispose [self])))
