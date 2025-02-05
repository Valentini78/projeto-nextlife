#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
    char nome[100];
    char email[100];
    float peso;
    float altura;
    int treinos;
    int plano; 
};

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

int main() {
    struct Cliente clientes[100]; 
    int opcao, numClientes = 0;

    do {
        system("clear");
        printf("Selecione uma opção:\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Visualizar clientes \n");
        printf("3 - Editar cliente\n");
        printf("4 - Excluir cliente\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                system("clear");
                printf("Digite o nome do cliente: ");
                scanf("%s", clientes[numClientes].nome);
                printf("Digite o email do cliente: ");
                scanf("%s", clientes[numClientes].email);
                printf("Digite o peso do cliente (em kg): ");
                scanf("%f", &clientes[numClientes].peso);
                printf("Digite a altura do cliente (em metros): ");
                scanf("%f", &clientes[numClientes].altura);
                printf("Digite o número de treinos do cliente: ");
                scanf("%d", &clientes[numClientes].treinos);
                
                int plano;
        
                printf("Escolha o seu plano:\n");
                printf("1 - Básico\n");
                printf("2 - Premium\n");
                printf("Digite o número do plano desejado: ");
                scanf("%d", &plano);
                do{
                    if(plano != 1 && plano != 2){
                        system("clear");
                        printf("plano invalido\n");
                        printf("Escolha o seu plano:\n");
                        printf("1 - Básico\n");
                        printf("2 - Premium\n");
                        printf("Digite o número do plano desejado: ");
                        scanf("%d", &plano);
                    }
                }while(plano != 1 && plano != 2);
                
                clientes[numClientes].plano = plano;
                system("clear");
                printf("Cliente adicionado com sucesso.\n");
                numClientes++;
                sleep(2);
                break;

            case 2: 
                if (numClientes == 0) {
                    printf("Nenhum cliente cadastrado.\n");
                    sleep(2);
                } 
                else {
                    system("clear");
                    printf("Clientes cadastrados e seus IMCs:\n");
                    for (int i = 0; i < numClientes; i++) {
                        printf("Nome: %s\n", clientes[i].nome);
                        printf("Email: %s\n", clientes[i].email);
                        printf("Peso: %.2f kg\n", clientes[i].peso);
                        printf("Altura: %.2f metros\n", clientes[i].altura);
                        printf("Treinos: %d\n", clientes[i].treinos);
                        
                        if (clientes[i].plano == 1) {
                            printf("Plano: Básico\n");
                        } else if (clientes[i].plano == 2) {
                            printf("Plano: Premium\n");
                        } else {
                            printf("Plano: Não especificado\n");
                        }

                        // Calcular e exibir o IMC
                        float imc = calcularIMC(clientes[i].peso, clientes[i].altura);
                        printf("IMC: %.2f\n", imc);

                        // Interpretar o IMC
                        if (imc < 18.5) {
                            printf("Recomendação: Treinos de resistência e ganho de massa muscular.\n");
                        } else if (imc >= 18.5 && imc < 25) {
                            printf("Recomendação: Treinos de manutenção e condicionamento físico.\n");
                        } else if (imc >= 25 && imc < 30) {
                            printf("Recomendação: Treinos de perda de peso e cardio.\n");
                        } else {
                            printf("Recomendação: Consulte um médico e siga orientações profissionais.\n");
                        }
                        sleep(6);
                    }
                }
                break;

            case 3: 
                char nome[100];
                printf("Digite o nome do cliente que deseja editar: ");
                scanf("%s", nome);
                for (int i = 0; i < numClientes; i++) {
                    if (strcmp(clientes[i].nome, nome) == 0) {
                        printf("Digite o novo nome do cliente: ");
                        scanf("%s", clientes[i].nome);
                        printf("Digite o novo email do cliente: ");
                        scanf("%s", clientes[i].email);
                        printf("Digite o novo peso do cliente (em kg): ");
                        scanf("%f", &clientes[i].peso);
                        printf("Digite a nova altura do cliente (em metros): ");
                        scanf("%f", &clientes[i].altura);
                        printf("Digite o novo número de treinos do cliente: ");
                        scanf("%d", &clientes[i].treinos);
                        
                        // Editar o plano
                        printf("Escolha o novo plano:\n");
                        printf("1 - Básico\n");
                        printf("2 - Premium\n");
                        printf("Digite o número do plano desejado: ");
                        scanf("%d", &clientes[i].plano);
                        
                        system("clear");
                        printf("Cliente editado com sucesso.\n");
                        sleep(2);
                        break;
                    }
                }
                break;

            case 4: 
                printf("Digite o nome do cliente que deseja excluir: ");
                scanf("%s", nome);
                for (int i = 0; i < numClientes; i++) {
                    if (strcmp(clientes[i].nome, nome) == 0) {
                        for (int j = i; j < numClientes - 1; j++) {
                            clientes[j] = clientes[j + 1];
                        }
                        numClientes--;
                        system("clear");
                        printf("Cliente excluído com sucesso.\n");
                        sleep(2);
                        break;
                    }
                }
                break;

            case 5: 
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}



