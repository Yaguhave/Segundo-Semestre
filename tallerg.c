#include <stdio.h>

int main()
{
    int id, stock = 0, cantidad, opcion, productoregistrado = 0,status;
    float precio, total_ganancias = 0, venta, descuento;
    char nombre[30];

    #define Rojo "\x1B[31m"
    #define Verde "\x1B[32m"
    #define Celeste "\x1B[36m"
    #define Reset "\x1B[0m"

    do
    {
        printf(Verde"\n\t------Menu------\n"Reset);
        printf("\t1. Registrar Producto\n");
        printf("\t2. Vender producto\n");
        printf("\t3. Reabastecer producto\n");
        printf("\t4. Mostrar informacion del producto\n");
        printf("\t5. Mostrar total de ganancias\n");
        printf("\t6. Salir\n");
        printf(Verde"\t----------------\n"Reset);
        printf("\tSeleccione una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            do
            {
                printf("\nIngrese el ID del producto: ");
                scanf("%d", &id);
                if (id <= 0)
                {
                    printf(Rojo"Id de producto no valido.\n"Reset);
                }
            } while (id <= 0);
            printf("Ingrese el nombre del producto: ");
            fflush(stdin);
            fgets(nombre, 30, stdin);

            do
            {
                printf("Ingrese la cantidad inicial en stock: ");
                status=scanf("%d", &stock);
                if (status==0)
                {
                    printf(Rojo"Ingrese un numero. "Reset);
                    while (getchar() != '\n');
                }
                if (stock <= 0)
                {
                    printf(Rojo"Stock Invalido.\n"Reset);
                }
            } while (stock <= 0||status==0);

            do
            {
                printf("Ingrese el precio unitario del producto: ");
                status=scanf("%f", &precio);
                if (status==0)
                {
                    printf(Rojo"Ingrese un numero. "Reset);
                    while (getchar() != '\n');
                }
                if (precio <= 0)
                {
                    printf(Rojo"Precio Invalido.\n"Reset);
                }
            } while (precio <= 0||status==0);
            productoregistrado = 1;
            break;
        case 2:
            if (productoregistrado != 1)
            {
                printf(Verde"\nPor favor primero registrar el producto.\n"Reset);
                break;
            }
            if (stock <= 0)
            {
                printf(Rojo"El stock actual del producto es de 0 unidades, por favor reabastecer el producto\n"Reset);
                break;
            }
            do
            {
                printf("\nIngrese la cantidad a vender: ");
                status=scanf("%d", &cantidad);
                if (status==0)
                {
                    printf(Rojo"Ingrese un numero. "Reset);
                    while (getchar() != '\n');
                }
                if (cantidad > stock)
                {
                    printf(Rojo"No existe la cantidad necesaria para esta venta. Vuelva a ingresar la cantidad. \n"Reset);
                }

            } while (cantidad < 1 || cantidad > stock||status==0);
            do
            {
                printf("Ingrese la cantidad de descuento que desea: ");
                status=scanf("%f", &descuento);
                if (status==0)
                {
                    printf(Rojo"Ingrese un numero.\n"Reset);
                    while (getchar() != '\n');
                }
                if (descuento < 0 || descuento > 100)
                {
                    printf(Rojo"Cantidad de descuento no valida.\n"Reset);
                }
            } while (descuento < 0 || descuento > 100||status==0);
            if (descuento == 0)
            {
                venta = cantidad * precio;
            }
            if (descuento >= 1)
            {
                venta = cantidad * precio;
                descuento = venta * (descuento / 100);
                venta = venta - descuento;
            }
            printf(Verde"El total de la venta es $%.2f\n", venta, Reset);
            total_ganancias += venta;
            stock -= cantidad;
            break;

        case 3:
            if (productoregistrado != 1)
            {
                printf(Rojo"\nPor favor primero registrar el producto.\n"Reset);
                break;
            }
            do
            {
                printf("\nIngrese la cantidad a agregar al stock: ");
                status=scanf("%d", &cantidad);
                if (status==0)
                {
                    printf(Rojo"Ingrese un numero. "Reset);
                    while (getchar() != '\n');
                }
                if (cantidad <= 0)
                {
                    printf(Rojo"La cantidad debe ser mayor a 0. Vuelva a ingresar la cantidad. \n"Reset);
                }

            } while (cantidad <= 0||status==0);

            stock += cantidad;
            printf(Verde"El stock actual ahora es de %d.\n", stock, Reset);
            break;

        case 4:
            if (productoregistrado != 1)
            {
                printf(Rojo"\nPor favor primero registrar el producto.\n"Reset);
                break;
            }
            printf(Celeste"\n\t----------------\n"Reset);
            printf("\tInformación del producto:\n");
            printf("\tID: %d\n", id);
            printf("\tNombre: %s", nombre);
            printf("\tStock disponible: %d\n", stock);
            printf("\tPrecio unitario: $%.2f\n", precio);
            printf(Celeste"\t----------------\n"Reset);
            break;

        case 5:
            if (productoregistrado != 1)
            {
                printf(Rojo"\nPor favor primero registrar el producto.\n"Reset);
                break;
            }
            printf(Verde"\nTotal de ganancias: $%.2f\n", total_ganancias, Reset);
            break;

        case 6:
            printf(Rojo"Saliendo del programa...\n"Reset);
            break;

        default:
            printf(Rojo"\nOpción inválida. Intente nuevamente.\n"Reset);
        }
    } while (opcion != 6);

    return 0;
}