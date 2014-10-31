(define (rev-help x curr)
  (if (= x 0) curr
      (rev-help (quotient x 10) (+(remainder x 10)(* curr 10)))))
(define (rev x)
  (rev-help x 0))
(define (palindrom? x)
  (if (= x (rev x)) #t
      #f))
(define (non-lychrel-sum a b)
  (if (= a b) (if (and (palindrom? (+ a (rev a))) #t )  a 
          0)
      (if (and (palindrom? (+ a (rev a))) #t ) (+ a (non-lychrel-sum (+ a 1) b))
          (+ 0 (non-lychrel-sum (+ a 1) b)))))