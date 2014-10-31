(define (test)
  ((lambda (x) (* x x)) 3))
(define (less-than list)
  (lambda (x)
    (if (null? list ) '()
               (if (> x (car list)) (cons (car list) ((less-than (cdr list)) x))
                   ((less-than (cdr list)) x)))))

                                                