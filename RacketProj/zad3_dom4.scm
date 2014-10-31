(define (filter-list pred? list)
(cond
((null? list) '())
((pred? (car list)) (cons (car list) (filter-list pred? (cdr list))))
(else (filter-list pred? (cdr list)))))

(define (difference list1 list2)
  (dif-help list1 list2 '()))
(define (dif-help list1 list2 curOut)
    (if (null? list1) (append curOut '())
        (dif-help (cdr list1) list2 (append curOut (if (null? (filter-list (lambda (x) (if(= x (car list1)) #t #f)) list2)) (cons (car list1) '()) '() )))))
