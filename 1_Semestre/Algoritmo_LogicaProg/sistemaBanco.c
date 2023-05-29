// Nicolas Gustavo Magrini Pereira
// Leonardo Morari dos Santos

#include <stdio.h>
#define MAX 50

struct cadastro {
  int codigoCliente, numeroAgencia;
  char nomeCliente[MAX], numeroContaCorrente[MAX];
  float saldoAtual;
};

struct cadastro clientes[MAX];
int contadorClientes = 0;

void cadastraCliente() {
  clientes[contadorClientes].codigoCliente = contadorClientes + 1;
  printf("\nNome: ");
  scanf("%s", clientes[contadorClientes].nomeCliente);
  printf("Agencia: ");
  scanf("%d", &clientes[contadorClientes].numeroAgencia);
  printf("Conta Corrente: ");
  scanf("%s", clientes[contadorClientes].numeroContaCorrente);
  printf("Saldo: ");
  scanf("%f", &clientes[contadorClientes].saldoAtual);
  contadorClientes++;
}

void sacar(int cliente) {
  int i = 0;
  while (clientes[i].codigoCliente != 0) {
    if (clientes[i].codigoCliente == cliente) {
      float quantia;
      printf("Digite uma quantia para saque: ");
      scanf("%f", &quantia);
      if (clientes[i].saldoAtual < quantia) {
        printf("Saldo insuficiente!");
      } else {
        clientes[i].saldoAtual -= quantia;
      }
    }
    i++;
  }
}

void depositar(int cliente) {
  int i = 0;
  while (clientes[i].codigoCliente != 0) {
    if (clientes[i].codigoCliente == cliente) {
      float quantia;
      printf("Digite uma quantia para depósito: ");
      scanf("%f", &quantia);
      clientes[i].saldoAtual += quantia;
    }
    i++;
  }
}

void pix(int cliente) {
  int i = 0;
  while (clientes[i].codigoCliente != 0) {
    if (clientes[i].codigoCliente == cliente) {
      float quantia;
      printf("Digite uma quantia para PIX: ");
      scanf("%f", &quantia);
      if (clientes[i].saldoAtual < quantia) {
        printf("Saldo insuficiente!");
      } else {
        clientes[i].saldoAtual -= quantia;
      }
    }
    i++;
  }
}

void transferencia() {
  float quantia;
  int cliente1, cliente2;
  printf("Digite o codigo da conta que vc quer tirar: ");
  scanf("%d", &cliente1);
  int i = 0;
  while (clientes[i].codigoCliente != 0) {
    if (clientes[i].codigoCliente == cliente1) {
      printf("Digite uma quantia para transferencia: ");
      scanf("%f", &quantia);
      clientes[i].saldoAtual -= quantia;
    }
    printf("Digite o codigo da conta que vc quer que receba e digite novamente: ");
    scanf("%d", &cliente2);
    if (clientes[i].codigoCliente == cliente2) {
      clientes[i].saldoAtual += quantia;
    }
    i++;
  }
}

void exibir() {
  for (int i = 0; i < contadorClientes; i++) {
    printf("CÓDIGO DO CLIENTE: %d - NOME DO CLIENTE: %s - AGÊNCIA: %d - CONTA "
           "CORRENTE: %s - SALDO ATUAL: %.2f",
           clientes[i].codigoCliente, clientes[i].nomeCliente,
           clientes[i].numeroAgencia, clientes[i].numeroContaCorrente,
           clientes[i].saldoAtual);
    printf("\n");
  }
}

void exibeUm(int cliente) {
  for (int i = 0; i < contadorClientes; i++) {
    if (clientes[i].codigoCliente == cliente) {
      printf("CÓDIGO DO CLIENTE: %d - NOME DO CLIENTE: %s - AGÊNCIA: %d "
             "- CONTA CORRENTE: %s - SALDO ATUAL: %.2f\n", clientes[i].codigoCliente, clientes[i].nomeCliente,clientes[i].numeroAgencia, clientes[i].numeroContaCorrente, clientes[i].saldoAtual);
    }
  }
}

void menu() {
  printf("Qual opção você deseja? \n1 - Sacar\n2 - Depositar\n3 - Pix\n4 - Cadastrar\n5 - Transferir\n6- Consultar\n");
}

int main() {
  int i, cliente, respMenu, respOP = 1;

  printf("Cadastre: \n");
  cadastraCliente(contadorClientes);

  while (respOP == 1) {
    i = 0;
    menu();
    scanf("%d", &respMenu);
    switch (respMenu) {
    case 1:
      exibir();
      i = 0;
      printf("Qual cliente você quer modificar (código)? ");
      scanf("%d", &cliente);
      sacar(cliente);
      break;
    case 2:
      exibir();
      i = 0;
      printf("Qual cliente você quer modificar (código)? ");
      scanf("%d", &cliente);
      depositar(cliente);
      break;
    case 3:
      exibir();
      i = 0;
      printf("Qual cliente você quer modificar (código)? ");
      scanf("%d", &cliente);
      pix(cliente);
      break;
    case 4:
      cadastraCliente();
      printf("Lista de clientes atualizada: \n");
      exibir();
      break;
    case 5:
      exibir();
      transferencia();
      break;
    case 6:
      int respConsulta, cliente;
      printf("Consultar um ou todos? 1-Um/2-Todos ");
      scanf("%d", &respConsulta);
      if (respConsulta == 1) {
        printf("Código do cliente: ");
        scanf("%d", &cliente);
        exibeUm(cliente);
      } else {
        exibir();
      }
    }
    printf("Quer continuar? 1-Sim/2-Nao ");
    scanf("%d", &respOP);
  }
}