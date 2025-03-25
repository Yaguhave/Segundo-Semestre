#include <stdio.h>

int main()
{
    int id, stock, cantidad, opcion;
    float precio, total_ganancias = 0, venta;
    char nombre[30];

    // Registro del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);

    printf("Ingrese el nombre del producto: ");
    fflush(stdin);
    fgets(nombre, 30, stdin);

    printf("Ingrese la cantidad inicial en stock: ");
    scanf("%d", &stock);

    printf("Ingrese el precio unitario del producto: ");
    scanf("%f", &precio);

    do
    {
        printf("\nMenu\n");
        printf("1. Registrar Producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el ID del producto: ");
            scanf("%d", &id);

            printf("Ingrese el nombre del producto: ");
            fgets(nombre, 30, stdin);

            printf("Ingrese la cantidad inicial en stock: ");
            scanf("%d", &stock);

            printf("Ingrese el precio unitario del producto: ");
            scanf("%f", &precio);
            break;
        case 2:
            do
            {
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                if (cantidad < 1)
                {
                    printf("La cantidad debe ser mayor a 0. Vuelva a ingresar la cantidad. \n");
                }
                if (cantidad > stock)
                {
                    printf("No existe la cantidad necesaria para esta venta. Vuelva a ingresar la cantidad. \n");
                }
            } while (cantidad < 1 || cantidad > stock);
            venta=cantidad*precio;
            printf("El total de la venta es %.2f\n",venta);
            total_ganancias+=venta;
            stock-=cantidad;
            break;

        case 3:
            printf("Ingrese la cantidad a agregar al stock: ");
            scanf("%d", &cantidad);

            break;

        case 4:
            printf("\nInformación del producto:\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s", nombre);
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: %.2f\n", precio);
            break;

        case 5:
            printf("Total de ganancias: $%.2f\n", total_ganancias);
            break;

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}