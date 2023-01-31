#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct patient{
    int id;
    char nompac[50];
    char dir[50];
    char dol[50];
    char dia[12];
}p;

struct doctor{
    int id;
    char name[50];
    char address[50];
    char specialize[50];
    char dia[12];
}d;

FILE *fp;

int main(){

    int ch;

    while(1){
        system("cls");
        printf("<== Sistema de admiciones ==>\n");
        printf("1.admiciones\n");
        printf("2.lista de Pacientes\n");
        printf("3.Eliminar pacientes\n");
        printf("0.salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &ch);


        switch(ch){
        case 0:
            exit(0);

        case 1:
            diaadmipac();
            break;

        case 2:
            listapac();
            break;

        case 3:
            elimpac();
            break;

        case 4:
            addDoctor();
            break;

        case 5:
            doctorList();
            break;

        default:
            printf("Invalid Choice...\n\n");

        }
        printf("\n\nPress Any Key To Continue...");
        getch();
    }

    return 0;
}

void diaadmipac(){
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(p.dia, myDate);

    fp = fopen("paciente.txt", "ab");

    printf("Ingrese ID Paciente: ");
    scanf("%d", &p.id);

    printf("Ingrese nombre del paciente: ");
    fflush(stdin);
    gets(p.nompac);

    printf("Ingrese Direccion domicilio: ");
    fflush(stdin);
    gets(p.dir);

    printf("Ingrese Sintomas: ");
    fflush(stdin);
    gets(p.dol);

    printf("\nPaciente Agregado Exitosamente");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}

void listapac(){

    system("cls");
    printf("<== Patient List ==>\n\n");
    printf("%-10s %-30s %-30s %-20s %s\n", "Id", "Patient Name", "Address", "Disease", "Date");
    printf("----------------------------------------------------------------------------------------------------------\n");

    fp = fopen("t", "rb");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("%-10d %-30s %-30s %-20s %s\n", p.id, p.nompac, p.dir, p.dol, p.dia);
    }

    fclose(fp);
}


void elimpac(){
    int id, f=0;
    system("cls");
    printf("<== Eliminar Paciente ==>\n\n");
    printf("Ingrese Id del paciente: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("paciente.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.id){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nPaciente eliminado exitosamente.");
    }else{
        printf("\n\nPaciente no encontrado !");
    }

    fclose(fp);
    fclose(ft);

    remove("paciente.txt");
    rename("temp.txt", "paciente.txt");

}

void addDoctor(){

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(d.dia, myDate);

    int f=0;

    system("cls");
    printf("<== Add Doctor ==>\n\n");

    fp = fopen("doctor.txt", "ab");

    printf("Enter Doctor id: ");
    scanf("%d", &d.id);

    printf("Enter Doctor Name: ");
    fflush(stdin);
    gets(d.name);

    printf("Enter Doctor Address: ");
    fflush(stdin);
    gets(d.address);

    printf("Doctor Specialize in: ");
    fflush(stdin);
    gets(d.specialize);

    printf("Doctor Added Successfully\n\n");

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
}



void doctorList(){
    system("cls");
    printf("<== Doctor List ==>\n\n");

    printf("%-10s %-30s %-30s %-30s %s\n", "id", "Name", "Address", "Specialize","Date");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("doctor.txt", "rb");
    while(fread(&d, sizeof(d), 1, fp) == 1){
        printf("%-10d %-30s %-30s %-30s %s\n", d.id, d.name, d.address, d.specialize, d.dia);
    }

fclose(fp);
}
