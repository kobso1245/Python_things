
(define (uniq-help list constList)
  (if(null? list) constList
     (if (exist? (car list) constList) (uniq-help (cdr list) constList)
         (uniq-help (cdr list) (cons (car list) constList)))))
(define (uniq list)
  (uniq-help list '()))
 (define (exist? elem list2)
   (if(null? list2) #f
       (if (= elem (car list2)) #t
           (exist? elem (cdr list2)))))
      
