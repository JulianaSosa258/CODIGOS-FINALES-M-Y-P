#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void ingresar_paciente();
void lista_pacientes();
void eliminar_cita();
void verespecialidades();
void login();
float charge(int);


struct patient{
    int cedula;
    char nombre_paciente[50];
    int esp_num;
    char correo[50];

}p;

FILE *fp;
int main(){

    int ch;

        system("cls");
		system("COLOR 0B");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
	printf("\t\t|       ---------------------------------       |\n");
	printf("\t\t|       |  FUNDACION SALUD PARA TODOS   |       |\n");
	printf("\t\t|       |       SISTEMA DE CITAS        |       |\n");
	printf("\t\t|       ---------------------------------       |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	printf(" \n Presione cualquier tecla para continuar:");
	getch();
	system("cls");
	login();
	flag1:
    system("cls");
	printf("\n====================================\n");
	printf("  SISTEMA DE AGENDAMIENTO DE CITAS");
	printf("\n====================================\n");
	printf("\n1>> Reserve una cita");
	printf("\n------------------------------------");
	printf("\n2>> Ver la lista de citas");
	printf("\n------------------------------------");
    printf("\n3>> Ver la lista de especialidades");
    printf("\n------------------------------------");
    printf("\n4>> Eliminar citas");
	printf("\n------------------------------------");
	printf("\n5>> Salir");
    printf("\n------------------------------------");
	printf("\n-->");
    scanf("%d", &ch);

        switch(ch){
        case 5:
            exit(0);

        case 1:
            ingresar_paciente();
            break;
            getch();

        case 2:
            lista_pacientes();
            break;

        case 3:
            verespecialidades();
            break;

        case 4:
        	eliminar_cita();
            break;


        default:
            printf("Opcion invalida...\n\n");

        }
        printf("\n\nPresiona una tecla para continuar...");
        getch();

	goto flag1;
    return 0;
}
void ingresar_paciente(){
    fp = fopen("patient.txt","ab");
    system("cls");
    char confirm;
	float charges;
    int i=0;
	printf("\t\t=================================================\n\n\n");
    printf("\nIngrese la cedula del paciente:  ");
    scanf("%d", &p.cedula);
    printf("\nIngrese nombre del paciente: ");
    fflush(stdin);
    gets(p.nombre_paciente);
    printf("\nIngrese el correo electronico del paciente:");
    fflush(stdin);
    gets(p.correo);
    printf("\n>>Presiona Enter para ver las especialidades disponibles<< ");
	getch();
	system("cls");
    verespecialidades();
    printf("\n-----------------------------------------------------\n");
	start1:
    printf(">>Ingrese en numero de la especialidad: ");
    fflush(stdin);
    scanf("%d",&p.esp_num);
    if(p.esp_num>=1 && p.esp_num<=10)
	{
		charges=charge(p.esp_num);
	}
	else
	{
		printf("\nNumero de especialidad incorrecto, intente de nuevo--> ");
		goto start1;
	}
    printf("\n\nPara confirmar cita escriba 'y', caso contrario escriba 'n':--->");
	start:
	scanf(" %c",&confirm);
	fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    system("cls");
    if(confirm == 'y')
	{
        printf("\n------------------------------------------------------------------------------------------------\n");
        printf("NOMBRE PACIENTE\t\tNro ESPECIALIDAD\tCORREO PACIENTE\t\tCOSTO\n");
        printf("------------------------------------------------------------------------------------------------\n");
	    printf("%s\t\t\t%d\t\t\t%s\t\t\t%.2f\n",&p.nombre_paciente,p.esp_num,p.correo,charges);
		printf("==================");
		printf("\n CITA AGENDADA\n");
		printf("==================");
		printf("\nPresiona cualquier tecla para ir al menu...");
    }
	else
	{
		if(confirm=='n'){
			printf("\n CITA NO AGENDADA!\nPresiona cualquier tecla para ir al menu...");
		}
		else
		{
			printf("\nOpcion incorrecta intente de nuevo... ");
			goto start;
		}
	}

}
void lista_pacientes(){
system("cls");
printf("==================\n");
printf("  LISTA DE CITAS \n");
printf("==================\n");
    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("%-10s %-30s %-30s %s\n","Cedula","Nom Paciente","Nro Especialidad","Correo");
    printf("------------------------------------------------------------------------------------------------\n");
    fp=fopen("patient.txt","rb");
    while(fread(&p,sizeof(p), 1, fp) == 1){
    printf("%-10d %-30s %-30d %s\n", p.cedula, p.nombre_paciente, p.esp_num, p.correo);
    }
    fclose(fp);

}
void verespecialidades(){
system("cls");
	printf("------------------------------------------------------------------------------------------------");
	printf("\nNo.Esp\tEspecialidades\t\t\tDoctores\t\tCostos\t\tHora de atencion\n");
	printf("------------------------------------------------------------------------------------------------");
	printf("\n01.\tMedicina general   \t\tDr.Tobias Sosa       \t$15  \t\t9:00am-17:00pm ");
	printf("\n02.\tObstetricia        \t\tDr.Koda Zuniga       \t$16  \t\t9:00am-17:00pm");
	printf("\n03.\tGinecologia        \t\tDra.Yeana Viral      \t$17  \t\t9:00am-17:00pm");
	printf("\n04.\tCardiologia        \t\tDr.Henry Guerra      \t$18  \t\t9:00am-17:00pm");
	printf("\n05.\tPediatria          \t\tDra.Abigail Casas    \t$19  \t\t9:00am-17:00pm");
	printf("\n06.\tOdontologia        \t\tDr.Derek Shepard     \t$20  \t\t9:00am-17:00pm");
    printf("\n07.\tOftalmologia       \t\tDra.Meredith Grey    \t$21  \t\t9:00am-17:00pm");
    printf("\n08.\tLaboratorio        \t\tDr.Juan P Isaza      \t$22  \t\t9:00am-17:00pm");
    printf("\n09.\tDermatologia       \t\tDr.Benito Martinez   \t$23  \t\t9:00am-17:00pm");
    printf("\n10.\tPsicologia         \t\tDr.Jh de la Cruz     \t$24  \t\t9:00am-17:00pm");

}
void eliminar_cita(){
system("cls");
    int id, f=0;
    system("cls");
    printf("<== Eliminar Citas ==>\n\n");
    printf("Ingrese la cedula del paciente: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("patient.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.cedula){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nCITA ELIMINADA");
    }else{
        printf("\n\nCita no existe el registro!");
    }

    fclose(fp);
    fclose(ft);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");

}
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10];
    char pass[10];
    do
{

    printf("\n  =======================  INICIAR SESION  =======================\n  ");
    printf(" \n                       USUARIO:-");
	scanf("%s", &uname);
	printf(" \n                       CONTRASENA:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"admin")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n   BIENVENIDO/A A LA RESERVACION DE CITAS DE LA FUNDACION SALUD PARA TODOS");
	printf("\n\n\n\t\t\t\tPresione cualquier tecla para continuar...");
	getch();
	break;
	}
	else
	{
		printf("\n        DATOS INCORRECTOS, INGRESE DE NUEVO");
		a++;
		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nDemasiados intentos fallidos, no se pudo ingresar sesion...");
		getch();
		}
		system("cls");
}

float charge(int esp_num)
{

	if (esp_num==1)

	{
		return(15);
	}
	if (esp_num==2)
	{
		return(16);
	}
	if (esp_num==3)
	{
		return(17);
	}
	if (esp_num==4)
	{
		return(18);
	}
	if (esp_num==5)
	{
		return(19);
	}
	if (esp_num==6)
	{
		return(20);
	}
	if (esp_num==7)
	{
		return(21);
	}
	if (esp_num==8)
	{
		return(22);
	}
	if (esp_num==9)
	{
		return(23);
	}
	if (esp_num==10)
	{
	    return(24);
	}
}