#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_leap_year(int year)
{
    return ((
        year % 4 == 0 &&
        year % 400 == 0 &&
        year % 100 == 0) ||
        year % 4 == 0 &&
        year % 100 != 0);
}

int valid_day_month(int day, int month) {
    int months_days[] = {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    return day <= months_days[month - 1];
}

int ask_day()
{
    while (1)
    {
        int day;
        printf("Dia: ");
        scanf("%d", &day);

        if (day < 1 || day > 31)
        {
            printf("Dia inválido\n");
        }
        else return day;
    }
}

int ask_month(int day)
{
    while (1)
    {
        int month;
        printf("Mês: ");
        scanf("%d", &month);

        if (month < 1 || month > 12)
            printf("[!] Mês inválido\n");
        else if (!valid_day_month(day, month))
            printf("[!] O mês %d não tem o dia %d\n", month, day);
        else
            return month;
    }
}

int ask_year(int day, int month)
{
    while (1)
    {
        int year;
        printf("Ano: ");
        scanf("%d", &year);

        if (year < 0)
            printf("[!] Ano inválido\n");
        else if (!is_leap_year(year) && month == 2 && day >= 29)
            printf("[!] O ano %d não tem o dia %d de feveriro\n", year, day);
        else
            return year;
    }
}

typedef struct date
{
    int day;
    int month;
    int year;
    int qtty;
    struct date *next;
} date;

typedef struct storage
{
    int code;
    char description[50];
    char brand[50];
    struct date *expiration;
    struct storage *next;
} storage;

void print_data(int day, int month, int year) {
    if (day < 10) printf("0");
    printf("%d/", day);
    if (month < 10) printf("0");
    printf("%d/%d", month, year);

}

void check_quantity(storage *aux)
{
    if (aux == NULL) return;

    printf("\n================ Produto %d ===============\n", aux->code);
    date *data_aux = aux->expiration;

    while (data_aux != NULL)
    {
        printf("===========================================\n");
        printf("Validade: ");
        print_data(data_aux->day, data_aux->month, data_aux->year);
        printf("\n%d unidades\n", data_aux->qtty);
        data_aux = data_aux->next;
        printf("===========================================\n");
    }
    printf("===========================================\n\n");
    aux = aux->next;
    check_quantity(aux);
}

date *set_expiration(date *expiration, int day, int month, int year, int qtty)
{
    date *new = (date *)malloc(sizeof(date));

    if (new == NULL)
    {
        printf("Algum erro aconteceu\n");
        return expiration;
    }
    if (expiration == NULL)
    {
        new->day = day;
        new->month = month;
        new->year = year;
        new->qtty += qtty;
        new->next = NULL;
        expiration = new;
        return expiration;
    }

    date *aux;
    aux = expiration;

    while ((aux->next != NULL) && (aux->day > day) && (aux->month > month) && (aux->year > year))
    {
        aux = aux->next;
    }

    if (aux->next == NULL)
    {

        if (aux->year > year)
        {

            new->day = aux->day;
            new->year = aux->year;
            new->month = aux->month;
            new->qtty = aux->qtty;
            new->next = aux->next;
            aux->day = day;
            aux->year = year;
            aux->month = month;
            aux->qtty = qtty;
            aux->next = new;
        }
        else if (aux->year == year)
        {
            if (aux->month > month)
            {

                new->day = aux->day;
                new->year = aux->year;
                new->month = aux->month;
                new->qtty = aux->qtty;
                new->next = aux->next;
                aux->day = day;
                aux->year = year;
                aux->month = month;
                aux->qtty = qtty;
                aux->next = new;
            }
            else if (aux->month == month)
            {
                if (aux->day > day)
                {
                    new->day = aux->day;
                    new->year = aux->year;
                    new->month = aux->month;
                    new->qtty = aux->qtty;
                    new->next = aux->next;
                    aux->day = day;
                    aux->year = year;
                    aux->month = month;
                    aux->qtty = qtty;
                    aux->next = new;
                }
                else if (aux->day == day)
                {
                    aux->qtty += qtty;
                }
                else
                {

                    new->day = aux->day;
                    new->year = new->year;
                    new->month = new->month;
                    new->qtty = new->qtty;
                    new->next = aux->next;
                    aux->day = day;
                    aux->year = year;
                    aux->month = month;
                    aux->qtty = qtty;
                    aux->next = new;
                }
            }
            else
            {

                new->next = aux->next;
                new->year = year;
                new->month = month;
                new->day = day;
                new->qtty = aux->qtty;

                aux->next = new;
                new->year = year;
                new->month = month;
                new->day = day;
                new->qtty = qtty;
            }
        }
        else
        {

            new->next = aux->next;
            new->year = year;
            new->month = month;
            new->day = day;
            new->qtty = aux->qtty;

            aux->next = new;
            new->year = year;
            new->month = month;
            new->day = day;
            new->qtty = qtty;
        }

        return expiration;
    }
    else
    {
        if (aux->year > year)
        {

            new->day = aux->day;
            new->year = aux->year;
            new->month = aux->month;
            new->qtty = aux->qtty;
            new->next = aux->next;
            aux->day = day;
            aux->year = year;
            aux->month = month;
            aux->qtty = qtty;
            aux->next = new;
        }
        else if (aux->year == year)
        {
            if (aux->month > month)
            {

                new->day = aux->day;
                new->year = aux->year;
                new->month = aux->month;
                new->qtty = aux->qtty;
                new->next = aux->next;
                aux->day = day;
                aux->year = year;
                aux->month = month;
                aux->qtty = qtty;
                aux->next = new;
            }
            else if (aux->month == month)
            {
                if (aux->day > day)
                {

                    new->day = aux->day;
                    new->year = aux->year;
                    new->month = aux->month;
                    new->qtty = aux->qtty;
                    new->next = aux->next;
                    aux->day = day;
                    aux->year = year;
                    aux->month = month;
                    aux->qtty = qtty;
                    aux->next = new;
                }
                else if (aux->day == day)
                {
                    aux->qtty += qtty;
                }
                else
                {

                    new->next = aux->next;
                    new->year = year;
                    new->month = month;
                    new->day = day;
                    new->qtty = aux->qtty;

                    aux->next = new;
                    new->year = year;
                    new->month = month;
                    new->day = day;
                    new->qtty = qtty;
                }
            }
            else
            {

                new->next = aux->next;
                new->year = year;
                new->month = month;
                new->day = day;
                new->qtty = aux->qtty;

                aux->next = new;
                new->year = year;
                new->month = month;
                new->day = day;
                new->qtty = qtty;
            }
        }
        else
        {

            new->next = aux->next;
            new->year = year;
            new->month = month;
            new->day = day;
            new->qtty = aux->qtty;

            aux->next = new;
            new->year = year;
            new->month = month;
            new->day = day;
            new->qtty = qtty;
        }
        return expiration;
    }
}

storage *create_product(storage *produto, storage *aux, storage *head)
{

    printf("\n===========================================\n");
    int cod, day, month, year, qtty;
    char desc[50], brand[50];
    printf("Digite o código do produto: ");
    scanf("%d", &cod);
    getchar();
    printf("Digite a descrição do produto: ");
    scanf("%s", desc);
    printf("Digite a marca do produto: ");
    scanf("%s", brand);
    printf("Digite a data de validade do produto:\n");
    day = ask_day();
    month = ask_month(day);
    year = ask_year(day, month);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &qtty);

    storage *new;
    new = (storage *)malloc(sizeof(storage));
    if (new == NULL)
        printf("Não foi possivel alocar memória\n");
    else
    {
        if (produto == NULL)
        {
            new->code = cod;
            strcpy(new->description, desc);
            strcpy(new->brand, brand);
            new->expiration = set_expiration(new->expiration, day, month, year, qtty);
            new->next = NULL;
            produto = new;
            return produto;
        }
        else
        {
            new->expiration = NULL;
            storage *aux = produto;
            while (aux->next != NULL && cod > aux->code)
            {
                aux = aux->next;
            }
            if (aux->next == NULL)
            {
                if (cod > aux->code)
                {
                    new->next = NULL;
                    new->code = cod;
                    strcpy(new->description, desc);
                    strcpy(new->brand, brand);
                    new->expiration = set_expiration(new->expiration, day, month, year, qtty);
                    aux->next = new;
                }
                else
                {
                    if (aux->code == cod)
                    {

                        new->code = aux->code;
                        new->expiration = aux->expiration;
                        aux->expiration = set_expiration(new->expiration, day, month, year, qtty);
                        aux->next = NULL;
                    }
                    else
                    {
                        new->code = aux->code;
                        new->expiration = aux->expiration;
                        strcpy(new->brand, aux->brand);
                        strcpy(new->description, aux->description);
                        new->next = aux->next;
                        aux->code = cod;
                        strcpy(aux->brand, brand);
                        strcpy(aux->description, desc);
                        aux->expiration = set_expiration(new->expiration, day, month, year, qtty);
                        aux->next = new;
                    }
                }
            }
            else
            {
                if (aux->code == cod)
                {
                    new->code = aux->code;
                    new->expiration = aux->expiration;
                    aux->expiration = set_expiration(new->expiration, day, month, year, qtty);
                    aux->next = NULL;
                }
                else
                {
                    new->code = aux->code;
                    new->expiration = aux->expiration;
                    strcpy(new->brand, aux->brand);
                    strcpy(new->description, aux->description);
                    new->next = aux->next;
                    aux->code = cod;
                    strcpy(aux->brand, brand);
                    strcpy(aux->description, desc);
                    aux->expiration = set_expiration(new->expiration, day, month, year, qtty);
                    aux->next = new;
                }
            }
            return produto;
        }
    }
}

