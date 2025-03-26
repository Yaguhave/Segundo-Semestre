#include <stdio.h>

int main()
{
    int id, stock=0, cantidad, opcion;
    float precio, total_ganancias = 0, venta;
    char nombre[30];
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
            do{
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                if(id<=0){
                    printf("Id de producto no valido.\n");
                }
            }while(id<=0);
            printf("Ingrese el nombre del producto: ");
            fflush(stdin);
            fgets(nombre, 30, stdin);
            
            do
            {
                printf("Ingrese la cantidad inicial en stock: ");   
                scanf("%d", &stock);
                if (stock <= 0)
                {
                    printf("El stock debe ser mayor a 0. Vuelva a ingresar la cantidad\n");
                }
            } while (stock <= 0);
        
            do
            {
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);
                if (precio <= 0)
                {
                    printf("El precio debe ser mayor a 0. Vuelva a ingresar la cantidad\n");
                }
            } while (precio <= 0);
        
            break;
        case 2:
            if (stock <= 0)
            {
                printf("El stock actual del producto es de 0 unidades, por favor reabastecer el producto\n");
                break;
            }
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
            venta = cantidad * precio;
            printf("El total de la venta es %.2f\n", venta);
            total_ganancias += venta;
            stock -= cantidad;
            break;

        case 3:
            if(precio<=0){
                printf("\nPor favor primero registrar el producto.\n");
                break;
            }
            do
            {
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                if (cantidad <=0)
                {
                    printf("La cantidad debe ser mayor a 0. Vuelva a ingresar la cantidad. \n");
                }
                
            } while (cantidad <= 0);

            stock += cantidad;
            printf("el stock actual ahora es de %d\n", stock);
            break;

        case 4:
            if(precio<=0){
                printf("\nPor favor primero registrar el producto.\n");
                break;
            }
            printf("\nInformación del producto:\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s", nombre);
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: %.2f\n", precio);
            break;

        case 5:
            if(precio<=0){
                printf("\nPor favor primero registrar el producto.\n");
                break;
            }
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