#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearCarpeta(const char *nombreCarpeta) {
    char comando[256];
    sprintf(comando, "mkdir %s", nombreCarpeta);
    system(comando);
    printf("Carpeta '%s' creada.\n", nombreCarpeta);
}

void bajarVolumen() {
    system("nircmd.exe changesysvolume -5000");
    printf("Volumen bajado.\n");
}

void bajarBrillo() {
    system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,10)");
    printf("Brillo bajado.\n");
}

int main() {
    int opcion;
    char nombreCarpeta[256];

    while (1) {
        printf("Sistema de Gestión de PC\n");
        printf("1. Crear Carpeta\n");
        printf("2. Bajar Volumen\n");
        printf("3. Bajar Brillo\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre de la carpeta: ");
                scanf("%s", nombreCarpeta);
                crearCarpeta(nombreCarpeta);
                break;
            case 2:
                bajarVolumen();
                break;
            case 3:
                bajarBrillo();
                break;
            case 4:
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    }

    return 0;
}