void print_storage(storage *aux)
{
    while (aux != NULL)
    {
        printf("\n\n");
        printf("Código: %d\n", aux->code);
        printf("Descrição: %s\n", aux->description);
        printf("Marca: %s\n", aux->brand);
    
        date *expiration = aux->expiration;
        printf("Validade: ");
        print_data(expiration->day, expiration->month, expiration->year);
        printf("\n%d unidades\n", expiration->qtty);
        expiration = expiration->next;
        printf("###\n");
        aux = aux->next;
    }
}

void remove_item(storage *head, int code, int qtty)
{
    if (head == NULL)
        return;

    date *data_aux = head->expiration;
    date *aux1 = NULL;

    if (code == head->code)
    {
        data_aux->qtty -= qtty;
        if (data_aux->qtty < 0)
        {
            qtty = (data_aux->qtty * -1);

            aux1 = data_aux->next;
            head->expiration = NULL;
            free(head->expiration);
            head->expiration = aux1;
            
            int old_qtty = qtty;
            while (qtty > 0 && aux1 != NULL)
            {
                aux1->qtty -= qtty;

                qtty = (aux1->qtty * -1);
                aux1 = aux1->next;
            }

            free(head->expiration);
            head->expiration = data_aux->next;

            if (head->expiration == NULL)
            {
                printf("[!] A quantidade a ser removida ultrapassa a quantidade em estoque\n\n");
            }
            else
            {
                free(head->expiration);
                head->expiration = data_aux->next;
                printf("\n### PRODUTO REMOVIDO COM SUCESSO ###\n\n\n");
            }
        }
        else
        {

            if (data_aux->qtty == 0)
            {
                free(head->expiration);
                head->expiration = data_aux->next;
            }
            printf("\n### PRODUTO REMOVIDO COM SUCESSO ###\n\n\n");
        }

        return;
    }
    else
        printf("\n### O PRODUTO NÃO EXISTE ###\n");

    free(head->expiration);
    head->expiration = data_aux->next;

    remove_item(head->next, code, qtty);
}

int show_options()
{
    printf("### Seja bem vindo ao gerenciador de estoque ###\n");
    storage *elem = NULL;
    storage *head = NULL;

    while (1)
    {

        printf("\n### Escreva uma das opções abaixo: ###\n");
        printf("(0) Fechar gerenciador\n(1) Adicionar produto\n(2) Retirar produto\n(3) Consultar produtos\n(4) Total de produtos\n");

        int input;
        scanf("%d", &input);

        if (input == 0)
            break;

        if (input == 1)
        {
            int n;
            storage *aux;
            aux = create_product(elem, aux, head);
            head = aux;
            elem = head;
            printf("\n### NOVO PRODUTO ADICIONADO ###\n\n\n");
        }
        else if (input == 2)
        {
            int qtty_remove, product_code;
            printf("Digite o código do produto a ser removido: ");
            scanf("%d", &product_code);
            printf("Digite a quantidade a ser removida: ");
            scanf("%d", &qtty_remove);
            remove_item(head, product_code, qtty_remove);
        }
        else if (input == 3)
            print_storage(head);
        else if (input == 4)
            check_quantity(head);
    }
}
int main()
{
    show_options();
    return 0;
}