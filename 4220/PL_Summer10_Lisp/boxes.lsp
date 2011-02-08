;Thomas Cross
(defun get3 ()
(let ((a) (b) (c))
(setf a (read))
(setf b (read))
(setf c (read))
(list (list a) (list b) (list c))
))
(defun makeGlobalCounters ()
        (setf acounter 0)
        (setf bcounter 0)
        (setf ccounter 0)
        (setf the_case 0)
)

(defun checkForThreeZeros (the_three)
        ;(print (nth 0 the_three) )
        ;(print (nth 1 the_three) )
        ;(print (nth 2 the_three) )
        (if(= (first (nth 0 the_three)) 0)
                (if(= (first (nth 1 the_three)) 0)
                        (if(= (first (nth 2 the_three)) 0) (exit) ; 3 (0)'s means quit
                        )
                )
        )
        ;( if(= (nth 2 the_three) 0) (setf retval -1) (setf retval 1) )
        ;(print (first (rest (rest the_three))) );Actually works :)
)

(defun checkForThreeNegitiveOnes (the_three)
        ;(print (nth 0 the_three) )
        ;(print (nth 1 the_three) )
        ;(print (nth 2 the_three) )
        (if(= (first (nth 0 the_three)) -1)
                (if(= (first (nth 1 the_three)) -1)
                        ( if(= (first (nth 2 the_three)) -1)  (progn 
                                                                        (setf conveyor (updateConveyorWidth (get3))) ;3 (-1)'s means update conveyor
                                                                        (getNextThree (get3))
                                                              )
                        )
                 )
        )
        ;( if(= (nth 2 the_three) -1) (setf retval -1) (setf retval 1) )
        ;(print (first (rest (rest the_three))) );Actually works :)
)

(defun updateConveyorWidth (the_three)
        (checkForThreeZeros the_three);Just making sure, in the event (-1 -1 -1) --> (0 0 0)
        (setf the_case (+ the_case 1))
        (format t "~%Case ~d:" the_case)

                                ;(print (first (nth 0 the_three)))
                                ;(print (first (nth 1 the_three)))
                                ;(print (first (nth 2 the_three)))
        (list
                (list 
                        (list 
                                (first (nth 0 the_three))
                        )
                        (list 
                        ;        ()
                        )
                )
                (list 
                        (list 
                                (first (nth 1 the_three))
                        )
                        (list 
                        ;        ()
                        )
                )
                (list 
                        (list 
                                (first (nth 2 the_three))
                        )
                        (list 
                        ;        ()
                        )
                )
        )
)

(defun evaluateABoxes (the_three)
        (if(first(last(last(first conveyor))))
                (if(>(-(+(first(first the_three)) (apply #'+ (first(last(first conveyor)))))40) (floor(/(first(first(last(first conveyor))))2)))
        ;(if(> (+ (first(first the_three)) (apply #'+ (first(last(first conveyor))))) 40) 
                        (progn
                                (setf (first(last(first conveyor))) (butlast (first(last(first conveyor)))))
                                (format t "~%   Box ~d fell off conveyor A" (setf acounter (+ acounter 1)))
                                (evaluateABoxes the_three)
                        )
                        (setf (first(last(first conveyor))) (cons (first (first the_three)) (first (last (first conveyor)))))
                )
        (setf (first(last(first conveyor))) (cons (first (first the_three)) (first (last (first conveyor))))) 
        )
)


(defun evaluateBBoxes (the_three)
        (if(first(last(last(second conveyor))))
                (if(>(-(+(first(first the_three)) (apply #'+ (first(last(second conveyor)))))40) (floor(/(first(first(last(second conveyor))))2)))
                ;(if(> (+ (first(first the_three)) (apply #'+ (first(last(second conveyor))))) 40) 
                        (progn
                                (setf (first(last(second conveyor))) (butlast (first(last(second conveyor)))))
                                (format t "~%   Box ~d fell off conveyor B" (setf bcounter (+ bcounter 1)))
                                (evaluateBBoxes the_three)
                        )
                        (setf (first(last(second conveyor))) (cons (first (first the_three)) (first (last (second conveyor)))))
                )
                (setf (first(last(second conveyor))) (cons (first (first the_three)) (first (last (second conveyor)))))
        )
)

(defun evaluateCBoxes (the_three)
        (if(first(last(last(third conveyor))))
                (if(>(-(+(first(first the_three)) (apply #'+ (first(last(third conveyor)))))40) (floor(/(first(first(last(third conveyor))))2)))
                ;(if(> (+ (first(first the_three)) (apply #'+ (first(last(third conveyor))))) 40) 
                        (progn
                                (setf (first(last(third conveyor))) (butlast (first(last(third conveyor)))))
                                (format t "~%   Box ~d fell off conveyor C" (setf ccounter (+ ccounter 1)))
                                (evaluateCBoxes the_three)
                        )
                        (setf (first(last(third conveyor))) (cons (first (first the_three)) (first (last (third conveyor)))))
                )
                (setf (first(last(third conveyor))) (cons (first (first the_three)) (first (last (third conveyor)))))
        )
)

(defun addToConveyor (the_three)
        (if(<= (first (second the_three)) (first(first(first conveyor)))) (evaluateABoxes the_three )
                (if(<= (first (second the_three)) (first(first(second conveyor)))) (evaluateBBoxes the_three)
                        (if(<= (first (second the_three)) (first(first(third conveyor)))) (evaluateCBoxes the_three)
                        )
                )    
        )
        ;(print (first(first(first conveyor))))
        ;(print (first(first(second conveyor))))
        ;(print (first(first(third conveyor))))
        ;(print conveyor)
        ;(print (sum-list (first(last(first conveyor)))))
)


(defun getNextThree (the_three)
        ;(print (nth 0 the_three) )
        ;(print (nth 1 the_three) )
        ;(print (nth 2 the_three) )
        ;(if(= (checkForThreeZeros the_three) -1) (exit))
        ;(if(= (checkForThreeNegitiveOnes the_three) 1) (if(= (checkForThreeZeros the_three) 1) (getNextThree (get3)) (exit) )  (setf conveyor (updateConveyorWidth (get3)))  );if not all (-1) or (0) 
        (checkForThreeZeros the_three)
        (checkForThreeNegitiveOnes the_three)
        (addToConveyor the_three)
        (getNextThree (get3))
)

(makeGlobalCounters)
(setf conveyor (updateConveyorWidth (get3)));Set up the conveyor for first time
(getNextThree (get3));Recursively get 3 numbers at a time
