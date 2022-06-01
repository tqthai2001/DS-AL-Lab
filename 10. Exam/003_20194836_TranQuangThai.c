#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Customer{
    int num_customer;
    struct Customer *next_customer;
}Customer;

typedef struct Cashier{
    int num_cashier;
    int count_customer;
    struct Cashier *next_cashier;
    struct Customer *root_customer;
}Cashier;

Cashier *rootCashier;

Cashier *makeCashier(int num){
    Cashier *newCashier = (Cashier*)malloc(sizeof(Cashier));
    newCashier->num_cashier = num;
    newCashier->count_customer = 0;
    newCashier->next_cashier = newCashier;
    newCashier->root_customer = NULL;
    return newCashier;
}

Customer *makeCustomer(int num){
    Customer *newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->num_customer = num;
    newCustomer->next_customer = NULL;
    return newCustomer;
}

Cashier *insertCashier(Cashier *r, int n){
    if(r == NULL) return makeCashier(n);
    Cashier *p = r;
    while (p->next_cashier != r){
        p = p->next_cashier;
    }
    Cashier *ptr = makeCashier(n);
    p->next_cashier = ptr;
    ptr->next_cashier = r;
    return r;
}

Customer *insertCustomer(Customer *r_cus, int n_cus){
    if(r_cus == NULL) return makeCustomer(n_cus);
    Customer *p = r_cus;
    while (p->next_customer != NULL){
        p = p->next_customer;
    }
    p->next_customer = makeCustomer(n_cus);
    return r_cus;
}

Cashier *enter(Cashier *r, Cashier **cur, int *i){
    (*cur) = (*cur)->next_cashier;
    (*cur)->root_customer = insertCustomer((*cur)->root_customer, *i);
    (*cur)->count_customer += 1;
    printf("%d %d\n", *i, (*cur)->num_cashier);
    *i += 1;
    return r;
}

void advanced_enter(Cashier *r, int *i){
    Cashier *cur_advanced;
    int min = r->count_customer;
    int c = 0;
    Cashier *k = r;
    do{
        if(k->count_customer < min){
            min = k->count_customer;
            cur_advanced = k;
            c += 1;
        }
        k = k->next_cashier;
    } while (k != r);
    if(c == 0) cur_advanced = r;
    cur_advanced->root_customer = insertCustomer(cur_advanced->root_customer, *i);
    cur_advanced->count_customer += 1;
    printf("%d %d\n", *i, cur_advanced->num_cashier);
    *i += 1;
}

Cashier *findCashier(Cashier *r, int n){
    Cashier *k = r;
    do{
        if(k->num_cashier == n){
            return k;
        }
        k = k->next_cashier;
    } while (k != r);
    return NULL;
}

Cashier *checkout(Cashier *r, int n){
    Cashier *k = findCashier(r, n);
    if(k != NULL){
        if(k->count_customer == 0){
            printf("Empty\n");
        }
        else{
            printf("%d\n", k->root_customer->num_customer);
            k->count_customer -= 1;
            Customer *delete = k->root_customer;
            k->root_customer = k->root_customer->next_customer;
            free(delete);
        }
    }
    else printf("Error\n");
    return r;
}

void countCustomerInLine(Cashier *r, int n){
    Cashier *k = findCashier(r, n);
    if(k != NULL) printf("%d\n", k->count_customer);
    else printf("Error\n");
}

void listCustomerInLine(Cashier *r, int n){
    Cashier *k = findCashier(r, n);
    if(k != NULL){
        for (Customer *j = k->root_customer; j != NULL; j = j->next_customer){
            printf("%d ", j->num_customer);
        }
        printf("\n");
    }
    else printf("Error\n");
}

void countCustomerInAllLine(Cashier *r){
    int allCustomer = 0;
    Cashier *k = r;
    do{
        allCustomer = allCustomer + k->count_customer;
        k = k->next_cashier;
    } while (k != r);
    printf("%d\n", allCustomer);
}

Cashier *openCashier(Cashier *r, int *i, int *count){
    r = insertCashier(r, *i);
    printf("%d\n", *i);
    *i += 1;
    *count += 1;
    return r;
}

Cashier *closeCashier(Cashier *r, Cashier **cur, int n, int *count){
    Cashier *k = findCashier(r, n);
    if(k != NULL && *count >= 2){
        Cashier *prev = r;
        while (prev->next_cashier != k){
            prev = prev->next_cashier;
        }
        if(k == r && k->count_customer == 0){
            int flag = 0;
            if((*cur)->next_cashier == r) flag = 1;
            r = k->next_cashier;
            if(flag == 1) (*cur)->next_cashier = r;
        }
        else if(k == r) r = k->next_cashier;
        if(k->count_customer == 0){
            prev->next_cashier = k->next_cashier;
        }
        else{
            Customer *head = k->root_customer;
            prev->next_cashier = k->next_cashier;
            while (head != NULL){
                (*cur) = (*cur)->next_cashier;
                (*cur)->root_customer = insertCustomer((*cur)->root_customer, head->num_customer);
                (*cur)->count_customer += 1;
                head = head->next_customer;
            }
        }
        free(k);
        printf("Closed\n");
        *count -= 1;
    }
    else printf("Error\n");
    return r;
}

void delete(Cashier *r){
    Cashier *p = r->next_cashier;
    while (p != r){
        Cashier *del = p;
        p = p->next_cashier;
        free(del);
    }
    free(r);
}

int main(){
    int sumCashier = 4;
    int numCustomer = 1;
    int new_openCashier = 5;

    for (int i = 1; i <= sumCashier; i++){
        rootCashier = insertCashier(rootCashier, i);
    }

    Cashier *cur = (Cashier*)malloc(sizeof(Cashier));
    cur->next_cashier = rootCashier;

    while (1){
        char cmd[50];
        int x;
        scanf("%s", cmd);
        if(strcmp(cmd, "$Enter") == 0) rootCashier = enter(rootCashier, &cur, &numCustomer);
        else if(strcmp(cmd, "$AdvancedEnter") == 0) advanced_enter(rootCashier, &numCustomer);
        else if(strcmp(cmd, "$Checkout") == 0){
            scanf("%d", &x);
            rootCashier = checkout(rootCashier, x);
        }
        else if(strcmp(cmd, "$CountNumberCustomerInLine") == 0){
            scanf("%d", &x);
            countCustomerInLine(rootCashier, x);
        }
        else if(strcmp(cmd, "$ListCustomerInLine") == 0){
            scanf("%d", &x);
            listCustomerInLine(rootCashier, x);
        }
        else if(strcmp(cmd, "$CountNumberCustomerInAllLines") == 0) countCustomerInAllLine(rootCashier);
        else if(strcmp(cmd, "$OpenCashier") == 0){
            rootCashier = openCashier(rootCashier, &new_openCashier, &sumCashier);
        }
        else if(strcmp(cmd, "$CloseCashier") == 0){
            scanf("%d", &x);
            rootCashier = closeCashier(rootCashier, &cur, x, &sumCashier);
        }
        else if(strcmp(cmd, "***") == 0){
            delete(rootCashier);
            break;
        }
    }
}