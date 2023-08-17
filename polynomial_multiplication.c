#include <stdio.h>
#include <stdlib.h>

struct term {
    int coefficient;
    int exponent;
};

struct polynomial {
    int n;
    struct term *t;
} poly1, poly2, product;

void create_poly(struct polynomial *poly) {
    printf("Number of non-zero terms: ");
    scanf("%d", &poly->n);

    poly->t = (struct term *)malloc(poly->n * sizeof(struct term));
    printf("Enter coefficient and exponent for each term (e.g., input: 2 4 output: 2x^4):\n");
    for (int i = 0; i < poly->n; i++) {
        scanf("%d%d", &poly->t[i].coefficient, &poly->t[i].exponent);
    }
}

void multiply_polynomials(const struct polynomial *poly1, const struct polynomial *poly2, struct polynomial *product) {
    product->n = poly1->n * poly2->n;
    product->t = (struct term *)malloc(product->n * sizeof(struct term));

    int k = 0;
    for (int i = 0; i < poly1->n; i++) {
        for (int j = 0; j < poly2->n; j++) {
            product->t[k].coefficient = poly1->t[i].coefficient * poly2->t[j].coefficient;
            product->t[k++].exponent = poly1->t[i].exponent + poly2->t[j].exponent;
        }
    }
}

void display_poly(const struct polynomial *poly) {
    for (int i = 0; i < poly->n; i++) {
        printf("%dx^%d ", poly->t[i].coefficient, poly->t[i].exponent);
        if (i != poly->n - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    printf("Creating polynomial 1:\n");
    create_poly(&poly1);
    printf("\nCreating polynomial 2:\n");
    create_poly(&poly2);

    printf("\nPolynomial 1: ");
    display_poly(&poly1);
    printf("Polynomial 2: ");
    display_poly(&poly2);

    multiply_polynomials(&poly1, &poly2, &product);

    printf("\nProduct of the polynomials: ");
    display_poly(&product);

    free(poly1.t);
    free(poly2.t);
    free(product.t);

    return 0;
}
