(ns gdxtest.desktop
  (:require [gdxtest.core :refer [make-game]])
  (:import [com.badlogic.gdx.backends.lwjgl LwjglApplication
                                            LwjglApplicationConfiguration])
  (:gen-class))

(defn -main
  [& args]
  (let [config (-> (LwjglApplicationConfiguration.))
        game (make-game)]
    (LwjglApplication. game config)))
