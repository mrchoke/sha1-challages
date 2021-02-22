(ns hashy.core
  (require [pandect.algo.sha1 :refer :all])
  (:gen-class))

(defn -main []
  (loop [acc (sha1 "clubhouse")
         n 5555555554]
    (if (= n 0)
      (println acc)
    (recur (sha1 acc) (dec n)))))
