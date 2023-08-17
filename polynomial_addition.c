#include <stdio.h>
#include <stdlib.h>

struct term {
    int coefficient;
    int exponent;
};

struct polynomial {
    int n;
    struct term *t;
} poly1, poly2, sum;

void create_poly(struct polynomial *poly) {
    printf("Number of non-zero terms: ");
    scanf("%d", &poly->n);

    poly->t = (struct term *)malloc(poly->n * sizeof(struct term));
    printf("Enter coefficient and exponent for each term (e.g., input: 2 4 output: 2x^4):\n");
    for (int i = 0; i < poly->n; i++) {
        scanf("%d%d", &poly->t[i].coefficient, &poly->t[i].exponent);
    }
}

void add_polynomials(const struct polynomial *poly1, const struct polynomial *poly2, struct polynomial *sum) {
    sum->n = poly1->n + poly2->n;
    sum->t = (struct term *)malloc(sum->n * sizeof(struct term));

    int i = 0, j = 0, k = 0;
    while (i < poly1->n && j < poly2->n) {
        if (poly1->t[i].exponent > poly2->t[j].exponent) {
            sum->t[k++] = poly1->t[i++];
        } else if (poly1->t[i].exponent < poly2->t[j].exponent) {
            sum->t[k++] = poly2->t[j++];
        } else {
            sum->t[k].coefficient = poly1->t[i].coefficient + poly2->t[j].coefficient;
            sum->t[k++].exponent = poly1->t[i].exponent;
            i++;
            j++;
        }
    }

    // Copy any remaining terms from poly1
    while (i < poly1->n) {
        sum->t[k++] = poly1->t[i++];
    }

    // Copy any remaining terms from poly2
    while (j < poly2->n) {
        sum->t[k++] = poly2->t[j++];
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

    add_polynomials(&poly1, &poly2, &sum);

    printf("\nSum of the polynomials: ");
    display_poly(&sum);

    free(poly1.t);
    free(poly2.t);
    free(sum.t);

    return 0;
}
