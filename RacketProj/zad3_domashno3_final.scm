(define (accumulate op initial-value f a next b)
  (if (> a b)
      initial-value
      (op (f a) (accumulate op initial-value f (next a) next b))))
(define (fact p)
  (if (= p 0) 1
      (accumulate * 1 (lambda (a) a) 1 (lambda (a) (+ a 1)) p)))
(define (pow x n)
  (if (= n 0) 1
      (* x (pow x (- n 1)))))
(define (cosh-series x n)
  (accumulate + 0 (lambda (n) (/ (pow x n) (fact n))) 0 (lambda (n) (+ n 2)) (* 2 n))) 

(define pi 3.14159265)
