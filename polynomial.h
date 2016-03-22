#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct polynomial_s *Polynomial;

#define  OK         0  /* operation with success */
#define  NO_POLY    1  /* the polynomial(s) do not exist */
#define  NO_MEM     2  /* out of memory */
#define  NO_FILE    3  /* file does not exist */
#define  BAD_DEGREE 4  /* wrong degree */
#define  BAD_INDEX  5  /* coefficient does not exist in the polynomial */

void        polynomial_error_clear          (void);
size_t      polynomial_error                (void);
char        *polynomial_error_message       (void);

Polynomial  polynomial_new                  (size_t degree);
Polynomial  polynomial_copy                 (Polynomial p);
void        polynomial_destroy              (Polynomial *p);

size_t      polynomial_get_degree           (Polynomial p);
void        polynomial_set_coefficient      (Polynomial p, size_t i, double a);
double      polynomial_get_coefficient      (Polynomial p, size_t i);

bool        polynomial_is_zero              (Polynomial p);
bool        polynomial_equals               (Polynomial p1, Polynomial p2);

double      polynomial_evaluate             (Polynomial p, double x);
Polynomial  polynomial_add                  (Polynomial p1, Polynomial p2);
Polynomial  polynomial_subtract             (Polynomial p1, Polynomial p2);
Polynomial  polynomial_multiply             (Polynomial p1, Polynomial p2);

Polynomial  polynomial_symmetric            (Polynomial p);
Polynomial  polynomial_derivative           (Polynomial p);
Polynomial  polynomial_indefinite_integral  (Polynomial p, double c);
double      polynomial_definite_integral    (Polynomial p, double a, double b);

void        polynomial_to_file              (Polynomial p, char *filename);
Polynomial  polynomial_from_file            (char *filename);

#endif /* __POLYNOMIAL_H__ */